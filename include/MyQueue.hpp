#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <vector>

template <class T, class Alloc = std::allocator<T>>
class MyQueue {
  public:
   using value_type = T;
   using size_type = std::size_t;
   using reference = value_type&;
   using const_reference = const value_type&;
   using allocator_type = Alloc;
   using iterator = typename std::vector<T>::iterator;
   using const_iterator = typename std::vector<T>::const_iterator;

   MyQueue(const Alloc& alloc = Alloc());

   reference front();
   const_reference front() const;
   void push(const value_type& value);
   void pop();
   bool empty() const;
   size_type size() const;
   iterator begin();
   const_iterator begin() const;
   iterator end();
   const_iterator end() const;

  private:
   std::vector<T, Alloc> m_vector;
};

#endif