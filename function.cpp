/**********************************************************
* AUTHOR : Navid Ehyaeeghodraty
**********************************************************/

#include "function.h"

/***************************/
//this function allows for printing the header directly to output files or console based on the parameter passed: No return value
void PrintHeader(char labOrAssignment,    // type of assignemnt
                 int assignmentnumber,    // number of the lab or exercise
                 string nameOfAssignment, // name of the assignment
                 ostream &streamVariable) //type of stream variable indicating output
{
    // USED FOR CLASS HEADING – OUTPUT
    const string PROGRAMMER = "Navid Ehyaeeghodraty";
    const string CLASS = "CS1B";
    const string SECTION = "MW: 7:30p - 9:50p";
    int width;
    string typeOfAssignment;
    int spaceadjuster; // number of spaces needed for lineup from the 2 options below

    if (toupper(labOrAssignment) == 'L')
    {
        typeOfAssignment = "* Lab #";
        spaceadjuster = 7;
    }
    else
    {
        typeOfAssignment = "* Assignment #";
        spaceadjuster = 14;
    }

    // OUTPUT – Class Heading
    streamVariable
        << left;
    streamVariable << "**************************************************" << endl;
    streamVariable << setw(17) << "* PROGRAMMED BY"
                   << " : " << PROGRAMMER << endl;
    streamVariable << setw(17) << "* CLASS"
                   << " : " << CLASS << endl;
    streamVariable << setw(17) << "* SECTION"
                   << " : " << SECTION << endl;
    streamVariable << typeOfAssignment << setw(17 - spaceadjuster) << assignmentnumber << " : " << nameOfAssignment << endl;
    streamVariable << "**************************************************\n\n";
};

/**********************/
/*This function outputs instructions to the users. 
There are no input or output parameters for this function as it only displays text to
the screen. RETURNS: nothing. Displays the instructions to the user*/
void OutputInstruct()
{
    cout << "Please select an option:" << endl;
    cout << "a. Exit" << endl;
    cout << "b. Set Player Names" << endl;
    cout << "c. Multiplayer Game" << endl;
    cout << "d. Single Player Game" << endl;
}

/******************/
//this function initializes the game board to spaces to begin with.
//No return value. Board is initialized.
void InitBoard(char boardAr[][3]) // OUT - tic tac toe board
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            boardAr[i][j] = ' ';
        }
    }
}

/***************************/
//This fucntion is provided in the class and it diplays the game board.
//Returns nothing but game board is outputted.
void DisplayBoard(const char boardAr[][3]) //IN-OUT Game array
{
    system("cmd /c cls"); //screan is cleared

    int row = 0; //rows
    int col = 0; // columns

    //first layer of the display is created here. Setw() ensures correct alignment.
    cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";
    //for each row
    for (row = 0; row < 3; row++)
    {
        //TOP indeces of each board cell is shown here
        cout << setw(7) << "[" << row + 1 << "][1] | "
             << "[" << row + 1;
        cout << "][2] | "
             << "[" << row + 1 << "][3]" << endl;

        //a layer of only vertical dividers are outputted
        cout << setw(14) << "|" << setw(9) << "|" << endl;

        //go thru each columns and adjust the board table
        for (col = 0; col < 3; col++)
        {
            //different columns will have different game cells in them.
            switch (col)
            {
            case 0:
                cout << row + 1 << setw(9) << boardAr[row][col];
                cout << setw(4) << "|";
                break;
            case 1:
                cout << setw(4) << boardAr[row][col];
                cout << setw(5) << "|";
                break;
            case 2:
                cout << setw(4) << boardAr[row][col] << endl;
                break;
            default:
                cout << "ERROR!\n\n";
            }
        }

        cout << setw(14) << "|" << setw(10) << "|\n";
        //horizontal divider is putputted except for the last row.
        if (row != 2)
        {
            cout << setw(32) << "--------------------------\n";
        }
    }
    cout << endl
         << endl;
}

/***************************/
//this function prompts the user to input the names of the players.
void GetPlayers(string &playerX, // OUT - player X’s name
                string &playerO) // OUT - player O’x name
{
    //first name is requested and checked(although checking is not required with getline?)
    cout << "Please input the name of the first player(X): ";
    while (!(getline(cin, playerX)))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please input the name of the first player(X): ";
    }
    //first name is requested and checked(although checking is not required with getline?)
    cout << endl
         << "Please input the name of the second player(O): ";

    while (!(getline(cin, playerO)))
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Please input the name of the first player(O): ";
    }
}

