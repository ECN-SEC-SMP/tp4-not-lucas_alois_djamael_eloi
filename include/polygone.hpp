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
#include <stdexcept>
#include "Point2D.hpp"

using namespace std;

/**
 * @brief Classe représentant un polygone en 2D
 *
 * @tparam T Type des coordonnées des sommets (int, float, double, etc.)
 */
template <typename T>
class Polygone
{
protected:
    /**
     * @brief Liste des sommets du polygone
     *
     */
    vector<Point2D<T>> sommets;

public:
    /**
     * @brief Construct a new Polygone object
     *
     */
    Polygone() = default;

    /**
     * @brief Construct a new Polygone object
     *
     * @param ListeSommet Liste des sommets du polygone
     */
    Polygone(const vector<Point2D<T>> &ListeSommet) : sommets(ListeSommet)
    {
        verifierSensTrigonometrigue();
    }

    /**
     * @brief Construct a new Polygone object
     *
     * @param poly Polygone à copier
     */
    Polygone(const Polygone<T> &poly)
    {
        try
        {
            sommets = poly.sommets;
        }
        catch (const exception &e)
        {
            throw invalid_argument("Erreur lors de la copie du Polygone : " + string(e.what()));
        }
    }

    /**
     * @brief Get the Sommets object
     *
     * @return const vector<Point2D<T>>& Liste des sommets
     */
    const vector<Point2D<T>> &getSommets() const;

    /**
     * @brief Set the Sommets object
     *
     * @param listeSommets Nouvelle liste des sommets
     */
    void setSommets(const vector<Point2D<T>> &listeSommets);

    /**
     * @brief Ajoute un sommet au polygone
     *
     * @param p sommet à ajouter
     */
    void addPoint(const Point2D<T> &p);

    /**
     * @brief Translate le polygone
     *
     * @param dx translation en x
     * @param dy translation en y
     */
    void translate(const T &dx, const T &dy);

    /**
     * @brief Surcharge de l'opérateur <<
     *
     * @param os flux de sortie
     * @param poly polygone à afficher
     * @return ostream& flux de sortie
     */
    template <typename U>
    friend ostream &operator<<(ostream &os, const Polygone<U> &poly);

    /**
     * @brief Calcule la surface du polygone
     *
     * @return T surface du polygone
     */
    T calculerSurface() const;

    /**
     * @brief Destructeur
     *
     */
    ~Polygone();

    /**
     * @brief Vérifie que les points du polygone sont dans le sens trigonométrique
     *
     */
    void verifierSensTrigonometrigue() const;
};

template <typename T>
const vector<Point2D<T>> &Polygone<T>::getSommets() const
{
    try
    {
        return sommets;
    }
    catch (const exception &e)
    {
        throw runtime_error("Erreur lors de la récupération des sommets : " + string(e.what()));
    }
}

template <typename T>
void Polygone<T>::setSommets(const vector<Point2D<T>> &listeSommets)
{
    try
    {
        if (listeSommets.size() < 3)
        {
            throw invalid_argument("Un polygone doit avoir au moins 3 sommets.");
        }
        sommets = listeSommets;
        verifierSensTrigonometrigue();
    }
    catch (const exception &e)
    {
        throw invalid_argument("Erreur lors de la modification des sommets : " + string(e.what()));
    }
}

template <typename T>
void Polygone<T>::addPoint(const Point2D<T> &p)
{
    try
    {
        sommets.push_back(p);
        if (sommets.size() >= 3)
        {
            verifierSensTrigonometrigue();
        }
    }
    catch (const exception &e)
    {
        sommets.pop_back();
        throw invalid_argument("Erreur lors de l'ajout d'un point : " + string(e.what()));
    }
}

template <typename T>
void Polygone<T>::translate(const T &dx, const T &dy)
{
    try
    {
        for (auto &sommet : sommets)
        {
            sommet.translate(dx, dy);
        }
    }
    catch (const exception &e)
    {
        throw runtime_error("Erreur lors de la translation du polygone : " + string(e.what()));
    }
}

template <typename T>
ostream &operator<<(ostream &os, const Polygone<T> &poly)
{
    os << "Polygone avec " << poly.sommets.size() << " sommets : ";
    for (const auto &sommet : poly.sommets)
    {
        os << "[" << sommet.getX() << ";" << sommet.getY() << "] ";
    }
    return os;
}

template <typename T>
T Polygone<T>::calculerSurface() const
{
    try
    {
        if (sommets.size() < 3)
        {
            throw invalid_argument("Un polygone doit avoir au moins 3 sommets pour calculer sa surface.");
        }
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
        {
            throw invalid_argument("Surface négative ou nulle : ajout invalide.");
        }
        return s;
    }
    catch (const exception &e)
    {
        throw runtime_error("Erreur lors du calcul de la surface : " + string(e.what()));
    }
}

template <typename T>
Polygone<T>::~Polygone() = default;

template <typename T>
void Polygone<T>::verifierSensTrigonometrigue() const
{
    try
    {
        size_t n = sommets.size();
        if (n < 3)
        {
            throw invalid_argument("Un polygone doit au moins avoir 3 points.");
        }

        // 1. Trouver le point en bas à gauche
        size_t idxO = 0;
        for (size_t i = 1; i < n; ++i)
        {
            if ((sommets[i].getY() < sommets[idxO].getY()) ||
                (sommets[i].getY() == sommets[idxO].getY() && sommets[i].getX() < sommets[idxO].getX()))
            {
                idxO = i;
            }
        }

        const Point2D<T> &O = sommets[idxO];

        // 2. Pour chaque couple (Pi, Pi+1)
        for (size_t k = 0; k < n; ++k)
        {
            const Point2D<T> &Pi = sommets[k];
            const Point2D<T> &Pi1 = sommets[(k + 1) % n];

            if (&Pi == &O || &Pi1 == &O)
                continue; // on saute si l’un des deux est O

            // vecteurs OPi et OPi+1
            T vix = Pi.getX() - O.getX();
            T viy = Pi.getY() - O.getY();
            T vjx = Pi1.getX() - O.getX();
            T vjy = Pi1.getY() - O.getY();

            // produit scalaire
            T dot = vix * vjx + viy * vjy;

            if (dot <= 0)
            {
                throw invalid_argument("Les points ne sont pas dans le sens trigonométrique (produit scalaire non positif).");
            }
        }
    }
    catch (const exception &e)
    {
        throw invalid_argument("Erreur lors de la vérification du sens trigonométrique : " + string(e.what()));
    }
}