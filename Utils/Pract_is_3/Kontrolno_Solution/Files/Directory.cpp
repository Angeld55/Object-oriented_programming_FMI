#include "Directory.h"
#pragma warning (disable : 4996)


Directory::Directory(const char* filename) : File(filename) {
    files = new File * [DEFAULT_CAPACITY] {nullptr};
    capacity = DEFAULT_CAPACITY;
    fileCount = 0;
}

Directory::~Directory() {
    free();
}

void Directory::copyFrom(const Directory& other) {
    files = new File * [other.capacity];

    for (int i = 0; i < other.fileCount; i++) {
        files[i] = other.files[i]->clone();
    }

    fileCount = other.fileCount;
    capacity = other.capacity;
}

void Directory::moveFrom(Directory&& other) {
    files = other.files;
    fileCount = other.fileCount;
    capacity = other.capacity;

    other.files = nullptr;
    other.fileCount = 0;
    other.capacity = 0;
}

void Directory::free() {
    for (int i = 0; i < fileCount; i++) {
        delete files[i];
    }

    delete[] files;
}

void Directory::resize(unsigned newCapacity) {
    if (newCapacity < fileCount) return;

    File** newFiles = new File * [newCapacity];
    for (int i = 0; i < fileCount; i++) {
        newFiles[i] = files[i];
    }
    capacity = newCapacity;

    delete[] files;
    files = newFiles;
}


Directory::Directory(const Directory& other) : File(other) {
    copyFrom(other);
}

Directory::Directory(Directory&& other) : File(std::move(other)) {
    moveFrom(std::move(other));
}

Directory& Directory::operator=(Directory&& other) {
    if (this != &other)
    {
        File::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

Directory& Directory::operator=(const Directory& other) {
    if (this != &other) {
        File::operator=(other);
        free();
        copyFrom(other);
    }

    return *this;
}


File* Directory::clone() const {
    return new Directory(*this);
}


void Directory::add(const File& file) {
    add(file.clone());
}

void Directory::add(File* file) {
    // steals the pointer
    if (fileCount == capacity) {
        resize(capacity * 2);

    }
    files[fileCount++] = file;
}


bool Directory::contains(const char* filename) const {
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i]->getName(), filename) == 0) {
            return true;
        }
    }
    return false;
}


void Directory::printContent() const {
    printInDir(0); 
    // the depth of the folder this method is called from is 0, 
    // meaning 
}

void Directory::printInDir(unsigned depth) const {
    File::printInDir(depth);
    for (int i = 0; i < fileCount; i++) {
        files[i]->printInDir(depth + 1); // the subfiles of a directory have a bigger depth
    }
}


File* Directory::getFileByName(const char* name) const {
    if (name == nullptr) {
        return nullptr;
    }
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i]->getName(), name) == 0) {
            return files[i];
        }
    }
    return nullptr;
}
