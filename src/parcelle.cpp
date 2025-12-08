/**
 * @file parcelle.cpp
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

#include <random>
#include "parcelle.hpp"

Parcelle::Parcelle(int num, string proprio, Polygone<int> forme)
{
    this->numero = num;
    this->proprietaire = proprio;
    this->forme = forme;

    this->surface = forme.calculerSurface();

    this->type = "N/A";
}

Parcelle::Parcelle(const Parcelle &Parc)
{
    this->numero = Parc.numero;
    this->proprietaire = Parc.proprietaire;
    this->forme = Parc.forme;

    this->surface = Parc.surface;
}

int Parcelle::getNumero() const
{
    return this->numero;
}

string Parcelle::getProprietaire() const
{
    return this->proprietaire;
}

float Parcelle::getSurface() const
{
    return this->surface;
}

Polygone<int> Parcelle::getForme() const
{
    return this->forme;
}

string Parcelle::getType() const
{
    return this->type;
}

void Parcelle::setNumero(int num)
{
    this->numero = num;
}

void Parcelle::setProprietaire(string proprio)
{
    this->proprietaire = proprio;
}

void Parcelle::setForme(Polygone<int> forme)
{
    this->forme = forme;
    this->surface = forme.calculerSurface();
}

void Parcelle::afficher(ostream &os) const
{
    os << "Parcelle n°" << this->getNumero() << " :\n";
    os << "    Type : " << this->getType() << "\n";
    os << "    Polygone : " << this->getForme() << "\n";
    os << "    Propriétaire : " << this->getProprietaire() << "\n";
    os << "    Surface : " << this->getSurface() << " m²\n";
}

ostream &operator<<(ostream &os, const Parcelle &p)
{
    p.afficher(os);
    return os;
}