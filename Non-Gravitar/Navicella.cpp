//
//  Navicella.cpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#include "Navicella.hpp"
#include "Nemici.hpp"
/* FUNZIONE PER INIZIALIZZARE LA NAVICELLA */
void navicella::setNavicella(){
    posizione[0]=2;
    posizione[1]=10;
    vita=100;
    carburante=300;
};

/* FUNZIONE CHE RESETTA LA POSIZIONE DEL GANCIO E DEI PROIETTILI DELLA NAVICELLA DOPO AVER SPARATO */
void navicella::resetPosizioneProiettileEGancio(){
    posizioneProiettile[1] = -1;
    posizioneGancio[0] = -1;
    posizioneGancio[1] = -1;
}

void navicella::setVita( int n){
    vita=n;
}

void navicella::setCarburante(int n){
    carburante=n;
}

int navicella::getPosizione1(){
    return posizione[0];
};

int navicella::getPosizione2(){
    return posizione[1];
};

void navicella::diminuisciVita(){
    vita = vita - 10;
}

int navicella::getVita(){
    return vita;
}

int navicella::getCarburante(){
    return carburante;
}

int navicella::getPosizioneProiettile1(){
    return posizioneProiettile[0];
}

int navicella::getPosizioneProiettile2(){
    return posizioneProiettile[1];
}

void navicella::sparo(){
        posizioneProiettile[0] = getPosizione1() + 1;
        posizioneProiettile[1] = getPosizione2();
    }
void navicella::movimentoSparo(){
    posizioneProiettile[0] = posizioneProiettile[0] + 1;
    }

void navicella::setPosizione1(int n){
    posizione[0] = n;
}

void navicella::setPosizione2(int n){
    posizione[1] = n;
}

void navicella::diminuisciCarburante(){
    carburante = carburante-1;
}

void navicella::recuperaCarburante(){
    carburante = carburante+5;
}

void navicella::setPosisizioneGancio(){
    posizioneGancio[0] = getPosizione1() + 1;
    posizioneGancio[1] = getPosizione2();
}

int navicella::getPosizioneGancio2(){
    return posizioneGancio[1];
}

int navicella::getPosizioneGancio1(){
    return posizioneGancio[0];
}

void navicella::setPunteggio(int n){
    Punteggio = n;
}

int navicella::getPunteggio(){
    return Punteggio;
}

void navicella::aumentaPunteggio(){
    Punteggio = Punteggio +100;
}


