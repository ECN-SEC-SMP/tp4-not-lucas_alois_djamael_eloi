/**
 * @file za.cpp
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

#include "za.hpp"

Za::Za(int num, string proprio, Polygone<int> forme, string typeCulture) : Zn(num, proprio, forme)
{
    this->setType("ZA");
    this->typeCulture = typeCulture;
}

void Za::setType(string _type)
{
    _type = "ZA";
    this->type = _type;
}

string Za::getTypeCulture() const
{
    return this->typeCulture;
}

void Za::setTypeCulture(string typeCulture)
{
    this->typeCulture = typeCulture;
}

void Za::peutConstruireBatAgricole()
{
    cout << "Construction de batiment agricole autorisée sur cette parcelle." << endl;
    //+logique
}