#include<iostream>
#include<string>
using namespace std;

void showGrid(char grid[3][3]){
    cout<<"\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int checkGameStatus(char grid[3][3],int CurrentPlayer){
    for(int i=0;i<3;i++){
        if( (grid[i][0]==grid[i][1] && grid[i][1]==grid[i][2] && grid[i][0]!='.') ||
            (grid[0][i]==grid[1][i] && grid[1][i]==grid[2][i] && grid[0][i]!='.') ){
            return CurrentPlayer;
        }
    }
    if( (grid[0][0]==grid[1][1] && grid[1][1]==grid[2][2] && grid[0][0]!='.') ||
        (grid[0][2]==grid[1][1] && grid[1][1]==grid[2][0] && grid[1][1]!='.') ){
        return CurrentPlayer;
    }

    return 0;
}

int main(){

    //Main Loop.
    while(1){
        string playerX="",playerO="",FirstPlayer="";
        int CurrentPlayer=0,winner=0;
        int r=0,c=0,GameStaus=1,Play=0;
        char grid[3][3]={'.','.','.','.','.','.','.','.','.'};
        cout<<"Enter a name for the X player: \n";
        cin>>playerX;
        cout<<"Enter a name for the O player: \n";
        cin>>playerO;

        //First Turn Loop.
        while(1){
            cout<<"Who plays first, "<<playerX<<" or "<<playerO<<"?\n";
            cin>>FirstPlayer;
            if(FirstPlayer==playerX){
                CurrentPlayer=1;
                break;
            }
            else if(FirstPlayer==playerO){
                CurrentPlayer=2;
                break;
            }
            else{
                cout<<FirstPlayer<<" is not a registered player.\n";
            }
        }//End of First Turn Loop.

        //Game Loop.
        while(1){
            showGrid(grid);
            if(CurrentPlayer==1){
                cout<<"Player of current turn: "<<playerX<<"\n";
            }
            else{
                cout<<"Player of current turn: "<<playerO<<"\n";
            }

            //Valid Cell Loop.
            while(1){
                cout<<"Choose a row number (0 to 2):\n";
                cin>>r;
                if(r<0||r>2){
                    cout<<r<<" is not a valid row.\n";
                    continue;
                }

                cout<<"Choose a column number (0 to 2):\n";
                cin>>c;
                if(c<0||c>2){
                    cout<<c<<" is not a valid column.\n";
                    continue;
                }

                if(grid[r][c]=='.'){
                    if(CurrentPlayer==1){
                        grid[r][c]='X';
                        CurrentPlayer=2;
                    }
                    else{
                        grid[r][c]='O';
                        CurrentPlayer=1;
                    }
                    break;
                }
                else{
                    cout<<"Slot is already taken.\n";
                    continue;
                }
            }//End of Valid Cell Loop.

            winner=checkGameStatus(grid,CurrentPlayer);
            if(winner==1){
                cout<<"\nGame is over: \n"<<playerO<<" wins!\n";
                CurrentPlayer=0;
                break;
            }
            else if(winner==2){
                cout<<"\nGame is over: \n"<<playerX<<" wins!\n";
                CurrentPlayer=0;
                break;
            }
            if(GameStaus++>=9){
                cout<<"Game is over: \nit is a tie!";
                break;
            }
        }//End of Game Loop.

        showGrid(grid);

        //Replay Loop.
        while(1){
            string again="";
            cout<<"\nWould you like to play again? (Y/N)\n";
            cin>>again;
            if(again=="y"||again=="Y"){
                Play=1;
                break;
            }
            else if(again=="n"||again=="N"){
                cout<<"Bye!";
                Play=0;
                break;
            }
            else{
                cout<<again<<" is not a valid answer.";
            }
        }//End of Replay Loop.

        if(!Play){
            break;
        }

    }//End of Main Loop.

    return 0;
}
