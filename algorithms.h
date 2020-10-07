template <template <typename, typename> class Conteiner, typename T>
T SearchNumber(const Conteiner<T, std::allocator<T>> &conteiner, int N) {
  auto S = std::accumulate(conteiner.begin(), conteiner.end(), 0);
  auto K = N - 1;
  auto num = (K + 1) * (K + 2) / 2 - S;
  return num;
}

template <class Conteiner>
size_t Count(const Conteiner &conteiner, int number) {
  size_t count = 0;
  for (const auto &unit : conteiner) {
    if (unit == number) {
      count += 1;
    }
  }
  return count;
}

template <template <typename, typename> class Conteiner, typename T>
std::map<T, T> Count(const Conteiner<T, std::allocator<T>> &conteiner) {
  std::map<T, T> data;
  for (const auto &unit : conteiner) {
    data[unit] += 1;
  }
  return data;
}

template <template <typename, typename> class Conteiner, typename T>
std::pair<T, T> MinMax(const Conteiner<T, std::allocator<T>> &conteiner) {
  T min = *conteiner.begin();
  T max = *conteiner.begin();
  for (const auto &unit : conteiner) {
    min = unit < min ? unit : min;
    max = unit > max ? unit : max;
  }
  return {min, max};
}

