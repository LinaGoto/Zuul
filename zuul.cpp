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

struct position_s{
  int x,y;
  int num_item;
  int item[6];
};

int main(){
  char inventory [10];
  char input [10];
  bool play = true;
  struct room_s room[8][5];
  struct position_s mypos;
  int count = 0;

  //initialize
  for(int i=0; i < 8; i++){
    for (int j=0; j < 5; j++){
      room[i][j].exist = 0;
      room[i][j].item  = -1;
      room[i][j].goal = 0;
    }
  }

  //making existing rooms
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

  //starting position
  mypos.x = 6;
  mypos.y = 2;
  mypos.num_item = 0;

  for (int i=0; i<7; i++){
    mypos.item[i] = -1;
  }

  
  do{
    if ((room[mypos.x][mypos.y].goal == 1) & (mypos.num_item == 5)) break;

    cout << "you are in room " << mypos.x << "-" << mypos.y << endl;

    if (room[mypos.x][mypos.y].item >= 0){
      cout << "there is an " << itemlist[room[mypos.x][mypos.y].item]
	   << " on the floor" << endl;
    }

    if (room[mypos.x][mypos.y].item < 0){
      cout << "there is no item to be picked up" << endl;
    }

    cout <<  "There are exits: ";
    if(room[mypos.x + 1][mypos.y].exist == 1){
	cout << "EAST ";
      }
    if(room[mypos.x -1][mypos.y].exist == 1){
	cout << "WEST ";
      }
    if(room[mypos.x][mypos.y + 1].exist == 1){
	cout << "NORTH ";
      }
    if(room[mypos.x][mypos.y -1].exist == 1){
	cout << "SOUTH ";
      }
    cout << endl;
    
    cout << "What would you like to do ? enter: MOVE/PICKUP/DROP" << endl;

    cin.get(input, 10);
    cin.get();

    //move
    if (input[0] == 'M' || input[0] == 'm'){
      cout << "Which direction would you like to move?" << endl;
      char move [10];
      cin.get(move, 10);
      cin.get();

      if (move[0] == 'E' || move[0] == 'e'){
	if(room[mypos.x + 1][mypos.y].exist == 1){
	  mypos.x ++;
	}
	else{
	  cout << "you cannot go east" << endl;
	}
      }

      if (move[0] == 'W' || move[0] == 'w'){
	if(room[mypos.x - 1][mypos.y].exist == 1){
	  mypos.x --;
	}
	else{
	  cout << "you cannot go west" << endl;
	}
      }
      
      if (move[0] == 'N' || move[0] == 'n'){
	if(room[mypos.x][mypos.y + 1].exist == 1){
	  mypos.y ++;
	}
	else{
	  cout << "you cannot go north" << endl;
	}
      }
      
      if (move[0] == 'S' || move[0] == 's'){
	if(room[mypos.x][mypos.y - 1].exist == 1){
	  mypos.y --;
	}
	else{
	  cout << "you cannot go south" << endl;
	}
      }
      
    }
    
    //pick up
    if (input[0] == 'P' || input[0] == 'p'){


      if (room[mypos.x][mypos.y].item >= 0){
	mypos.item[count] = room[mypos.x][mypos.y].item;
	count ++;
       room[mypos.x][mypos.y].item = -1;
	cout << "you had successfully picked up the item and had stored it into your inventory" << endl;   
      }

      else{
	cout << "there is no item to be picked up" << endl;
      }
      
    }

    
    //drop
    if(input[0] == 'D' || input[0] == 'd'){
      cout << "what would you like to drop(enter number): ";
      int counting = 0;
      for(int i=0; i<7; i++){
	if(mypos.item[i] != -1){
	  cout << mypos.item[i] << "."<< itemlist[mypos.item[i]];
	  counting ++;
	}
      }
      if (counting == 0){
	cout << "there is nothing in your inventory that you could drop" << endl;
      }
      if (counting > 0){
	cout << endl;
	char dropping [10];
	cin.get (dropping, 10);
	cin.get ();

	for (int i=0; i<7; i++){
	  if (mypos.item[i] == mypos.item[dropping]){
	    mypos.item[i] == -1;
	  }
	}
	
      }
    }
    
  } while (play == true);
}
