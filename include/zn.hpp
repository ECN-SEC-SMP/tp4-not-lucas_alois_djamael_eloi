/**
 * @file zn.hpp
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
 * @brief Classe représentant une zone non constructible (ZN)
 *
 */
class Zn : public Parcelle
{
protected:
	string typeCulture;

	/**
	 * @brief Affiche les informations de la parcelle, surcharge de la méthode pure virtuelle de la classe mère
	 *
	 * @param os flux de sortie
	 */
	void afficher(ostream &os) const override;

public:
	/**
	 * @brief Construct a new Zn object
	 *
	 * @param num numéro de la parcelle
	 * @param proprio propriétaire de la parcelle
	 * @param forme forme de la parcelle
	 */
	Zn(int num, string proprio, Polygone<int> forme);

	/**
	 * @brief Modifie le type de la parcelle en "ZN"
	 *
	 * @param type type de la parcelle
	 */
	void setType(string type) override;
};
