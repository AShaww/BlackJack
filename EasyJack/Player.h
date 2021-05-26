//
// Created by AmirS on 26/05/2021.
//

#pragma once

class Player{

public:
    Player();
    ~Player();
    int gethandTotal();
    string getName();
    vector<Card*> getHand();
    void sethandTotal(int);
    void setName(string);
    void getCard(Card*);
    void printHand();


private:
    vector<Card*> hand;
    int handTotal;
    string name;
};

Player::Player() {
    hand.reserve(11);
}

Player::~Player() {
    for(Card* card : hand)
    {
        delete (card);
    }
    hand.clear();
}

vector<Card*> Player::getHand(){
    return this->hand;
}

int Player::gethandTotal() {
    return this->handTotal;
}

void Player::sethandTotal(int handTotalIn) {
    this->handTotal = handTotalIn;
}

string Player::getName()  {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}
void Player::getCard(Card* card) {
    hand.push_back(card);
}
void Player::printHand() {
    for (Card *c : hand)
    {
        c->printCard(c);
    }
}
