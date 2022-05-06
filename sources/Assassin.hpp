//
// Created by shaul on 24/04/2022.
//

#include <iostream>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Assassin:public Player{
    public:
        Assassin(Game & game, string player_name): Player(game,player_name){}
        Player& coup(Player& player1);
        string role(){
            return "Assassin";
        }
    };


}
