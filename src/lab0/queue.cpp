#pragma once;
#include "queue.h"

namespace MAI {

template <typename T, typename Alloc>
Queue<T, Alloc>::Queue(const Alloc& alloc) : data(alloc) {}

template <typename T, typename Alloc>
bool Queue<T, Alloc>::empty() const {
   return data.empty();
}

template <typename T, typename Alloc>
typename Queue<T, Alloc>::size_type Queue<T, Alloc>::size() const {
   return data.size();
}

template <typename T, typename Alloc>
void Queue<T, Alloc>::push(const T& value) {
   data.insert(data.begin(), value);
}

template <typename T, typename Alloc>
void Queue<T, Alloc>::pop() {
   if (data.empty()) {
      throw std::out_of_range("Queue is empty");
   }
   data.pop_back();
}

template <typename T, typename Alloc>
typename Queue<T, Alloc>::reference Queue<T, Alloc>::front() {
   if (data.empty()) {
      throw std::out_of_range("Queue is empty");
   }
   return data.back();
}

template <typename T, typename Alloc>
typename Queue<T, Alloc>::const_reference Queue<T, Alloc>::front() const {
   if (data.empty()) {
      throw std::out_of_range("Queue is empty");
   }
   return data.back();
}

template <typename T, typename Alloc>
typename Queue<T, Alloc>::iterator Queue<T, Alloc>::begin() {
   return data.begin();
}

template <typename T, typename Alloc>
typename Queue<T, Alloc>::const_iterator Queue<T, Alloc>::begin() const {
   return data.begin();
}

template <typename T, typename Alloc>
typename Queue<T, Alloc>::iterator Queue<T, Alloc>::end() {
   return data.end();
}

template <typename T, typename Alloc>
typename Queue<T, Alloc>::const_iterator Queue<T, Alloc>::end() const {
   return data.end();
}
}  // namespace MAI