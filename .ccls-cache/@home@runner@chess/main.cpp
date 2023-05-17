#include <iostream>
#include <string>
bool wwin = false, bwin = false;
const int BLACK_PAWN = 7,BLACK_ROOK = 8,BLACK_KNIGHT = 9,BLACK_BISHOP = 10,BLACK_QUEEN = 11,BLACK_KING = 12,WHITE_PAWN = 1,WHITE_ROOK = 2,WHITE_KNIGHT = 3,WHITE_BISHOP = 4,WHITE_QUEEN = 5,WHITE_KING = 6;
int board[8][8] = {
{BLACK_ROOK,BLACK_KNIGHT,BLACK_BISHOP,BLACK_QUEEN,BLACK_KING,BLACK_BISHOP,BLACK_KNIGHT,BLACK_ROOK},
{BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN,BLACK_PAWN},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
{WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN,WHITE_PAWN},
{WHITE_ROOK,WHITE_KNIGHT,WHITE_BISHOP,WHITE_QUEEN,WHITE_KING,WHITE_BISHOP,WHITE_KNIGHT,WHITE_ROOK}
};
std::string pieces[] {" ","P","R","H","B","Q","K","p","r","h","b","q","k"};
std::string build()
{
  std::string str;
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
      {
        str+= pieces[board[i][j]];
        if(j < 7)
        {
          str+="|";
        }
      }
    str+="\n";
  }
  return str;
}
bool turn(bool p1turn)
{
  std::string move, piece;
  std::cout << build() << "\n";
  if(p1turn)
  {
    std::cout << "Player 1 turn.\n";
  }
  else
  {
    std::cout << "Player 2 turn.\n";  
  }
  std::cout << "What piece? (column),(row)";
  std::cin >> move;
  int row = std::stoi(move.substr(move.length()-1,1));
  int col = std::stoi(move.substr(0,1));
  if(board[col][row] != 0)
  {
    piece = move.substr(0,1);
    piece += move.substr(move.length()-1,1);
    std::cout << piece << "\n";
  }
  return !p1turn;
}
int main()
{
  bool p1turn = true;
  while(!wwin && !bwin)
  {
    p1turn = turn(p1turn);
  }
  std::cout << build();
  return 0;
}