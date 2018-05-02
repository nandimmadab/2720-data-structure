#include "ItemType.h"
#include "BinaryTree.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int cinNumber();

int main(const int argc, const char * argv[]){
  BinaryTree tree;
  ItemType item;
  int input;
  string command;
  fstream fs;
  int number;

  // open file and put all the variable in the linkedList
  fs.open(argv[1],ifstream::in);
  if(fs.is_open()){
    fs >> input;
    while(!fs.eof()){
      item.initialize(input);
      tree.insertItem(item);
      fs >> input;
    }
  }
  else{
    cout << "File could not be opened. " <<
      "Try again." << endl;
    return 0;
  }

  // prompt user for command
  cout << "Commands - insert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order(p), post-order (o), quit (q)" << endl;
  cout << "enter command: ";
  cin >> command;
  while(true){
    // command quit
    if(command == "q"){
      break;
      
      // command insert
    }else if(command == "i"){
      cout << "number to insert: ";
      number = cinNumber();
      item.initialize(number);
      tree.insertItem(item);
      
      // command delete
    }else if(command == "d"){
      bool found;
      cout << "number to delete: ";
      number =cinNumber();
      item.initialize(number);
      tree.retrieveItem(item,found);
      if(found){
	tree.deleteItem(item);
      }else{
	cout << "Item not in tree." << endl;
      }
      
      // command retrieve
    }else if(command == "r"){
      bool found;
      cout << "number to delete: ";
      number =cinNumber();
      item.initialize(number);
      tree.retrieveItem(item,found);
      if(found){
	cout << "Item found in the tree" << endl;
      }else{
	cout << "Item not in tree." << endl;
      }
    
      // command length
    }else if(command == "l"){
      cout << tree.getLength() << endl;
      
      // command in-order
    }else if(command == "n"){
      tree.inOrder();
      cout << endl;
    
      // command pre-order
    }else if(command == "p"){
      tree.preOrder();
      cout << endl;

      // command post-order
    }else if(command == "o"){
      tree.postOrder();
      cout << endl;

      // invalid command
    }else{
      cout << "Command not recognized. Try again" << endl;
    }
    cout << "enter command: ";
    cin >> command;
  }
  return EXIT_SUCCESS;
}

int cinNumber(){
  int x;
  cin >> x;
  while(cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(),'\n');
      cout << "invalid entry." << endl << "Enter a number: ";
      cin >> x;
    }
  return x;
}