/***************************/
//this function asks for the location to be used for each player and
// after checking the availibilty, fills the location with the correct token.
void GetAndCheckInp(char boardAr[][3], //game array
                    char token,        //current token at play
                    string playerX,    //name of playerX
                    string playerO)    //name of playerO
{
    int i, j;          //used as the row/col input from the user
    bool done = false; //used to signal successfull play
    bool correctInput; //used for making sure the input is correct
    while (!done)
    {
        //for plaerX
        if (token == 'X')
        {

            cout << playerX << "'s turn (X)! What's your play?: ";
            correctInput = false; //default to start the loop

            //input is validated
            while (!correctInput)
            {
                while (!(cin >> i) || !(cin >> j))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please use integers between 1 to 3." << endl;
                    cout << playerX << "'s turn (X)! What's your play?: ";
                }

                //correct range is checked here
                if ((i > 3 || i < 1) && (j > 3 || j < 1))
                {
                    cout << "Row and column are both out of range. Please use integers between 1 to 3" << endl;
                    cout << playerX << "'s turn (X)! What's your play?: ";
                }
                else if (i > 3 || i < 1)
                {
                    cout << "Row is out of range. Please use integers between 1 to 3" << endl;
                    cout << playerX << "'s turn ! What's your play?: ";
                }
                else if (j > 3 || j < 1)
                {
                    cout << "Column is out of range. Please use integers between 1 to 3" << endl;
                    cout << playerX << "'s turn(X)! What's your play?: ";
                }
                else
                {
                    correctInput = true;
                }
            }

            cin.ignore(1000, '\n');

            //if location is avaialbe baord is updated
            if (boardAr[i - 1][j - 1] == ' ')
            {
                boardAr[i - 1][j - 1] = 'X';
                done = true;
            }
            //if loaction is unavailable error is given.
            else
            {
                cout << "That location is not available. Please try again." << endl;
            }
        }
        //for playerO
        else if (token == 'O')
        {

            cout << playerO << "'s turn(O)! What's your play?: ";
            correctInput = false; //default to start the loop

            //input is validated
            while (!correctInput)
            {
                //input is validated
                while (!(cin >> i) || !(cin >> j))
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid input. Please use integers between 1 to 3." << endl;
                    cout << playerO << "'s turn(O)! What's your play?: ";
                }
                //correct range is checked here
                if ((i > 3 || i < 1) && (j > 3 || j < 1))
                {
                    cout << "Row and column are both out of range. Please use integers between 1 to 3" << endl;
                    cout << playerO << "'s turn(O)! What's your play?: ";
                }
                else if (i > 3 || i < 1)
                {
                    cout << "Row is out of range. Please use integers between 1 to 3" << endl;
                    cout << playerO << "'s turn(O)! What's your play?: ";
                }
                else if (j > 3 || j < 1)
                {
                    cout << "Column is out of range. Please use integers between 1 to 3" << endl;
                    cout << playerO << "'s turn(O)! What's your play?: ";
                }
                else
                {
                    correctInput = true;
                }
            }

            cin.ignore(1000, '\n');
            //if location is avaialbe baord is updated
            if (boardAr[i - 1][j - 1] == ' ')
            {
                boardAr[i - 1][j - 1] = 'O';
                done = true;
            }
            //if loaction is unavailable error is given.
            else
            {
                cout << "That location is not available. Please try again." << endl;
            }
        }
    }
}

/***************************/
//This function receives as input a token, and returns the opposite token and keep the game cycle going.
//returns a char token
char SwitchToken(char token) // IN - current player’s token ('X' or 'O')
{
    if (token == 'X')
    {
        token = 'O';
    }
    else if (token == 'O')
    {
        token = 'X';
    }
    return token;
}

