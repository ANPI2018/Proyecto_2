/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: 
 * @Date  : 03.03.2018
 */

#include <cmath>
#include <limits>
#include <functional>
#include <algorithm>

#include "Exception.hpp"
#include "Matrix.hpp"

#ifndef ANPI_LU_DOOLITTLE_HPP
#define ANPI_LU_DOOLITTLE_HPP

namespace anpi {


  /**
   * Auxiliary method used to debug LU decomposition.
   *
   * It separates a packed LU matrix into the lower triangular matrix
   * L and the upper triangular matrix U, such that the diagonal of L
   * is composed by 1's.
   */
  template<typename T>
  void unpackDoolittle(const Matrix<T>& LU,
                       Matrix<T>& L,
                       Matrix<T>& U) {
	if(LU.rows() != LU.cols())
		throw anpi::Exception("The matrix LU is not a square matrix");

	L.allocate(LU.rows(), LU.rows());
   	U.allocate(LU.rows(), LU.rows());

	std::size_t matrixSize = LU.rows();
	for(std::size_t i = 0 ; i < matrixSize; i++){
		for (std::size_t j = 0 ; j < matrixSize; j++){
			if(i > j)
				L[i][j] = LU[i][j];
			else if (i == j){
				L[i][j] = 1;
				U[i][j] = LU[i][j];
			}
			else
				U[i][j] = LU[i][j];
		}
	}
  }
  
