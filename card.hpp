#ifndef CARD_HPP
#define CARD_HPP


#include <iostream>


namespace cg {


enum class suit : unsigned char {
    CLUBS
    , DIAMONDS
    , HEARTS
    , SPADES
};


enum class court : unsigned char {
    TWO
    , THREE
    , FOUR
    , FIVE
    , SIX
    , SEVEN
    , EIGHT
    , NINE
    , TEN
    , JACK
    , QUEEN
    , KING
    , ACE
};


class Card {
public:
    explicit Card(suit, court);
    ~Card();
public:
    //static Card generateCard();
public:
    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        os << card._value;
        return os;
    }
//private:
    unsigned short _value;
    suit _suit;
    court _court;
};


}


#endif // CARD_HPP
