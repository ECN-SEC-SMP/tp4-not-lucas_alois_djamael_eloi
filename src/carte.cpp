/**
 * @file carte.cpp
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

#include <fstream>
#include <iostream>

#include "carte.hpp"
#include "point2d.hpp"
#include "polygone.hpp"

using namespace std;

carte::carte(string pathToFile)
{
    // ouvrir le fichier
    ifstream file(pathToFile);
    if (!file.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier : " << pathToFile << endl;
        return;
    }
    // lire les données
    string line;
    while (getline(file, line))
    {
        // Récupérer le premier mot
        string type = line.substr(0, line.find(' ')); // Entre le début de la ligne et le premier espace
        printf("Type de parcelle : %s\n", type.c_str());
        // Récupérer le deuxième mot
        string numero = line.substr(line.find(' '), line.find(' ', line.find(' ') + 1) - line.find(' ')); // Entre le premier et le deuxième espace
        printf("Numéro de parcelle : %s\n", numero.c_str());
        // Récupérer le troisième mot
        string proprietaire = line.substr(line.find(' ', line.find(' ') + 1), line.find(' ', line.find(' ', line.find(' ') + 1) + 1) - line.find(' ', line.find(' ') + 1)); // Entre le deuxième et le troisième espace
        printf("Propriétaire de parcelle : %s\n", proprietaire.c_str());
        // TODO reste de la ligne

        vector<Point2D<int>> mesSommets;

        // Récupérer les coordonnées sur la ligne du dessous
        getline(file, line);
        printf("Coordonnées : %s\n", line.c_str());
        // isoler les x;y [0;30] [60;100] [0;100]
        while (line.find(' ') != string::npos)
        {
            string coord = line.substr(0, line.find(' '));
            line = line.substr(line.find(' ') + 1);

            // isoler les x et y
            mesSommets.push_back(Point2D<int>(
                stoi(coord.substr(coord.find('[') + 1, coord.find(';') - coord.find('[') - 1)),
                stoi(coord.substr(coord.find(';') + 1, coord.find(']') - coord.find(';') - 1))
            ));
        }

        Polygone<int> maForme(mesSommets);
    }

    file.close();
}

carte::~carte()
{
    for (Parcelle *parcelle : listeParcelles)
    {
        delete parcelle;
    }
}

void carte::sauvegarder(string pathToFile)
{
    // TODO
}