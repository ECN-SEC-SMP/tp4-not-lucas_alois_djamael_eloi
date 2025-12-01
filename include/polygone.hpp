/**
 * @file polygone.hpp
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

#include <vector>
#include "point2d.hpp"

using namespace std;
template <typename T>

class polygone {
protected:
    vector<point2d<T>> sommets;
public:
    polygone() = default;

    polygone(const vector<point2d<T>>& ListeSommet) : sommets(ListeSommet) {}

    polygone(const polygone<T>& poly) : sommets(poly.sommets) {}

    const vector<point2d<T>>& getSommets() const {
        return sommets;
    }

    void setSommets(const vector<point2d<T>>& listeSommets) {
        sommets = listeSommets;
    }

    void addPoint(const point2d<T>& p) {
        sommets.push_back(p);
    }

    void translate(const T& dx, const T& dy) {
        for (auto& sommet : sommets) {
            sommet.translate(dx, dy);
        }
    }
};