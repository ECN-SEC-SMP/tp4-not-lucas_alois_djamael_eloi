/**
 * @file zau.hpp
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

/**
 * @brief Classe représentant une zone à urbaniser (ZAU)
 *
 */
class Zau : public Constructible, public Parcelle
{
public:
	/**
	 * @brief Construct a new Zau object
	 *
	 * @param num numéro de la parcelle
	 * @param proprio propriétaire de la parcelle
	 * @param forme forme de la parcelle
	 * @param mypConstructible pourcentage constructible de la parcelle
	 */
	Zau(int num, string proprio, Polygone<int> forme, float mypConstructible);

	/**
	 * @brief Modifie le type de la parcelle en "ZAU"
	 *
	 * @param type type de la parcelle
	 */
	void setType(string type) override;

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
	 * @param zau zone à urbaniser à afficher
	 * @return ostream& flux de sortie
	 */
	friend ostream &operator<<(ostream &os, const Zau &zau);

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
