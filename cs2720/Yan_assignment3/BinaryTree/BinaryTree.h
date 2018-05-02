#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "ItemType.h"
#include <iostream>

using namespace std;

struct TreeNode{
  ItemType info;
  TreeNode* left;
  TreeNode* right;
};

class BinaryTree{
  
  TreeNode* root;
  int length;
    
 public:
  BinaryTree();
  ~BinaryTree();
  void destory(TreeNode*& tree);
  void retrieveItem(ItemType &item, bool &found)const;
  void retrieve(TreeNode* tree, ItemType &item, bool &found)const;
  void insertItem(ItemType &item);
  void insert(TreeNode*& tree, ItemType item);
  void deleteItem(ItemType &item);
  void Delete(TreeNode*& tree, ItemType item);
  void DeleteNode(TreeNode*& tree);
  void getPredecessor(TreeNode* tree, ItemType& data);
  void preOrder()const;
  void prePrint(TreeNode* tree)const;
  void inOrder()const;
  void inPrint(TreeNode* tree)const;
  void postOrder()const;
  void postPrint(TreeNode* tree)const;
  int getLength()const;
  int countNode(TreeNode* tree)const;
};


#endif
