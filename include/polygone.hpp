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
#include "Point2D.hpp"

using namespace std;

template <typename T>
class Polygone
{
protected:
    vector<Point2D<T>> sommets;

public:
    Polygone() = default;

    Polygone(const vector<Point2D<T>> &ListeSommet) : sommets(ListeSommet) {}

    Polygone(const Polygone<T> &poly) : sommets(poly.sommets) {}

    const vector<Point2D<T>> &getSommets() const
    {
        return sommets;
    }

    void setSommets(const vector<Point2D<T>> &listeSommets)
    {
        sommets = listeSommets;
    }

    void addPoint(const Point2D<T> &p)
    {
        sommets.push_back(p);
    }

    void translate(const T &dx, const T &dy)
    {
        for (auto &sommet : sommets)
        {
            sommet.translate(dx, dy);
        }
    }

    friend ostream &operator<<(ostream &os, const Polygone<T> &poly)
    {
        for (const auto &sommet : poly.sommets)
        {
            os << "[" << sommet.getX() << ";" << sommet.getY() << "] ";
        }
        return os;
    }

    T calculerSurface() const
    {
        T surface_buff = 0;
        size_t n = sommets.size();
        for (size_t i = 0; i < n; ++i)
        {
            const Point2D<T> &p1 = sommets[i];
            const Point2D<T> &p2 = sommets[(i + 1) % n];
            surface_buff += p1.getX() * p2.getY() - p2.getX() * p1.getY();
        }
        T s = abs(surface_buff) / static_cast<T>(2);
        if (s <= 0)
            throw invalid_argument("ajout invalide : surface négative ou nulle");
        return s;
    }

    // destructeur
    ~Polygone() = default;
};