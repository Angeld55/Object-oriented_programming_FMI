#include "FileSystem.h"
#pragma warning (disable : 4996)

FileSystem::FileSystem() {
	root = new Directory("root");
}

void FileSystem::createTextFile(const char* path, const char* content) {
	char* filename = getPrevFilename(path);
	if (filename == nullptr) {					// means there's no slash in the path
		return;									// all files start from root
	}

	int dirnameLen = strlen(path) - strlen(filename);
	char* directoryPath = new char[dirnameLen];
	strncpy(directoryPath, path, dirnameLen);
	directoryPath[dirnameLen - 1] = '\0';
	createDirectory(directoryPath);
	Directory* dir = static_cast<Directory*>(getFile(directoryPath)); // dir can't be nullptr because we just created it
	delete[] directoryPath;

	dir->add(new TextFile(filename, content));
	
}
void FileSystem::createDirectory(const char* path) {
	char* nextFileName = getNextFilename(path);
	if (nextFileName == nullptr) {							// then we're at the level of the file
		if (strcmp(path, root->getName()) == 0) {
			return;
		}
		throw std::invalid_argument("all files must be in root");
	}

	if (strcmp(nextFileName, root->getName()) != 0) {
		throw std::invalid_argument("all files must be in root");// every file must start at the root
	}
	const char* subpath = path + strlen(nextFileName) + 1;		// + strlen because we want the subpath, + 1 because of the / 
	delete[] nextFileName;
	createSubfolderInFolder(root, subpath);
}

void FileSystem::createSubfolderInFolder(Directory* folder, const char* path) {
	if (folder == nullptr) {
		return;
	}
	char* nextFileName = getNextFilename(path);
	if (nextFileName == nullptr) {							// then we're at the level of the file
		if (folder->contains(path)) {						// there is already a file with that name in the folder
			Directory* subfolder = static_cast<Directory*>(folder->getFileByName(path));
			if (subfolder == nullptr) {						// then the file that's there is a textFile	
				throw std::invalid_argument("There already exists a textfile with that name");
			}
			// then the file already exists and is a directory, so we don't need to do anything;
			return;
		}
		folder->add(new Directory(path));
		return;
	}
	// if there are more slashes, then there's more subfolders
	Directory* subfolder = static_cast<Directory*>(folder->getFileByName(nextFileName));
	// this gets the file from the folder, expecting it to be of type Directory, if it's not or there's no such file
	// then subfolder will be nullptr
	if (subfolder == nullptr) {
		if (folder->contains(nextFileName)) {
			throw std::invalid_argument("There already exists a textfile with that name");
		}
		subfolder = new Directory(nextFileName); // we must create the missing folders
		folder->add(subfolder);
	}
	const char* subpath = path + strlen(nextFileName) + 1;		// + strlen because we want the subpath, + 1 because of the / 
	delete[] nextFileName;
	return createSubfolderInFolder(subfolder, subpath);
}


char* FileSystem::getNextFilename(const char* path) const {
	// gets the first directory in the path 
	int nextSlash = -1;
	int pathLen = strlen(path);
	for (int i = 0; i < pathLen; i++) {
		if (path[i] == '/') {
			nextSlash = i;
			break;
		}
	}
	if (nextSlash == -1) {
		return nullptr;
	}
	char* nextFile = new char[nextSlash + 1];
	strncpy(nextFile, path, nextSlash);
	nextFile[nextSlash] = '\0';
	return nextFile;
}

char* FileSystem::getPrevFilename(const char* path) const {
	int lastSlash = -1;
	int pathLen = strlen(path);
	for (int i = pathLen - 1; i >= 0; i--) {
		if (path[i] == '/') {
			lastSlash = i;
			break;
		}
	}
	if (lastSlash == -1) {
		return nullptr;
	}
	char* lastFile = new char[pathLen - lastSlash + 1];
	strcpy(lastFile, path + lastSlash + 1);
	lastFile[pathLen - lastSlash] = '\0';
	return lastFile;
}


 File* FileSystem::getFile(const char* path) const {
	char* nextFileName = getNextFilename(path);
	if (nextFileName == nullptr) {							// then we're at the level of the file
		if (strcmp(path, root->getName()) == 0) {
			return root;
		}
		// given that every file is a subfile of root, if there are no slashes, and we aren't searching for 'root'
		// then there is no such file in the system
		throw std::invalid_argument("no such file");
	}

	if (strcmp(nextFileName, root->getName()) != 0) {
		throw std::invalid_argument("no such file");			// every file must start at the root
	}
	const char* subpath = path + strlen(nextFileName) + 1;		// + strlen because we want the subpath, + 1 because of the / 
	delete[] nextFileName;
	return getFileFromSubfolder(root, subpath);
}

File* FileSystem::getFileFromSubfolder(const Directory* folder, const char* path) const {
	if (folder == nullptr) {
		return nullptr;
	}
	char* nextFileName = getNextFilename(path);
	if (nextFileName == nullptr) {							// then we're at the level of the file
		return folder->getFileByName(path);
	}
	// if there are more slashes, then there's more subfolders
	Directory* subfolder = static_cast<Directory*>(folder->getFileByName(nextFileName));
	// this gets the file from the folder, expecting it to be of type Directory, if it's not or there's no such file
	// then subfolder will be nullptr
	const char* subpath = path + strlen(nextFileName) + 1;		// + strlen because we want the subpath, + 1 because of the / 
	delete[] nextFileName;
	return getFileFromSubfolder(subfolder, subpath);
}


void FileSystem::printFile(const char* path) const {
	File* file = getFile(path);
	if (file == nullptr) {
		return;
	}
	file->printContent();
}


FileSystem::~FileSystem() {
	free();
}
FileSystem::FileSystem(const FileSystem& other) {
	copyFrom(other);
}
FileSystem::FileSystem(FileSystem&& other) {
	moveFrom(std::move(other));
}
FileSystem& FileSystem::operator=(const FileSystem& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
FileSystem& FileSystem::operator=(FileSystem&& other) {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

void FileSystem::copyFrom(const FileSystem& other) {
	this->root = other.root;
}
void FileSystem::moveFrom(FileSystem&& other) {
	root = other.root;
	other.root = nullptr;
}
void FileSystem::free() {
	delete root;
}