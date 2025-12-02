/**
 * @file carte.hpp
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
#include <vector>

#include "parcelle.hpp"
#include "za.hpp"
#include "zau.hpp"
#include "zn.hpp"
#include "zu.hpp"

using namespace std;

class carte
{
protected:
    vector<Parcelle *> listeParcelles;
    float surfaceTotale;

public:
    /**
     * @brief Construct a new carte object
     *
     * @param pathToFile
     */
    carte(string pathToFile);

    ~carte();

    /**
     * @brief Méthode permettant de sauvegarder la carte dans un fichier
     * 
     * @param pathToFile chemin du fichier de sauvegarde
     */
    void sauvegarder(string pathToFile);
};