//
// Created by shaul on 24/04/2022.
//
#include <iostream>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Contessa:public Player{
    public:
        Contessa(Game & game, string  player_name): Player(game,player_name){}
        void block(Player &);
        string role(){
            return "Contessa";
        }
    };


}
