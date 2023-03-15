#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void print(const int* arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i]<< " ";
	}
}

void selectionSort(int* arr, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		size_t minIndex = i;

		// first i numbers are already ordered
		for (size_t j = i + 1; j < length; j++) {
			if (arr[minIndex] > arr[j]) {
				minIndex = j;
			}
		}

		if (minIndex != i) { // if minIndex changed - swap
			swap(arr[i], arr[minIndex]);
		}
	}
}

int main() {
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	selectionSort(arr, 9);
	print(arr, 9);
}