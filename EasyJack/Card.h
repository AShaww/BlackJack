//
// Created by AmirS on 25/05/2021.
//

#include "mainHeader.h"

enum Rank{
    ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};
enum Suit{
    HEARTS, DIAMONDS, CLUBS, SPADES
};

struct Card{
    Card();
    Card(Rank, Suit);
    static void printCard(Card*);
    int getValue() const;
    Rank rank;
    Suit suit;
};

Card::Card() {}
Card::Card(Rank rank, Suit suit): rank(rank), suit(suit) {}

int Card::getValue() const {
    int value = 0;
    while (true) {
        value = rank;
        if (value > 10) {
            value = 10;
        }
        return value;
    }
}

void Card::printCard(Card* card) {
    if (card->rank >= 0 && card->rank <= card->rank) {
        switch (card->rank) {
            case ACE:
                printf("%s of ", " ACE");
                break;
            case TWO:
                printf("%s of ", " TWO");
                break;
            case THREE:
                printf("%s of ", " THREE");
                break;
            case FOUR:
                printf("%s of ", " FOUR");
                break;
            case FIVE:
                printf("%s of ", " FIVE");
                break;
            case SIX:
                printf("%s of ", " SIX");
                break;
            case SEVEN:
                printf("%s of ", " SEVEN");
                break;
            case EIGHT:
                printf("%s of ", " EIGHT");
                break;
            case NINE:
                printf("%s of ", " NINE");
                break;
            case TEN:
                printf("%s of ", " TEN");
                break;
            case JACK:
                printf("%s of ", " JACK");
                break;
            case QUEEN:
                printf("%s of ", " QUEEN");
                break;
            case KING:
                printf("%s of ", " KING");
                break;
        }
        switch (card->suit) {
            case HEARTS:
                puts("HEARTS");
                break;
            case SPADES:
                puts("SPADES");
                break;
            case DIAMONDS:
                puts("DIAMONDS");
                break;
            case CLUBS:
                puts("CLUBS");
                break;
        }
    }
}

