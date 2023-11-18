#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <vector>
#include "MyQueue.hpp"
#include "allocator.hpp"

using namespace std;

int factorial(int n) { return (n == 0) ? 1 : n * factorial(n - 1); }

int main() {
   std::map<int, int, std::less<int>, MAI::Allocator<std::pair<const int, int>>>
       m;
   for (int i = 0; i < 10; ++i) {
      m[i] = factorial(i);
   }

   for (const auto& p : m) {
      std::cout << p.first << ' ' << p.second << '\n';
   }

   MyQueue<int, MAI::Allocator<int>> q;
   for (int i = 0; i < 10; ++i) {
      q.push(i);
   }

   while (!q.empty()) {
      std::cout << q.front() << ' ';
      q.pop();
   }

   return 0;
}