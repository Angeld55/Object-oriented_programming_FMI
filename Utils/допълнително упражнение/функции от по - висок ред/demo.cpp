#include<iostream>
#include<vector>

template<class T>
class Entity {
private:
	int integerData;
	char symbolData;
	T abstractData;

public:
	Entity(int iArg, char cArg, const T& aArg) : integerData(iArg), symbolData(cArg), abstractData(aArg) {}

	int getIntegerData() const {
		return integerData;
	}

	char getCharData() const {
		return symbolData;
	}

	const T& getAbstractData() const {
		return abstractData;
	}

	void print() const {
		std::cout << integerData << " " << symbolData << " " << abstractData << std::endl;
	}
};

template<class T>
bool compareIntegerValues(const Entity<T>& fst, const Entity<T>& snd) {
	return fst.getIntegerData() < snd.getIntegerData();
}

template<class T>
bool compareCharValues(const Entity<T>& fst, const Entity<T>& snd) {
	return fst.getCharData() < snd.getCharData();
}

template<class T>
bool compareAbstractValues(const Entity<T>& fst, const Entity<T>& snd) {
	return fst.getAbstractData() < snd.getAbstractData();
}

template<class T>
void sort(std::vector<Entity<T>>& collection, bool (*lessThan)(const Entity<T>&, const Entity<T>&)) {
	for (size_t i = 0; i < collection.size(); i++) {
		size_t minElementIndex = i;

		for (size_t j = i + 1; j < collection.size(); j++) {
			if (lessThan(collection[j], collection[minElementIndex])) {
				minElementIndex = j;
			}
		}

		if (minElementIndex != i)
			std::swap(collection[i], collection[minElementIndex]);
	}
}

char generateRandomLetter() {
	return (char)(rand() % 26 + 'a');
}

double generateRandomDouble() {
	return (double)rand() / RAND_MAX + rand() % 256;
}

int main() {
	std::vector<Entity<double>> collection;

	for (size_t i = 0; i < 100; i++)
		collection.push_back({ rand() % 10000, generateRandomLetter(), generateRandomDouble() });


	// Sort integer values
	// sort(collection, compareIntegerValues);

	// Sort char values
	// sort(collection, compareCharValues);

	// Sort abstract values
	sort(collection, compareAbstractValues);


	for (size_t i = 0; i < 100; i++)
		collection[i].print();
}
