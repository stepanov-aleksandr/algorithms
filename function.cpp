#include "function.h"

namespace function {
std::unique_ptr<std::map<int, int>> WordCount(std::string path) {
  std::ifstream file;
  file.open(path);
  if (!file.is_open()) {
    std::cerr << "error" << std::endl;
  }
  auto worlds = std::make_unique<std::map<int, int>>();
  std::string word;
  while (file) {
    file >> word;
    (*worlds)[word.size()]++;
  }
  return worlds;
}

std::pair<unsigned int, unsigned int> GetMinMax(unsigned int value) {
  unsigned int min_val = 0;
  unsigned int max_val = 0;

  std::vector<bool> data;
  for (unsigned int i = 0; i < 32; i++) {
    auto val_bit = (value >> i) & 1;
    data.insert(data.begin(), val_bit);
    if (val_bit == 1) {
      static auto i_min = 0;
      static auto i_max = 31;
      min_val = min_val | val_bit << i_min++;
      max_val = max_val | val_bit << i_max--;
    }
  }
  return {min_val, max_val};
}

}  // namespace function
