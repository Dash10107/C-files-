#include <iostream>

using namespace std;


  char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
  char turn = 'X';
  int choice;
  int row,column;
  bool draw=false;
  
  
//   func to display board     
  
  void displayBoard(){
      cout<<"Player-1 [O], Player-2 [X]\n\n\n";
      cout<<"\t   |    |\n";
      cout<<"\t"<<board[0][0]<<"  | "<<board[0][1]<<"  | "<<board[0][2]<<"\n";
      cout<<"\t___|____|_____\n";
      cout<<"\t   |    |     \n";
      cout<<"\t"<<board[1][0]<<"  | "<<board[1][1]<<"  | "<<board[1][2]<<"\n"; 
      cout<<"\t___|____|_____\n";
      cout<<"\t   |    |     \n";
      cout<<"\t"<<board[2][0]<<"  | "<<board[2][1]<<"  | "<<board[2][2]<<"\n";
      cout<<"\t   |    |\n";
  }
  
//   func to take input and update board

void playerTurn(){
    if(turn == 'X'){
        cout<<"Player-1 [X] Turn :";
        
    }
    else if(turn == 'O'){
        cout<<"Player-2 [O] Turn :";
    }
    cin>>choice;
    
    switch(choice){
        
        case 1:
            row=0; column = 0;    break;
        
        case 2:
            row=0; column = 1;    break;
        case 3:
            row=0; column = 2;    break;
        case 4:
            row=1; column = 0;    break;
        case 5:
            row=1; column = 1;    break;
        case 6:
            row=1; column = 2;    break;
        case 7:
            row=2; column = 0;    break;
        case 8:
            row=2; column = 1;    break;
        case 9:
            row=2; column = 2;    break;
        default:
            cout<<"Invalid Move"; 
    }
    
    if(turn == 'X' && board[row][column] != 'X' &&  board[row][column] != 'O'){
        board[row][column] = 'X';
        turn='O';
    }
    else if(turn == 'O' && board[row][column] != 'X' &&  board[row][column] != 'O'){
        board[row][column] = 'O';
        turn='X';
    }
    else{
        cout<<"Box is already filled. Choose another one \n\n";
        playerTurn();
    }
}

//Function to get the game status e.g. GAME WON, GAME DRAW GAME IN CONTINUE MODE

bool gameOver(){
    
    
     for(int i=0;i<3;i++)
     //checking the win for Simple Rows and Simple Column
        if ( board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])   {
         return false;   }
            
        
        
        
    //checking the win for both diagonal
        if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
            return false;}
        
    
 //Checking the game is in continue mode or not
    for(int i=0; i<3;i++)
        for(int j=0; j<3;j++)
            if (board[i][j] != 'X' && board[i][j] != 'O' )
                return true;
   

    //Checking the if game already draw        
    
    draw = true;
    return false;
    
}
  
  
int main()
{
    cout<<"\t\t TIC--TAC--TOE   --GAME \n\n  \t\t For Two Players \n\n";
    while(gameOver()){
        displayBoard();
        playerTurn();
        gameOver();
    }
    
    if(turn == 'X' && draw == false){
        cout<<"\n\n Congratulations!!!! Player-1 [X] has won the game. \n\n ";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\n Congratulations!!!! Player-2 [O] has won the game. \n\n ";
    }else{
        cout<<"\t\t Game Draw !! \n\n";
    }
  

    return 0;
}
