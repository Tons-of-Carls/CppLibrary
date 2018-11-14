#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <memory>

template <typename T>
class Queue
{
public:
  void enqueue(T& element);
  std::unique_ptr<T> dequeue();
  const T& first();
private:
  class Node
  {
  public:
    T element;
    std::shared_ptr<Node> next = nullptr;
  };

  std::shared_ptr<Node> front = nullptr;
  std::shared_ptr<Node> back = nullptr;
};

#endif // QUEUE_HPP
