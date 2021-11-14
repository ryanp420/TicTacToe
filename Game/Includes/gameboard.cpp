#include <iostream> 

using std:: cout; 
using std:: endl; 
using std:: cin; 
using std:: string; 

// Global Variables 
string board[9] =  {" ", " ", " ", " ", " ", " ", " ", " ", " "}; 
int player = 1; 
int position = 0; 

void gameBoard()
{


    cout<<"--------------------" << endl;
    cout<<"WELCOME TO TIC TAC TOE!" << endl;
    cout<<"--------------------" << endl;
    
    cout<<"Player 1: X" << endl; 
    cout<<"Player 2: O" << endl; 
    

// 6 - 6 - 7 : space width 
//             0     1     2
//             3     4     5
//             6     7     8 
    cout << "     |     |      \n";
    cout << "  1  |  2  |  3   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  4  |  5  |  6   \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  7  |  8  |  9   \n";
    cout << "     |     |      \n\n";
  
}

bool determineWinner()
{
    bool winner = false; 
    // Rows (horizontal)
    if((board[0] == board[1]) && (board[1] == board[2]) && board[0] != " ")
        winner = true;
    else if((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ") 
        winner = true;  
    else if((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ")
        winner = true; 


    // Colums (vertical)
    else if((board[0] == board[3]) && (board[3] == board[6]) && board[0] != " " )
        winner = true; 
    else if((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " " )
        winner = true; 
    else if((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " " )
        winner = true; 

    // Diagonal 
    else if((board[0] == board[4]) && (board[4] == board[8]) && board[0] != " " )
        winner = true; 
    else if((board[2] == board[4]) && (board[4] == board[6]) && board[2] != " " )
        winner = true; 

    return winner; 

}

bool checkBoard()
{
    // this function determines is a square is filled 
    bool is_filled = true; 
    for(int i = 0; i < 9; i++)
    {
        if(board[i] == " ")
            is_filled = false; 
    }

    return is_filled; 
}

void draw()
{

    cout<<  "     |     |      \n";
    cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |      \n";
    cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
    cout << "_____|_____|_____ \n";
    cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    cout << "     |     |      \n";
    cout << "\n";


}

void setPosition()
{
    cout << "Player: " << player << " [Enter 1-9]" << endl; 
    while(!(cin >> position))
    {
        cout << "Enter your position: [1-9] " << endl; 
        cin.clear(); 
        cin.ignore(); 

    }
    while(board[position - 1] != " ")
    {
        cout << "Position is filled. Try again" << endl;
        cout << "Enter your position: [1-9] " << endl; 
        cin >> position; 
        cout << endl; 
    }

}

void updateBoard()
{
    // the player is set to 1 thus this changes whos turn it is by checking
    // modulation 
    // player = 1 
    if(player % 2 == 1) 
        board[position - 1] = "X"; 
    else
        board[position - 1] = "O"; 
}

void changePlayer()
{
    // to change player turn we can increment by 1 and decrease by 1
    // Player 1 + 1 -- > Player 2's turn  
    // Player 2 - 1 -- > Player 1's turn

    if(player == 1)
        player++; 
    else
        player--; 
}

void changeTurns()
{
  // in order to change turns we can invoke the prevous functions
  // determineWinner() && checkBoard()
  // if a winner has not been determined && and a position hasn't been filled
  // then we can change turns


  while(!determineWinner() && !checkBoard())
  {
      setPosition(); 
      updateBoard(); 
      changePlayer(); 
      draw(); 
  }
  

}

void endGame()
{
    if(determineWinner())
        cout << "Winner!" << endl; 
    else if(checkBoard())
        cout << "Tie!" << endl; 
    
}