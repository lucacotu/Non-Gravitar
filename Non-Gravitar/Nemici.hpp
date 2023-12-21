//
//  Nemici.hpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#ifndef Nemici_hpp
#define Nemici_hpp

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include <iostream>
#include <unistd.h>

class nemici{
protected:
    int posizioneNem[2];
    int posizioneProiettile[2][3];
    int tipo;
    bool esiste = false;
public:
    void setNemici(int c);
    bool getEsiste();
    void setEsiste(bool c);
    void setVita();
    int getPosizioneNem1();
    int getPosizioneNem2();
    int getPosizioneProiettile00();
    int getPosizioneProiettile10();
    int getPosizioneProiettile01();
    int getPosizioneProiettile11();
    int getPosizioneProiettile02();
    int getPosizioneProiettile12();
    void sparo1();
    void sparo2();
    void sparo3();
    void resetPosizioneProiettile();
    int getTipo();
};

#endif /* Nemici_hpp */