/***************************/
//This fucntion check the status of the game.
//if the game has been won by a player, the token of the player is returned. Otherwise t for tie or u for undetermined is returned.
//because of the way the prototype was defined and we were not allowed to add parameters, the 16 varables storing info about the game
//are defined again and used again.
//It return X or O or T or U to indicate the status of the game.
char CheckWin(const char array[][3]) // IN - tic tac toe board
{                                    //all the variables below will store valuable information about the number of X/O in each row/column/diag
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
    char result; //X or O or T or U to be putputted.

    //variable i will be used to indicate both row and columns when needed.
    for (int i = 0; i < 3; i++)
    {
        //rows are checked first
        //first row
        if (array[0][i] == 'X')
        {
            row_1_X++;
        }
        else if (array[0][i] == 'O')
        {
            row_1_O++;
        }
        //second row
        if (array[1][i] == 'X')
        {
            row_2_X++;
        }
        else if (array[1][i] == 'O')
        {
            row_2_O++;
        }
        //third row
        if (array[2][i] == 'X')
        {
            row_3_X++;
        }
        else if (array[2][i] == 'O')
        {
            row_3_O++;
        }

        //columns are checked now
        //first column
        if (array[i][0] == 'X')
        {
            col_1_X++;
        }
        else if (array[i][0] == 'O')
        {
            col_1_O++;
        }
        //second column
        if (array[i][1] == 'X')
        {
            col_2_X++;
        }
        else if (array[i][1] == 'O')
        {
            col_2_O++;
        }
        //third column
        if (array[i][2] == 'X')
        {
            col_3_X++;
        }
        else if (array[i][2] == 'O')
        {
            col_3_O++;
        }
    }

    //Right to left diagonals are cheched now
    if (array[0][0] == 'X')
    {
        diag_RL_X++;
    }
    else if (array[0][0] == 'O')
    {
        diag_RL_O++;
    }
    if (array[1][1] == 'X')
    {
        diag_RL_X++;
        diag_LR_X++;
    }
    else if (array[1][1] == 'O')
    {
        diag_RL_O++;
        diag_LR_O++;
    }
    if (array[2][2] == 'X')
    {
        diag_RL_X++;
    }
    else if (array[2][2] == 'O')
    {
        diag_RL_O++;
    }
    //left to right diagonals are checked now
    if (array[0][2] == 'X')
    {
        diag_LR_X++;
    }
    else if (array[0][2] == 'O')
    {
        diag_LR_O++;
    }

    if (array[2][0] == 'X')
    {
        diag_LR_X++;
    }
    else if (array[2][0] == 'O')
    {
        diag_LR_O++;
    }

    //checking for winning begins here
    //whinning is defined as having 3 like char in the same row/column/diag

    //if X is winner
    if (row_1_X == 3 || row_2_X == 3 || row_3_X == 3 || col_1_X == 3 || col_2_X == 3 || col_3_X == 3 || diag_LR_X == 3 || diag_RL_X == 3)
    {
        result = 'X';
    }
    //if O is winner
    else if (row_1_O == 3 || row_2_O == 3 || row_3_O == 3 || col_1_O == 3 || col_2_O == 3 || col_3_O == 3 || diag_LR_O == 3 || diag_RL_O == 3)
    {
        result = 'O';
    }

    //if none of the above is true, then the game is eitehr a tie or undetermined yet.
    //if there is atleast 1 space availble, the game is undetermined. If not, it is a tie.
    else
    {
        //row and column for transversing the game board.
        int i = 0;
        int j = 0;
        bool undetermined = false;
        //this will check and see if there is any empty space available which means the game is not done:undetermined
        while (!undetermined && i < 3)
        {

            while (!undetermined && j < 3)
            {
                if (array[i][j] == ' ')
                {
                    undetermined = true;
                }
                j++;
            }
            j = 0; //to reset the inenr loop;
            i++;
        }
        if (undetermined == true)
        {
            result = 'U'; //for undetermined
        }
        //game is over without winning.
        else
        {
            result = 'T'; //for tie
        }
    }

    return result;
}

