//
// Created by shaul on 24/04/2022.
//
#pragma once
#include <iostream>
#include "Game.hpp"
using namespace std;
namespace coup{
    class Player{
    public:
        Game * p_game;
        string name;
        int Coins;
        Player * action_on_him;
        Player(Game& game, string player_name);

        //Now the 3 actions each player can execute in each turn
        Player& income();
        Player& foreign_aid();
        virtual void coup(Player);
        virtual string role(){
            return Player::name;
        }
        string get_name(){
            return name;
        }
        int coins(){
            return Player::Coins;
        }
    };


}