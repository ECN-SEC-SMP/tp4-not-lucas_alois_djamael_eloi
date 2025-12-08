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
protected:
    string type;
    int numero;
    string proprietaire;
    float surface;
    Polygone<int> forme;
    int pConstructible;

    /**
     * @brief Affiche les informations de la parcelle
     *
     * @param os flux de sortie
     */
    virtual void afficher(ostream &os) const = 0;

public:
    /**
     * @brief Construct a new Parcelle:: Parcelle object
     *
     * @param num Numéro de la parcelle
     * @param proprio Propriétaire de la parcelle
     * @param forme Forme de la parcelle
     */
    Parcelle(int num, string proprio, Polygone<int> forme);

    /**
     * @brief Construct a new Parcelle:: Parcelle object
     *
     * @param Parc Parcelle à copier
     */
    Parcelle(const Parcelle &Parc);

    /**
     * @brief Destroy the Parcelle object
     *
     */
    virtual ~Parcelle() = default;

    /**
     * @brief Get the Numero object
     *
     * @return int numéro de la parcelle
     */
    int getNumero() const;

    /**
     * @brief Get the Proprietaire object
     *
     * @return string propriétaire de la parcelle
     */
    string getProprietaire() const;

    /**
     * @brief Get the Surface object
     *
     * @return float surface de la parcelle
     */
    float getSurface() const;

    /**
     * @brief Get the Forme object
     *
     * @return Polygone<int> forme de la parcelle
     */
    Polygone<int> getForme() const;

    /**
     * @brief Get the Type object
     *
     * @return string type de la parcelle
     */
    string getType() const;

    /**
     * @brief Set the Numero object
     *
     * @param num numéro de la parcelle
     */
    void setNumero(int num);

    /**
     * @brief Set the Proprietaire object
     *
     * @param proprio propriétaire de la parcelle
     */
    void setProprietaire(string proprio);

    /**
     * @brief Set the Forme object
     *
     * @param forme forme de la parcelle
     */
    void setForme(Polygone<int> forme);

    /**
     * @brief Set the Type object
     *
     * @param type type de la parcelle
     */
    virtual void setType(string type) = 0; // Virtuel pure

    /**
     * @brief Affichage d'une parcelle
     *
     * @param os flux de sortie
     * @param p parcelle à afficher
     * @return ostream&
     */
    friend ostream &operator<<(ostream &os, const Parcelle &p);
};