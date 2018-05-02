#include "BinaryTree.h"

/**
tree is created.
*/
BinaryTree::BinaryTree(){
  root = nullptr;
  length = 0;
}

/**
all nodes are freed.
*/
BinaryTree::~BinaryTree(){
  destory(root);
}

void BinaryTree::destory(TreeNode*& tree){
  if(tree != nullptr){
    destory(tree->left);
    destory(tree->right);
    delete tree;
  }
}

/**
found is set to true if the item is found in the tree and
item is set to the info instance variable of the node
that is equal to item.
@param item: this is the item you want to retrieve
*/
void BinaryTree::retrieveItem(ItemType &item, bool &found)const{
  retrieve(root,item,found);
}

void BinaryTree::retrieve(TreeNode* tree, ItemType &item, bool &found)const{
  if(tree == nullptr){
    found = false;
  }else if(item.compareTo(tree->info) == LESS){
    retrieve(tree->left,item,found);
  }else if(item.compareTo(tree->info) == GREATER){
    retrieve(tree->right,item,found);
  }else{
    found = true;
    item = tree->info;
  }
}

/**
item is inserted into the tree in sorted order.
@param item: this is the item you want to insert
*/
void BinaryTree::insertItem(ItemType &item){
  insert(root,item);
  length++;
}

void BinaryTree::insert(TreeNode*& tree, ItemType item){
  if(tree == nullptr){
    tree = new TreeNode;
    tree->right = nullptr;
    tree->left = nullptr;
    tree->info.initialize(item.getValue());
  }else if(item.compareTo(tree->info) == LESS){
    insert(tree->left,item);
  }else if(item.compareTo(tree->info) == GREATER){
    insert(tree->right,item);
  }else{
    return;
  }
}

/**
the node that contains item is removed from the tree.
@param item: this is the item you want to delete
*/
void BinaryTree::deleteItem(ItemType &item){
  Delete(root,item);
}

void BinaryTree::Delete(TreeNode*& tree, ItemType item){
  if(item.compareTo(tree->info) == LESS){
    Delete(tree->left,item);
  }else if(item.compareTo(tree->info) == GREATER){
    Delete(tree->right,item);
  }else{
    DeleteNode(tree);
  }
}

void BinaryTree::DeleteNode(TreeNode*& tree){
  ItemType data;
  TreeNode* tempPtr;

  tempPtr = tree;
  if(tree->left == nullptr){
    tree = tree->right;
    delete tempPtr;
  }else if(tree->right == nullptr){
    tree = tree->left;
    delete tempPtr;
  }else{
    getPredecessor(tree->left,data);
    tree->info = data;
    Delete(tree->left,data);
  }
}

void BinaryTree:: getPredecessor(TreeNode* tree, ItemType& data){
  while(tree->right != nullptr){
    tree = tree->right;
    data = tree->info;
  }
}

void BinaryTree::preOrder()const{
  prePrint(root);
}

void BinaryTree::prePrint(TreeNode* tree)const{
  if(tree != nullptr){
    cout << tree->info.getValue() << " ";
    prePrint(tree->left);
    prePrint(tree->right);
  }
}

void BinaryTree::inOrder()const{
  inPrint(root);
}

void BinaryTree::inPrint(TreeNode* tree)const{
  if(tree != nullptr){
    inPrint(tree->left);
    cout << tree->info.getValue() << " ";
    inPrint(tree->right);
  }
}

void BinaryTree::postOrder()const{
  postPrint(root);
}

void BinaryTree::postPrint(TreeNode* tree)const{
  if(tree != nullptr){
    postPrint(tree->left);
    postPrint(tree->right);
    cout << tree->info.getValue() << " ";
  } 
}

int BinaryTree::getLength()const{
  return countNode(root);
}

int BinaryTree::countNode(TreeNode* tree)const{
  if(tree == nullptr){
    return 0;
  }else{
    return countNode(tree->left) + countNode(tree->right) + 1;
  }
}
