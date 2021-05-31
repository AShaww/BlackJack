//
// Created by AmirS on 26/05/2021.
//

#pragma once

#include "Deck.h"

class Game{
public:
    Game();
    void initialiseGame();
    void getName();
    void menu();
    void title();
    void instructions();

    void playGame();

    void dealCardToPlayer();
    void dealCardToDealer();
    void displayStatus();
    bool checkDealerHand();
    void playerAction();

    void checkDeckCount();
    void dealGame();
    void push();
    void stand();
    void dealerMoveCheckWinner();
    void playerWin();
    void dealerWin();
    void checkWinner();
    void endGameMenu();
private:
    vector<Player*> players;
    Player* player = new Player;
    Player* dealer = new Player;
    Deck* deck = new Deck;
    const int twentyOne = 21;
};

Game::Game() {
    initialiseGame();
}

void Game::initialiseGame() {
    title();
    menu();
}

void Game::playGame() {
    dealGame();
    playerAction();
}

void Game::dealGame() {
    checkDeckCount();
    dealCardToPlayer();
    dealCardToPlayer();
    dealCardToDealer();
    dealCardToDealer();

    if(player->hasBlackJack() && dealer->hasBlackJack())
    {
        displayStatus();
        cout << "" << endl;
        cout << " TWO BLACKJACKS!" << endl;
        cout << " NO WINNER!" << endl;
        cout << " NO PAYOUT!" << endl;
        cout << "" << endl;
        system("pause");
        push();
    }
    if (player->hasBlackJack())
    {
        displayStatus();
        cout << "" << endl;
        cout << "" << player->getName() << " GOT BLACKJACK!" << endl;
        cout << "" << endl;
        system("pause");
        playerWin();
    }
    if (dealer->hasBlackJack())
    {
        displayStatus();
        cout << "" << endl;
        cout << "" << dealer->getName() << " GOT BLACKJACK!" << endl;
        cout << "" << endl;
        system("pause");
        push();
    }
    playerAction();
}

void Game::title() {
    cout << "\tWelcome to Jack Black. A simple Black Jack game! " << endl;
}

void Game::instructions() {

    cout << "The game is simple, closest to 21 wins." << endl;
    cout << "The dealer will keep hitting until 17 or over." << endl;

    cout << "Decide when to stand, but be careful; if the dealer beats you, you lose." << endl;

    cout << "This is for pure entertainment, and not for gambling." << endl;
    cout << "Play responsibly." << endl;
}

void Game::menu() {
    char input;

    cout << "" << endl;
    cout << " MENU" << endl;
    cout << " 1. START" << endl;
    cout << " 2. HOW TO PLAY" << endl;
    cout << " 3. QUIT" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "Input number for menu item: " << endl;

    cin >> input;
    switch (input)
    {
        case '1' :
            getName();
            break;
        case '2':
            instructions();
            break;
        case '3':
            cout << "YOU HAVE CHOSEN TO EXIT!" << endl;
            cout << "THANKS FOR PLAYING!" << endl;
            exit(1);
        default:
            cout << "Incorrect input, select an item from the menu. \n";
            system("pause");
            menu();
    }
}
void Game::checkDeckCount() {
    while(deck->getDeckOfCards().size() < 10)
    {
        cout << "Deck is low on cards ( Reshuffling and initialising the deck ) " << endl;
        deck->initialiseDeck();
    }
}
void Game::getName() {
    string input;
    cout << "Please enter your name: " << endl;
    cin >> input;
    player->setName(input);
    dealer->setName("Dealer");

    cout << "Your name is: " << player->getName() << endl;
    cout << "You are playing against: " << dealer->getName() <<" (The HOUSE) " <<  endl;
    cout << "Are you ready? " << player->getName() << endl;
    cout << " " << endl;
    system("pause");
    playGame();
}

void Game::dealCardToPlayer() {
    deck->giveTopCardTo(player);
}

