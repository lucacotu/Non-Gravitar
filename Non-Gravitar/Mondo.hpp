//
//  Mondo.hpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#ifndef Mondo_hpp
#define Mondo_hpp

#include <stdio.h>
using namespace std;
#include <iostream>
#include <stdlib.h>
#include "Navicella.hpp"
#include "Nemici.hpp"
#include "Carburante.hpp"
#include <curses.h>
#include <ncurses.h>
#include <time.h>

#define LARGHEZZA_MONDO 60
#define ALTEZZA_MONDO 20
#define NUMERO_MASSIMO_NEMICI 8
#define NUMERO_CARBURANTI 2

#define NAVICELLA   1
#define NEMICI 2
#define CARBURANTE 3
#define CARBURANTESPECIAL 4
#define SPARO 5

class Mondo{
protected:
    char mondo[ALTEZZA_MONDO][LARGHEZZA_MONDO];
    navicella nav;
    nemici lista_nemici[NUMERO_MASSIMO_NEMICI];
    carburante lista_carburante[NUMERO_CARBURANTI];
    bool distrutto;
    bool visitato = false;
    char punteggio[10];
    char vita[10];
    char carburante[10];
public:
    bool controlloSeMondoVuoto();
    void definisciMondo();
    void scriviMondo();
    void movimento();
    bool gameover();
    void sparoNavicella();
    void sparoNemici();
    int getPosizioneProiettile1();
    void movimentoSparo();
    int posizioneMondo[2];
    bool getDistrutto();
    int getPosizioneMondo0();
    int getPosizioneMondo1();
    void setDistrutto();
    void setDistrutto1();
    void setVisitato();
    bool getVisitato();
    void setVitaNavicella(int n);
    void setCarburanteNavicella(int n);
    int getVitaNavicella();
    int getCarburanteNavicella();
    int getPunteggio();
    void setPunteggio(int n);
};

#endif /* Mondo_hpp */
