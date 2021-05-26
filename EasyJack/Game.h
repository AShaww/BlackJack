//
// Created by AmirS on 26/05/2021.
//

#pragma once


class Game{
public:
    Game();

    void playGame();
    void getName();
    void title();
    void instructions();
    void menu();

    void initialiseGame();
    void dealCard();

    void displayStatus();

//    vector<Player*> getPlayers();

private:
    vector<Player*> players;
    Player* player = new Player;
    Player* dealer = new Player;
    Deck* deck = new Deck;

//    vector<Player*> players;
};
Game::Game() {

    initialiseGame();
}
void Game::initialiseGame() {
    title();
    menu();
}


void Game::title() {
    cout << "\tWelcome to Jack Black. A simple Black Jack game! " << endl;
}
void Game::playGame() {
    dealCard();

}
void Game::dealCard() {
    deck->popCard(player);
    displayStatus();
}

void Game::menu() {

    int input;

    cout << "--------------------------" << endl;
    cout << "| MENU                   |" << endl;
    cout << "| 1. START               |" << endl;
    cout << "| 2. HOW TO PLAY         |" << endl;
    cout << "| 3. QUIT                |" << endl;
    cout << "--------------------------" << endl;
    cout << "" << endl;
    cout << "Input number for menu item: " << endl;
    cin >> input;
    switch (input)
    {
        case 1:
            getName();
            break;
        case 2:
            instructions();
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "Incorrect input, try again.";
            menu();
    }
}

void Game::getName() {
    string input;
    cout << "Please enter your name: " << endl;
    cin >> input;
    player->setName(input);
    cout << "your name is: " << player->getName() << endl;

    playGame();

}
void Game::instructions() {}

void Game::displayStatus() {
    cout << player->getName() << "'s hand:" << endl;

    player->printHand();
}
