//
//  main.cpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 08/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>
#include "Galassia.hpp"
#include "Mondo.hpp"
#include "Navicella.hpp"
#include <curses.h>
#include <ncurses.h>
#include <iostream>
#include <stdlib.h>


int main(){
    /* VARIABILE PER FAR SPARARE AD INTERMITTENZA I NEMICI */
    int ciclo=0;
    
    /* CREO UNA VARIABILE DA USARE NEL CICLO FOR PER RINIZIARE IL GIOCO UNA VOLTA CHE SI PERDE   */
    int partita = 1 ;
    
    /* VARIABILE PER VISUALIZZARE IL MENÙ FIN QUANDO NON SI PREMA LA X PER PROSEGUIRE*/
    int var=1;
    
    /* LISTA BIDIREZIONALE PER LE GALASSIE */
    struct lista_galassie{
        galassia corrente;
        bool visitato = false;
        lista_galassie *prossimo;
        lista_galassie *precedente;
        bool visitatoProssimo = false;
        bool visitatoPrecedente = false;
    };
    typedef lista_galassie* ptr_lista;
    
    
    
    /* FUNIZONI DI NCURSES PER INIZIALIZZARE IL TERMINALE */
    initscr();
    cbreak();
    noecho();
    erase();
    scrollok(stdscr, TRUE);
   
    /* has_color CONTROLLA SE IL TERMINALE SUPPORTA I COLORI */
    /* SE VERO star_color ABILITA I COLORI                   */
    if (has_colors()== true ){
        start_color();
    }

    /* MENÙ INIZIALE 1 */
    for (int i = 0; i < var; i++){
    clear();
    refresh();
    mvprintw(5, 7, "#     #    ###    #     #                               ####   ######      #     ##   ##   #####   #######     #     ######");
    mvprintw(6, 7, "##    #   #   #   ##    #                              #    #  #     #     #      #   #      #        #        #     #     #");
    mvprintw(7, 7, "# #   #  #     #  # #   #                             #        #     #    ###     #   #      #        #       ###    #     #");
    mvprintw(8, 7, "#  #  #  #     #  #  #  #           #######           #   ###  ######     # #      # #       #        #       # #    ######");
    mvprintw(9, 7, "#   # #  #     #  #   # #                             #     #  #   #     #####     # #       #        #      #####   #   #");
    mvprintw(10, 7,"#    ##   #   #   #    ##                              #    #  #    #    #   #      #        #        #      #   #   #    #");
    mvprintw(11, 7,"#     #    ###    #     #                               #####  #     #  ##   ##     #      #####      #     ##   ##  #     #");
    mvprintw(14, 60, "PRESS X TO CONTINUE ");
    mvprintw(16, 61, " COTUGNO LUCA ");
        char l;
        l= getch();
        switch (l) {
            case 'X':
            case 'x':
                break;
            default:
                var = var + 1;
                break;
        }
    }
    
    var=1;
    /* MENÙ INIZIALE 2*/
    for (int i = 0; i < var; i++){
    clear();
    refresh();
    mvprintw(7, 50 ," W = YOU " );
    mvprintw(9, 50 ," A = ENEMIES " );
    mvprintw(11, 50," @ = FUEL " );
    mvprintw(13, 50," O = PLANET " );
    mvprintw(15, 50," PRESS X TO CONTINUE ");
        char l;
        l= getch();
        switch (l) {
            case 'X':
            case 'x':
                break;
            default:
                var = var + 1;
                break;
        }}
    
    var=1;
    /* MENÙ INIZIALE 3 */
    for (int i = 0; i < var; i++){
    clear();
    refresh();
    mvprintw(7, 50 ," CONTROLS " );
    mvprintw(9, 50 ," W = UP " );
    mvprintw(11, 50," S = DOWN " );
    mvprintw(13, 50," A = LEFT " );
    mvprintw(15, 50," D = RIGHT ");
    mvprintw(17, 50," L = SHOOT " );
    mvprintw(19, 50, " K = GRAB FUEL " );
    mvprintw(21, 50," O = ESCAPE FROM WORLD " );
    mvprintw(23, 50," PRESS X TO CONTINUE ");
        char l;
        l= getch();
        switch (l) {
            case 'X':
            case 'x':
                break;
            default:
                var = var + 1;
                break;
        }}
    
    for (int k=0; k < partita ; k++){
        var = 1;
        for (int i = 0; i < var; i++){
        clear();
        refresh();
        mvprintw(15, 38, "EXPLORE THE UNIVERSE AND CONQUER ALL THE WORLDS ");
        mvprintw(17, 51," ARE YOU READY?");
        mvprintw(19, 50," PRESS X TO START ");
            char l;
            l= getch();
            switch (l) {
                case 'X':
                case 'x':
                    break;
                default:
                    var = var + 1;
                    break;
            }}
        
        
        ptr_lista lista;                                                                          /* CREO LA LISTA  */
        lista = new lista_galassie;
        lista->precedente = NULL;                                                                 /* INIZIALIZZO LA GALASSIA SINISTRA A NULL */
        lista->prossimo = NULL;                                                                   /* INIZIALIZZO LA GALASSIA SINISTRA A NULL */
        lista->corrente.setNavicella();                                                           /* INIZIALIZZO LA NAVICELLA DELLA GALASSIA */
        while (lista->corrente.gameover() == true){
            if (lista->corrente.getPosizioneNavicella1() <= 0){                                   /* CONDIZIONE PER CONTROLLARE SE LA NAVICELLA SI STA SPOSTANDO VERSO LA GALASSIA SINISTRA */
                if (lista->visitatoPrecedente == false){                                          /* SE LA GALASSIA SINISTRA NON É STATA ANCORA VISITATA VIENE CREATA                       */
                    lista->precedente = new lista_galassie;
                }
                lista->precedente->prossimo = lista;                                                                           /* LA LISTA SI SPOSTA SULLA GALASSIA SINISTRA,SALVA I VALORI */
                lista->precedente->corrente.setVitaNavicella(lista->corrente.getVitaNavicella());                              /* DELLA VITA E DEL CARBURANTE DELLA NAVICELLA E UNISCE LE   */
                lista->precedente->corrente.setCarburanteNavicella(lista->corrente.getCarburanteNavicella());                  /* GALASSIE NELLA LISTA PER POTER TORNARE DI NUOVO NELLA     */
                lista->precedente->corrente.setPunteggio(lista->corrente.getPunteggio()); 
                lista = lista->precedente;                                                                                     /* GALASSIA PRECEDENTE                                       */
                lista->visitatoProssimo = true;
                lista->corrente.setPosizioneNavicella1(3);
                lista->corrente.setPosizioneNavicella2(LARGHEZZA_MONDO - 2);
            }
            if (lista->corrente.getPosizioneNavicella1() >= LARGHEZZA_MONDO){                   /* CONDIZIONE PER CONTROLLARE SE LA NAVICELLA SI STA SPOSTANDO VERSO LA GALASSIA DESTRA */
                if ( lista->visitatoProssimo == false){                                         /* SE LA GALASSIA DESTRA NON É STATA ANCORA VISITATA VIENE CREATA                       */
                    lista->prossimo= new lista_galassie;
                }
                    lista->prossimo->precedente = lista;                                                                       /* LA LISTA SI SPOSTA SULLA GALASSIA DESTRA,SALVA I VALORI   */
                    lista->prossimo->corrente.setVitaNavicella(lista->corrente.getVitaNavicella());                            /* DELLA VITA E DEL CARBURANTE DELLA NAVICELLA E UNISCE LE   */
                    lista->prossimo->corrente.setCarburanteNavicella(lista->corrente.getCarburanteNavicella());                /* GALASSIE NELLA LISTA PER POTER TORNARE DI NUOVO NELLA     */
                    lista->prossimo->corrente.setPunteggio(lista->corrente.getPunteggio());                               /* GALASSIA PRECEDENTE                                       */
                    lista = lista->prossimo;
                    lista->visitatoPrecedente = true;
                    lista->corrente.setPosizioneNavicella1(3);
                    lista->corrente.setPosizioneNavicella2(2);
            }
                if (lista->visitato==false) {                                       /* SE LA GALASSIA DOVE CI SI SPOSTA NON ERA ANCORA STATA VISITATA VIENE INIZIALIZZATA CON LA CREAZIONE  */
                    lista->corrente.creaMondi();                                    /* DEI MONDO E VIENE POI SCRITTA SU TERMINALE IN ATTESA DI INPUT PER MUOVERE LA NAVICELLA               */
                    lista->corrente.scriviGalassia();
                    lista->visitato=true;
                    lista->corrente.movimento();
                }
                else {
                    lista->corrente.scriviGalassia();                              /* VIENE SCRITTO IL MONDO SUL TERMINALE E SI ATTENDE UN INPUT PER MUOVERE LA NAVICELLA                  */
                    lista->corrente.movimento();
                        for (int s=0; s < NUMERO_MONDI_GALASSIA; s++){
                            if ((lista->corrente.getPosizioneNavicella0() == lista->corrente.lista_mondi[s].getPosizioneMondo0()) && ( lista->corrente.getPosizioneNavicella1() == lista->corrente.lista_mondi[s].getPosizioneMondo1()) )          /* CONTROLLO PER VEDERE SE LA NAVICELLA SI MUOVE SU UNO DEI MONDI */
                            {       halfdelay(3);                                         /* FUNZIONE DI NCURSES CHE NON BLOCCA L'ESECUZIONE DEL GIOCO SE NON C'É UN INPUT PER IL MOVIMENTO */
                                    lista->corrente.lista_mondi[s].setCarburanteNavicella(lista->corrente.getCarburanteNavicella());           /* SALVO I VALORI DELLA VITA, DEL CARBURANTE */
                                    lista->corrente.lista_mondi[s].setVitaNavicella(lista->corrente.getVitaNavicella());                       /* E DEL PUNTEGGIO DELLA NAVICELLA           */
                                    lista->corrente.lista_mondi[s].setPunteggio(lista->corrente.getPunteggio());
                                while (lista->corrente.lista_mondi[s].getDistrutto() == false && lista->corrente.lista_mondi[s].gameover() == true ){  
                                        if ( lista->corrente.lista_mondi[s].getVisitato() == true){                                     /* SE IL MONDO É STATO VISITATO VENGONO CARICATI    */
                                                lista->corrente.lista_mondi[s].scriviMondo();                                           /* LA VITA, IL CARBURANTE E IL PUNTEGGIO PER ESSERE */
                                                lista->corrente.lista_mondi[s].movimento();                                             /* VISUALIZZATI INSIEME AL MONDO NEL TERMINALE E SI */
                                                lista->corrente.setCarburanteNavicella(lista->corrente.lista_mondi[s].getCarburanteNavicella()); /*ASPETTA L'INPUT PER MUOVERE LA NAVICELLA */
                                                lista->corrente.setVitaNavicella(lista->corrente.lista_mondi[s].getVitaNavicella());
                                                lista->corrente.setPunteggio(lista->corrente.lista_mondi[s].getPunteggio());
                                                if (ciclo%2 == 1){
                                                lista->corrente.lista_mondi[s].sparoNemici();}              /* PER FAR SPARARE I NEMICI AD INTERMITTENZA */
                                                ciclo = ciclo+1;
                                        }
                                        else {  lista->corrente.lista_mondi[s].definisciMondo();                    /* SE IL MONDO NON ERA VISITATO VIENE DEFINITO E VENGONO CARICATI LA    */
                                                lista->corrente.lista_mondi[s].setVisitato();                       /* VITA, IL CARBURANTE E IL PUNTEGGIO PER ESSERE VISUALIZZATI INSIEME   */
                                                lista->corrente.lista_mondi[s].scriviMondo();                       /* AL MONDO NEL TERMINALE E SI ASPETTA L'INPUT PER MUOVERE LA NAVICELLA */
                                                lista->corrente.lista_mondi[s].movimento();
                                                lista->corrente.setCarburanteNavicella(lista->corrente.lista_mondi[s].getCarburanteNavicella());
                                                lista->corrente.setVitaNavicella(lista->corrente.lista_mondi[s].getVitaNavicella());
                                                lista->corrente.setPunteggio(lista->corrente.lista_mondi[s].getPunteggio());
                                }
                                }
                                lista->corrente.setCarburanteNavicella(lista->corrente.lista_mondi[s].getCarburanteNavicella());
                                lista->corrente.setVitaNavicella(lista->corrente.lista_mondi[s].getVitaNavicella());
                                lista->corrente.setPunteggio(lista->corrente.lista_mondi[s].getPunteggio());
                            }
                        
                            lista->corrente.lista_mondi[s].setDistrutto1();           /* FUNZIONE PER PERMETTERE DI RIVISTARE IL MONDO DISTRUTTO*/
                            cbreak();                                                 /* FUNZIONE DI NCURSES CHE BLOCCA L'ESECUZIONE DI halfdelay() */
                        }
                }
            }
        cbreak();
        getch();
        
        char punteggioFinale[10];
        sprintf(punteggioFinale,"%d",lista->corrente.getPunteggio());
        
        /* SCHERMATA FINALE DOVE SI PUÓ USCIRE O RINIZIARE LA PARTITA */
        var = 1;
        for (int i = 0; i < var; i++){
        clear();
        refresh();
        mvprintw(5, 15,  "#     #    ###    #     #           #          ###     #####   ####### ");
        mvprintw(6, 15,  " #   #    #   #   #     #           #         #   #   #     #  # ");
        mvprintw(7, 15,  "  # #    #     #  #     #           #        #     #  #        #");
        mvprintw(8, 15,  "   #     #     #  #     #           #        #     #   #####   ##### ");
        mvprintw(9, 15,  "   #     #     #  #     #           #        #     #        #  #");
        mvprintw(10, 15, "   #      #   #   #     #           #         #   #   #     #  # ");
        mvprintw(11, 15, "   #       ###     #####            ######     ###     #####   #######");
        mvprintw(13, 40, "YOUR SCORE IS : ");
        mvprintw(13, 57, punteggioFinale);
        mvprintw(15, 30, " PRESS X TO PLAY AGAIN OR Z TO EXIT");
        char f;
        f = getch();
        switch (f) {
            case 'X':
            case 'x':
                partita = partita + 1;
                break;
            case 'Z':
            case 'z':
                break;
            default:
                var = var + 1;
                break;
        }
    }
    }
    endwin();
    return 0;
    
}
