//
//  Carburante.hpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 30/07/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#ifndef Carburante_hpp
#define Carburante_hpp

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class carburante{
protected:
    int posizioneCarburante[2];
    int tipo;
     bool esiste=false;
public:
    int getPosizioneCarburante1();
    int getPosizioneCarburante2();
    bool getEsiste();
    void setEsiste(bool c);
    void setPosizione();
    int getTipo();
};
#endif /* Carburante_hpp */
