#include <iostream>
#include <cstring>

using namespace std;

template <typename T>
T max(const T *array, int size) {
  T max = array[0];

  for (int i = 0; i < size; i++) {
    if (max < array[i]) max = array[i];
  }

  return max;
}

int main(int argc, char **argv) {
  char charArray[] = "abcba";
  int intArray[] = {0, 1, 2, 1, 0};

  char maxChar = max(charArray, strlen(charArray));
  int maxInt = max(intArray, sizeof(intArray) / sizeof(intArray[0]));

  cout << "Maximum char element: " << maxChar << endl;
  cout << "Maximum int element: " << maxInt << endl;

  return 0;
}
