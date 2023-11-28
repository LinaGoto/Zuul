/*
Lina Goto
11/27/23
play the game of zuul:
collect all 5 items from the 15 rooms and bring it back to the starting point
*/

#include <iostream>
#include <cstring>

using namespace std;

// room structure set up
struct room_s{
  int exist;
  int item;
  int goal;
};

#define	MAX_ITEM  5

// drop items
static const char *itemlist[MAX_ITEM]= {
  "circle",
  "triangle",
  "star",
  "square",
  "heart",
};

// my position and inventory items
struct position_s{
  int x,y;
  int num_item;
  int item[MAX_ITEM + 1];
};

int main(void) {
  char input [10];
  bool play = true;
  struct room_s room[8][5];
  struct position_s mypos;
  
  // initialize - clear the board
  for(int i=0; i < 8; i++){
    for (int j=0; j < 5; j++){
      room[i][j].exist =  0;
      room[i][j].item  = -1;
      room[i][j].goal  =  0;
    }
  }

  // making existing rooms
  for(int i = 1; i < 6; i++){
    for (int j = 1; j < 4; j++){
      room[i][j].exist = 1;
    }
  }

  // setup the goal
  room[6][2].exist = 1;
  room[6][2].goal  = 1;
  
  // placing items
  room[1][1].item = 0; // circle
  room[5][1].item = 1; // triangle
  room[3][2].item = 2; // star
  room[2][3].item = 3; // square
  room[4][3].item = 4; // heart

  // my initial position
  mypos.x = 6;
  mypos.y = 2;
  mypos.num_item = 0;
  // empty the inventory
  for (int i=0; i<MAX_ITEM + 1; i++){
    mypos.item[i] = -1;
  }
  
  // main loop
  do{
    //if all conditions for winning is achived - break to win
    if ((room[mypos.x][mypos.y].goal == 1) & (mypos.num_item == 5)) break;
    //print current place
    cout << "You are in room " << mypos.x << "-" << mypos.y << "." << endl;
    //print what is in the room
    if (room[mypos.x][mypos.y].item >= 0){
      cout << "There is an " << itemlist[room[mypos.x][mypos.y].item]
	   << " on the floor." << endl;
    } else {
      cout << "There is no item to be picked up." << endl;
    }
    //print possible exists
    cout <<  "There are exits:";
    if(room[mypos.x + 1][mypos.y].exist == 1){
	cout << " EAST";
      }
    if(room[mypos.x - 1][mypos.y].exist == 1){
	cout << " WEST";
      }
    if(room[mypos.x][mypos.y - 1].exist == 1){
	cout << " NORTH";
      }
    if(room[mypos.x][mypos.y + 1].exist == 1){
	cout << " SOUTH";
      }
    cout << endl;
    //ask for move
    cout << "What would you like to do? Enter: [M]ove / [P]ickup / [D]rop" << endl;
    cin.get(input, 10);
    cin.get();
    //move
    if (input[0] == 'M' || input[0] == 'm'){
      cout << "Which direction would you like to move?" << endl;
      char move [10];
      cin.get(move, 10);
      cin.get();
      //east
      if (move[0] == 'E' || move[0] == 'e'){
	if(room[mypos.x + 1][mypos.y].exist == 1){
	  mypos.x ++;
	} else {
	  cout << "You cannot go east." << endl;
	}
      }
      //west
      if (move[0] == 'W' || move[0] == 'w'){
	if(room[mypos.x - 1][mypos.y].exist == 1){
	  mypos.x --;
	} else {
	  cout << "You cannot go west." << endl;
	}
      }
      //north
      if (move[0] == 'N' || move[0] == 'n'){
	if(room[mypos.x][mypos.y - 1].exist == 1){
	  mypos.y --;
	} else {
	  cout << "You cannot go north." << endl;
	}
      }
      //south
      if (move[0] == 'S' || move[0] == 's'){
	if(room[mypos.x][mypos.y + 1].exist == 1){
	  mypos.y ++;
	} else {
	  cout << "You cannot go south." << endl;
	}
      }
    }
    
    // pick up
    if (input[0] == 'P' || input[0] == 'p'){
      // if there is an item to pick up
      if (room[mypos.x][mypos.y].item >= 0){
	// find empty location
	int i = 0;
	while (mypos.item[i] >= 0) i ++;
	// add item to mypos
	mypos.item[i] = room[mypos.x][mypos.y].item;

	// take out from room
	room[mypos.x][mypos.y].item = -1;
        // increment number of items that I have
	mypos.num_item ++;
	cout << "You had successfully picked up the item and had stored it into your inventory." << endl;   
      } else{
	cout << "There is no item to be picked up." << endl;
      }
    }
    
    // drop
    if(input[0] == 'D' || input[0] == 'd'){
      // if there was nothing printed out, there is nothing in inventory
      if (mypos.num_item <= 0){
	cout << "There is nothing in your inventory that you could drop." << endl;
      } else {
	cout << "What would you like to drop? ";
	// list out all numbers listed in the inventory
	for(int i=0; i<MAX_ITEM; i++){
	  if(mypos.item[i] >= 0){
	    cout << mypos.item[i] << ". " << itemlist[mypos.item[i]] << " ";
	  }
	}
	cout << endl;

	cout << "Enter number : ";
	// input what to drop
	int dropping = 0;
	cin >> dropping;
	cin.get();

	for (int i=0; i<MAX_ITEM; i++){
	  // see if there is the item inputed existing in inventory
	  if (mypos.item[i] == dropping){
	    // put the number in the room
	    room[mypos.x][mypos.y].item = mypos.item[i];
	    // clear number form inventory
	    mypos.item[i] = -1;
	    // decrement number of items that I have
	    mypos.num_item --;
	  }
	}
      }
    }
    
  } while (play == true);

  // Goal
  cout << endl << "Congratulations! You have successfully cleared this maze." << endl;

  return 0;
}
