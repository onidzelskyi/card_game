#include "card.hpp"


namespace cg {


Card::Card(suit s, court c)
    : _value(0x1F0A)
    , _suit(s)
    , _court(c)
{
}


Card::~Card()
{
}

/*
Card Card::generateCard() {
    return Card();
}
*/

} /* namespace cg */
