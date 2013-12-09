#ifndef CARDGAME_HPP
#define CARDGAME_HPP


#include "card.hpp"
#include "player.hpp"
#include <vector>
#include <stack>


namespace cg {


class CardGame
{
public:
    CardGame();
    ~CardGame();
public:
    int init();
    void start();
private:
    int addPlayer(const Player&);
    int initStackCards();
    int dispenceCards();
    bool isPlayerEmpty();
    int goPlayer();
    int nextPlayer();
    //Card takeCardFomDesk();
private:
    static std::vector<Card> _deck;
    std::vector<Card> _stack;
    std::vector<Card> _heap;
    std::vector<Card> _field;
    std::vector<Player> _players;
    unsigned int _currentPlayer;
    static unsigned int _totalNumCards;
    static unsigned int _numPlayers;
};


} /* namespace cg */

#endif // CARDGAME_HPP
