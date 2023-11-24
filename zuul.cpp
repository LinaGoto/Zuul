#include <iostream>
#include <cstring>

using namespace std;

struct room_s{
  bool exist;
  int item;
}

static char *itemlist[]= {
  "circle",
  "triangle",
  "star",
  "heart",
}

struct positions_s{
  int x,y
  int num_items;
}

int main(){
  char inventory [10];
  char input [10];
  book play = true;

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

}
