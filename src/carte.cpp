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
    string line = "";
    string type = "";
    string numero = "";
    string proprietaire = "";
    string pConstructible = "";
    string surfaceConstruite = "";
    string culture = "";

    while (getline(file, line))
    {
        // Réinitialiser les variables à chaque itération
        type = "";
        numero = "";
        proprietaire = "";
        pConstructible = "";
        surfaceConstruite = "";
        culture = "";
        
        // Récupérer le premier mot
        type = line.substr(0, line.find(' ')); // Entre le début de la ligne et le premier espace
        // printf("Type de parcelle : %s\n", type.c_str());
        line = line.substr(line.find(' ') + 1);
        // Récupérer le deuxième mot
        numero = line.substr(0, line.find(' ')); // Entre le début de la ligne et le premier espace
        // printf("Numéro de parcelle : %s\n", numero.c_str());
        // Récupérer le troisième mot
        line = line.substr(line.find(' ') + 1);
        proprietaire = line.substr(0, line.find(' ')); // Entre le début de la ligne et le premier espace
        // printf("Propriétaire de parcelle : %s\n", proprietaire.c_str());
        line = line.substr(line.find(' ') + 1);
        
        if (type == "ZU")
        {
            // récupérer pConstructible et surfaceConstruite
            pConstructible = line.substr(0, line.find(' '));
            // printf("Pourcentage constructible : %s\n", pConstructible.c_str());
            line = line.substr(line.find(' ') + 1);
             surfaceConstruite = line.substr(0, line.find(' '));
            // printf("Surface construite : %s\n", surfaceConstruite.c_str());
        }
        else if (type == "ZAU")
        {
            // récupérer pConstructible
            pConstructible = line.substr(0, line.find(' '));
            // printf("Pourcentage constructible : %s\n", pConstructible.c_str());
        }
        else if (type == "ZA")
        {
            // récupérer culture
            culture = line.substr(0, line.find(' '));
            // printf("Culture : %s\n", culture.c_str());
        }

        vector<Point2D<int>> mesSommets;

        // Récupérer les coordonnées sur la ligne du dessous
        getline(file, line);
        // printf("Coordonnées : %s\n", line.c_str());
        // isoler les x;y [0;30] [60;100] [0;100]
        while (line.find(' ') != string::npos)
        {
            string coord = line.substr(0, line.find(' '));
            line = line.substr(line.find(' ') + 1);

            // isoler les x et y
            Point2D<int> monPoint(  stoi(coord.substr(coord.find('[') + 1, coord.find(';') - coord.find('[') - 1)),
                                    stoi(coord.substr(coord.find(';') + 1, coord.find(']') - coord.find(';') - 1)));

            mesSommets.push_back(monPoint);
        }

        Polygone<int> maForme(mesSommets);

        if (type == "ZU")
        {
            Zu *newZu = new Zu(stoi(numero), proprietaire, maForme, stof(pConstructible), stof(surfaceConstruite));
            listeParcelles.push_back(newZu);
        }
        else if (type == "ZAU")
        {
            Zau *newZau = new Zau(stoi(numero), proprietaire, maForme, stof(pConstructible));
            listeParcelles.push_back(newZau);
        }
        else if (type == "ZA")
        {
            Za *newZa = new Za(stoi(numero), proprietaire, maForme, culture);
            listeParcelles.push_back(newZa);
        }
        else if (type == "ZN")
        {
            Zn *newZn = new Zn(stoi(numero), proprietaire, maForme);
            listeParcelles.push_back(newZn);
        }
    }

    // calculer la surface totale
    for (Parcelle *parcelle : listeParcelles)
    {
        this->surfaceTotale += parcelle->getSurface();
    }
    file.close();

    printf("Surface totale de la nouvelle carte : %.2f m² pour %lu parcelles\n", this->surfaceTotale, listeParcelles.size());
}

carte::~carte()
{
    for (Parcelle *parcelle : listeParcelles)
    {
        delete parcelle;
    }

    listeParcelles.clear();
}

void carte::sauvegarder(string pathToFile)
{
    ofstream file(pathToFile);
    if (!file.is_open())
    {
        cerr << "Erreur lors de l'ouverture du fichier en écriture : " << pathToFile << endl;
        return;
    }

    for (Parcelle *parcelle : listeParcelles)
    {
        file << parcelle->getType() << " " << parcelle->getNumero() << " " << parcelle->getProprietaire() << " ";

        if (parcelle->getType() == "ZU")
        {
            Zu *zu = dynamic_cast<Zu *>(parcelle);
            file << zu->getPourcentageConstructible() << " " << zu->getSurfaceConstruite() << " ";
        }
        else if (parcelle->getType() == "ZAU")
        {
            Zau *zau = dynamic_cast<Zau *>(parcelle);
            file << zau->getPourcentageConstructible() << " ";
        }
        else if (parcelle->getType() == "ZA")
        {
            Za *za = dynamic_cast<Za *>(parcelle);
            file << za->getTypeCulture() << " ";
        }

        // passer à la ligne
        file << "\n";

        // écrire les coordonnées
        vector<Point2D<int>> listeSommets = parcelle->getForme().getSommets();
        for (const Point2D<int> &point : listeSommets)
        {
            file << point << " ";
        }
        file << "\n";
    }

    file.close();
}