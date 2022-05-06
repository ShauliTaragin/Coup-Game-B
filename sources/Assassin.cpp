//
// Created by shaul on 24/04/2022.
//
#include "Assassin.hpp"

namespace coup{

    Player &Assassin::coup(Player& player1) {
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        if(this->Coins < 3){
            throw invalid_argument("Not enough coins to do this action");
        }
        this->Coins-=3;
        action_on_him = &player1;
        p_game->remove_player(player1.name);
        return *this;
    }
}