// hex.cpp: Santiago Arias
// Description: Hex game

#include "hex.h"

// default constructor.
// default size at 7
Hex::Hex():board_size(7){
  game = new Graph(board_size*board_size);
  //game.add(0)
  for(int i = 0; i < game.V(); i++){

    // horizontal neighbors
    if(i%board_size == 0){
      game.add(i, i + 1); // -->
    } else if( i%board_size == board_size - 1){
      game.add(i, i - 1); // <--
    } else {
      game.add(i, i + 1); // -->
      game.add(i, i - 1); // <--
    }

    // upper neighbors
    int x = i - board_size;
    if( x >= 0){
      game.add(i, x);
    }
    if( x - 1 >= 0){
      game.add(i, x - 1);
    }

    // lower neighbors
    int y = i + board_size;
    if(y < board_size*board_size){
      game.add(i, y);
    }
    if(y+1 < board_size*board_size){
      game.add(i, y + 1);
    }

  }
}

Hex::Hex(int size):board_size(size){

}


// display board game:
// example:
// .  -  .  -  .  -  .  -  .  -  .  -  . 
//  \   / \   / \   / \   / \   / \   / \ 
//   .  -  .  -  .  -  .  -  .  -  .  -  . 
//    \   / \   / \   / \   / \   / \   / \ 
//     .  -  .  -  .  -  .  -  .  -  .  -  . 
//      \   / \   / \   / \   / \   / \   / \ 
//       .  -  .  -  .  -  .  -  .  -  .  -  . 
//        \   / \   / \   / \   / \   / \   / \ 
//         .  -  .  -  .  -  .  -  .  -  .  -  . 
//          \   / \   / \   / \   / \   / \   / \ 
//           .  -  .  -  .  -  .  -  .  -  .  -  . 
//            \   / \   / \   / \   / \   / \   / \ 
//             .  -  .  -  .  -  .  -  .  -  .  -  .  
void Hex::display(){

  string space =  "";
  for(int j = 0; j < board_size; j++){
    cout << space;
    for(int i = 0; i < board_size; i++){
      cout << " . ";
      if(i != board_size - 1)
	cout << " - ";
    }
    cout << endl;
    if(j != board_size - 1){ // do not display another row for the bottom case
      space += " ";
      cout << space;
      cout << " \\ ";
      for(int i = 0; i < board_size - 1; i++){
	cout << "  / " << "\\ ";
      }
      cout << endl;
      space += " ";
    }
  }
  cout << endl << endl;

}
