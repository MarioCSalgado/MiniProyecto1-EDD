#include "ListArr.h"
#include <chrono>
#include <iostream>

int main() {
  int n = 1000000;
  int b = 64;
  int repetitions = 20;
  double total_time = 0;
  for (int i = 0; i < repetitions; i++) {
    ListArr listarr(b);
    auto start = std::chrono::high_resolution_clock::now();
    for (int j = 0; j < n; j++) {
      listarr.insert_left(j);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    total_time += duration.count();
  }
  double average_time = total_time / repetitions;
  std::cout << "Average time for insert_left() with n=" << n << " and b=" << b
            << ": " << average_time << " microseconds" << std::endl;
  return 0;
}
