#include "Queue.hpp"

template <typename T>
void Queue<T>::enqueue(T& element)
{
  std::shared_ptr<Node> temp = std::shared_ptr<Node>(new Node());
  temp->element = element;
  
  if(front == nullptr)
  {
    front = temp;
    back = temp;
  }
  else
  {
    back->next = temp;
    back = temp;
  }
}

template <typename T>
std::unique_ptr<T> Queue<T>::dequeue()
{
  if(front != nullptr)
  {
    std::shared_ptr<Node> temp = front;
    front = front->next;
    return std::unique_ptr<T>(new T(temp->element));
  }
}

template <typename T>
const T& Queue<T>::first()
{
  if(front != nullptr)
  {
    return front->element;
  }
}
