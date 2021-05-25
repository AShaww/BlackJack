//
// Created by AmirS on 25/05/2021.
//

#ifndef EASYJACK_CARDOFCARDS_H
#define EASYJACK_CARDOFCARDS_H

class Deck{
public:
    Deck();
    ~Deck();
    void shuffle();
    void initialiseDeck();
    void printDeck();
    Card* getTopCard();
    void popCard();
    vector<Card*> getDeckOfCards();
private:
    const int SIZE = 52;
    vector<Card*> deck;
};

Deck::Deck() {
    deck.reserve(SIZE);
    initialiseDeck();
    shuffle();
}
void Deck::printDeck() {
    for (Card *c : deck) {
        Card::printCard(c);
    }
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
}

Card* Deck::getTopCard(){
    return deck.front();
}

void Deck::popCard(){
    deck.push_back(deck.front());
    deck.erase(deck.begin());
}

void Deck::shuffle() {
    srand(time(NULL));
    random_shuffle(deck.begin(), deck.end());
}

vector<Card*> Deck::getDeckOfCards() {
    this->shuffle();
    return this->deck;
}

#endif //EASYJACK_CARDOFCARDS_H
