#pragma once
#include "File.h"

const int DEFAULT_CAPACITY = 8;

class Directory : public File {
    File** files;
    size_t fileCount;
    size_t capacity;

    void resize(unsigned newCap);
    void free();
    void copyFrom(const Directory& other);
    void moveFrom(Directory&& other);

    void printInDir(unsigned depth) const override;
public:
    Directory(const Directory& other);
    Directory(const char* filename);
    Directory(Directory&& other);
    ~Directory();

    void printContent() const override;
    File* clone() const override;

    Directory& operator=(const Directory& other);
    Directory& operator=(Directory&& other);

    void add(const File& file);
    void add(File* file);
    bool contains(const char* filename) const;
    File* getFileByName(const char* name) const;
};