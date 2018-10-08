/**
 * Copyright (C) 2018
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: Pablo Bustamante Mora
 * @Date  : 07.10.2018
 */


#include <iostream>
#include "Exception.hpp"
#include <stdlib.h>
#include <vector>
#include <iostream>

namespace anpi{

struct IndexPair{

	std::size_t row1;
	std::size_t col1;
	std::size_t row2;
	std::size_t col2;

};
	std::size_t nodesToIndex(const std::size_t inputRow1, const std::size_t inputCol1,
				const std::size_t inputRow2,
				const std::size_t inputCol2, std::vector<IndexPair>& vector){

		if(inputRow1 != inputRow2){
			if(inputCol1 != inputCol2)
				throw anpi::Exception("Nodos no adyacentes");
			else{
				IndexPair resistencia1;
				resistencia1.col1 = inputCol1;
				resistencia1.row1 = inputRow1;
				resistencia1.col2 = inputCol2;
				resistencia1.row2 = inputRow2;
				vector.push_back(resistencia1);
			}
		}
		else{
			IndexPair resistencia1;
			resistencia1.col1 = inputCol1;
			resistencia1.row1 = inputRow1;
			resistencia1.col2 = inputCol2;
			resistencia1.row2 = inputRow2;
			vector.push_back(resistencia1);
		}
		std::size_t resistorIndex = vector.size() -1;

		return resistorIndex;

	}

	IndexPair indexToNodes(const std::size_t idx,
			const std::vector<IndexPair>& vector){
		IndexPair resistor;
		resistor = vector[idx];
		return resistor;
	}

}