/***************************/
//This function crawls the game array and gathers information about the number of X/O in each row/col/diag.
//no return value but variables are updated by reference and are used by the singleplayer function below to allow computer play the opponent.
void updateVariables(char array[][3],
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
                     int &diag_LR_O)
{
    //initialized to zero to allow for summation.
    row_1_X = 0;
    row_2_X = 0;
    row_3_X = 0;
    row_1_O = 0;
    row_2_O = 0;
    row_3_O = 0;
    col_1_X = 0;
    col_2_X = 0;
    col_3_X = 0;
    col_1_O = 0;
    col_2_O = 0;
    col_3_O = 0;
    diag_RL_X = 0;
    diag_RL_O = 0;
    diag_LR_X = 0;
    diag_LR_O = 0;

    //variable i will be used to indicate both row and columns when needed.
    for (int i = 0; i < 3; i++)
    {
        //rows are checked first
        if (array[0][i] == 'X')
        {
            row_1_X++;
        }
        else if (array[0][i] == 'O')
        {
            row_1_O++;
        }
        if (array[1][i] == 'X')
        {
            row_2_X++;
        }
        else if (array[1][i] == 'O')
        {
            row_2_O++;
        }
        if (array[2][i] == 'X')
        {
            row_3_X++;
        }
        else if (array[2][i] == 'O')
        {
            row_3_O++;
        }

        //columns are checked now
        if (array[i][0] == 'X')
        {
            col_1_X++;
        }
        else if (array[i][0] == 'O')
        {
            col_1_O++;
        }
        if (array[i][1] == 'X')
        {
            col_2_X++;
        }
        else if (array[i][1] == 'O')
        {
            col_2_O++;
        }
        if (array[i][2] == 'X')
        {
            col_3_X++;
        }
        else if (array[i][2] == 'O')
        {
            col_3_O++;
        }
    }

    //Right to left diagonals are cheched now
    if (array[0][0] == 'X')
    {
        diag_RL_X++;
    }
    else if (array[0][0] == 'O')
    {
        diag_RL_O++;
    }
    if (array[1][1] == 'X')
    {
        diag_RL_X++;
        diag_LR_X++;
    }
    else if (array[1][1] == 'O')
    {
        diag_RL_O++;
        diag_LR_O++;
    }
    if (array[2][2] == 'X')
    {
        diag_RL_X++;
    }
    else if (array[2][2] == 'O')
    {
        diag_RL_O++;
    }
    //left to right diagonals are checked now
    if (array[0][2] == 'X')
    {
        diag_LR_X++;
    }
    else if (array[0][2] == 'O')
    {
        diag_LR_O++;
    }

    if (array[2][0] == 'X')
    {
        diag_LR_X++;
    }
    else if (array[2][0] == 'O')
    {
        diag_LR_O++;
    }
}

