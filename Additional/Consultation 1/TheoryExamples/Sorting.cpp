#include <iostream>

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void print(const int* arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i] << " ";
	}
}

void bubbleSort(int* arr, size_t length) {
	for (size_t i = 0; i < length - 1; i++) {
		bool hasSwaps = false;

		// last i numbers are already ordered
		for (size_t j = 0; j < length - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				hasSwaps = true;
			}
		}

		if (!hasSwaps) {// if no swaps were made - array is ordered
			break;
		}
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

int main1() {
	int arr[] = { 9, 5, 6, 3, 4, 7, 2, 1, 8 };

	selectionSort(arr, 9);	// not stable
	bubbleSort(arr, 9);		// stable
	print(arr, 9);
	return 0;
}