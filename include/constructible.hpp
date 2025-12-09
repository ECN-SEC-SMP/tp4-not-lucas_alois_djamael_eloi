/**
 * @file constructible.hpp
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

/**
 * @brief Classe abstraite représentant un objet constructible
 *
 */
class Constructible
{
public:
    /**
     * @brief Calcule la surface constructible restante, méthode virtuelle pure
     *
     * @return float surface constructible restante
     */
    virtual float surfaceConstructible() const = 0;
};
