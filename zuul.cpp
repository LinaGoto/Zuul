#include <iostream>
#include <cstring>

using namespace std;

struct room_s{
  int exist;
  int item;
  int goal;
};

static const char *itemlist[]= {
  "circle",
  "triangle",
  "star",
  "square",
  "heart",
};

struct positions_s{
  int x,y;
  int num_items;
};

int main(){
  char inventory [10];
  char input [10];
  bool play = true;
  struct room_s room[7][5];

  for(int i=0; i < 7; i++){
    for (int j=0; j < 5; j++){
      room[i][j].exist = 0;
      room[i][j].item  = -1;
      room[i][j].goal = 0;
    }
  }

  for(int i = 1; i < 6; i++){
    for (int j = 1; j < 4; j++){
      room[i][j].exist = 1;
      
    }
  }

  room[6][2].exist = 1;
  room[6][2].goal = 1;
  room[1][1].item = 0;
  room[5][1].item = 1;
  room[3][2].item = 2;
  room[2][3].item = 3;
  room[4][5].item = 4;
  
#if 0
  
  do{
    cout << "INVENTORY/MOVE/PICKUP/DROP" << endl;

    cin.get(input, 0);
    cin.get();

    //inventory
    if (input[0] == 'I' || input[0] == 'i'){
      cout << "you have this in your inventory:" << endl;
    }
    //move
    if (input[0] == 'M' || input[0] == 'm'){
      cout << "you could move" << endl;
    }
    //pick up
    if (input[0] == 'P' || input[0] == 'p'){
      cout << "you could pick up" << endl;
    }
    //inventory
    if (input[0] == 'D' || input[0] == 'd'){
      cout << "you could drop" << endl;
    }    
#endif

    return 0;
}
