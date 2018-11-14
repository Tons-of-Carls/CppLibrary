#include "AVL.hpp"

template <typename T>
void AVL::insert(T& element)
{
  if(root == nullptr)
  {
    root = std::shared_ptr<Node>(new Node());
    root->element = element;
    return;
  }

  inserted = false;

  _insert(root, element);
}

template <typename T>
std::unique_ptr<T> AVL::remove(T& element)
{
  
}

int AVL::_getNodeHeight(std::shared_ptr<Node> node)
{
  if(node == nullptr)
  {
    return -1;
  }
  return node->height;
}

template <typename T>
std::shared_ptr<Node> AVL::_insert(std::shared_ptr<Node> node, T& element)
{  
  if(node->element == element)
  {
    inserted = false;
    return node;
  }
  else if(element > node->element)
  {
    if(node->right == nullptr)
    {
      node->right = std::shared_ptr<Node>(new Node());
      node->right->element = element;
      inserted = true;
      if(node->left == nullptr)
      {
        node->height++;
      }
      return node;
    }
    _insert(node->right, element);

    if(inserted && _getNodeHeight(node->right) > _getNodeHeight(node->left))
    {
      node->height++;
    }
  }
  else
  {
    if(node->left == nullptr)
    {
      node->left = std::shared_ptr<Node>(new Node());
      node->left->element = element;
      inserted = true;
      if(node->right == nullptr)
      {
        node->height++;
      }
      return node;
    }
    _insert(node->left, element);

    if(inserted && _getNodeHeight(node->left) > _getNodeHeight(node->right))
    {
      node->height++;
    }
  }

  int heightDiff = _getNodeHeight(node->left) - _getNodeHeight(node->right);

  if(heightDiff > 1)
  {
    if(_getNodeHeight(node->left->left) > _getNodeHeight(node->left->right))
    {
      return llRotation(node);
    }
    return lrRotation(node);
  }

  if(heightDiff < -1)
  {
    if(_getNodeHeight(node->right->left) > _getNodeHeight(node->right->right))
    {
      return rlRotation(node);
    }
    return rrRotation(node);
  }

  return node;
}

// Rotations

template <typename T>
std::shared_ptr<Node> AVL::llRotation(std::shared_ptr<Node> nodeB)
{
  std::shared_ptr<Node> nodeA = nodeB->left;
  std::shared_ptr<Node> t2 = nodeA->right;
  nodeA->right = nodeB;
  nodeB->left = t2;
  // update height
  return nodeA;
}

template <typename T>
std::shared_ptr<Node> AVL::rrRotation(std::shared_ptr<Node> nodeA)
{
  std::shared_ptr<Node> nodeB = nodeA->right;
  std::shared_ptr<Node> t2 = nodeB->left;
  nodeB->left = nodeA;
  nodeA->right = t2;
  // update height
  return nodeB;
}

template <typename T>
std::shared_ptr<Node> AVL::lrRotation(std::shared_ptr<Node> nodeC)
{
  nodeC->left = rrRotation(nodeC->left);
  return llRotation(nodeC);
}

template <typename T>
std::shared_ptr<Node> AVL::rlRotation(std::shared_ptr<Node> nodeA)
{
  nodeA->right = llRotation(nodeA->left);
  return rrRotation(nodeA);
}
