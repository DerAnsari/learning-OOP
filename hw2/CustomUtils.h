#ifndef CUSTOM_UTILS_H
#define CUSTOM_UTILS_H

#include <vector>

using std::vector;

// Custom sorting algorithm (Bubble Sort) that takes a lambda/function pointer
// for comparison.
template <typename T, typename Compare>
void custom_sort(vector<T> &vec, Compare comp) {
  size_t n = vec.size();
  if (n == 0)
    return;
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < n - i - 1; ++j) {
      if (comp(vec[j + 1], vec[j])) {
        T temp = std::move(vec[j]);
        vec[j] = std::move(vec[j + 1]);
        vec[j + 1] = std::move(temp);
      }
    }
  }
}

// Custom filter that returns a new vector based on a predicate.
template <typename T, typename Predicate>
vector<T> custom_filter(const vector<T> &vec, Predicate pred) {
  vector<T> result;
  for (const auto &item : vec) {
    if (pred(item)) {
      result.push_back(item);
    }
  }
  return result;
}

#endif
