/**
 * @file zau.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr)
 * @author Lucas Oros (lucas.oros@eleves.ec-nantes.fr)
 * @author Djamael Lahamion (djamael.lahamion@eleves.ec-nantes.fr)
 * @author Aloïs Guillon (alois.guillon@eleves.ec-nantes.fr)
 * 
 * @brief 
 * @version 0.1
 * @date 01-12-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef zau_hpp
#define zau_hpp

#pragma once

#include <iostream>
#include "constructible.hpp"
#include "parcelle.hpp"
using namespace std;

class Zau : public Constructible, public Parcelle{
	private:
		string type;
		
	public:
		Zau(int num, string proprio, Polygone<int> forme);
		float surfaceConstructible();
		void setType(string type);
		
};

#endif
