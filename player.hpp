#ifndef PLAYER_HPP
#define PLAYER_HPP


#include "card.hpp"
#include <vector>
#include <stack>


namespace cg {


enum {
    EXIT_ADD_CADR_FAIL
    , EXIT_UNINIT
    , EXIT_SKIP_GO
    , EXIT_NO_PLAYER
};


static unsigned int nextTurn = 0;
static unsigned int numCards = 52;


class Player {
public:
    Player();
    ~Player();
public:
    int init();
    int addCard(const Card&);
    bool isEmpty() const;
private:
    std::vector<Card> cards;
};
/*

class Players {
public:
    Players();
    ~Players();
public:
    int init();
    int startGame();
private:
    int addPlayer(const Player&);
    int initStackCards();
    int dispenceCards();
    bool isPlayerEmpty();
    int goPlayer();
    int nextPlayer();
    const Card& popCardFromStack();
private:
    std::stack<Card> cardsStack;
    std::vector<Card> heap;
    std::vector<Card> field;
    std::vector<Player> players;
    unsigned int currentPlayer;
    static unsigned int nextTurn;
    static unsigned int totalNumCards;
    static unsigned int playerNumCards;
    static unsigned int numPlayers;
};
*/

} // namespace cg


#endif // PLAYER_HPP
