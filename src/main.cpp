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
    cout << "Sommets du polygone initial :" << endl;
    cout << poly << endl;

    //création par recopie
    Polygone<double> polyCopy(poly);
    cout << "Sommets du polygone copie :" << endl;
    cout << polyCopy << endl;

    //translation du polygone polycopy avec translate
    double dx = 2.0;
    double dy = 3.0;
    polyCopy.translate(dx, dy);
    cout << "Sommets du polygone copie apres translation de (2.0, 3.0) :" << endl;
    cout << polyCopy << endl;

    //tester si Si un polygone est translaté, les Polygones construits par recopie ne doivent pas être translatés.
    cout << "Verification que le polygone original na pas ete modifie :" << endl;
    cout << poly << endl;
    

    return 0;
}