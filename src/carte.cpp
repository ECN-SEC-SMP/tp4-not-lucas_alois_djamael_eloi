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
#include <stdexcept>

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
        throw runtime_error("Erreur lors de l'ouverture du fichier : " + pathToFile);
    }
    
    try {
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
            else
            {
                throw invalid_argument("Type de parcelle invalide : " + type);
            }
        }

        // calculer la surface totale
        for (Parcelle *parcelle : listeParcelles)
        {
            this->surfaceTotale += parcelle->getSurface();
        }
        file.close();
    } catch (const exception &e) {
        file.close();
        // Libérer la mémoire allouée avant de relancer l'exception
        for (Parcelle *parcelle : listeParcelles) {
            delete parcelle;
        }
        listeParcelles.clear();
        throw runtime_error("Erreur lors du chargement de la carte : " + string(e.what()));
    }
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
        throw runtime_error("Erreur lors de l'ouverture du fichier en écriture : " + pathToFile);
    }

    try {
        for (Parcelle *parcelle : listeParcelles)
        {
            if (parcelle == nullptr) {
                throw logic_error("Pointeur de parcelle null détecté lors de la sauvegarde");
            }

            file << parcelle->getType() << " " << parcelle->getNumero() << " " << parcelle->getProprietaire() << " ";

            if (parcelle->getType() == "ZU")
            {
                Zu *zu = dynamic_cast<Zu *>(parcelle);
                if (zu == nullptr) {
                    throw logic_error("Erreur de cast pour la parcelle ZU numéro " + to_string(parcelle->getNumero()));
                }
                file << zu->getPourcentageConstructible() << " " << zu->getSurfaceConstruite() << " ";
            }
            else if (parcelle->getType() == "ZAU")
            {
                Zau *zau = dynamic_cast<Zau *>(parcelle);
                if (zau == nullptr) {
                    throw logic_error("Erreur de cast pour la parcelle ZAU numéro " + to_string(parcelle->getNumero()));
                }
                file << zau->getPourcentageConstructible() << " ";
            }
            else if (parcelle->getType() == "ZA")
            {
                Za *za = dynamic_cast<Za *>(parcelle);
                if (za == nullptr) {
                    throw logic_error("Erreur de cast pour la parcelle ZA numéro " + to_string(parcelle->getNumero()));
                }
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

            // Vérifier si l'écriture s'est bien déroulée
            if (!file.good()) {
                throw ios_base::failure("Erreur lors de l'écriture dans le fichier");
            }
        }
        file.close();
    } catch (const ios_base::failure &e) {
        file.close();
        throw runtime_error("Erreur d'I/O lors de la sauvegarde : " + string(e.what()));
    } catch (const exception &e) {
        file.close();
        throw;
    }
}

// Surcharge de l'opérateur <<
ostream &operator<<(ostream &os, const carte &c)
{
    os << "\nCarte avec " << c.listeParcelles.size() << " parcelles et une surface totale de " << c.surfaceTotale << " m²\n";

    for (const Parcelle *parcelle : c.listeParcelles)
    {
        // utiliser la surcharge de l'opérateur << des classes dérivées de Parcelle (Zn, Za, Zu, Zau)
        os << *parcelle << endl;
    }
    return os;
}