  /**
   * Decompose the matrix A into a lower triangular matrix L and an
   * upper triangular matrix U.  The matrices L and U are packed into
   * a single matrix LU. 
   *
   * The L matrix will have in the Doolittle's LU decomposition a
   * diagonal of 1's
   *
   * @param[in] A a square matrix 
   * @param[out] LU matrix encoding the L and U matrices
   * @param[out] permut permutation vector, holding the indices of the
   *             original matrix falling into the corresponding element.
   *             For example if permut[5]==3 holds, then the fifth row
   *             of the LU decomposition in fact is dealing with the third
   *             row of the original matrix.
   *
   * @throws anpi::Exception if matrix cannot be decomposed, or input
   *         matrix is not square.
   */
  template<typename T>
  void luDoolittle(const Matrix<T>& A,
                   Matrix<T>& LU,
                   std::vector<size_t>& permut) {

	if(A.rows() != A.cols())					//First corroboration.
		throw anpi::Exception("Matrix not square");
	const std::size_t matrixSize = A.rows();

	permut.resize(matrixSize);
	LU = A;

	for (std::size_t i = 0 ; i < matrixSize ; ++i) 			//Filling the permutation vector.
		permut[i] = T(i);
	
									//Copy of the original matrix to one that can be worked on.
	for (std::size_t i = 0 ; i < matrixSize-1; ++i){ 		//Iterates through rows. Main for.
		std::size_t j = i; 					//It works diagonally.
		T pivot = LU[i][j];					//The starting pivot always starts in an element of the diagonal.
		std::size_t row_pivot = i;				//It's necessary to know in which row is the pivot.

		for (std::size_t i_temp = i ; i_temp < matrixSize; ++i_temp){
			/*Finds the biggest absolute value in the column
		 		* and sets it as the pivot.*/		
			if(std::abs(LU(i_temp,j)) > std::abs(pivot)){ 	//A biggest value is found.
				pivot = LU[i_temp][j];			//Changes the pivot.
				row_pivot = i_temp;			//Sets the row of the element found as the new row of the pivot.
				permut[i] = permut[row_pivot];  				//Changes the permutation vector.
				permut[row_pivot] = i;
			}
		}
		if(pivot == T(0))
			throw anpi::Exception("Singular matrix");
		swapRows(LU, i,row_pivot,j);				//Swaps the row with the old pivot with the row of the new one.
		for (std::size_t i2 = i ; i2 < matrixSize -1 ; ++i2){ 	//Calculates the factors according to the row.
		T factor = LU[i2+1][j]/LU[i][j];						//Calculates the factor.
			for (std::size_t j2 = i ; j2 < matrixSize ; ++j2) 	//Executes the changes in the U matrix with the right factor.
				LU[i2+1][j2] = LU[i2+1][j2]-LU[i][j2]*factor;	//Executes the changes.
			LU[i2+1][j] = factor;								//Sets the factor calculated in the L matrix.
		}
	}
  }
	template<class T> 
	void swapRows(Matrix<T>& matriz, std::size_t row1, std::size_t row2, std::size_t column){ //Swap two rows given in the given matrix.

		for (std::size_t j = column; j < matriz.rows(); j++){
			T temporal = matriz[row1][j];
			matriz[row1][j] = matriz[row2][j];
			matriz[row2][j] = temporal;
		}
	}

namespace simd{

using namespace std;
template<typename T,class alloc,typename regType>
    inline void luDoolittleSIMD(const Matrix<T,alloc>& A,
                                Matrix<T,alloc>& LU,
                                std::vector<size_t>& permut){
	//First corroboration.
	if(A.rows() != A.cols())throw anpi::Exception("Matrix not square");

	const std::size_t matrixSize = A.rows(); //tamaño de la matriz

	const size_t stepSize = ceil(static_cast<float>(sizeof(regType))/static_cast<float>(sizeof(T))); //tamaño de los pasos
	const size_t stepTotal = static_cast<size_t>(A.dcols())/stepSize;//cantidad de pasos

	size_t i,j,k,t; //variables de iteracion
	T major; //mayor magnitud de la columna
	LU = A;

	regType* firstRow = reinterpret_cast<regType*>(LU.data()); //casteo el puntero de tipo T a regType
	regType* nextRow = firstRow + stepTotal; //casteo de puntero a la segunda columna
	regType* temporalRow = firstRow; //puntero temporal para pivote
	regType temporalData; //dato tempporal para pivote


	//llenado del vecto de permutacion
	permut.resize(matrixSize);
	for (std::size_t i = 0 ; i < matrixSize ; ++i)permut[i] = T(i);

	//copia de la matriz original
	Matrix<T,alloc> matrizTemporal;
	matrizTemporal=LU; //se opera en temporal y luego se copia a LU

	for(i=0; i<A.rows();++i){ //for 1
		major = abs(LU[i][i]);
		t = i;
		for(j=i;j<A.rows();++j){//for 2
			if(major<abs(LU[j][i])){//if 1
				major=abs(LU[j][i]);
				t = j;

			}//if 1
		}//for 2

		if(t!=i){//if 2
			k = permut[i];
			permut[i] = permut[t];
			permut[t] = k;
		}//if 2

		if(major == T(0)){//if 3
			throw anpi::Exception("Singular matrix");
		}//if 3

		if(size_t(permut[i])!=i){//if 4
			regType* LUrow1 = reinterpret_cast<regType*>(LU.data());
			regType* LUrow2 = reinterpret_cast<regType*>(LU.data());
			regType* MTrow1 = reinterpret_cast<regType*>(matrizTemporal.data());
			regType* MTrow2 = reinterpret_cast<regType*>(matrizTemporal.data());

			LUrow1+=t*stepTotal;
			MTrow1+=t*stepTotal;
			LUrow2+=i*stepTotal;
			MTrow2+=i*stepTotal;

			for(k=0; k<stepTotal; ++k){//for 3
				temporalData = *LUrow1;
				*LUrow1 = *LUrow2;
				*LUrow2 = temporalData;

				temporalData = *MTrow1;
				*MTrow1 = *MTrow2;
				*MTrow2 = temporalData;

				LUrow1++;
				LUrow2++;
				MTrow1++;
				MTrow2++;


			}//for 3
		}//if 4

		temporalRow = firstRow;
		for(j=i+1; j<A.rows();++j){//for 4

			T coeficiente = LU(j,i)/LU(i,i);
			matrizTemporal(j,i) = coeficiente;
			for(k=0; k<stepTotal; ++k){//for 5
				regType multiply = *firstRow * static_cast<regType>(coeficiente);
				*nextRow-=multiply;
				nextRow++;
				firstRow++;
			}//for 5
			firstRow = temporalRow;

		}//for 4
		firstRow+=stepTotal;
		nextRow=firstRow+stepTotal;

	}//for 1
	LU=matrizTemporal;

    }//cierra el luDoolittleSIMD
}//cierra SiMD
}//cierra anpi
  
#endif

