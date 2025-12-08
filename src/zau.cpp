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

Zau::Zau(int num, string proprio, Polygone<int> forme, float mypConstructible) : Parcelle(num, proprio, forme)
{
	this->setNumero(num);
	this->setProprietaire(proprio);
	this->setForme(forme);
	this->setType("ZAU");
	this->surface = this->getForme().calculerSurface();
	
	this->pConstructible = mypConstructible;
}

void Zau::setType(string _type)
{
	_type = "ZAU";
	this->type = _type;
}

float Zau::surfaceConstructible() const
{
	return (this->pConstructible * this->getSurface()) / 100; // pConstructible est un attribut de la classe Parcelle
}

void Zau::afficher(ostream &os) const
{
	Parcelle::afficher(os);
	os << "    % constructible : " << this->pConstructible << " %\n";
}

ostream &operator<<(ostream &os, const Zau &zau)
{
	zau.afficher(os);
	return os;
}