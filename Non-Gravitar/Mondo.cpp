//
//  Mondo.cpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//
#include "Mondo.hpp"

/* FUNZIONE PER STAMPARE SUL TERMINALE LA SCHERMATA DEL MONDO  */
void Mondo::definisciMondo(){
    nav.setPosizione1(3);
    nav.setPosizione2(30);
    srand((unsigned int)time(0));
    int c = rand()%4 + 5;
        for (int l=0; l <= c; l++){
            lista_nemici[l].setNemici(rand()%((LARGHEZZA_MONDO - 5)/c) + (l*(((LARGHEZZA_MONDO - 5)/c))+ 2) );
            lista_nemici[l].setEsiste(true);
            lista_nemici[l].resetPosizioneProiettile();
        }
    for (int f = c; f < NUMERO_MASSIMO_NEMICI; f++ ){
        lista_nemici[f].setEsiste(false);
        }
        for (int p=0; p < NUMERO_CARBURANTI; p++){
            lista_carburante[p].setPosizione();
            for (int l=0; l <= c; l++){
                if (lista_carburante[p].getPosizioneCarburante2() == lista_nemici[l].getPosizioneNem2())
                        lista_carburante[p].setPosizione();
        }
        }
};
/* FUNZIONE PER CONTROLLARE SE TUTTI I NEMICI SONO DISTRUTTI E TUTTI I CARBURANTI SONO STATI RACCOLTI*/
bool Mondo::controlloSeMondoVuoto(){
    for (int x=0; x< NUMERO_MASSIMO_NEMICI; x++){
        if (lista_nemici[x].getEsiste() == true){
            return false;
        }
    }
    for (int z=0; z< NUMERO_CARBURANTI; z++){
        if (lista_carburante[z].getEsiste() == true){
            return false;
        }
    }
    
    return true;
    
}
/* FUNZIONE PER MUOVERE, PER SPARARE E PER FAR RACCOGLIERE IL CARBURANTE ALLA NAVICELLA */
void Mondo::movimento(){
    char c;
    c=getch();
    switch (c) {
        case 'W':
        case 'w':
            if (nav.getPosizione1() > 1 ) {
                nav.setPosizione1(nav.getPosizione1() - 1);
                nav.diminuisciCarburante();
            }
            break;
        case 'A':
        case 'a':
            if (nav.getPosizione2() > 1 ) {
                nav.setPosizione2(nav.getPosizione2() - 1);
                nav.diminuisciCarburante();
            }
            break;
        case 'S':
        case 's':
            if (nav.getPosizione1() < 17 ) {
                nav.setPosizione1(nav.getPosizione1() + 1);
                nav.diminuisciCarburante();
            }
            if (nav.getPosizione1() == 17 ) {
                nav.diminuisciVita();
            }
            break;
        case 'D':
        case 'd':
            if (nav.getPosizione2() < 58 ) {
                nav.setPosizione2(nav.getPosizione2() + 1);
                nav.diminuisciCarburante();
            }
            break;
        case 'L':
        case 'l':
            nav.sparo();
            break;
        case 'K':
        case 'k':
            nav.setPosisizioneGancio();
            break;
        case 'o':
        case 'O':
            setDistrutto();
        default:
            break;
    }
}

