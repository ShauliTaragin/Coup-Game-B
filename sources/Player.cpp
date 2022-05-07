//
// Created by shaul on 24/04/2022.
//
#include <iostream>
#include "Player.hpp"
using namespace std;
namespace coup{
    int seven = 7;
    Player::Player(Game & current_game, string player_name) : p_game(&current_game),
                                                              name(player_name) , Coins(0){
        if(current_game.Players.size()>seven-2){
            throw invalid_argument("No Room for more Players");
        }
        if(!p_game->started){
            throw invalid_argument("game already started");
        }
        current_game.Players.push_back(player_name);//adding player to game
        current_game.alive.push_back(true);//adding player to game
        current_game.Turns.push(player_name);
        current_game.Bank_of_Actions.push_back("entered");
        action_on_him = nullptr;
    }
    //Now the 3 actions each player can execute in each turn
    Player &Player::income() {
        //maybe need to add here and in forign aid check if this player is alive
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        if(p_game->Players.size()<2){
            throw invalid_argument("No game yet");
        }
        //throw if not his turn
        this->Coins++;
        //possibly add to game array the action this player took
        //changing the turn to the next player
        string player_which_played = p_game->Turns.front();
        p_game->Turns.pop();
        p_game->Turns.push(player_which_played);
        p_game->Bank_of_Actions.at(p_game->player_position(name)) = "income" ;
        p_game->change_Turn();
        p_game->started = false;
        return *this;
    }
    Player &Player::foreign_aid() {
        if(this->Coins>=10){
            throw invalid_argument("Has more then 10 coins");
        }
        //throw if not his turn
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        if(p_game->Players.size()<2){
            throw invalid_argument("not enough players");
        }
        this->Coins+=2;
        //changing the turn to the next player
        string player_which_played = p_game->Turns.front();
        p_game->Turns.pop();
        p_game->Turns.push(player_which_played);
        p_game->Bank_of_Actions.at(p_game->player_position(name)) = "foreign_aid" ;
        p_game->change_Turn();
        return *this;
    }

    void Player::coup(Player player2) {
        if(!p_game->is_player_alive(player2.name)){
            throw invalid_argument("player already dead");
        }
        if(p_game->Turns.front()!=this->name){
            throw invalid_argument("Not your turn");
        }
        if(this->Coins < seven){
            throw invalid_argument("Not enough coins to do this action");
        }
        p_game->Bank_of_Actions.at(p_game->player_position(name))
                = "coup "+player2.name;
        this->Coins-=seven;
        p_game->remove_player(player2.name);
        //changing the turn to the next player
        string player_which_played = p_game->Turns.front();
        p_game->Turns.pop();
        p_game->Turns.push(player_which_played);
        p_game->change_Turn();
    }




}