void Game::dealCardToDealer(){
    deck->giveTopCardTo(dealer);
}

void Game::displayStatus() {
    cout << player->getName() << "'s hand:" << endl;
    player->showHand();
    cout << "Current hand score: " << player->getPlayerHandValue() << endl;
    cout << endl;
    cout << dealer->getName() << "'s hand:" << endl;
    dealer->showHand();
    cout << "Current hand score: " << dealer->getPlayerHandValue() << endl;
}

bool Game::checkDealerHand() {
    if (dealer->getPlayerHandValue() >= 17)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Game::dealerMoveCheckWinner(){
   while(checkDealerHand())
    {
        dealCardToDealer();
    }
    checkWinner();
}


void Game::checkWinner(){
    cout << " WINNER: " << endl;
    player->getPlayerHandValue();
    dealer->getPlayerHandValue();

    displayStatus();

    cout << "" << endl;

    if (player->getPlayerHandValue() > twentyOne)
    {
        dealerWin();
    }
    else if (player->getPlayerHandValue() == dealer->getPlayerHandValue())
    {
        push();
    }
    else if (dealer->getPlayerHandValue() > twentyOne)
    {
        playerWin();
    }
    else if (dealer->getPlayerHandValue() > player->getPlayerHandValue())
    {
        dealerWin();
    }
    else if (dealer->getPlayerHandValue() == player->getPlayerHandValue())
    {
        push();
    }
    else if (dealer->getPlayerHandValue() < player->getPlayerHandValue())
    {
        playerWin();
    }

}
void Game::playerAction() {
    char input;
    player->getPlayerHandValue();
    while(player->getHand().size() < 11 && player->getPlayerHandValue() < twentyOne) {
        displayStatus();
        cout << endl;
        cout << "Player Options: " << endl;
        cout << " 1. HIT " << endl;
        cout << " 2. STAND " << endl;
        cout << "Input: ";

        cin >> input;
        switch (input) {
            case '1' :
                cout << "Player has Hit: " << endl;
                dealCardToPlayer();
                playerAction();
                break;
            case '2' :
                cout << "" << endl;
                stand();
                break;
            default:
                cout << "INCORRECT INPUT! TRY AGAIN" << endl;
                system("pause");
                playerAction();
                break;
        }
    }
    dealerMoveCheckWinner();
}

void Game::stand() {
    cout << "Player has chosen to stand: " << endl;
    dealerMoveCheckWinner();
}
void Game::dealerWin(){
    cout << "\t" << player->getName() << " has Lost!" <<endl;
    cout << "\t" << dealer->getName() << " has Won!" << endl;
    player->clearHand();
    dealer->clearHand();
    endGameMenu();
}

void Game::playerWin(){
    cout << "\t" << player->getName() << " has Won!" <<endl;
    cout << "\t" << dealer->getName() << " has Lost!" << endl;
    player->clearHand();
    dealer->clearHand();
    endGameMenu();
}

void Game::push(){
    cout << endl;
    cout << " PUSH - NO WINNERS     " << endl;
    cout << endl;
    system("pause");
    player->clearHand();
    dealer->clearHand();
    endGameMenu();
}
void Game::endGameMenu(){
    char input;
    cout << endl;
    cout << " 1. NEW DEAL" << endl;
    cout << " 2. MAIN MENU" << endl;
    cout << " 3. EXIT" << endl;
    cout << endl;
    cout << "Input: ";
    cin >> input;
    switch (input)
    {
    case '1':
        cout << "NEW DEAL (NEW GAME)" << endl;
        playGame();
        break;
    case '2':
        menu();
        break;
    case '3':
        cout << "YOU HAVE CHOSEN TO EXIT!" << endl;
        cout << "THANKS FOR PLAYING!" << endl;
        exit(0);
    default:
        cout << "INCORRECT INPUT" << endl;
        system("pause");
        endGameMenu();
        break;
    }
}


