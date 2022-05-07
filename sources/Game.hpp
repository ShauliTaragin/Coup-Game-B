//
// Created by shaul on 24/04/2022.
//
#pragma once
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
namespace coup{
    class Game{
    public:
        vector<string> Players;
        vector<bool> alive;
        queue<string> Turns;
        vector<string> Bank_of_Actions;
        bool started = true;
        /* income
         * foreign_aid
         * coup player_name
         * tax
         * block player_name
         * transfer player1 player2
         * steal player
         *
         */
        //need to add game vector which shows for each player what move he did
        Game();
        string turn();
        vector<string> players();
        string winner();
        void remove_player(string const & player_name);
        size_t player_position(string const &  player_name);
        void change_Turn();
        bool is_player_alive(string const & player_name);
        //other methods we need for game:
        //next() -> perhaps runned by a queue
        //remove ->removing player perhaps from queue and vector

    };

}
