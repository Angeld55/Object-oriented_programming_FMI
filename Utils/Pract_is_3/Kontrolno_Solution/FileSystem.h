#pragma once
#include "Files/Directory.h"
#include "Files/TextFile.h"

class FileSystem
{
	Directory* root;

	char* getNextFilename(const char* path) const;
	char* getPrevFilename(const char* path) const;
	File* getFileFromSubfolder(const Directory* subfolder, const char* path) const;
	void createSubfolderInFolder(Directory* folder, const char* path);

	void copyFrom(const FileSystem& other);
	void moveFrom(FileSystem&& other);
	void free();
public:
	FileSystem();
	~FileSystem();
	FileSystem(const FileSystem& other);
	FileSystem(FileSystem&& other);
	FileSystem& operator=(const FileSystem& other);
	FileSystem& operator=(FileSystem&& other);

	void createTextFile(const char* path, const char* content);
	void createDirectory(const char* path);
	File* getFile(const char* path) const;
	void printFile(const char* path) const;
};

