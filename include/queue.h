#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>
#include <vector>
#include "allocator.h"

namespace MAI {

template <typename T, typename Alloc>
class Queue {
  public:
   using allocator_type = Alloc;
   using value_type = T;
   using size_type = typename std::vector<T, Alloc>::size_type;
   using reference = typename std::vector<T, Alloc>::reference;
   using const_reference = typename std::vector<T, Alloc>::const_reference;
   using iterator = typename std::vector<T, Alloc>::iterator;
   using const_iterator = typename std::vector<T, Alloc>::const_iterator;

  private:
   std::vector<T, Alloc> data;

  public:
   Queue(const Alloc& alloc = Alloc());

   bool empty() const;
   size_type size() const;
   void push(const T& value);
   void pop();
   reference front();
   const_reference front() const;
   iterator begin();
   const_iterator begin() const;
   iterator end();
   const_iterator end() const;
};
}  // namespace MAI

#endif