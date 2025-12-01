/**
 * @file parcelle.hpp
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

#pragma once

#include <string>

#include "polygone.hpp"

using namespace std;

/**
 * @brief Classe abstraite représentant une parcelle de terrain
 *
 */
class Parcelle
{
private:
    string type;

    int numero;

    string proprietaire;

    float surface;

    Polygone<int> forme;

    int pConstructible;

public:
    Parcelle(int num, string proprio, Polygone<int> forme);

    Parcelle(Parcelle Parc);

    virtual ~Parcelle() = default;

    int getNumero();

    string getProprietaire();

    float getSurface();

    Polygone<int> getForme();

    string getType();

    void setNumero(int num);

    void setProprietaire(string proprio);

    void setForme(Polygone<int> forme);

    void setType(string type);
};