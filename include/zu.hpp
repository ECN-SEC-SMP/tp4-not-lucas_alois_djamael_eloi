/**
 * @file zu.hpp
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

#ifndef zu_hpp
#define zu_hpp

#pragma once

#include <iostream>
#include "constructible.hpp"
#include "parcelle.hpp"
using namespace std;

class Zu : public Constructible, public Parcelle{
	private:
		string type;
        float surfaceConstruite; //une ZU a déjà une surface (en m2) construite.
		
	public:
		Zu(int num, string proprio, Polygone<int> forme);
        void setType(string type);
        void setSurfaceConstruite(float surfaceConstruite);
        float getSurfaceConstruite();
		float surfaceConstructible(); //donne la surface constructible restante
};

#endif