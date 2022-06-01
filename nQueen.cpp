#include <iostream>
#include <string>
#include <vector>
#define N 4
using namespace std;
void printVectorMatrix(vector<vector<bool>> vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = 0; j < vec[i].size(); j++){
      if(vec[i][j]==0)  
       cout <<"X ";
      else
       cout << "\x1B[34m" << "Q " << "\x1B[0m";
    }   
    cout << endl;
  }
}
bool isQueenSafe(vector<vector<bool>> board, int r, int c)
{
  int i,j;
  // vertical
  for (i = 0; i < board.size(); i++)
  {
    if (board[i][c] == true)
      return false;
  }
  // horizontal
  for (i = 0; i < board.size(); i++)
  {
    if (board[r][i] == true)
      return false;
  }
  //diagonal
  for (i = r,j=c; i>=0 && j<board.size(); i--,j++)
  {
    if (board[i][j] == true)
      return false;
  }
  for (i = r,j=c; i>=0 && j>=0; i--,j--)
  {
    if (board[i][j] == true)
      return false;
  }

  return true;
}
void NQueen(vector<vector<bool>> board, int r, int c)
{
  if (r == board.size())
  {
    printVectorMatrix(board);
    cout<<endl<<endl;
    return;
  }

  if (isQueenSafe(board, r, c))
  {
    board[r][c] = true;
    NQueen(board, r + 1, 0);
    //Bactracking
    board[r][c] = false;
  }
  
  if(c< (board.size()-1)) 
      NQueen(board,r,c+1);       

}
int main()
{ 
  vector<bool> v(N,0);
  vector<vector<bool> > board(N,v);
  NQueen(board,0,0);
  
  return 0;
}