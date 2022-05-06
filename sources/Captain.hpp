//
// Created by shaul on 24/04/2022.
//

#include <iostream>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Captain:public Player{
    public:
        Captain(Game & game, string player_name): Player(game,player_name){}
        void block(Player &);
        string role(){
            return "Captain";
        }
        void steal(Player& player1);
    };


}