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

    Polygone(const vector<Point2D<T>> &ListeSommet) : sommets(ListeSommet) {
        verifierSensTrigonometrigue();
    }

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

    void verifierSensTrigonometrigue() const
    {
        size_t n = sommets.size();
        if (n < 3)
            throw std::invalid_argument("Un polygone doit au moins avoir 3 points.");

        // 1. Trouver le point en bas à gauche
        size_t idxO = 0;
        for (size_t i = 1; i < n; ++i)
        {
            if ( (sommets[i].getY() < sommets[idxO].getY()) ||
                (sommets[i].getY() == sommets[idxO].getY() && sommets[i].getX() < sommets[idxO].getX()) )
            {
                idxO = i;
            }
        }

        const Point2D<T> &O = sommets[idxO];

        // 2. Pour chaque couple (Pi, Pi+1)
        for (size_t k = 0; k < n; ++k)
        {
            const Point2D<T> &Pi   = sommets[k];
            const Point2D<T> &Pi1  = sommets[(k + 1) % n];

            if (&Pi == &O || &Pi1 == &O)
                continue; // on saute si l’un des deux est O

            // vecteurs OPi et OPi+1
            T vix = Pi.getX()  - O.getX();
            T viy = Pi.getY()  - O.getY();
            T vjx = Pi1.getX() - O.getX();
            T vjy = Pi1.getY() - O.getY();

            // produit scalaire
            T dot = vix * vjx + viy * vjy;

            if (dot <= 0)
                throw std::invalid_argument("Les points ne sont pas dans le sens trigonométrique (produit scalaire non positif).");
        }
    }

    // destructeur
    ~Polygone() = default;
};