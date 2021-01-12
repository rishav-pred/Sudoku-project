// 	Program to solve a sudoku


#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

void display(int board[9][9])	// function to display sudoku
{
	cout<<"Solved Sudoku: \n";
    for(int i = 0; i<9 ; i++)
    {
        for(int j=0; j<9; j++)
            cout<<board[i][j]<<" ";
        cout<<"\n";
    }
}

bool isValid(int board[9][9],int x,int y,int val)		// returns true if the place is valid to enter number
{
    for(int j=0;j<9;j++)
    {
        if(board[x][j] == val)
            return false;
    }

    for(int i = 0;i<9;i++)
    {
        if(board[i][y]== val)
            return false;
    }

    int smi = 3*(x/3);
    int smj = 3*(y/3);
    for(int i = 0 ;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[smi+i][smj+j] == val)
                return false;
        }
    }

    return true;
}

void SolveSudoku(int i,int j,int grid[9][9])
{
    if(i == 9)
    {
        display(grid);
        return ;
    }
    int  ni = 0;
    int  nj = 0 ;
    if(j == 8)
    {
        ni = i+1;
        nj = 0 ;
    }
    else
    {
        ni =i;
        nj = j+1;
    }

    if(grid[i][j] != 0){
    	SolveSudoku(ni,nj,grid);
	}
        
    else
    {
        for(int po = 1 ;po <= 9 ;po++)
        {
            if(isValid(grid,i,j,po) == true)
            {
            	
                grid[i][j] = po;
                
                SolveSudoku(ni,nj,grid);
                
                grid[i][j] = 0;		// Backtracking
                
            }
        }
    }
}


int main()
{
    cout<<"Enter you Unsolved sudoku: "<<endl;
    int  board[9][9];
    
    cout<<"Enter the elements of the board: \n";
    for(int i = 0; i<9 ; i++)
    {
        for(int j=0; j<9; j++)
            cin>>board[i][j];
    }
    
    SolveSudoku(0,0,board);	// function to call sudoku solver

    return 0;
}
