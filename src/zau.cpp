/**
 * @file zau.cpp
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
#include "zau.hpp"

Zau::Zau(int num, string proprio, Polygone<int> forme)
{
	Parcelle(num, proprio, forme);
	this->setType("ZAU");
}

void Zau::setType(string _type)
{
	_type = "ZAU";
	this->type = _type;
}

float Zau::surfaceConstructible()
{
	return this->pConstructible * this->getSurface();
}