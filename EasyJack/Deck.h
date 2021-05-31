//
// Created by AmirS on 25/05/2021.
//

#include "Card.h"
#include "Player.h"

#pragma once

class Deck{
public:
    Deck();
    ~Deck();
    void shuffle();
    void initialiseDeck();
    void giveTopCardTo(Player* pPlayer);
    vector<Card*>& getDeckOfCards();
private:
    const int _deckSize = 52;
    vector<Card*> deck;
};

Deck::Deck() {
    deck.reserve(_deckSize);
    initialiseDeck();
}

Deck::~Deck() {
    for (Card *c : deck) {
        delete (c);
    }
    deck.clear();
}

void Deck::initialiseDeck() {
    for (int suit = HEARTS; suit <= SPADES; ++suit)
    {
        for (int rank = ACE; rank <= KING; ++rank)
        {
            suit = Suit(suit);
            rank = Rank(rank);
            deck.push_back(new Card(static_cast<Rank>(rank), static_cast<Suit>(suit)));
        }
    }
    shuffle();
}

void Deck::giveTopCardTo(Player* pPlayer) {
    Card* card = deck.front();
    pPlayer->hit(card);
    deck.erase(deck.begin());
}

void Deck::shuffle() {
    srand(time(NULL));
    random_shuffle(deck.begin(), deck.end());
}

vector<Card*>& Deck::getDeckOfCards() {
    return this->deck;
}

