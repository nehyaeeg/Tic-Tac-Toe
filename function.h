/**********************************************************
* AUTHOR : Navid A. Ehyaee
**********************************************************/

#ifndef FUNCTION_H_
#define FUNCTION_H_
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <ctime>   //extra
#include <sstream> //extra
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//this function allows for printing the header directly to output files(name of file)or console(cout): No return value
void PrintHeader(char labOrAssignment,     // type of assignemnt
                 int assignmentnumber,     // number of the lab or exercise
                 string nameOfAssignment,  // name of the assignment
                 ostream &streamVariable); //type of stream variable indicating output;

/**********************/
/*This function outputs instructions to the users. 
There are no input or output parameters for this function as it only displays text to
the screen. RETURNS: nothing. Displays the instructions to the user*/
void OutputInstruct();

/******************/
//this function initializes the game board to spaces to begin with.
//No return value. Board is initialized.
void InitBoard(char boardAr[][3]); // OUT - tic tac toe board

/***************************/
//This fucntion is provided in the class and it diplays the game board.
//Returns nothing but game board is outputted.
void DisplayBoard(const char boardAr[][3]); //IN-OUT Game array

/***************************/
//this function prompts the user to input the names of the players.
void GetPlayers(string &playerX,  // IN_OUT - player X’s name
                string &playerO); //IN_OUT - player O’x name

/***************************/
//this function asks for the location to be used for each player and
// after checking the availibilty, fills the location with the correct token.
void GetAndCheckInp(char boardAr[][3], //CALC: game array
                    char token,        //CALC: current token at play
                    string playerX,    //IN:name of playerX
                    string playerO);   //IN: name of playerO

/***************************/
//This function receives as input a token, and returns the opposite token and keep the game cycle going.
//returns a char token
char SwitchToken(char token); //IN- current token of player

/***************************/
//This fucntion check the status of the game.
//if the game has been won by a player, the token of the player is returned. Otherwise t for tie or u for undetermined is returned.
//because of the way the prototype was defined and we were not allowed to add parameters, the 16 varables storing info about the game
//are defined again and used again.
//It return X or O or T or U to indicate the status of the game.
char CheckWin(const char array[][3]); // IN - tic tac toe board

/***************************/
//This function crawls the game array and gathers information about the number of X/O in each row/col/diag.
//no return value but variables are updated by reference and are used by the singleplayer function below to allow computer play the opponent.
void updateVariables(char array[][3], // CALC: game array
                     int &row_1_X,
                     int &row_2_X,
                     int &row_3_X,
                     int &row_1_O,
                     int &row_2_O,
                     int &row_3_O,
                     int &col_1_X,
                     int &col_2_X,
                     int &col_3_X,
                     int &col_1_O,
                     int &col_2_O,
                     int &col_3_O,
                     int &diag_RL_X,
                     int &diag_RL_O,
                     int &diag_LR_X,
                     int &diag_LR_O);

/***************************/
/*This function Extremely Brute Forces the game. First an attacking mode checks if winning at this stage winning is possible,
if not it switches to a defensive mode that tries to block the other player from winning. If defense is not needed, it will switch
to another attacking mode that tries to steer the game towards winning in the future iterations by attacking instead of defending.
No return value but the board is updated by playing*/
void singlePlayer(char array[][3], //CALC: game array
                  int &row_1_X,    //CALC: all the variables below store X/O in each row/column/diagonal.
                  int &row_2_X,
                  int &row_3_X,
                  int &row_1_O,
                  int &row_2_O,
                  int &row_3_O,
                  int &col_1_X,
                  int &col_2_X,
                  int &col_3_X,
                  int &col_1_O,
                  int &col_2_O,
                  int &col_3_O,
                  int &diag_RL_X,
                  int &diag_RL_O,
                  int &diag_LR_X,
                  int &diag_LR_O);
#endif
