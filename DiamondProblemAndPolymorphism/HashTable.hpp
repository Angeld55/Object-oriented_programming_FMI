#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<iostream>

const int N = 10;

template<typename K>
struct List {

	std::string key;
	K data;
	List* next;

	List(std::string key, K data) {
		this->key = key;
		this->data = data;
		next = nullptr;
	}
};

template<typename K>
class HashTable {

public:
	HashTable();
	HashTable(const HashTable&) = delete;
	HashTable& operator=(const HashTable&) = delete;
	~HashTable();
	void Put(std::string key, K data); //add element
	K Get(std::string key); //search for element
	void Remove(std::string key); //remove element

private:
	List<K>** hashTable;
	unsigned HashFunction(std::string key);
	List<K>* CheckKeyUniqueness(std::string key, int index);

};

#endif // !HASHTABLE_H

template<typename K>
HashTable<K>::HashTable() {

	hashTable = new List<K>*[N];
	for (int i = 0; i < N; i++) 
		hashTable[i] = nullptr;
	
}

template<typename K>
HashTable<K>::~HashTable() {

	for (int i = 0; i < N; i++) {

		List<K>* current = hashTable[i];
		while (current != nullptr) {
			List<K>* next = current->next;
			delete current;
			current = next;
		}
	}
	delete hashTable;
}

template<typename K>
void HashTable<K>::Put(std::string key, K data) {

	unsigned result = HashFunction(key);
	if (CheckKeyUniqueness(key, result) != nullptr)
		return;

	List<K>* newList = new List<K>(key, data);
	newList->next = hashTable[result];
	hashTable[result] = newList;
}

template<typename K>
K HashTable<K>::Get(std::string key) {

	unsigned result = HashFunction(key);
	List<K>* iter = hashTable[result];
	while (iter->key != key)
		iter = iter->next;

	if (iter != nullptr)
		return iter->data;
	else
		throw std::logic_error("Can't find this element.\n");
}

template<typename K>
void HashTable<K>::Remove(std::string key) {

	unsigned result = HashFunction(key);
	List<K>* iter = hashTable[result];
	List<K>* prev = iter;

	if (iter == hashTable[result] && iter->key == key) {
		hashTable[result] = iter->next;
		delete iter;
		return;
	}

	while (iter->key != key) {
		prev = iter;
		iter = iter->next;
	}
	
	prev->next = iter->next;
	delete iter;
}

template<typename K>
unsigned HashTable<K>::HashFunction(std::string key) {

	int keyLength = key.length();
	int result = keyLength;
	for (int i = 0; i < keyLength; i++)
		result = (result << 4) ^ (result >> 8) ^ (key[i]);

	return result % N;
}

template<typename K>
List<K>* HashTable<K>::CheckKeyUniqueness(std::string key, int index) {

	List<K>* iter = hashTable[index];
	while (iter != nullptr) {
		if (iter->key == key)
			return iter;
		iter = iter->next;
	}

	return nullptr;
}
