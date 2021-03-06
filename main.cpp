//first tic tac toe game
//add maybe board.length instead to allow for rezisig.
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


bool start(){
  //true for x flase for o
  char mystr;
  bool xo = true;
  cout << "X or O: ";
  cin >> mystr;
  if (mystr == 'X'){
    xo = true;
  }
  else {
    xo = false;
  }
  return xo;
}
void showboard(int board[3][3]){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      if (board[j][i]==-1){
        cout << "O ";
      }
      else if (board[j][i]==1){
        cout << "X ";
      }
      else {
        cout << "  ";
      }
    }
    cout << "\n";
  }
  cout << "\n";
}
void userturn(int board[3][3], bool turn){
  int x, y;
  do {
  cout << "\n Pick a coordinate: ";
  cin >> x >> y;
  } while (board[x][y]!=0);
  if (turn){
    board[x][y] = 1;
    //turn = false;
  }
  else {
    board[x][y] = -1;
    //turn = true;
  }
}
void initializeboard(int board[3][3]){
  //fill with 0s
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = 0;
    }
  }
}

bool checkforwin(int board[3][3]){
  //rows, columns, diagonals
  for (int j = 0; j < 3; j++){
    if (board[0][j]==board[1][j]&&board[0][j]==board[2][j] && board[0][j]!=0){
      return true;
    }
    if (board[j][0]==board[j][1]&&board[j][0]==board[j][2] && board[j][0]!=0){
      return true;
    }
  }
  if (board[0][0]==board[1][1]&&board[0][0]==board[2][2] && board[0][0]!=0){
    return true;
  }
  if (board[2][0]==board[1][1]&&board[2][0]==board[0][2] && board[1][1]!=0){
    return true;
  }
  return false;
}

void swap(int in[], int a, int b){
  int t = in[a];
  in[a] = in[b];
  in[b] = t;
}
void makeperms(int input[], int length){
  /*struct item{
    int val;
    int prevspots[length];
    int futurespots[length];
  } ;
  item items[length];
  for (int i = 0; i<length; i++){
    items[i].val = input[i];
    items[i].prevspots[0] = i;
    for (j =0; j<length; j++){
      if (!items[i].prevspots[0]==j){
        items[i].futurespots[j] = j;
      }
      else {
        items[i].futurespots[j] = -1;
      }
    }
  }*/
  int indexes[length];
  for (int i =0; i<length; i++){
    indexes[i] = 0;
  }
  //note: 01234 is first while 43210 is last (going from increase to decrease)
  //0123* 1023 1203 1230* 2130 2310 2301* 3201 3021 3012* 0312 0132 == length(length -1)
  //Note: that is half of all, just running through and repeatedly swapping neighbours
  //next swap mid first
  //0213 2013 2103 2130^ 1230 1320 1302 3102 3012^ 3021^ 0321 0231 
}

void fillfile(int board[3][3], int sequence[][2], bool turn, int length){
  int newsequence[length][2];
  for (int i =0; i<length; i++){
    //definitely not a great idea
    //produces array of numbers like [1][0][1][0]
    //now I can just create every permutation of that array
    newsequence[i][0]=board[sequence[i][0]][sequence[i][1]];
    newsequence[i][1]=i; //to store their correct position to be placed.
  }

}
void computerturn(int board[3][3], bool turn, int left){
  int compboard[3][3];
  for (int i =0; i<3; i++){
    for (int j =0; j<3; j++){
      compboard[j][i] = board[j][i];
    }
  }
  int listleft[left][2];
  int listcount = 0;
  int playnum = 0;
  double percentofwins[left];
  int wins[left];
  int loss[left];
  int total[left];
  int leftcount = left;
  bool t2 = turn;
  if (turn){
    playnum = 1;
  }
  else{
    playnum = -1;
  }
  for (int i =0; i<3; i++){
    for (int j =0; j<3; j++){
      if (board[j][i]==0){
        listleft[listcount][0] = j;
        listleft[listcount][1] = i;
        listcount++;
      }
    }
  }

  /*for (int i = 0; i<left; i++){
    compboard[listleft[i][0]][listleft[i][1]] = playnum;
    t2 = !t2;
    leftcount--;

    for(int j = 0; (j < leftcount)&&!checkforwin(compboard); j ++){
      if (compboard[listleft[j][0]][listleft[j][1]]==0){
        if (t2 != turn){
          compboard[listleft[j][0]][listleft[j][1]] = -1*playnum;
        }
        else{
          compboard[listleft[j][0]][listleft[j][1]] = playnum;
        }
      }
      t2 = !t2;
    }
    if (checkforwin(compboard)){
      if (t2==turn){
        loss[i]++;
      }
      else {
        wins[i]++;
      }
    }
    total[i]++;


  }*/
}
int main(){
  int game[3][3];
  int empty = 9;
  bool turn = true;
  bool usr = start();
  //start();
  initializeboard(game);
  while (!checkforwin(game) && empty>0){
    /*if (empty == 0){
      showboard(game);
      cout << "Its a tie! \n";
      return 0;
    }*/
    showboard(game);
    if (usr){
      userturn(game, turn);
    }
    else {
      computerturn(game, turn, empty);
    }
    empty--;
    turn = !turn;
  }
  showboard(game);
  if (checkforwin(game)){
    if (turn){
      cout << "O is the winner! \n";
    }
    else{
      cout << "X is the winner! \n";
    }
  }
  else {
    cout << "It's a tie! \n";
  }
  cout << "Gameover \n";
  return 0;
}
