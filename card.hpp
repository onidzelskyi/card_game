#ifndef CARD_HPP
#define CARD_HPP


namespace cg {


enum class suit : unsigned char {
    CLUBS
    , DIAMONDS
    , HEARTS
    , SPADES
};




class Card {
public:
    Card();
    ~Card();
public:
    static Card generateCard();
private:

};


}


#endif // CARD_HPP
