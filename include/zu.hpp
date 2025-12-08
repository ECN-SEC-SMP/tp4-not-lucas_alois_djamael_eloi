/**
 * @file zu.hpp
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
using namespace std;

class Zu : public Constructible, public Parcelle
{
protected:

    /**
     * @brief Pourcentage constructible de la parcelle, une ZU a déjà un pourcentage constructible en m².
     *
     */
    float surfaceConstruite;

public:
    /**
     * @brief Construct a new Zu object
     *
     * @param num numéro de la parcelle
     * @param proprio propriétaire de la parcelle
     * @param forme forme de la parcelle
     * @param mypConstructible pourcentage constructible de la parcelle
     * @param mysurfaceConstruite surface déjà construite de la parcelle
     */
    Zu(int num, string proprio, Polygone<int> forme, float mypConstructible, float mysurfaceConstruite);

    /**
     * @brief Modifie le type de la parcelle en "ZU"
     *
     * @param type type de la parcelle
     */
    void setType(string type) override;

    /**
     * @brief Modifie la surface construite de la parcelle
     *
     * @param surfaceConstruite nouvelle surface construite
     */
    void setSurfaceConstruite(float surfaceConstruite);

    /**
     * @brief Obtient la surface construite de la parcelle
     *
     * @return float surface construite
     */
    float getSurfaceConstruite() const;

    /**
     * @brief Calcule la surface constructible restante
     *
     * @return float surface constructible restante
     */
    float surfaceConstructible() const override;

    /**
     * @brief Surcharge de l'opérateur <<
     *
     * @param os flux de sortie
     * @param zu zone urbaine à afficher
     * @return ostream& flux de sortie
     */
    friend ostream &operator<<(ostream &os, const Zu &zu);

    /**
     * @brief Obtient le pourcentage constructible de la parcelle
     *
     * @return float pourcentage constructible
     */
    float getPourcentageConstructible() const;

private:
    /**
     * @brief Affiche les informations de la parcelle, surcharge de la méthode pure virtuelle de la classe mère
     *
     * @param os flux de sortie
     */
    void afficher(ostream &os) const override;
};
