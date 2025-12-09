/**
 * @file za.hpp
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

#include <iostream>
#include "constructible.hpp"
#include "parcelle.hpp"
#include "zn.hpp"
using namespace std;

/**
 * @brief Classe représentant une zone agricole (ZA)
 *
 */
class Za : public Zn
{
protected:
        string typeCulture;

public:
        /**
         * @brief Construct a new Za object
         *
         * @param num numéro de la parcelle
         * @param proprio propriétaire de la parcelle
         * @param forme forme de la parcelle
         * @param typeCulture type de culture de la ZA
         */
        Za(int num, string proprio, Polygone<int> forme, string typeCulture);

        /**
         * @brief Modifie le type de la parcelle en "ZA"
         *
         * @param type type de la parcelle
         */
        void setType(string type) override;

        /**
         * @brief Obtient le type de culture de la ZA
         *
         * @return string type de culture
         */
        string getTypeCulture() const;

        /**
         * @brief Modifie le type de culture de la ZA
         *
         * @param typeCulture nouveau type de culture
         */
        void setTypeCulture(string typeCulture);

        /**
         * @brief Méthode indiquant si la construction de bâtiments agricoles est autorisée
         *
         * @param surfaceConstruite surface déjà construite sur la parcelle
         */
        void peutConstruireBatAgricole(float surfaceConstruite);

        /**
         * @brief Surcharge de l'opérateur <<
         *
         * @param os flux de sortie
         * @param za zone agricole à afficher
         * @return ostream& flux de sortie
         */
        friend ostream &operator<<(ostream &os, const Za &za);

private:
        /**
         * @brief Affiche les informations de la parcelle, surcharge de la méthode pure virtuelle de la classe mère
         *
         * @param os flux de sortie
         */
        void afficher(ostream &os) const override;
};
