/**
 * @file zu.cpp
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
#include "zu.hpp"
    
Zu::Zu(int num, string proprio, Polygone<int> forme)
{
	Parcelle(num, proprio, forme);
	this->setType("ZU");
}

void Zu::setType(string _type)
{
	_type = "ZU";
	this->type = _type;
}

void Zu::setSurfaceConstruite(float surfaceConstruite)
{
    this->surfaceConstruite = surfaceConstruite;
}

float Zu::getSurfaceConstruite()
{
    return this->surfaceConstruite;
}

float Zu::surfaceConstructible()
{
	return this->pConstructible * this->getSurface();
}
	
