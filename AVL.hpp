#ifndef AVL_HPP
#define AVL_HPP

#include <memory>

template <typename T>
class AVL
{
public:
  void insert(T& element);
  std::unique_ptr<T> remove(T& element);

  // Rotations
  std::shared_ptr<Node> llRotation(std::shared_ptr<Node> nodeB);
  std::shared_ptr<Node> rrRotation(std::shared_ptr<Node> nodeA);
  
  std::shared_ptr<Node> lrRotation(std::shared_ptr<Node> nodeC);
  std::shared_ptr<Node> rlRotation(std::shared_ptr<Node> nodeA);
  
private:
  class Node
  {
  public:
    T element;
    int height = 0;
    std::shared_ptr<Node> left = nullptr;
    std::shared_ptr<Node> right = nullptr;
  };

  int _getNodeHeight(std::shared_ptr<Node> node);
  std::shared_ptr<Node> _insert(std::shared_ptr<Node> node, T& element);
  
  std::shared_ptr<Node> root = nullptr;
  bool inserted = false;
};

#endif // AVL_HPP
