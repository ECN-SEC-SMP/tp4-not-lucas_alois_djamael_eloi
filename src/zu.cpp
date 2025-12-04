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

Zu::Zu(int num, string proprio, Polygone<int> forme) : Parcelle(num, proprio, forme)
{
	this->setNumero(num);
	this->setProprietaire(proprio);
	this->setForme(forme);
	this->setType("ZU");
	this->surface = this->getForme().calculerSurface();
	// surface construite aléatoire entre 20 et 80% de la surface totale
	float pourcentage = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 0.6)) + 0.2;
	this->surfaceConstruite = pourcentage * surfaceConstructible();
	// pConstructible est aléatoirement défini dans le constructeur de la classe Parcelle
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

ostream &operator<<(ostream &os, const Zu &zu)
{
	os << static_cast<const Parcelle &>(zu);
	os << "    % constructible : " << zu.pConstructible << " %\n";
	os << "    Surface construite : " << zu.getSurfaceConstruite() << " m2\n";
	os << "    Surface a construire restante : " << zu.surfaceConstructible() - zu.getSurfaceConstruite() << " m2\n";
	return os;
}