#ifndef MY_ALLOCATOR_H
#define MY_ALLOCATOR_H

#include <cstdlib>
#include <unordered_map>

template <typename T>
class MyAllocator {
  public:
   using value_type = T;

   MyAllocator() noexcept = default;

   template <typename U>
   MyAllocator(const MyAllocator<U>&) noexcept {}

   T* allocate(std::size_t n);

   void deallocate(T* p, std::size_t n) noexcept;

  private:
   std::unordered_map<void*, std::size_t> allocatedBlocks;
};

template <typename T, typename U>
bool operator==(const MyAllocator<T>&, const MyAllocator<U>&) noexcept;

template <typename T, typename U>
bool operator!=(const MyAllocator<T>&, const MyAllocator<U>&) noexcept;

#endif  // MY_ALLOCATOR_H