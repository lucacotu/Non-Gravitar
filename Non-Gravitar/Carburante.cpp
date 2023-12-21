//
//  Carburante.cpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 30/07/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#include "Carburante.hpp"

/* INIZIALIZZO I CARBURANTI */
void carburante::setPosizione(){
    posizioneCarburante[0] = 18;
    posizioneCarburante[1] = rand()%50 + 5;
    esiste = true;
    tipo = rand()%2;
}

int carburante::getPosizioneCarburante1(){
    return posizioneCarburante[0];
}

int carburante::getPosizioneCarburante2(){
    return posizioneCarburante[1];
}

int carburante::getTipo(){
    return tipo;
}

bool carburante::getEsiste(){
    return esiste;
}

void carburante::setEsiste(bool c){
    esiste = c;
}
