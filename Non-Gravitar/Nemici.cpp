//
//  Nemici.cpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#include "Nemici.hpp"

/* INIZIALIZZO I NEMICI */
void nemici::setNemici(int c){
    posizioneNem[0] = 18;
    posizioneNem[1] = c;
    esiste = true;
    tipo = rand()%2;
}
int nemici::getPosizioneNem1(){
    return posizioneNem[0];
}

int nemici::getPosizioneNem2(){
    return posizioneNem[1];
}

/* SPARO IN VERTICALE */
void nemici::sparo1(){
    posizioneProiettile[0][0] = getPosizioneNem1() - 1;
    posizioneProiettile[1][0] = getPosizioneNem2();
}

/* SPARO IN DIAGONALE SINISTRA */
void nemici::sparo2(){
    posizioneProiettile[0][1] = getPosizioneNem1() - 1;
    posizioneProiettile[1][1] = getPosizioneNem2() - 1;
}

/* SPARO IN DIAGONALE DESTRA */
void nemici::sparo3(){
    posizioneProiettile[0][2] = getPosizioneNem1() - 1;
    posizioneProiettile[1][2] = getPosizioneNem2() + 1;
}

int nemici::getPosizioneProiettile00(){
    return posizioneProiettile[0][0];
}

int nemici::getPosizioneProiettile10(){
    return posizioneProiettile[1][0];
}
int nemici::getPosizioneProiettile01(){
    return posizioneProiettile[0][1];
}

int nemici::getPosizioneProiettile11(){
    return posizioneProiettile[1][1];
}
int nemici::getPosizioneProiettile02(){
    return posizioneProiettile[0][2];
}

int nemici::getPosizioneProiettile12(){
    return posizioneProiettile[1][2];
}

void nemici::resetPosizioneProiettile(){
    posizioneProiettile[0][0] = 200;
    posizioneProiettile[1][0] = 300;
    posizioneProiettile[0][1] = 200;
    posizioneProiettile[1][1] = 300;
    posizioneProiettile[0][2] = 200;
    posizioneProiettile[1][2] = 300;
    
}

int nemici::getTipo(){
    return tipo;
}

bool nemici::getEsiste(){
    return esiste;
}

void nemici::setEsiste(bool c){
    esiste = c;
}
