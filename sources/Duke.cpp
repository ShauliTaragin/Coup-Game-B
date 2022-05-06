//
// Created by shaul on 24/04/2022.
//
#include "Duke.hpp"
namespace coup{

    void Duke::block(Player& player1) {
        if(p_game->Bank_of_Actions.at(p_game->player_position(player1.get_name()))!="foreign_aid" ){
            throw invalid_argument("Can't block something that didnt happen");
        }
        player1.Coins-=2;
    }

    void Duke::tax() {
        //throw if not his turn
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        this->Coins+=3;
        //changing the turn to the next player
        string player_which_played = p_game->Turns.front();
        p_game->Turns.pop();
        p_game->Turns.push(player_which_played);
        p_game->Bank_of_Actions.at(p_game->player_position(name)) = "tax" ;
    }
}

