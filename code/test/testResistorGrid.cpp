/**
 * Copyright (C) 2017 
 * Área Académica de Ingeniería en Computadoras, TEC, Costa Rica
 *
 * This file is part of the CE3102 Numerical Analysis lecture at TEC
 *
 * @Author: Pablo Bustamante
 * @Date  : 07.10.2018
 */

#include <boost/test/unit_test.hpp>
#include "ResistorGrid.hpp"
#include <iostream>
#include <exception>

namespace anpi {

	namespace test {

		void resistorGridTest(){
			std::vector<IndexPair> vector;
			anpi::nodesToIndex(1,0,2,0,vector);
			anpi::nodesToIndex(0,0,0,1,vector);
			anpi::nodesToIndex(0,1,0,2,vector);
			std::size_t indice4 = anpi::nodesToIndex(0,1,1,1,vector);

			//Revisa que el número de índices sea el correcto.		
			BOOST_CHECK(indice4 == 3);

			//Revisa si algunos valores de las resistencias están correctas.
			BOOST_CHECK(indexToNodes(0,vector).row1 == 1);
			BOOST_CHECK(indexToNodes(1,vector).col1 == 0);
			BOOST_CHECK(indexToNodes(2,vector).row2 == 0);
			BOOST_CHECK(indexToNodes(3,vector).col2 == 1);
	
		}
       
    	}
}

BOOST_AUTO_TEST_SUITE( ResistorGrid )

    BOOST_AUTO_TEST_CASE(ResistorGrid)
    {
        anpi::test::resistorGridTest();
    }

  
BOOST_AUTO_TEST_SUITE_END()



