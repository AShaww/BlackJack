//
// Created by AmirS on 25/05/2021.
//

#ifndef EASYJACK_PLAYER_H
#define EASYJACK_PLAYER_H

class Player{
public:
    Player(string&, vector<Card*>);
    ~Player();

    const string &getName() const;
    void setName(const string);

    int getHandTotal() const;
    void setHandTotal(int);
    void printHand();

    vector<Card*> getHand();
private:
    vector<Card*> hand;
    string name;
    int handTotal;
};

Player::Player(string& name, vector<Card*> pVector) {
    this->name = "";
    this->hand = pVector;
}

Player::~Player() {
    for (Card *c : hand)
    {
        delete (c);
    }
    hand.clear();
}

vector<Card*> Player::getHand() {
    return this->hand;
}

const string& Player::getName() const{
    return name;
}
void Player::setName(const string nameIn){
    name = nameIn;
}

int Player::getHandTotal() const{
    return handTotal;
}
void Player::setHandTotal(int handTotalIn){
    handTotal = handTotalIn;
}

void Player::printHand(){
    for(Card *c : hand)
    {
        c->printCard(c);
    }
}

#endif //EASYJACK_PLAYER_H
