#ifndef FUNCTION_H
#define FUNCTION_H

#include "headers.h"

namespace function {

template <template <typename, typename> class Conteiner, typename T>
void FindPrimes(Conteiner<T, std::allocator<T>> &data) {
  try {
    auto start = data.begin();
    start++;
    T num = *start;
    while (start != data.end()) {
      for (auto ptr = start; ptr != data.end(); ptr++) {
        if ((*ptr) != num && num != 0 && (*ptr) % (num) == 0) {
          *ptr = 0;
        }
      }
      start++;
      num = *start;
    }
    data.erase(std::remove_if(data.begin(), data.end(),
                              [](const auto &unit) {
                                if (0 == unit) return true;
                              }),
               data.end());

  } catch (std::exception &exp) {
    std::cout << exp.what() << std::endl;
  }
}

std::unique_ptr<std::map<int, int>> WordCount(std::string path);
std::pair<unsigned int, unsigned int> GetMinMax(unsigned int value);

}  // namespace function

#endif  // FUNCTION_H
