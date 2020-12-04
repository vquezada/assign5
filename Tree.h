#include <cstddef>
#include <iostream>
#include <fstream>
#include "TreeNode.h"
using namespace std;
template <class T>
class Tree
{
private:
  TreeNode<T>* root;
public:
  Tree();
  ~Tree();

  void insert(T value);
  bool deleteNode(T value);

  bool isEmpty();

  TreeNode<T>* search(T value);
  TreeNode<T>* getSuccessor(TreeNode<T>* s);
  TreeNode<T>* getMin();
  TreeNode<T>* getMax();

  void printTree();
  void treeOrder(TreeNode<T>* node);
  void deleteTreeNode(TreeNode<T>* node);
  void treeToFile(ofstream& myFile);
  void treeToFile2(TreeNode<T>* node, ofstream& myFile);

};

template <class T>
Tree<T>::Tree()
{
  root = NULL;
}

template <class T>
Tree<T>::~Tree()
{
  deleteTreeNode(root);
}
//deletes nodes
template <class T>
void Tree<T>::deleteTreeNode(TreeNode<T>* node)
{
  if (node)
  {
    deleteTreeNode(node->left);
    deleteTreeNode(node->right);
    delete node;
  }
}
//orders tree
template <class T>
void Tree<T>::treeOrder(TreeNode<T>* node)
{
  if (node == NULL)
    return;

  treeOrder(node->left);
  cout << node->key << endl;
  treeOrder(node->right);
}
//prints tree
template <class T>
void Tree<T>::printTree()
{
 treeOrder(root);
}

template <class T>
TreeNode<T>* Tree<T>::getMin()
{
  TreeNode<T>* current = root;

  if (root == NULL)
    return NULL;

  while (current->left != NULL)
    current = current->left;

  return current;
}
//gets max
template <class T>
TreeNode<T>* Tree<T>::getMax()
{
  TreeNode<T>* current = root;

  if (root == NULL)
    return NULL;

  while (current->right != NULL)
    current = current->right;

  return current;
}
//inserts
template <class T>
void Tree<T>::insert(T value)
{
  TreeNode<T>* node = new TreeNode<T>(value);

  if (root == NULL)
    root = node;
  else
  {
    TreeNode<T>* current = root;
    TreeNode<T>* parent = NULL;

    while (true)
    {
      parent = current;

      if (value < current->key)
      {
        current = current->left;
        if (current == NULL)
        {
          parent->left = node;
          break;
        }
      }
      else
      {
        current = current->right;

        if (current == NULL)
        {
          parent->right = node;
          break;
        }
      }
    }
  }
}
//searches
template <class T>
TreeNode<T>* Tree<T>::search(T value)
{
  if (root == NULL)
    return NULL;

  TreeNode<T>* current = root;

  while (current->key != value)
  {
    if (value < current->key)
      current = current->left;
    else
      current = current->right;

    if (current == NULL)
      return NULL;
  }

  return current;
}
//deletes node
template <class T>
bool Tree<T>::deleteNode(T value)
{
  if (root == NULL)
    return false;

  TreeNode<T>* current = root;
  TreeNode<T>* parent = root;
  bool isLeft = true;

  while (current->key != value)
  {
    parent = current;

    if (value < current->key)
    {
      isLeft = true;
      current = current->left;
    }
    else
    {
      isLeft = false;
      current = current->right;
    }

    if (current == NULL)
      return false;
  }
  if (current->left == NULL && current->right == NULL)
  {
    if (current == root)
      root = NULL;
    else if (isLeft)
      parent->left = NULL;
    else
      parent->right = NULL;
  }
  else
  {
    TreeNode<T>* successor = getSuccessor(current);

    if (current == root)
      root = successor;
    else if (isLeft)
      parent->left = successor;
    else
      parent->right = successor;

    successor->left = current->left;
  }
}
//gets the successor
template <class T>
TreeNode<T>* Tree<T>::getSuccessor(TreeNode<T>* s)
{
  TreeNode<T>* current = s->right;
  TreeNode<T>* sp = s;
  TreeNode<T>* successor = s;

  while (current != NULL)
  {
    sp = successor;
    successor = current;
    current = current->left;
  }
  if (successor != s->right)
    sp->left = successor->right;

  return successor;
}
//tree to file
template <class T>
void Tree<T>::treeToFile(ofstream& myFile)
{
  treeToFile2(root, myFile);
}

template <class T>
void Tree<T>::treeToFile2(TreeNode<T>* node, ofstream& myFile)
{
  if (node == NULL)
    return;
  treeToFile2(node->left, myFile);
  myFile << node->key << endl;
  treeToFile2(node->right, myFile);
}
