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

#ifndef point2d_hpp
#define point2d_hpp

#pragma once

#include <iostream>
using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream &, Point2D<T> const&);

template <typename T>
class Point2D {
	protected:
		T x;
		T y;
	public:
		Point2D(T x, T y);
		Point2D(Point2D const & point2d);
		Point2D();
		T getx();
		T gety();
		void setx(T x);
		void sety(T y);
		void translater(T a, T b);
};

template <typename T>
Point2D<T>::Point2D(T x, T y){
	this->x = x;
	this->y = y;
}

template <typename T>
Point2D<T>::Point2D(Point2D const & point2d){
	this->x = x->point2d;
	this->y = y->point2d;
}

template <typename T>
Point2D<T>::Point2D(){
	this->x = static_cast<T>(0);
	this->y = static_cast<T>(0);
}

template <typename T>
T Point2D<T>::getx(){
	return this->x;
}

template <typename T>
T Point2D<T>::gety(){
	return this->y;
}

template <typename T>
void Point2D<T>::setx(T x){
	this->x = x;
}

template <typename T>
void Point2D<T>::sety(T y){
	this->y = y;
}

template <typename T>
void Point2D<T>::translater(T a, T b){
	this->x += a;
	this->y += b;
	
friend std::ostream& operator<< <T>(std::ostream &, Point2D const&);

}

#endif

