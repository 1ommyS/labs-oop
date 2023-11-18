#include "MyQueue.hpp"

template <class T, class Alloc>
MyQueue<T, Alloc>::MyQueue(const Alloc& alloc) : m_vector(alloc) {}

template <class T, class Alloc>
typename MyQueue<T, Alloc>::reference MyQueue<T, Alloc>::front() {
   return m_vector.front();
}

template <class T, class Alloc>
typename MyQueue<T, Alloc>::const_reference MyQueue<T, Alloc>::front() const {
   return m_vector.front();
}

template <class T, class Alloc>
void MyQueue<T, Alloc>::push(const value_type& value) {
   m_vector.push_back(value);
}

template <class T, class Alloc>
void MyQueue<T, Alloc>::pop() {
   m_vector.erase(m_vector.begin());
}

template <class T, class Alloc>
bool MyQueue<T, Alloc>::empty() const {
   return m_vector.empty();
}

template <class T, class Alloc>
typename MyQueue<T, Alloc>::size_type MyQueue<T, Alloc>::size() const {
   return m_vector.size();
}

template <class T, class Alloc>
typename MyQueue<T, Alloc>::iterator MyQueue<T, Alloc>::begin() {
   return m_vector.begin();
}

template <class T, class Alloc>
typename MyQueue<T, Alloc>::const_iterator MyQueue<T, Alloc>::begin() const {
   return m_vector.begin();
}

template <class T, class Alloc>
typename MyQueue<T, Alloc>::iterator MyQueue<T, Alloc>::end() {
   return m_vector.end();
}

template <class T, class Alloc>
typename MyQueue<T, Alloc>::const_iterator MyQueue<T, Alloc>::end() const {
   return m_vector.end();
}