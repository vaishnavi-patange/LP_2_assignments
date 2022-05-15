#define N 20
#include<bits/stdc++.h>
#include<iostream>

using namespace std;
// A utility function to print solution 
void printSolution(int board[N][N],int n){
    cout << "\n\t Solution : \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        
        }
        cout<<endl;
        
    }
    cout<<endl;
}
// a utility function to check if a queen can be placed on board[row][col]

bool issafe(int board[N][N], int row, int col,int n){
    int i, j;
    //check this row on left size
    for(i=0;i<col;i++){
        if(board[row][i])
         return false;
    }
 // check upper diagonal on left  side
    for(i=row, j=col;i>=0 && j>=0;i--,j--){
        if(board[i][j])
            return false;
    }
    // check lower diagonal on left  side
    for(i=row, j=col;j>=0 && i<n;i++,j--){
        if(board[i][j])
            return false;
    }
     
    return true;
}
//recursive utilitty funvion to solve n
bool solveNqutil(int board[N][N],int col,int n){

    //base case if all queens are placed then return true
    if(col>=n){
        printSolution(board,n);
     return true;
    }
    //consider this column and try placing this queen in all rows one by one
        
    for(int i=0; i<n; i++){
//check if queen can be placed on board[i][col]
        if(issafe(board,i,col,n)){
              //place this queen in board[i][col]
            board[i][col]=1;

            //recure to place rest of the queens
            (solveNqutil(board,col+1,n));
          //if(solveNqutil(board,col+1,n))
           // return true;

          // if placing queen in board[i][col]
          // doesnt lead to a solution , then
          // remove queen from board[i][col]

            board[i][col]=0;// Backtrack
        }
    }

    //if return false if queens 
    //cannot be placed , otherwise , return true and 
    // print placement of queens in the form of 1s.
    return false;
}
bool solveNq(int n)
{
    int board[N][N]={0};
    if(n==2||n==3){
        cout<<"solution doesnt exist"<<endl;
    }
    if(solveNqutil(board,0,n)==false){
     
        return false;
    }
    printSolution(board,n);
    return true;
}
int main()
{
    int n;
    cout<<"enter size of board :"<<endl;
    cin>>n;
    solveNq(n);
    return 0;
}
