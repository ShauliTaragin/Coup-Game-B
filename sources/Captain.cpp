//
// Created by shaul on 24/04/2022.
//
#include "Captain.hpp"
namespace coup{

    void Captain::block(Player & player1) {
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

    void Captain::steal(Player &player1) {
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        if(player1.Coins == 0){
            return;
        }
        if (player1.Coins == 1){
            player1.Coins-=1;
            this->Coins +=1;
            p_game->Bank_of_Actions.at(p_game->player_position(name))
                    = "1steal "+player1.name;
        }
        else {
            player1.Coins -= 2;
            this->Coins +=2;
            p_game->Bank_of_Actions.at(p_game->player_position(name))
                    = "2steal "+player1.name;
        }
        action_on_him = &player1;
        //changing the turn to the next player
        string player_which_played = p_game->Turns.front();
        p_game->Turns.pop();
        p_game->Turns.push(player_which_played);
        p_game->change_Turn();
    }
}
