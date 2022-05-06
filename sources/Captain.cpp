//
// Created by shaul on 24/04/2022.
//
#include "Captain.hpp"
namespace coup{

    void Captain::block(Player & player1) {
    }

    void Captain::steal(Player &player1) {
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        player1.Coins-=2;
        this->Coins +=1;
        //changing the turn to the next player
        string player_which_played = p_game->Turns.front();
        p_game->Turns.pop();
        p_game->Turns.push(player_which_played);
        p_game->Bank_of_Actions.at(p_game->player_position(name))
                = "steal "+player1.name;
    }
}
