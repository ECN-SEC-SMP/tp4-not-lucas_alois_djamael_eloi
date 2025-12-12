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
    Polygone(const std::vector<Point2D<T>> &ListeSommet) : sommets(ListeSommet)
    {
        try
        {
            verifierSensTrigonometrigue();
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error(std::string("Erreur dans verifierSensTrigonometrigue() : ") + e.what());
        }

        try
        {
            verifierPolygoneCroise();
        }
        catch (const std::exception &e)
        {
            throw std::runtime_error(std::string("Erreur dans verifierPolygoneCroise() : ") + e.what());
        }
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
     * @return int 1 si sens trigo, -1 si sens horaire, 0 si points alignés
     */
    int verifierSensTrigonometrigue() const;

    /**
     * @brief Vérifie que le polygone ne se croise pas lui-même
     *
     */
    void verifierPolygoneCroise() const;
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
int Polygone<T>::verifierSensTrigonometrigue() const
{
    try
    {
        size_t n = sommets.size();
        if (n < 3)
        {
            throw invalid_argument("Un polygone doit au moins avoir 3 points.");
        }

        // Calcul de la surface signée en utilisant la formule du shoelace
        T signedArea = 0;
        for (size_t i = 0; i < n; ++i)
        {
            const Point2D<T> &p1 = sommets[i];
            const Point2D<T> &p2 = sommets[(i + 1) % n];
            signedArea += p1.getX() * p2.getY() - p2.getX() * p1.getY();
        }

        // Positif = sens trigonométrique (counter-clockwise)
        // Négatif = sens horaire (clockwise)
        // Zéro = points alignés
        if (signedArea > 0)
        {
            return 1; // sens trigonométrique
        }
        else if (signedArea < 0)
        {
            throw invalid_argument("Les points ne sont pas dans le sens trigonométrique.");
        }
        else
        {
            throw invalid_argument("Les points sont alignés.");
        }
    }
    catch (const exception &e)
    {
        throw invalid_argument("Erreur lors de la vérification du sens trigonométrique : " + string(e.what()));
    }
}

template <typename T>
void Polygone<T>::verifierPolygoneCroise() const
{
    try
    {
        size_t n = sommets.size();
        if (n < 4)
        {
            return; // impossible de se croiser avec moins de 4 points
        }

        // Fonction lambda pour calculer le produit vectoriel (CCW)
        auto ccw = [](const Point2D<T> &A, const Point2D<T> &B, const Point2D<T> &C) -> T
        {
            return (B.getX() - A.getX()) * (C.getY() - A.getY()) - (B.getY() - A.getY()) * (C.getX() - A.getX());
        };

        // Vérifier tous les segments non-adjacents
        for (size_t i = 0; i < n; ++i)
        {
            size_t i_next = (i + 1) % n;

            // Commencer à j = i + 2 pour éviter les segments adjacents
            for (size_t j = i + 2; j < n; ++j)
            {
                // Ne pas vérifier le dernier et le premier segment s'ils sont adjacents
                if (i == 0 && j == n - 1)
                {
                    continue;
                }

                size_t j_next = (j + 1) % n;

                const Point2D<T> &A = sommets[i];
                const Point2D<T> &B = sommets[i_next];
                const Point2D<T> &C = sommets[j];
                const Point2D<T> &D = sommets[j_next];

                // Deux segments [AB] et [CD] se croisent si:
                // - ccw(A,C,D) et ccw(B,C,D) ont des signes opposés
                // - ET ccw(A,B,C) et ccw(A,B,D) ont des signes opposés
                T ccw1 = ccw(A, C, D);
                T ccw2 = ccw(B, C, D);
                T ccw3 = ccw(A, B, C);
                T ccw4 = ccw(A, B, D);

                if ((ccw1 * ccw2 < 0) && (ccw3 * ccw4 < 0))
                {
                    throw invalid_argument("Le polygone se croise lui-même.");
                }
            }
        }
    }
    catch (const exception &e)
    {
        throw invalid_argument("Erreur lors de la vérification des croisements : " + string(e.what()));
    }
}
