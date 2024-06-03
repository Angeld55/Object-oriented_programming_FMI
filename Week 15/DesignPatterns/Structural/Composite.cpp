#include <iostream>
#include "polymorphic_ptr.hpp"
#include "MyVector.hpp"

class FileSystemEntity {
public:
	virtual size_t getSize() const = 0;
	virtual ~FileSystemEntity() = default;
};

class File : public FileSystemEntity {
	size_t size = 0;
public:
	size_t getSize() const {
		return size;
	}
};

class Directory : public FileSystemEntity {
	Vector<polymorphic_ptr<FileSystemEntity>> children;
public:
	size_t getSize() const {
		size_t size = 0;
		for (size_t i = 0; i < children.getSize(); i++) {
			size += children[i]->getSize();
		}

		return size;
	}
};

int main() {

}
