//Tic-Tac-Toe game
#include<bits/stdc++.h>
using namespace std;
#define player1Move 'O' 
#define player2Move 'X'  
struct Move
{
    int r;
    int c;
};
void player();
void showInitial()   //structure of initial board
{
    char board[3][3];
    board[0][0]='1';board[0][1]='2';board[0][2]='3';board[1][0]='4';board[1][1]='5';board[1][2]='6';
    board[2][0]='7';board[2][1]='8';board[2][2]='9';
    cout<<"choose number in board and play"<<endl; 
    cout<<"  "<<board[0][0]<<"  |"<<"  "<<board[0][1]<<"  |"<<"  "<<board[0][2]<<"  "<<endl;
    cout<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<endl;
    cout<<endl;
    cout<<"  "<<board[1][0]<<"  |"<<"  "<<board[1][1]<<"  |"<<"  "<<board[1][2]<<"  "<<endl;
    cout<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<endl;
    cout<<endl;
    cout<<"  "<<board[2][0]<<"  |"<<"  "<<board[2][1]<<"  |"<<"  "<<board[2][2]<<"  "<<endl;
}
bool whoIsWinner(char board[][3])
{
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]&& board[0][0]!=' ')
    return true;
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=' ')
    return true;
    for (int i=0; i<3; i++) 
    { 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] &&  board[0][i] != ' ') 
        return true; 
    } 
    for (int i=0; i<3; i++) 
    { 
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] &&  board[i][0] != ' ') 
        return true; 
    } 
    return false;
}
void updateBoard(int temp,char board[][3],int count)
{
    if(temp==0)
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j]=' ';
        }
    }
    else
    {
        if(temp==1 && count%2!=0)
        board[0][0]=player1Move;
        else if(temp==1 && count%2==0)
        board[0][0]=player2Move;
        else if(temp==2 && count%2!=0)
        board[0][1]=player1Move;
        else if(temp==2 && count%2==0)
        board[0][1]=player2Move;
        else if(temp==3 && count%2!=0)
        board[0][2]=player1Move;
        else if(temp==3 && count%2==0)
        board[0][2]=player2Move;
        else if(temp==4 && count%2!=0)
        board[1][0]=player1Move;
        else if(temp==4 && count%2==0)
        board[1][0]=player2Move;
        else if(temp==5 && count%2!=0)
        board[1][1]=player1Move;
        else if(temp==5 && count%2==0)
        board[1][1]=player2Move;
        else if(temp==6 && count%2!=0)
        board[1][2]=player1Move;
        else if(temp==6 && count%2==0)
        board[1][2]=player2Move;
        else if(temp==7 && count%2!=0)
        board[2][0]=player1Move;
        else if(temp==7 && count%2==0)
        board[2][0]=player2Move;
        else if(temp==8 && count%2!=0)
        board[2][1]=player1Move;
        else if(temp==8 && count%2==0)
        board[2][1]=player2Move;
        else if(temp==9 && count%2!=0)
        board[2][2]=player1Move;
        else if(temp==9 && count%2==0)
        board[2][2]=player2Move;
    }
    
}
void showBoard(char board[][3])
{
    cout<<"  "<<board[0][0]<<"  |"<<"  "<<board[0][1]<<"  |"<<"  "<<board[0][2]<<"  "<<endl;
    cout<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<endl;
    cout<<endl;
    cout<<"  "<<board[1][0]<<"  |"<<"  "<<board[1][1]<<"  |"<<"  "<<board[1][2]<<"  "<<endl;
    cout<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<"_"<<" "<<endl;
    cout<<endl;
    cout<<"  "<<board[2][0]<<"  |"<<"  "<<board[2][1]<<"  |"<<"  "<<board[2][2]<<"  "<<endl;
}
int generateRandom(int ind,vector<int>&index)
{
    int sum=0;
    int temp=(rand()%ind)+1;
    for (int i = 0; i < 9; i++)
    {
        if(index[i]!=0)
        sum++;
        if(sum==temp)
        return i+1;
    }
    
}
bool movesLeft(char board[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j]==' ')
            return true;
        }
    }
    return false;
    
}
int points(char board[][3])
{
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        if(board[0][0]==player1Move)
        return  -10;
        else if(board[0][0]==player2Move)
        return 10;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        if(board[0][2]==player1Move)
        return  -10;
        else if(board[0][2]==player2Move)
        return 10;
    }
    for (int i=0; i<3; i++) 
    { 
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
        {
            if(board[0][i]==player1Move)
            return  -10;
            else if(board[0][i]==player2Move)
            return 10;
        }
    } 
    for (int i=0; i<3; i++) 
    { 
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if(board[i][2]==player1Move)
            return  -10;
            else if(board[i][2]==player2Move)
            return 10;
        } 
    } 
    return 0;
}
int miniMax(char board[][3],int depth,bool isMaximizing)
{
    int currentScore=points(board);
    if(currentScore==10 || currentScore==-10)
    return currentScore;
    if(!movesLeft(board))
    return 0;
    if(isMaximizing)
    {
        int temp=INT_MIN;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[i][j]==' ')
                {
                    board[i][j]=player2Move;
                    temp=max(temp,miniMax(board,depth+1,!isMaximizing));
                    board[i][j]=' ';
                }
            }
        }
        return temp;
    }
    else
    {
        int temp=INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[i][j]==' ')
                {
                    board[i][j]=player1Move;
                    temp=min(temp,miniMax(board,depth+1,!isMaximizing));
                    board[i][j]=' ';
                }
            }   
        }
        return temp;
    }
}
Move bestMove(char board[][3])  //search best move based on the points
{
    int value=INT_MAX * (-1);
    Move best;
    best.r=-1;
    best.c=-1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(board[i][j]==' ')
            {
                board[i][j]=player2Move;   // not assigning real value just for checkup
                int temp=miniMax(board,0,false);
                board[i][j]=' '; //making board again like previous one
                if(temp>value)    //if score is higher than this is the better move
                {
                    best.r=i;
                    best.c=j;
                    value=temp;
                }
            }
        }
    }
    return best;
}
void Computer_hard() //hard version either computer win or tie!
{
    cout<<"Enter player name:"<<endl;
    string name;
    cin>>name;
    int count=1;
    int temp=0;
    char board[3][3];
    updateBoard(temp,board,count);
    vector<int>index(9,1);
    showInitial();
    while(count<=9)
    {
        if(count%2!=0)   //player1 turn
        {
            int num;
            cout<<"your turn"<<endl;
            cin>>num;
            while(index[num-1]==0||num<1||num>9)
            {
                cout<<"invalid! number, enter again"<<endl;
                cin>>num;
            }
            temp=num;
        }
        else //player2 turn or computer
        {
            int n=0;
            Move best=bestMove(board);
            for (int i = 0; i < 3; i++)
            {
                bool flag=0;
                for (int j = 0; j < 3; j++)
                {
                    n++;
                    if((i==best.r) and (j==best.c))
                    {
                        flag=1;
                        break;
                    }   
                }    
                if(flag)
                break;
            }
            temp=n;
            // cout<<best.r<<" "<<best.c<<" "<<n<<endl;
        }
        index[temp-1]=0;
        updateBoard(temp,board,count);
        showBoard(board);
        if(whoIsWinner(board))
        {
            if(count%2==0)
            cout<<"computer won!"<<endl;
            else
            cout<<"Congratulation! "<<name<<" you won"<<endl;
            break;
        }
        else if(count==9 && !whoIsWinner(board))
        {
            cout<<"draw"<<endl;
            break;
        }
        count++;
    }   
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    player();
}
void Computer() //computer is playing randomly or easy level
{
    cout<<"Enter player name:"<<endl;
    string name;
    cin>>name;
    int count=1;
    int temp=0;
    char board[3][3]; //tic-tac field
    updateBoard(temp,board,count); //fill with ' '
    vector<int>index(9,1);    //place vaccant or not
    showInitial();// initial board and instruction
    srand (time(NULL));
    while(count<=9)
    {
        if(count%2==0) ///odd computer turn
        {
            Move best=bestMove(board);
            cout<<"computer turn"<<endl;
            board[best.r][best.c]=player2Move;
            if(!whoIsWinner(board))
            {
                board[best.r][best.c]=' ';
                temp=generateRandom(9-count+1,index);
            }
            else
            {
                showBoard(board);
                cout<<"computer won!"<<endl;
                break;
            }
        }
        else //even turn is player
        {
            int num;
            cout<<"your turn"<<endl;
            cin>>num;
            while(index[num-1]==0 || num<1 || num>9)//check presence of num
            {
                cout<<"invalid number, enter again"<<endl;
                cin>>num;
            }
            temp=num;
        }
        index[temp-1]=0;//erase temp from list so that next time it cant get selected
        updateBoard(temp,board,count);
        showBoard(board);
        if(whoIsWinner(board))
        {
            if(count%2==0)
            cout<<"computer won!"<<endl;
            else
            cout<<"Congratulation! "<<name<<" you won"<<endl;
            break;
        }
        else if(count==9 && !whoIsWinner(board))
        {
            cout<<"draw"<<endl;
            break;
        }
        count++;
    }
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    player();
}
void Friend() //playing with friend
{
    cout<<"Enter player1 and player2 names:"<<endl;
    string name1,name2;
    cin>>name1>>name2;
    char board[3][3];
    int count=1,temp=0;
    updateBoard(temp,board,count); //fill with ' '
    vector<int>index(9,1);    //place vaccant or not
    showInitial();
    while(count<=9)
    {
        if(count%2!=0) //odd number of turn for player1
        cout<<name1<<" your turn"<<endl;
        else cout<<name2<<" your turn"<<endl;  //even number of turn for player2
        int num=0;
        cin>>num;
        while(index[num-1]==0||num<1||num>9)
        {
            cout<<"invalid number! enter again"<<endl;
            cin>>num;
        }
        index[num-1]=0;
        updateBoard(num,board,count);
        showBoard(board); //showing the updated board 
        if(whoIsWinner(board))
        {
            if(count%2!=0)
            cout<<"Congratulation! "<<name1<<" you won"<<endl;
            else
            cout<<"Congratulation! "<<name2<<" you won"<<endl;
            break;
        }
        else if(count==9 && !whoIsWinner(board))
        {
            cout<<"draw"<<endl;
            break;
        }
        count++;
    }
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    player();
}
void player()
{
    cout<<"Play with"<<endl;
    cout<<"__________"<<" "<<"________"<<endl;
    cout<<"|"<<"Computer"<<"|"<<" "<<"|"<<"Friend"<<"|"<<endl;
    cout<<"press 1 for Computer, 2 for Friend, anyother for exit"<<endl; // choose to play with computer or friend
    int n;
    cin>>n;
    if(n==1)
    {
        cout<<"Select the level: for EASY press 0, for HARD press 1"<<endl;
        int num;
        cin>>num;
        while(num>1||num<0)
        {
            cout<<"invalid! press again"<<endl;
            cin>>num;
        }
        if(num==0)
        Computer(); //computer vs u in easy level
        else Computer_hard(); //computer play optimally either computer will win or draw
    }
    else if(n==2)
    Friend(); //two player game
    else
    cout<<"Thankyou!"<<endl;
}
int main()
{
    player(); //for type of game user want
}