/**
 * @file point2d.hpp
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
#include <stdexcept>
#include <limits>
#include <typeinfo>
using namespace std;

/**
 * @brief Classe représentant un point en 2D
 *
 * @tparam T Type des coordonnées (int, float, double, etc.)
 */
template <typename T>
class Point2D
{
protected:
	T x;
	T y;

public:
	/**
	 * @brief Construct a new Point2D object
	 *
	 * @param x abscisse
	 * @param y ordonnée
	 */
	Point2D(T x, T y);

	/**
	 * @brief Construct a new Point2D object
	 *
	 */
	Point2D();

	/**
	 * @brief Construct a new Point2D object
	 *
	 * @param point2d point à copier
	 */
	Point2D(Point2D const &point2d);

	/**
	 * @brief Get the X object
	 *
	 * @return T abscisse
	 */
	T getX() const;

	/**
	 * @brief Get the Y object
	 *
	 * @return T ordonnée
	 */
	T getY() const;

	/**
	 * @brief Set the X object
	 *
	 * @param x abscisse
	 */
	void setX(T x);

	/**
	 * @brief Set the Y object
	 *
	 * @param y ordonnée
	 */
	void setY(T y);

	/**
	 * @brief Translate le point
	 *
	 * @param a translation en x
	 * @param b translation en y
	 */
	void translate(T a, T b);

	/**
	 * @brief Surcharge de l'opérateur <<
	 *
	 * @param os flux de sortie
	 * @param point point à afficher
	 * @return ostream& flux de sortie
	 */
	template <typename U>
	friend ostream &operator<<(ostream &os, const Point2D<U> &point);
};

template <typename T>
Point2D<T>::Point2D(T x, T y)
{
	try
	{
		this->x = x;
		this->y = y;
	}
	catch (const exception &e)
	{
		throw invalid_argument("Erreur lors de l'initialisation des coordonnées : " + string(e.what()));
	}
}

template <typename T>
Point2D<T>::Point2D()
{
	try
	{
		this->x = static_cast<T>(0);
		this->y = static_cast<T>(0);
	}
	catch (const exception &e)
	{
		throw runtime_error("Erreur lors de l'initialisation du Point2D par défaut : " + string(e.what()));
	}
}

template <typename T>
Point2D<T>::Point2D(Point2D const &point2d)
{
	try
	{
		this->x = point2d.x;
		this->y = point2d.y;
	}
	catch (const exception &e)
	{
		throw invalid_argument("Erreur lors de la copie du Point2D : " + string(e.what()));
	}
}
template <typename T>
T Point2D<T>::getX() const
{
	return this->x;
}

template <typename T>
T Point2D<T>::getY() const
{
	return this->y;
}

template <typename T>
void Point2D<T>::setX(T x)
{
	try
	{
		this->x = x;
	}
	catch (const exception &e)
	{
		throw invalid_argument("Erreur lors de la modification de l'abscisse : " + string(e.what()));
	}
}

template <typename T>
void Point2D<T>::setY(T y)
{
	try
	{
		this->y = y;
	}
	catch (const exception &e)
	{
		throw invalid_argument("Erreur lors de la modification de l'ordonnée : " + string(e.what()));
	}
}

template <typename T>
void Point2D<T>::translate(T a, T b)
{
	try
	{
		this->x += a;
		this->y += b;
	}
	catch (const exception &e)
	{
		throw runtime_error("Erreur lors de la translation du point : " + string(e.what()));
	}
}

template <typename T>
ostream &operator<<(ostream &os, const Point2D<T> &point)
{
	os << "[" << point.x << ";" << point.y << "]";
	return os;
}