/***************************/
/*This function Extremely Brute Forces the game. First an attacking mode checks if winning at this stage winning is possible,
if not it switches to a defensive mode that tries to block the other player from winning. If defense is not needed, it will switch
to another attacking mode that tries to steer the game towards winning in the future iterations by attacking instead of defending.
No return value but the board is updated by playing*/
void singlePlayer(char array[][3], //game array
                  int &row_1_X,    //all the variables below store X/O in each row/column/diagonal.
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
                  int &diag_LR_O)
{

    //Computer is always 'X'.
    //*****************************************************************************
    //First Attacking Mode:
    //If any row/comun/diag has 2 X's and an empty spot, the spot is filled with X to win.
    //every row/col/diag is separately checked.

    bool done = false; // CALC; to signal while loop when to break for each else if below.
    //row 1 is checked
    if (row_1_X == 2 && row_1_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[0][i] == ' ')
            {
                array[0][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //row 2 is checked
    else if (row_2_X == 2 && row_2_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[1][i] == ' ')
            {
                array[1][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //row 3 is checked
    else if (row_3_X == 2 && row_3_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[2][i] == ' ')
            {
                array[2][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //column 1 is checked
    else if (col_1_X == 2 && col_1_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][0] == ' ')
            {
                array[i][0] = 'X';
                done = true;
            }
            i++;
        }
    }

    //column 2 is checked
    else if (col_2_X == 2 && col_2_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][1] == ' ')
            {
                array[i][1] = 'X';
                done = true;
            }
            i++;
        }
    }

    //column 3 is checked
    else if (col_3_X == 2 && col_3_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][2] == ' ')
            {
                array[i][2] = 'X';
                done = true;
            }
            i++;
        }
    }

    //diagonal right to left is check here

    else if (diag_RL_X == 2 && diag_RL_O == 0)
    {
        int i = 0;
        int j = 0;
        while (!done && i < 3)
        {
            if (array[i][j] == ' ')
            {
                array[i][j] = 'X';
                done = true;
            }
            //both col/row increase diaginally
            i++;
            j++;
        }
    }
    //diagonal left to right is check here
    else if (diag_LR_X == 2 && diag_LR_O == 0)
    {
        int i = 0;
        int j = 2;
        while (!done && i < 3)
        {
            if (array[i][j] == ' ')
            {
                array[i][j] = 'X';
                done = true;
            }
            //row is increased but column is decreased diagonally.
            i++;
            j--;
        }
    }
    //*****************************************************************************
    /*Defensive mode: This checks to see if the enemy is close to winning by having 2 O's in a row/col/diag.
    If yes, it blocks that row/col/diag.*/

    //row 1 is checked
    else if (row_1_O == 2 && row_1_X == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[0][i] == ' ')
            {
                array[0][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //row 2 is checked
    else if (row_2_O == 2 && row_2_X == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[1][i] == ' ')
            {
                array[1][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //row 3 is checked
    else if (row_3_O == 2 && row_3_X == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[2][i] == ' ')
            {
                array[2][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //column 1 is checked
    else if (col_1_O == 2 && col_1_X == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][0] == ' ')
            {
                array[i][0] = 'X';
                done = true;
            }
            i++;
        }
    }

    //column 2 is checked
    else if (col_2_O == 2 && col_2_X == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][1] == ' ')
            {
                array[i][1] = 'X';
                done = true;
            }
            i++;
        }
    }

    //column 3 is checked
    else if (col_3_O == 2 && col_3_X == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][2] == ' ')
            {
                array[i][2] = 'X';
                done = true;
            }
            i++;
        }
    }

    //diagonal right to left is check here

    else if (diag_RL_O == 2 && diag_RL_X == 0)
    {
        int i = 0;
        int j = 0;
        while (!done && i < 3)
        {
            if (array[i][j] == ' ')
            {
                array[i][j] = 'X';
                done = true;
            }
            //both row and column increase to move forward diagonally
            i++;
            j++;
        }
    }
    //diagonal left to right is check here
    else if (diag_LR_O == 2 && diag_LR_X == 0)
    {
        int i = 0;
        int j = 2;
        while (!done && i < 3)
        {
            if (array[i][j] == ' ')
            {
                array[i][j] = 'X';
                done = true;
            }
            //row increases and column decreases to move diagonally
            i++;
            j--;
        }
    }
    //*****************************************************************************
    //Second Attackign Mode: This tries to move the game forward towards winning by accumulating X's in row/col/diags that
    //alreay have an X.

    //row 1 is checked
    else if (row_1_X == 1 && row_1_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[0][i] == ' ')
            {
                array[0][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //row 2 is checked
    else if (row_2_X == 1 && row_2_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[1][i] == ' ')
            {
                array[1][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //row 3 is checked
    else if (row_3_X == 1 && row_3_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[2][i] == ' ')
            {
                array[2][i] = 'X';
                done = true;
            }
            i++;
        }
    }
    //column 1 is checked
    else if (col_1_X == 1 && col_1_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][0] == ' ')
            {
                array[i][0] = 'X';
                done = true;
            }
            i++;
        }
    }

    //column 2 is checked
    else if (col_2_X == 1 && col_2_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][1] == ' ')
            {
                array[i][1] = 'X';
                done = true;
            }
            i++;
        }
    }

    //column 3 is checked
    else if (col_3_X == 1 && col_3_O == 0)
    {
        int i = 0;
        while (!done && i < 3)
        {
            if (array[i][2] == ' ')
            {
                array[i][2] = 'X';
                done = true;
            }
            i++;
        }
    }

    //diagonal right to left is check here

    else if (diag_RL_X == 1 && diag_RL_O == 0)
    {
        int i = 0;
        int j = 0;
        while (!done && i < 3)
        {
            if (array[i][j] == ' ')
            {
                array[i][j] = 'X';
                done = true;
            }
            i++;
            j++;
        }
    }
    //diagonal left to right is check here
    else if (diag_LR_X == 1 && diag_LR_O == 0)
    {
        int i = 0;
        int j = 2;
        while (!done && i < 3)
        {
            if (array[i][j] == ' ')
            {
                array[i][j] = 'X';
                done = true;
            }
            i++;
            j--;
        }
    }
    else //if none of the above conditions are applied, a random game is played. This only applies to the initial
    //stages of the game
    {
        srand(time(NULL)); //seed the

        int cycle = 0; //CALC; to control the number of loop iterations in case an infnite loop is encountered
        while (!done && cycle < 50)
        {
            int i = rand() % 3;
            int j = rand() % 3;
            if (array[i][j] == ' ')
            {
                array[i][j] = 'X';
                done = true;
            }

            cycle++;
        }
    }
}
