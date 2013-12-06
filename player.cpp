#include "player.hpp"
#include <algorithm>
#include <iostream>

namespace cg {


unsigned int Players::nextTurn = 0;
unsigned int Players::totalNumCards = 52;
unsigned int Players::playerNumCards = 6;
unsigned int Players::numPlayers = 2;


Player::Player()
{
}


Player::~Player() {}


int Player::init() {
    int err = EXIT_UNINIT;
    return err;
}

int Player::addCard(const Card& card) {
    int err = EXIT_ADD_CADR_FAIL;
    this->cards.push_back(card);
    return err;
}


bool Player::isEmpty() const {
    return this->cards.empty();
}
// ----------------------------------------------------


Players::Players()
    : currentPlayer(0)
{}


Players::~Players() {}


int Players::init() {
    int err = EXIT_UNINIT;
    for(unsigned int i=0; i<Players::numPlayers; ++i) {
        Player player;
        player.init();
        addPlayer(player);
    }
    for(unsigned int i=0; i<Players::playerNumCards; ++i) {
        std::for_each(players.begin(), players.end(), [](Player p){p.addCard(/*this->cardsStack.pop()*/Card());});
    }
    return err;
}


int Players::startGame() {
    int err = EXIT_UNINIT;
    while(!(this->isPlayerEmpty())) {
        this->goPlayer();
        this->nextPlayer();
    }
    return err;
}


bool Players::isPlayerEmpty() {
    std::cout << "test" << std::endl;
    return this->players.at(currentPlayer).isEmpty();
}


int Players::goPlayer() {
    int err = EXIT_SKIP_GO;
//#ifdef _DEBUG_
    std::cout << this->currentPlayer << "'s player turn" << std::endl;
//#endif
    return err;
}


int Players::nextPlayer() {
    int err = EXIT_NO_PLAYER;
    this->currentPlayer = (this->currentPlayer<(this->players.size()-1)) ? ++this->currentPlayer : 0;
    return err;
}


int Players::addPlayer(const Player& player) {
    int err = EXIT_NO_PLAYER;
    this->players.push_back(player);
    return err;
}


} // namespace cg
