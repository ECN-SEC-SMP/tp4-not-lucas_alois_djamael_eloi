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
using namespace std;

template <typename T>
class Point2D
{
protected:
	T x;
	T y;

public:
	Point2D(T x, T y)
	{
		this->x = x;
		this->y = y;
	}

	Point2D()
	{
		this->x = static_cast<T>(0);
		this->y = static_cast<T>(0);
	}

	Point2D(Point2D const &point2d)
	{
		this->x = point2d.x;
		this->y = point2d.y;
	}

	T getX() const
	{
		return this->x;
	}

	T getY() const
	{
		return this->y;
	}

	void setX(T x)
	{
		this->x = x;
	}

	void setY(T y)
	{
		this->y = y;
	}

	void translate(T a, T b)
	{
		this->x += a;
		this->y += b;
	}

	// Surcharge de l'opérateur <<
	friend ostream &operator<<(ostream &os, const Point2D<T> &point)
	{
		os << "(" << point.x << ", " << point.y << ")";
		return os;
	}
};
