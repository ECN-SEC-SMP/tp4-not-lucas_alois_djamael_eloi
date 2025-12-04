/**
 * @file zn.cpp
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

#include "zn.hpp"

Zn::Zn(int num, string proprio, Polygone<int> forme) : Parcelle(num, proprio, forme)
{
	this->setNumero(num);
	this->setProprietaire(proprio);
	this->setForme(forme);
	this->setType("ZN");
	this->surface = this->getForme().calculerSurface();
}

void Zn::setType(string _type)
{
	_type = "ZN";
	this->type = _type;
}