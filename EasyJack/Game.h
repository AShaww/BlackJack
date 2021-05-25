//
// Created by AmirS on 25/05/2021.
//

#ifndef EASYJACK_GAME_H
#define EASYJACK_GAME_H

#include "mainHeader.h"
#include "Deck.h"
#include "Player.h"

class Game{
public:
      Game();
      ~Game();
      void dealCard();
private:
    Deck *deck;
    vector<Player*> players;
};

Game::Game() { }
void Game::dealCard() {

    for (int player = 0; player < players.size(); player++)
    {
        players.push_back(players.front());

    }
}


#endif //EASYJACK_GAME_H
