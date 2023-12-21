//
//  Universo.cpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#include "Galassia.hpp"

/* FUNZIONE PER STAMPARE SUL TERMINALE LA SCHERMATA DELLA GALASSIA  */
void galassia::scriviGalassia(){
    
    sprintf(punteggio,"%d", nav.getPunteggio());        /* TRASFORMO GLI INT IN CHAR PER ESSERE STAMPATI DA NCURSES */
    sprintf(vita,"%d",nav.getVita());
    sprintf(carburante,"%d",nav.getCarburante());
    
    init_pair(NAVICELLA, COLOR_GREEN, COLOR_BLACK);     /* FUNZIONE DI NCURSES PER IMPOSTARE IL COLORE DELLA NAVICELLA */
    
    clear();
    refresh();
    mvprintw(7, 50,"Vita = ");
    mvprintw(7, 57,vita);
    mvprintw(7, 63, "Carburante = ");
    mvprintw(7, 76,carburante);
    mvprintw(7, 82,"Punteggio = ");
    mvprintw(7, 94,punteggio);
    for (int i=0; i < ALTEZZA_MONDO; i++)
    {
        for (int j=0; j < LARGHEZZA_MONDO; j++)
        {
            for (int s=0; s < NUMERO_MONDI_GALASSIA; s++)
            {
                if (i==0 || i==(ALTEZZA_MONDO-1) )
                    mvprintw(i+10,j+50,"_");
                else if (nav.getPosizione1() == i && nav.getPosizione2() == j ){
                    attron(COLOR_PAIR(NAVICELLA));
                    mvprintw(i+10,j+50, "W" );
                    attroff(COLOR_PAIR(NAVICELLA));
                }
                else if (lista_mondi[s].posizioneMondo[0] == i && lista_mondi[s].posizioneMondo[1] == j ){
                    mvprintw(i+10,j+50,"O");
                    }
                }
                
            }
        }
}

/* CONTROLLA SE LE CONDIZIONI PER IL CONTINUO DEL GIOCO SONO VALIDE */
bool galassia::gameover(){
    if (nav.getVita() <= 0 || nav.getCarburante() <= 0 )
        return false;
    else return true;
}

/* FUNZIONE PER MUOVERE LA NAVICELLA */
void galassia::movimento(){
    char c;
    c=getch();
    switch (c) {
        case 'W':
        case 'w':
            if (nav.getPosizione1() > 1 ) {
                nav.setPosizione1(nav.getPosizione1() - 1);
            }
            break;
        case 'A':
        case 'a':
            if (nav.getPosizione2() > 0 ) {
                nav.setPosizione2(nav.getPosizione2() - 1);
            }
            break;
        case 'S':
        case 's':
            if (nav.getPosizione1() < ALTEZZA_MONDO - 2 ) {
                nav.setPosizione1(nav.getPosizione1() + 1);
            }
            break;
        case 'D':
        case 'd':
            if (nav.getPosizione2() < LARGHEZZA_MONDO) {
                nav.setPosizione2(nav.getPosizione2() + 1);
            }
            break;
        default:
            break;
    }
};

/* INIZIALIZZO LA POSIZIONE DEI MONDI NELLA GALASSIA */
void galassia::creaMondi(){
    srand((unsigned int)time(0));
    for (int s=0; s < NUMERO_MONDI_GALASSIA; s++){
        int temp = rand()%(ALTEZZA_MONDO - 10) + 5;                     
        int temp1 = rand()%10 + (s*(LARGHEZZA_MONDO/NUMERO_MONDI_GALASSIA)) + 1 ;
        lista_mondi[s].posizioneMondo[0] = temp;
        lista_mondi[s].posizioneMondo[1] = temp1;
    }
}

int galassia::getPosizioneNavicella0(){
    return nav.getPosizione1();
};

int galassia::getPosizioneNavicella1(){
    return nav.getPosizione2();
};

int galassia::getVitaNavicella(){
    return nav.getVita();
}

int galassia::getCarburanteNavicella(){
    return nav.getCarburante();
}

void galassia::setCarburanteNavicella(int n){
    nav.setCarburante(n);
}

void galassia::setVitaNavicella(int n){
    nav.setVita(n);
}

void galassia::setNavicella(){
    nav.setNavicella();
}

void galassia::setPosizioneNavicella1(int n){
    nav.setPosizione1(n);
}

void galassia::setPosizioneNavicella2(int n){
    nav.setPosizione2(n);
}

void galassia::setPunteggio(int n){
    nav.setPunteggio(n);
}

int galassia::getPunteggio(){
     return nav.getPunteggio();
}
