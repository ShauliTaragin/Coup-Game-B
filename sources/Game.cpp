//
// Created by shaul on 24/04/2022.
//
#include "Game.hpp"
using namespace std;
namespace coup{

    //I want to add a function to change to next player which its his turn meaninig is alive


    Game::Game() {
    }

    //Now the 3 Generic methods a game needs to support
    string Game::turn(){
        return Turns.front();
    }
    vector<string> Game::players() {
        vector<string> temp_players;
        for (size_t i = 0; i < alive.size() ; ++i) {
            if (alive.at(i)){
                temp_players.push_back(Players.at(i));
            }
        }
        return temp_players;
    }

    //changed this according to having boolean for each player if hes alive or not
    string Game::winner(){
        vector<string> temp_players;
        for (size_t i = 0; i < alive.size() ; ++i) {
            if (alive.at(i)){
                temp_players.push_back(Players.at(i));
            }
        }
        if (temp_players.size()!=1){
            throw invalid_argument("no winner yet!");
        }
        return temp_players.front();
    }

    void Game::remove_player(string player_name) {
        size_t i = player_position(player_name);
        alive.at(i) = false;
//        Players.erase(std::remove(Players.begin(), Players.end(), player_name), Players.end());
//
//        //not sure about deletion
//        this->Bank_of_Actions.erase(Bank_of_Actions.begin() + static_cast<long>(i));
//        //now delete him from turns
//        queue<string> temp;
//        while(!Turns.empty()){
//            string curr = Turns.front();
//            Turns.pop();
//            if (curr!=player_name){
//                temp.push(curr);
//            }
//        }
//        while(!temp.empty()){
//            string curr = temp.front();
//            temp.pop();
//            Turns.push(curr);
//        }
    }

    size_t Game::player_position(string player_name) {
        size_t position =0;
        for (size_t i = 0; i < Players.size() ; ++i) {
            if(Players.at(static_cast<unsigned long>(i)) == player_name){
                position = i;
                return position;
            }
        }
        throw invalid_argument("this player is not in the game");
    }
}

