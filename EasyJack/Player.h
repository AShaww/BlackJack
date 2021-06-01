//
// Created by AmirS on 26/05/2021.
//

#pragma once

class Player{

public:
    Player();
    ~Player();
    int getPlayerHandValue();
    string getName();
    void setName(string);
    vector<Card*>& getHand();

    void hit(Card *card);
    void showHand();
    bool hasBlackJack();
    void clearHand();
private:
    const int _MaxCardsPerHand = 11; //11 cards maximum, four ace's, four 2's, three three's. = 21
    vector<Card*> hand;
    int handTotal;
    string name;
};

Player::Player() {
    hand.reserve(_MaxCardsPerHand);
}

Player::~Player() {
    for(Card* card : hand)
    {
        delete (card);
    }
    hand.clear();
}

void Player::clearHand(){
    hand.clear();
}

vector<Card*>& Player::getHand(){
    return this->hand;
}

int Player::getPlayerHandValue() {
    int value = 0;
    int numOfAces = 0;

    if (hand.empty()) {
        return 0;
    }

    for (int i = 0; i < hand.size(); i++) {
        Card *card = hand[i];

        if (card->getValue() == ACE) {
            numOfAces += 1;
        }
        handTotal = value += card->getValue();
    }
    return handTotal;
}

string Player::getName()  {
    return this->name;
}

void Player::setName(string name) {
    this->name = name;
}

void Player::hit(Card* card) {
    hand.push_back(card);
}

void Player::showHand() {
    for (Card *c : hand)
    {
        c->printCard( c);
    }
}

bool Player::hasBlackJack(){
    for (int i = 0; i < hand.size(); i++)
    {
        if(hand[i]->getValue() == ACE)
        {
            for(int i = 0; i < hand.size(); i++)
            {
                if(hand[i]->getValue() == 10)
                {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    return false;
}

