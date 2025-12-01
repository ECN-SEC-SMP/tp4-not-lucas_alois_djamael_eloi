/**
 * @file main.cpp
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

#include <iostream>
#include <vector>
#include "Point2D.hpp"
#include "polygone.hpp"

using namespace std;


int main() {
    cout << "-----------------------------------" << endl;
    cout << "TP PLU - Test de la classe Polygone" << endl;
    cout << "-----------------------------------" << endl;

    //création polygone
    vector<Point2D<double>> listeSommets = {Point2D<double>(0.0, 0.0), Point2D<double>(1.0, 0.0), Point2D<double>(1.0, 1.0)};
    Polygone<double> poly(listeSommets);

    //affichage des sommets avec getSommets
    cout << "Sommets du polygone initial : ";
    cout << poly << endl;

    //création par recopie
    Polygone<double> polyCopy(poly);
    cout << "Sommets du polygone copie : ";
    cout << polyCopy << endl;

    //translation du polygone polycopy avec translate
    double dx = 2.0;
    double dy = 3.0;
    polyCopy.translate(dx, dy);
    cout << "Sommets du polygone copie apres translation de (2.0, 3.0) : ";
    cout << polyCopy << endl;

    //tester si Si un polygone est translaté, les Polygones construits par recopie ne doivent pas être translatés.
    cout << "Verification que le polygone original na pas ete modifie : ";
    cout << poly << endl;

    //calcul de la surface avec surface 
    cout << "\nCalcul de la surface du polygone 5 sommets (attendu: 0.75) :" << endl;
    vector<Point2D<double>> listeSommets_5 = {Point2D<double>(0.0, 0.0), Point2D<double>(1.0, 0.0), Point2D<double>(1.0, 1.0), Point2D<double>(0.0, 1.0), Point2D<double>(0.5, 1.5)};
    Polygone<double> poly5(listeSommets_5);
    cout << "Sommets du polygone  : ";
    cout << poly5 << endl;
    cout << "Surface du polygone : " << poly5.CalculerSurface() << endl;

    return 0;
}