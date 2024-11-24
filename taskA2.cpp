#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

class ArrayGenerator {
 public:
  static std::vector<int> generateRandomArray() {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distr(0, 6000);
    std::vector<int> arr(10000);
    for (int i = 0; i < 10000; ++i) {
      arr[i] = distr(generator);
    }
    return arr;
  }

  static std::vector<int> generateReverseSortedArray() {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distr(0, 6000);
    std::vector<int> arr(10000);
    for (int i = 0; i < 10000; ++i) {
      arr[i] = distr(generator);
    }
    std::sort(arr.begin(), arr.end());
    std::reverse(arr.begin(), arr.end());
    return arr;
  }

  static std::vector<int> generateNearlySortedArray() {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<> distr(0, 6000);
    std::vector<int> arr(10000);
    for (int i = 0; i < 10000; ++i) {
      arr[i] = distr(generator);
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < 15; ++i) {
      std::uniform_int_distribution<> distrs(0, 500);
      int idx1 = distrs(generator);
      int idx2 = distrs(generator);
      std::swap(arr[idx1], arr[idx2]);
    }
    for (int i = 500; i <= 9900; i += 100) {
      std::uniform_int_distribution<> distrs(i, i + 100);
      for (int j = 0; j < 3; ++j) {
        int idx1 = distrs(generator);
        int idx2 = distrs(generator);
        std::swap(arr[idx1], arr[idx2]);
      }
    }
    return arr;
  }
};

class SortTester {
 private:
  static void insertionSort(std::vector<int>& vect, int start, int end) {
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

  static void merge(std::vector<int>& vect, int start, int middle, int end) {
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

  static void mergeInsertionSort(std::vector<int>& vect, int start, int end, int threshold) {
    if (end - start + 1 <= threshold) {
      insertionSort(vect, start, end);
      return;
    }
    if (start >= end) {
      return;
    }
    int middle = start + (end - start) / 2;
    mergeInsertionSort(vect, start, middle, threshold);
    mergeInsertionSort(vect, middle + 1, end, threshold);
    merge(vect, start, middle, end);
  }

  static void mergeSort(std::vector<int>& vect, int start, int end) {
    if (start >= end) {
      return;
    }
    int middle = start + (end - start) / 2;
    mergeSort(vect, start, middle);
    mergeSort(vect, middle + 1, end);
    merge(vect, start, middle, end);
  }

 public:
  static long long testMergeSort(std::vector<int>& arr) {
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr, 0, arr.size() - 1);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
  }

  static long long testMergeInsertionSort(std::vector<int>& arr, int threshold) {
    auto start = std::chrono::high_resolution_clock::now();
    mergeInsertionSort(arr, 0, arr.size() - 1, threshold);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    return std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
  }
};

template <typename T>
void printVector(const std::vector<T>& vec) {
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i] << ", ";
  }
  std::cout << std::endl << std::endl;
}

int main() {
  std::vector<int> randomArrParent = ArrayGenerator::generateRandomArray();
  std::vector<int> reverseArrParent = ArrayGenerator::generateReverseSortedArray();
  std::vector<int> nearlySortedArrParent = ArrayGenerator::generateNearlySortedArray();
  double timeMergeArr;
  double timeMergeReverse;
  double timeInsertionMergeReverse;
  double timeMergeNear;
  double timeInsertionMergeNear;
  double timek10;
  double timek20;
  double timek30;
  double timek40;
  double timek50;
  std::vector<double> vecTimeMergeArr;
  std::vector<double> vecTimeMergeReverse;
  std::vector<double> vecTimeInsertionMergeReverse;
  std::vector<double> vecTimeMergeNear;
  std::vector<double> vecTimeInsertionMergeNear;
  std::vector<double> veck10;
  std::vector<double> veck20;
  std::vector<double> veck30;
  std::vector<double> veck40;
  std::vector<double> veck50;
  std::vector<int> is;
  for (int i = 500; i <= 10000; i += 100) {
    is.push_back(i);
    for (int j = 0; j < 5; ++j) {
      std::vector<int> randomArr = std::vector<int>(randomArrParent.begin(), randomArrParent.begin() + i);
      timeMergeArr += SortTester::testMergeSort(randomArr);
      randomArr = std::vector<int>(randomArrParent.begin(), randomArrParent.begin() + i);
      timek10 += SortTester::testMergeInsertionSort(randomArr, 20);
      randomArr = std::vector<int>(randomArrParent.begin(), randomArrParent.begin() + i);
      timek20 += SortTester::testMergeInsertionSort(randomArr, 50);
      randomArr = std::vector<int>(randomArrParent.begin(), randomArrParent.begin() + i);
      timek30 += SortTester::testMergeInsertionSort(randomArr, 100);
      randomArr = std::vector<int>(randomArrParent.begin(), randomArrParent.begin() + i);
      timek40 += SortTester::testMergeInsertionSort(randomArr, 300);
      randomArr = std::vector<int>(randomArrParent.begin(), randomArrParent.begin() + i);
      timek50 += SortTester::testMergeInsertionSort(randomArr, 500);

      std::vector<int> reverseArr = std::vector<int>(reverseArrParent.begin(), reverseArrParent.begin() + i);
      timeMergeReverse += SortTester::testMergeSort(reverseArr);
      reverseArr = std::vector<int>(reverseArrParent.begin(), reverseArrParent.begin() + i);
      timeInsertionMergeReverse += SortTester::testMergeInsertionSort(reverseArr, 20);

      std::vector<int> nearlySortedArr =
          std::vector<int>(nearlySortedArrParent.begin(), nearlySortedArrParent.begin() + i);
      timeMergeNear += SortTester::testMergeSort(nearlySortedArr);
      nearlySortedArr = std::vector<int>(nearlySortedArrParent.begin(), nearlySortedArrParent.begin() + i);
      timeInsertionMergeNear += SortTester::testMergeInsertionSort(nearlySortedArr, 20);
    }
    timeMergeArr /= 5.;
    timeMergeReverse /= 5.;
    timeInsertionMergeReverse /= 5.;
    timeMergeNear /= 5.;
    timeInsertionMergeNear /= 5.;
    timek10/=5.;
    timek20/=5.;
    timek30/=5.;
    timek40/=5.;
    timek50/=5.;


    vecTimeMergeArr.push_back(timeMergeArr);
    vecTimeMergeReverse.push_back(timeMergeReverse);
    vecTimeInsertionMergeReverse.push_back(timeInsertionMergeReverse);
    vecTimeMergeNear.push_back(timeMergeNear);
    vecTimeInsertionMergeNear.push_back(timeInsertionMergeNear);
    veck10.push_back(timek10);
    veck20.push_back(timek20);
    veck30.push_back(timek30);
    veck40.push_back(timek40);
    veck50.push_back(timek50);
  }
  printVector(is);
  printVector(vecTimeMergeArr);
  printVector(veck10);
  printVector(veck20);
  printVector(veck30);
  printVector(veck40);
  printVector(veck50);
  printVector(vecTimeMergeReverse);
  printVector(vecTimeInsertionMergeReverse);
  printVector(vecTimeMergeNear);
  printVector(vecTimeInsertionMergeNear);
}