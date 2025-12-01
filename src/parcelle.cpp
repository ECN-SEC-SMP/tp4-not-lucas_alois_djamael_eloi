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

#include "parcelle.hpp"

Parcelle::Parcelle(int num, string proprio, Polygone<int> forme)
{
    this->numero = num;
    this->proprietaire = proprio;
    this->forme = forme;

    this->surface = forme.calculerSurface();
}

Parcelle::Parcelle(Parcelle Parc)
{
    this->numero = Parc.numero;
    this->proprietaire = Parc.proprietaire;
    this->forme = Parc.forme;

    this->surface = Parc.surface;
}

int Parcelle::getNumero()
{
    return this->numero;
}

string Parcelle::getProprietaire()
{
    return this->proprietaire;
}

float Parcelle::getSurface()
{
    return this->surface;
}

Polygone<int> Parcelle::getForme()
{
    return this->forme;
}

string Parcelle::getType()
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

ostream &operator<<(ostream &os, const Parcelle &p)
{
    os << "Parcelle n°" << p.getNumero() << "\n";
    os << "    Type : " << p.getType() << "\n";
    os << "    Propriétaire : " << p.getProprietaire() << "\n";
    os << "    Polygone : " << this->forme << "\n";
    os << "    Surface : " << p.getSurface() << " m²\n";
    return os;
}