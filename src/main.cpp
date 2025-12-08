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

#include "point2d.hpp"
#include "polygone.hpp"
#include "parcelle.hpp"
#include "zau.hpp"
#include "zn.hpp"
#include "zu.hpp"
#include "za.hpp"
#include "carte.hpp"

using namespace std;

int main()
{
    cout << "------------" << endl;
    cout << "|  TP PLU  |" << endl;
    cout << "------------" << endl;

    srand(time(nullptr)); // Initialisation de la graine pour les nombres aléatoires

    cout << "--------------------------" << endl;
    cout << "Test de la classe Polygone" << endl;
    cout << "--------------------------" << endl;

    // création polygone
    vector<Point2D<double>> listeSommets = {Point2D<double>(0.0, 0.0), Point2D<double>(1.0, 0.0), Point2D<double>(1.0, 1.0)};
    Polygone<double> poly(listeSommets);

    // affichage des sommets avec getSommets
    cout << "Sommets du polygone initial : ";
    cout << poly << endl;

    // création par recopie
    Polygone<double> polyCopy(poly);
    cout << "Sommets du polygone copie : ";
    cout << polyCopy << endl;

    // translation du polygone polycopy avec translate
    double dx = 2.0;
    double dy = 3.0;
    polyCopy.translate(dx, dy);
    cout << "Sommets du polygone copie apres translation de (2.0, 3.0) : ";
    cout << polyCopy << endl;

    // tester si Si un polygone est translaté, les Polygones construits par recopie ne doivent pas être translatés.
    cout << "Verification que le polygone original na pas ete modifie : ";
    cout << poly << endl;

    // calcul de la surface avec surface
    cout << "\nCalcul de la surface du polygone 5 sommets (attendu: 0.75) :" << endl;
    vector<Point2D<double>> listeSommets_5 = {Point2D<double>(0.0, 0.0), Point2D<double>(1.0, 0.0), Point2D<double>(1.0, 1.0), Point2D<double>(0.0, 1.0), Point2D<double>(0.5, 1.5)};
    Polygone<double> poly5(listeSommets_5);
    cout << "Sommets du polygone  : ";
    cout << poly5 << endl;
    cout << "Surface du polygone : " << poly5.calculerSurface() << endl;

    cout << "--------------------" << endl;
    cout << "Test de la classe ZU" << endl;
    cout << "--------------------" << endl;

    // création polygone (4 sommets) pour la parcelle1 ZU
    vector<Point2D<int>> listeSommets_parcelle1 = {Point2D<int>(10, 10), Point2D<int>(14, 10), Point2D<int>(14, 13) , Point2D<int>(10, 13)};
    Polygone<int> poly_parcelle1(listeSommets_parcelle1);

    // création de la parcelle1 ZU
    Zu zu1_test(43, "Robert", poly_parcelle1, 60.0, 3.0);
    cout << zu1_test << endl;

    cout << "--------------------" << endl;
    cout << "Test de la classe ZAU" << endl;
    cout << "--------------------" << endl;
    
    // création polygone (3 sommets) pour la parcelle1 ZAU
    vector<Point2D<int>> listeSommets_parcelle2 = {Point2D<int>(0, 0), Point2D<int>(4, 0), Point2D<int>(4, 3)};
    Polygone<int> poly_parcelle2(listeSommets_parcelle2);

    // création de la parcelle1 ZAU
    Zau zau1_test(14, "Alice", poly_parcelle2, 40.0);
    cout << zau1_test << endl;

    cout << "--------------------" << endl;
    cout << "Test de la classe ZN" << endl;
    cout << "--------------------" << endl;

    // création polygone (3 sommets) pour la parcelle1 ZN - pas de superposition avec les précédentes
    vector<Point2D<int>> listeSommets_parcelle3 = {Point2D<int>(20, 20), Point2D<int>(29, 20), Point2D<int>(29, 33)};
    Polygone<int> poly_parcelle3(listeSommets_parcelle3);

    // création de la parcelle3 ZN
    Zn zn1_test(67, "Jean", poly_parcelle3);
    cout << zn1_test << endl;

    cout << "--------------------" << endl;
    cout << "Test de la classe ZA" << endl;
    cout << "--------------------" << endl;

    // création polygone (3 sommets) pour la parcelle1 ZA - pas de superposition avec les précédentes
    vector<Point2D<int>> listeSommets_parcelle4 = {Point2D<int>(40, 40), Point2D<int>(50, 40), Point2D<int>(50, 55)};
    Polygone<int> poly_parcelle4(listeSommets_parcelle4);

    // création de la parcelle4 ZA
    Za za1_test(92, "Marie", poly_parcelle4, "Céréales");
    cout << za1_test << endl; 

    //test méthode peutConstruireBatAgricole
    bool canBuild = false;
    cout << "Test de la methode peutConstruireBatAgricole pour la parcelle ZA :" << endl;
    za1_test.peutConstruireBatAgricole(1); //1 m2 construit


    
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "Test de la classe Carte" << endl;
    cout << "-----------------------" << endl;

    carte maCarte("assets/Parcelles_short.txt");

    cout << maCarte << endl;

    maCarte.sauvegarder("assets/Parcelles_short_sauvegarde.txt");

    // delete &maCarte;

    //carte maCarteFull("assets/Parcelles.txt");

    //maCarteFull.sauvegarder("assets/Parcelles_sauvegarde.txt");
    
    cout << "-----------------------" << endl;
    cout << "Test des exceptions" << endl;
    cout << "-----------------------" << endl;

    cout << "Test des exceptions - sens trigo" << endl;

    vector<Point2D<double>> listeSommets_test = {Point2D<double>(0.0, 0.0), Point2D<double>(1.0, 0.0), Point2D<double>(1.0, 1.0), Point2D<double>(0.0, 1.0)};
    Polygone<double> poly_test(listeSommets_test);
    cout << "PASS" << endl;

    vector<Point2D<double>> listeSommets_test2 = {Point2D<double>(0.0, 0.0), Point2D<double>(1.0, 1.0), Point2D<double>(0.0, 1.0), Point2D<double>(1.0, 0.0)};
    //Polygone<double> poly_test2(listeSommets_test2);
    cout << "ERROR" << endl; // Ne doit pas passer ici => test ok ici

    vector<Point2D<double>> listeSommets_test3 = {Point2D<double>(0.0, 0.0), Point2D<double>(1.0, 1.0)};
    //Polygone<double> poly_test3(listeSommets_test3);
    cout << "ERROR" << endl; // Ne doit pas passer ici => test ok ici



    return 0;
}