/* FUNZIONE PER STAMPARE SUL TERMINALE LA SCHERMATA DEL MONDO DOPO AVER CONTROLLATO SE LA NAVICELLA VIENE COLPITA DAI NEMICI, SE UN NEMICO VIENE DISTRUTTO O SE VIENE RACCOLTO UN CARBURANTE*/
void Mondo::scriviMondo(){
    
    init_pair(NAVICELLA, COLOR_GREEN, COLOR_BLACK);
    init_pair(NEMICI, COLOR_RED, COLOR_BLACK);
    init_pair(CARBURANTE, COLOR_CYAN, COLOR_BLACK);
    init_pair(CARBURANTESPECIAL, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(SPARO, COLOR_YELLOW, COLOR_BLACK);
    
    for(int l=0; l < NUMERO_MASSIMO_NEMICI; l++){
        if ((nav.getPosizioneProiettile1() <= lista_nemici[l].getPosizioneNem1() && nav.getPosizioneProiettile2() == lista_nemici[l].getPosizioneNem2()) && lista_nemici[l].getEsiste()==true) {
            lista_nemici[l].setEsiste(false);
            nav.aumentaPunteggio();
        }
        if ((nav.getPosizione2() == lista_nemici[l].getPosizioneProiettile10()) && (lista_nemici[l].getEsiste() == true )){
            nav.diminuisciVita();
        }
        if ((lista_nemici[l].getPosizioneProiettile01() - lista_nemici[l].getPosizioneProiettile11()) == (nav.getPosizione1() - nav.getPosizione2()) && (lista_nemici[l].getEsiste() == true)){
            nav.diminuisciVita();
        }
        if ((lista_nemici[l].getPosizioneProiettile02() + lista_nemici[l].getPosizioneProiettile12()) == (nav.getPosizione1() + nav.getPosizione2()) && (lista_nemici[l].getEsiste() == true) ) {
            nav.diminuisciVita();
        }
        for (int p=0; p < NUMERO_CARBURANTI; p++){
            if (nav.getPosizioneGancio2() == lista_carburante[p].getPosizioneCarburante2()){
                    nav.recuperaCarburante();
                if (lista_carburante[p].getTipo() == 1){
                    nav.recuperaCarburante();}
                lista_carburante[p].setEsiste(false);
            }
        }
    }
    
    sprintf(punteggio,"%d", nav.getPunteggio());        /* TRASFORMO GLI INT IN CHAR PER ESSERE STAMPATI DA NCURSES */
    sprintf(vita,"%d",nav.getVita());
    sprintf(carburante,"%d",nav.getCarburante());
    
    clear();
    refresh();
    
    mvprintw(7, 50,"Vita = ");
    mvprintw(7, 57,vita);
    mvprintw(7, 63, "Carburante = ");
    mvprintw(7, 76,carburante);
    mvprintw(7, 82,"Punteggio = ");
    mvprintw(7, 94,punteggio);
    
    if (controlloSeMondoVuoto() == true) {
       mvprintw(9,50, "MONDO DISTRUTTO PREMI O PER TORNARE NELLA GALASSIA" );
    }
        for (int i=0; i < ALTEZZA_MONDO; i++)
        {
            for (int j=0; j < LARGHEZZA_MONDO; j++)
            {
                if (i==0 || i==(ALTEZZA_MONDO-1) )
                    mvprintw(i+10,j+50,"_");
                else if (j==0 || j==(LARGHEZZA_MONDO-1) )
                    mvprintw(i+10,j+50,"|");
                else if (nav.getPosizione1() == i && nav.getPosizione2() == j ){
                    attron(COLOR_PAIR(NAVICELLA));
                    mvprintw(i+10,j+50,"W");
                    attroff(COLOR_PAIR(NAVICELLA));
                    }
                else if (nav.getPosizioneProiettile1() <= i &&  nav.getPosizioneProiettile2()== j )
                    mvprintw(i+10,j+50,"|");
                else if ((nav.getPosizioneGancio1() <= i) && nav.getPosizioneGancio2() == j  )
                    mvprintw(i+10,j+50,"I");
                else for (int l=0; l< NUMERO_MASSIMO_NEMICI; l++)
                {   if ((lista_nemici[l].getPosizioneNem1() == i && lista_nemici[l].getPosizioneNem2() == j) && lista_nemici[l].getEsiste()==true){
                        attron(COLOR_PAIR(NEMICI));
                        mvprintw(i+10,j+50,"A");
                        attroff(COLOR_PAIR(NEMICI));
                        }
                    if (((lista_nemici[l].getPosizioneProiettile01() - lista_nemici[l].getPosizioneProiettile11()) == ( i-j )) && lista_nemici[l].getEsiste()==true ){
                        if ( i < ALTEZZA_MONDO-2){
                                attron(COLOR_PAIR(SPARO));
                                mvprintw(i+10, j+50, "\\" );}
                                attroff(COLOR_PAIR(SPARO));
                                }
                    if ((lista_nemici[l].getPosizioneProiettile00() >= i && lista_nemici[l].getPosizioneProiettile10() == j) && lista_nemici[l].getEsiste()==true ){
                        attron(COLOR_PAIR(SPARO));
                        mvprintw(i+10, j+50, "|");
                        attroff(COLOR_PAIR(SPARO));
                        }
                    if (((lista_nemici[l].getPosizioneProiettile02() + lista_nemici[l].getPosizioneProiettile12()) == ( i+j )) && lista_nemici[l].getEsiste()==true ){
                        if ( i < ALTEZZA_MONDO-2){
                            attron(COLOR_PAIR(SPARO));
                            mvprintw(i+10, j+50, "/" );
                            attroff(COLOR_PAIR(SPARO));}
                        }
                }
                for (int p=0; p < NUMERO_CARBURANTI; p++){
                    if ((lista_carburante[p].getPosizioneCarburante1() == i) && (lista_carburante[p].getPosizioneCarburante2() == j) && (lista_carburante[p].getEsiste() == true)){
                        if (lista_carburante[p].getTipo() == 0){
                                attron(COLOR_PAIR(CARBURANTE));
                                mvprintw(i+10, j+50, "@");
                                attroff(COLOR_PAIR(CARBURANTE));
                        }
                        else {
                                attron(COLOR_PAIR(CARBURANTESPECIAL));
                                mvprintw(i+10, j+50, "@");
                                attroff(COLOR_PAIR(CARBURANTESPECIAL));
                        }
                        }
                        }
                }
            }
    nav.resetPosizioneProiettileEGancio();
    for (int k=0; k < NUMERO_MASSIMO_NEMICI; k++){
        lista_nemici[k].resetPosizioneProiettile();
    }
};

/* CONTROLLA SE LE CONDIZIONI PER IL CONTINUO DEL GIOCO SONO VALIDE */
bool Mondo::gameover(){
    if (getVitaNavicella() <= 0 || getCarburanteNavicella() <= 0 )
        return false;
    else return true;
}

/* FUNZIONE PER FAR SPARARE LA NAVICELLA */
void Mondo::sparoNavicella(){
    nav.sparo();
    while (nav.getPosizioneProiettile1() < ALTEZZA_MONDO-2){
        nav.movimentoSparo();
    }
}

/* FUNZIONE PER FAR SPARARE I NEMICI */
void Mondo::sparoNemici(){
    for (int g = 0; g < NUMERO_MASSIMO_NEMICI; g++ ){
        if ( (lista_nemici[g].getTipo()) == 0 && (lista_nemici[g].getEsiste() == true)){
            int x = rand()%3;
            switch(x){
                case 0:
                    lista_nemici[g].sparo2();
                    lista_nemici[g].sparo3();
                    break;
                case 1:
                    lista_nemici[g].sparo2();
                    break;
                case 2:
                    lista_nemici[g].sparo3();
                    break;
                    
                    }
                }
        else if (lista_nemici[g].getEsiste() == true){
            int x = rand()%7;
                switch(x){
                    case 0:
                        lista_nemici[g].sparo2();
                        lista_nemici[g].sparo3();
                        break;
                    case 1:
                        lista_nemici[g].sparo2();
                        break;
                    case 2:
                        lista_nemici[g].sparo3();
                        break;
                    case 3:
                        lista_nemici[g].sparo1();
                        break;
                    case 4:
                        lista_nemici[g].sparo1();
                        lista_nemici[g].sparo2();
                        lista_nemici[g].sparo3();
                        break;
                    case 5:
                        lista_nemici[g].sparo2();
                        lista_nemici[g].sparo1();
                        break;
                    case 6:
                        lista_nemici[g].sparo3();
                        lista_nemici[g].sparo1();
                        break;
            }
        }
    }
}

int Mondo::getPosizioneProiettile1(){
    return nav.getPosizioneProiettile1();
}

void Mondo::movimentoSparo(){
     nav.movimentoSparo();
}

bool Mondo::getDistrutto(){
    return distrutto;
};

int Mondo::getPosizioneMondo0(){
    return posizioneMondo[0];
};

int Mondo::getPosizioneMondo1(){
    return posizioneMondo[1];
};

void Mondo::setDistrutto(){
    distrutto = true;
}

void Mondo::setDistrutto1(){
    distrutto = false;
}

void Mondo::setVisitato(){
    visitato = true;
}

bool Mondo::getVisitato(){
    return visitato;
}

void Mondo::setVitaNavicella(int n){
    nav.setVita(n);
}

void Mondo::setCarburanteNavicella(int n){
    nav.setCarburante(n);
}

int Mondo::getCarburanteNavicella(){
    return nav.getCarburante();
}

int Mondo::getVitaNavicella(){
    return nav.getVita();
}

int Mondo::getPunteggio(){
    return nav.getPunteggio();
}

void Mondo::setPunteggio(int n){
    nav.setPunteggio(n);
}
