/*
 * Copyright (C) 2017
 * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
 *
 * This file is part of the numerical analysis lecture CE3102 at TEC
 *
 * @Author: Juan Pablo Brenes Coto
 * @Date:   7.10.2018
 */

#include <opencv2/core.hpp>    // For cv::Mat
#include <opencv2/highgui.hpp> // For cv::imread/imshow
#include <string>
#include <cstdlib>

#include "ResistorGrid.hpp"
#include "Exception.hpp"


namespace anpi {

  ResistorGrid::ResistorGrid() {
  }


  /**
   * Loads the map image and converts it into an anpi Matrix
   *
   * @param[in] filename Name of the map image
   */
   /*
  void ResistorGrid::loadMap(std::string filename) {
    std::string mapPath = std::string( ANPI_DATA_PATH) + "/" + filename;

    cv::Mat_<float> map;

    cv::imread(mapPath.c_str(), CV_LOAD_IMAGE_GRAYSCALE).convertTo(map, CV_32FC1);

    if (!map.data) throw anpi::Exception("Error loading the image");
    map /= 255.0f;

    anpi::Matrix<float, std::allocator<float> > amapTmp(map.rows, map.cols, map.ptr<float>());
    // And transform it to a SIMD-enabled matrix
    anpi::Matrix<float> tmp(amapTmp);
    this->rawMap_ = tmp;
  }*/


  /**
   * Maps two nodes of the resistor grid to the corresponding resistor index
   *
   * @return index of the resistor between the two nodes
   */
  std::size_t ResistorGrid::nodesToIndex(const std::size_t row1,
      const std::size_t col1, const std::size_t row2, const std::size_t col2, std::vector<IndexPair>& vector) {
      

		if(row1 != row2){
			if(col1 != col2)
				throw anpi::Exception("Nodos no adyacentes");
			else{
				IndexPair resistencia;
				resistencia.col1 = col1;
				resistencia.row1 = row1;
				resistencia.col2 = col2;
				resistencia.row2 = row2;
				vector.push_back(resistencia);
			}
		}
		else{
			IndexPair resistencia;
			resistencia.col1 = col1;
			resistencia.row1 = row1;
			resistencia.col2 = col2;
			resistencia.row2 = row2;
			vector.push_back(resistencia);
		}
		std::size_t resistorIndex = vector.size() -1;
		return resistorIndex;
	} // nodesToIndex


  /**
   * Maps the index of a resistor to the indexes of the two nodes where it's
   * connected in the grid
   *
   * @param[in] idx Index of the resistor
   *
   * @return Indexpair struct with the indexes grid nodes
   */
  IndexPair ResistorGrid::indexToNodes(const std::size_t idx, const std::vector<IndexPair>& vector) {
		
		IndexPair resistor;
		resistor = vector[idx];
		return resistor;		
  } // indexToNodes



  /**
   * Construct the grid from the given file
   *
   * @return true if successful or false otherwise
   */
  bool ResistorGrid::build(const std::string filename) {
    throw anpi::Exception("To be implemented");
  }

  /**
   * Compute the internal data to navigate between the given nodes
   */
  bool ResistorGrid::navigate(const IndexPair& nodes) {
    throw anpi::Exception("To be implemented");
  }



}



