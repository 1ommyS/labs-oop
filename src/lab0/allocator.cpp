#pragma once;
#include "allocator.h"

template <typename T>
T* MyAllocator<T>::allocate(std::size_t n) {
   if (n > std::size_t(-1) / sizeof(T)) {
      throw std::bad_alloc();
   }

   // Выравнивание памяти
   constexpr std::size_t alignment = alignof(T);
   std::size_t size = n * sizeof(T);
   void* ptr = nullptr;

   if (posix_memalign(&ptr, alignment, size) != 0) {
      throw std::bad_alloc();
   }

   allocatedBlocks[ptr] = size;

   return static_cast<T*>(ptr);
}

template <typename T>
void MyAllocator<T>::deallocate(T* p, std::size_t n) noexcept {
   // Освобождение памяти
   auto it = allocatedBlocks.find(p);
   if (it != allocatedBlocks.end()) {
      std::size_t size = it->second;
      allocatedBlocks.erase(it);
      std::free(p);
   }
}

template <typename T, typename U>
bool operator==(const MyAllocator<T>&, const MyAllocator<U>&) noexcept {
   return true;
}

template <typename T, typename U>
bool operator!=(const MyAllocator<T>&, const MyAllocator<U>&) noexcept {
   return false;
}