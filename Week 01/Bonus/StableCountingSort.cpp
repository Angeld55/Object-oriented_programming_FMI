#include <iostream>

void stableCountingSort(char* arr, size_t length) {
	size_t arrLength = strlen(arr);
	char* copy = new char[arrLength];
	// copy the original
	for (size_t i = 0; i < arrLength; i++) {
		copy[i] = arr[i];
	}
	
	int counter[256] = { 0 };
	// count every char
	for (size_t i = 0; i < length; i++) {
		counter[arr[i]]++;
	}

	// the counter will become the index where the next element
	// of every different type should be placed
	for (size_t i = 1; i < 256; i++) {
		counter[i] += counter[i - 1];
	}

	// put the characters in the initial array sorted
	// started backwards so that the sorting is stable
	for (int i = arrLength - 1; i >= 0; i--) {
		// counter[copy[i] - 1 => where the element should be placed
		arr[counter[copy[i]] - 1] = copy[i];
		// the next element of this type should be placed one index behind this one
		--counter[copy[i]];
	}

	delete[] copy;
}

int main() {
	char arr[] = "ababababababa";
	stableCountingSort(arr, 13);
	std::cout << arr;
}
