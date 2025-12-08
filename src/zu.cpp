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

Zu::Zu(int num, string proprio, Polygone<int> forme, float mypConstructible, float mysurfaceConstruite) : Parcelle(num, proprio, forme)
{
	this->setNumero(num);
	this->setProprietaire(proprio);
	this->setForme(forme);
	this->setType("ZU");
	this->surface = this->getForme().calculerSurface();
	
	this->pConstructible = mypConstructible;
	this->surfaceConstruite = mysurfaceConstruite;
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

float Zu::getSurfaceConstruite() const
{
	return this->surfaceConstruite;
}

float Zu::surfaceConstructible() const
{
	return (this->pConstructible * this->getSurface()) / 100;
}

void Zu::afficher(ostream &os) const
{
	Parcelle::afficher(os);
	os << "    % constructible : " << this->pConstructible << " %\n";
	os << "    Surface construite : " << this->getSurfaceConstruite() << " m²\n";
	os << "    Surface à construire restante : " << this->surfaceConstructible() - this->getSurfaceConstruite() << " m²\n";
}

ostream &operator<<(ostream &os, const Zu &zu)
{
	zu.afficher(os);
	return os;
}