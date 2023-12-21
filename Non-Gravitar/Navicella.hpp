//
//  Navicella.hpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#ifndef Navicella_hpp
#define Navicella_hpp

#include <stdio.h>
using namespace std;
#include <iostream>
#include <curses.h>
#include <ncurses.h>

class navicella{
protected:
    int vita;
    int carburante;
    int posizione[2];
    int posizioneProiettile[2]= {100, 100};
    int posizioneGancio[2];
    int Punteggio;
    int tipo;
public:
   void setNavicella();
    int getPosizione1();
    int getPosizione2();
    int getVita();
    int getCarburante();
    void diminuisciVita();
    void setVita(int n);
    int getPosizioneProiettile1();
    int getPosizioneProiettile2();
    void sparo();
    void movimentoSparo();
    void setPosizione1(int n);
    void setPosizione2(int n);
    void setCarburante(int n);
    void diminuisciCarburante();
    void recuperaCarburante();
    void resetPosizioneProiettileEGancio();
    void setPosisizioneGancio();
    int getPosizioneGancio1();
    int getPosizioneGancio2();
    void setPunteggio(int n);
    int getPunteggio();
    void aumentaPunteggio();
};

#endif /* Navicella_hpp */
