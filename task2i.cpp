#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& vect, int start, int end) {
  for (int i = start + 1; i <= end; ++i) {
    int key = vect[i];
    int j = i - 1;
    while (j >= start && vect[j] > key) {
      vect[j + 1] = vect[j];
      j--;
    }
    vect[j + 1] = key;
  }
}

void merge(std::vector<int>& vect, int start, int middle, int end) {
  int left_half_size = middle - start + 1;
  int right_half_size = end - middle;
  std::vector<int> left_half(left_half_size);
  std::vector<int> right_half(right_half_size);
  int i = 0;
  int j = 0;
  for (i = 0; i < left_half_size; ++i) {
    left_half[i] = vect[start + i];
  }
  for (i = 0; i < right_half_size; ++i) {
    right_half[i] = vect[middle + 1 + i];
  }
  i = 0;
  int curr = start;
  while (i < left_half_size && j < right_half_size) {
    if (left_half[i] <= right_half[j]) {
      vect[curr] = left_half[i];
      i++;
      curr++;
    } else {
      vect[curr] = right_half[j];
      j++;
      curr++;
    }
  }
  for (i; i < left_half_size; ++i) {
    vect[curr] = left_half[i];
    curr++;
  }
  for (j; j < right_half_size; ++j) {
    vect[curr] = right_half[j];
    curr++;
  }
}

void mergeSort(std::vector<int>& vect, int start, int end) {
  if (end - start + 1 <= 15) {
    insertionSort(vect, start, end);
    return;
  }
  if (start >= end) {
    return;
  }
  int middle = start + (end - start) / 2;
  mergeSort(vect, start, middle);
  mergeSort(vect, middle + 1, end);
  merge(vect, start, middle, end);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n = 0;
  std::cin >> n;
  std::vector<int> vect(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vect[i];
  }
  mergeSort(vect, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    std::cout << vect[i] << " ";
  }
  return 0;
}