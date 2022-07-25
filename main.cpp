/**********************************************************
* AUTHOR : Navid A. Ehyaee
**********************************************************/

/**********************************************************
 This program allows for a game of Tic Tac Toe in single/ multiplayer mode.


Variable;
     char array[3][3;

     //The follwoing variables store X/O characters in each row/column/diagonal
     int row_1_X = 0;
     int row_2_X = 0;
     int row_3_X = 0;
     int row_1_O = 0;
     int row_2_O = 0;
     int row_3_O = 0;
     int col_1_X = 0;
     int col_2_X = 0;
     int col_3_X = 0;
     int col_1_O = 0;
     int col_2_O = 0;
     int col_3_O = 0;
     int diag_RL_X = 0;
     int diag_RL_O = 0;
     int diag_LR_X = 0;
     int diag_LR_O = 0;

     string playerX = " "; //name of player X
     string playerO = " "; //name of player O
     char selection = ' '; //selection of the user
     char token = 'X';     //token used to indicated players turn. Initially set to X for player X.
     char winner;          //token value of the winner or the tie or undetermined status of the game


 **********************************************************/

#include "function.h"

#include "function.cpp"

int main()
{

     char array[3][3];

     //The follwoing variables are all CALC and are self explanatory(they store X/O characters in each row/column/diagonal)
     int row_1_X = 0;
     int row_2_X = 0;
     int row_3_X = 0;
     int row_1_O = 0;
     int row_2_O = 0;
     int row_3_O = 0;
     int col_1_X = 0;
     int col_2_X = 0;
     int col_3_X = 0;
     int col_1_O = 0;
     int col_2_O = 0;
     int col_3_O = 0;
     int diag_RL_X = 0;
     int diag_RL_O = 0;
     int diag_LR_X = 0;
     int diag_LR_O = 0;

     string playerX = " "; //name of player X
     string playerO = " "; //name of player O
     char selection = ' '; //selection of the user
     char token = 'X';     //token used to indicated players turn. Initially set to X for player X.
     char winner;          //token value of the winner or the tie or undetermined status of the game

     
     cout << "Welcome To Navid's Game:" << endl
          << endl;

     //instructions for the game is outputted.
     OutputInstruct();
     //selection is error checked.
     while (!(cin >> selection))
     {
          cin.clear();
          cin.ignore(1000, '\n');
          cout << "Invalid input. Please Try Again;" << endl
               << endl;
          OutputInstruct();
     }
     cin.ignore(1000, '\n'); //empty the buffer,

     //main loop of the game. WHile exit is not selected, loop continues.
     while (selection != 'a')
     {

          system("cmd /c cls"); //screan is cleared at the beginning for a fresh start.

          //setup of the names selection
          if (selection == 'b' || selection == 'B')
          {
               GetPlayers(playerX, playerO);
          }
          //multiplayer selection
          else if (selection == 'c' || selection == 'C')
          {
               //board is initialized to empty spaces
               InitBoard(array);

               //is the users didnt set up their names first
               if (playerO == " " || playerX == " ")
               {
                    GetPlayers(playerX, playerO);
               }

               winner = CheckWin(array); //check the status of the game

               //while is game is not done
               while (winner == 'U')
               {
                    DisplayBoard(array); //board is displyed.

                    //a players move is done
                    GetAndCheckInp(array, token, playerX, playerO);

                    //current player switches
                    token = SwitchToken(token);

                    //check the status of the game
                    winner = CheckWin(array);
               }
               DisplayBoard(array); //final board is displyed.

               //winner or a tie is determined below.
               if (winner == 'X')
               {
                    cout << playerX << " Won!" << endl
                         << endl;
               }
               else if (winner == 'O')
               {
                    cout << playerO << " Won!" << endl
                         << endl;
               }
               else
               {
                    cout << "The game was a tie!" << endl
                         << endl;
               }
          }

          //Single player selection
          else if (selection == 'd' || selection == 'D')
          {
               //the game board array is initialized to spaces
               InitBoard(array);
               //if the user didnt set up a name first
               if (playerO == " ")
               {
                    //name inputting and check for errors is done here.
                    cout << "What is your name?(O): ";
                    //error checking getline is not neccessary?
                    while (!(getline(cin, playerO)))
                    {
                         cin.clear();
                         cin.ignore(1000, '\n');
                         cout << "What is your name?(O): ";
                    }
               }

               winner = CheckWin(array); //check the status of the game

               //while the game is not done
               while (winner == 'U')
               {
                    DisplayBoard(array);                          //display the game board
                    GetAndCheckInp(array, 'O', playerX, playerO); //only playO is allowed to play since the X player is PC.

                    //board variables are updated for the singleplayer function to use.
                    updateVariables(array,
                                    row_1_X,
                                    row_2_X,
                                    row_3_X,
                                    row_1_O,
                                    row_2_O,
                                    row_3_O,
                                    col_1_X,
                                    col_2_X,
                                    col_3_X,
                                    col_1_O,
                                    col_2_O,
                                    col_3_O,
                                    diag_RL_X,
                                    diag_RL_O,
                                    diag_LR_X,
                                    diag_LR_O);

                    //computer makes an intelligent move
                    singlePlayer(array,
                                 row_1_X,
                                 row_2_X,
                                 row_3_X,
                                 row_1_O,
                                 row_2_O,
                                 row_3_O,
                                 col_1_X,
                                 col_2_X,
                                 col_3_X,
                                 col_1_O,
                                 col_2_O,
                                 col_3_O,
                                 diag_RL_X,
                                 diag_RL_O,
                                 diag_LR_X,
                                 diag_LR_O);

                    winner = CheckWin(array); //check the status of the game
               }
               DisplayBoard(array); //final board is displyed.

               //winner or a tie is determined below.
               if (winner == 'X')
               {
                    cout << "The computer Won!" << endl
                         << endl;
               }
               else if (winner == 'O')
               {
                    cout << playerO << " Won!" << endl
                         << endl;
               }
               else
               {
                    cout << "The game was a tie!" << endl
                         << endl;
               }
          }
          else
          {
               cout << "Invalid Input. Please try again." << endl
                    << endl;
          }

          //line adjusment

          cout << endl
               << endl;
          OutputInstruct();
          while (!(cin >> selection))
          {
               cin.clear();
               cin.ignore(1000, '\n');
               cout << "Invalid input. Please Try Again;" << endl
                    << endl;
               OutputInstruct();
          }
          cin.ignore(1000, '\n');
     }
     system("cmd /c cls"); //screan is cleared
     cout << endl
          << endl
          << "Thanks for playing my game" << endl
          << "Press Enter to Close the windows.";
     cin.ignore(1000, '\n'); //to force the user to press enter to leave

     return 0;
}
