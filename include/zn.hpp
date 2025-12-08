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

class Zn : public Parcelle
{
protected:
	string typeCulture;

	void afficher(ostream &os) const override;

public:
	Zn(int num, string proprio, Polygone<int> forme);
	void setType(string type) override;
};
