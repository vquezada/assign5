#include <cstddef>
#include <iostream>
using namespace std;
//tree structure
template <class T>
class TreeNode
{
public:
  TreeNode();
  TreeNode(T k);
  ~TreeNode();

  T key;
  TreeNode* left;
  TreeNode* right;
};
template <class T>
TreeNode<T>::TreeNode()
{
  key = NULL;
  left = NULL;
  right = NULL;
}
template <class T>
TreeNode<T>::TreeNode(T k)
{
  key = k;
  left = NULL;
  right = NULL;
}
template <class T>
TreeNode<T>::~TreeNode()
{
  delete left;
  delete right;
}
