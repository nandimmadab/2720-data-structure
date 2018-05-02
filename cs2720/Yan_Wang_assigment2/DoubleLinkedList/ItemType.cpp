#include "ItemType.h"

/**
ItemType object is created.
*/
ItemType::ItemType(){
  value = 0;
}

/**
returns an enumeration that indicates whether the
calling object is GREATER, LESS, or EQUAL to item.
@return: the enumeration of relationType
*/
RelationType ItemType::compareTo(ItemType & item){
  if(value > item.value){
    return GREATER;
  }else if(value == item.value){
    return EQUAL;
  }else{
    return LESS;
  }
}

/**
value instance variable is printed to standard-out.
*/
void ItemType::print(){
  cout << "value is: " << value << endl;
}

/**
the value instance variable is set to number.
@param number: this is the number you want to initialize
*/
void ItemType::initialize(int number){
  value = number;
}

/**
return the value instance variable.
@return: the number value
*/
int ItemType::getValue()const{
  return value;
}
