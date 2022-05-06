//
// Created by shaul on 24/04/2022.
//

#include "Ambassador.hpp"
namespace coup {


    void Ambassador::block(Player & player1) {
        player1.action_on_him->Coins+=2;
        player1.Coins-=2;
        size_t i = p_game->player_position(player1.name);
        if(p_game->Bank_of_Actions.at(i)[0]=='1'){
            player1.action_on_him->Coins+=1;
            player1.Coins-=1;
        }
        else{
            player1.action_on_him->Coins+=2;
            player1.Coins-=2;
        }
    }

    void Ambassador::transfer(Player &player1, Player &player2) {
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        player1.Coins-=1;
        player2.Coins+=1;
        //changing the turn to the next player
        string player_which_played = p_game->Turns.front();
        p_game->Turns.pop();
        p_game->Turns.push(player_which_played);
        p_game->Bank_of_Actions.at(p_game->player_position(name))
        = "transfer "+player1.name+" "+player2.name;
        p_game->change_Turn();
    }
}