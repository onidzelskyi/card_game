#include "cardgame.hpp"
#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>


namespace cg {


unsigned int CardGame::_totalNumCards = 52;
unsigned int CardGame::_numPlayers = 2;
std::vector<Card> CardGame::_deck = {
    Card(suit::CLUBS, court::TWO), Card(suit::CLUBS, court::THREE)
    , Card(suit::DIAMONDS, court::TWO)
    , Card(suit::HEARTS, court::TWO)
    , Card(suit::SPADES, court::TWO)
};


CardGame::CardGame()
    : _currentPlayer(0)
{
}


CardGame::~CardGame()
{
}


int CardGame::init() {
    int err = EXIT_UNINIT;

    this->_players.clear();
    this->_stack.clear();
    this->_heap.clear();
    this->_field.clear();

    for(unsigned int i=0; i<CardGame::_numPlayers; ++i) {
        Player player;
        player.init();
        this->addPlayer(player);
    }
    return err;
}


void CardGame::start() {
    this->initStackCards();
    this->dispenceCards();
    while(!(this->isPlayerEmpty())) {
        this->goPlayer();
        this->nextPlayer();
    }
}


int CardGame::addPlayer(const Player& player) {
    int err = EXIT_UNINIT;
    this->_players.push_back(player);
    return err;
}


int CardGame::initStackCards() {
    int err = EXIT_UNINIT;

    //!<
    //!< shuffle the desk
    //!<
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->_deck.begin(), this->_deck.end(), g);

#ifdef _DEBUG_
    copy(this->_deck.begin(), this->_deck.end(), std::ostream_iterator<Card>(std::cout, " "));
    std::cout << "\n";
#endif

    //!<
    //!< copy desk to stack
    //!<
    std::copy(this->_deck.begin(), this->_deck.end(), this->_stack.begin());
    return err;
}


int CardGame::dispenceCards() {
    int err = EXIT_UNINIT;
    return err;
}


bool CardGame::isPlayerEmpty() {
    return this->_players.at(_currentPlayer).isEmpty();
}


int CardGame::goPlayer() {
    int err = EXIT_SKIP_GO;
#ifdef _DEBUG_
    std::cout << this->_currentPlayer << "'s player turn" << std::endl;
#endif
    return err;
}


int CardGame::nextPlayer() {
    int err = EXIT_NO_PLAYER;
    this->_currentPlayer = (this->_currentPlayer<(this->_players.size()-1)) ? ++this->_currentPlayer : 0;
    return err;
}

/*
Card CardGame::takeCardFomDesk() {
    Card card(suit::DIAMONDS, court::TWO);
    return card;
}
*/

} /* namespace cg */
