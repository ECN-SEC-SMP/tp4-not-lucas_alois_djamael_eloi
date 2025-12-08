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

void Za::peutConstruireBatAgricole(float surfaceConstruite)
{
    cout << "Construction de batiment agricole autorisée sur cette parcelle." << endl;
    //Sur une ZA, un agriculteur peut construire des bâtiments agricoles à condition que la
    //surface construite ne dépasse pas 10% de la surface de la ZA et 200m2 au maximum
    if(surfaceConstruite * 100 / this->getSurface() > 10) 
    {
        cout << "Surface construite dépasse 10% de ka surface de la ZA. Construction non autorisée." << endl;
    }
    else if(surfaceConstruite > 200)
    {
        cout << "Surface construite dépasse 200m2. Construction non autorisée." << endl;
    }
    else
    {
        cout << "Construction autorisée." << endl;
    }    
    
}

void Za::afficher(ostream &os) const
{
    Zn::afficher(os);
    os << "    Type de culture : " << this->typeCulture << "\n";
}

ostream &operator<<(ostream &os, const Za &za)
{
    za.afficher(os);
    return os;
}