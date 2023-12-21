//
//  Universo.hpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#ifndef Universo_hpp
#define Universo_hpp

#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include "Navicella.hpp"
#include "Mondo.hpp"

#define NAVICELLA   1
#define NUMERO_MONDI_GALASSIA 5

class galassia{
private:
    navicella nav;
    char punteggio[10];
    char vita[10];
    char carburante[10];
public:
    Mondo lista_mondi[NUMERO_MONDI_GALASSIA];
    void scriviGalassia();
    bool gameover();
    void movimento();
    void creaMondi();
    bool mondoDistrutto();
    int getPosizioneNavicella0();
    int getPosizioneNavicella1();
    int getVitaNavicella();
    int getCarburanteNavicella();
    void setVitaNavicella(int n);
    void setCarburanteNavicella(int n);
    void setNavicella();
    void setPosizioneNavicella1(int n);
    void setPosizioneNavicella2(int n);
    void setPunteggio(int n);
    int getPunteggio();
};

#endif /* Universo_hpp */
