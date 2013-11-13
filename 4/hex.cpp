// hex.cpp: Santiago Arias
// Description: Hex game

#include "hex.h"

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
