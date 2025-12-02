/**
 * @file za.hpp
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
#ifndef za_hpp
#define za_hpp

#pragma once

#include <iostream>
#include "constructible.hpp"
#include "parcelle.hpp"
#include "zn.hpp"
using namespace std;

class Za : public Zn{
protected:
        string typeCulture;
        
public:
        Za(int num, string proprio, Polygone<int> forme, string typeCulture);
        void setType(string type) override;
        string getTypeCulture() const;
        void setTypeCulture(string typeCulture);
        void peutConstruireBatAgricole();
};

#endif