//
//  GameOver.cpp
//  Non-Gravitar
//
//  Created by Luca Cotugno on 09/02/2019.
//  Copyright © 2019 Luca Cotugno. All rights reserved.
//

#include "GameOver.hpp"


bool Gameover::Setgameover(){
    if (nav.getVita() <= 0 || nav.getCarburante() <= 0 )
        Gameover=false;
    else Gameover=true;
    return Gameover;
}
