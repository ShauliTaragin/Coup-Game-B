//
// Created by shaul on 24/04/2022.
//


#include <iostream>
#include "Player.hpp"
using namespace std;
namespace coup{
    class Ambassador:public Player{
    public:
        Ambassador(Game & game, string player_name): Player(game,player_name){}
        void block(Player &);
        string role(){
            return "Ambassador";
        }
        void transfer(Player& player1 , Player& player2);
    };


}
