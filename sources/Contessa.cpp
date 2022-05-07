//
// Created by shaul on 24/04/2022.
//
#include "Contessa.hpp"

namespace coup {

    void Contessa::block(Player& player1) {
        if(player1.action_on_him== nullptr){
            throw invalid_argument("nothing to block");
        }
        size_t i = p_game->player_position(player1.name);
        if(p_game->Bank_of_Actions.at(i)[0]!='0'){
            throw invalid_argument("couped with 7 cannot block");
        }
        p_game->alive.at(p_game->player_position(player1.action_on_him->name))=true;

    }
}
