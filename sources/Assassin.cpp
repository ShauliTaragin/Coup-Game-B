//
// Created by shaul on 24/04/2022.
//
#include "Assassin.hpp"

namespace coup{

    void Assassin::coup(Player& player1) {
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        if(this->Coins >= 7){
            this->Coins-=7;
            p_game->remove_player(player1.name);
            p_game->Bank_of_Actions.at(p_game->player_position(name))
                    = "coup "+player1.name;
            p_game->change_Turn();
            return;
        }
        if(this->Coins < 3){
            throw invalid_argument("Not enough coins to do this action");
        }
        p_game->Bank_of_Actions.at(p_game->player_position(name))
                = "0coup "+player1.name;
        this->Coins-=3;
        action_on_him = &player1;
        p_game->remove_player(player1.name);
        p_game->change_Turn();
    }
}