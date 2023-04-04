#include "User.h"
#include <cstring>

#pragma warning(disable : 4996)

void copyDynamicCharArray(char*& destination, const char* source) {
    destination = new char[strlen(source) + 1];
    strcpy(destination, source);
}

void writeDynamicCharArrayToFile(std::ofstream& out, const char* arr) {
    size_t arrLength = strlen(arr);
    out.write((const char*)&arrLength, sizeof(arrLength));
    out.write(arr, arrLength);
}

void readDynamicCharArrayFromFile(std::ifstream& in, char*& arr) {
    size_t arrLength;
    in.read((char*)&arrLength, sizeof(arrLength));
    arr = new char[arrLength + 1];
    in.read(arr, arrLength);
    arr[arrLength] = '\0';
}

void User::copyUserName(const char* userName) {
    copyDynamicCharArray(this->userName, userName);
}

void User::copyPassword(const char* password) {
    copyDynamicCharArray(this->password, password);
}

User::User(const char* userName, const char* password) {
    copyUserName(userName ? userName : "\0");
    copyPassword(password ? password : "\0");
}

User::User(const User& other) {
    copyFrom(other);
}

User& User::operator=(const User& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

User::~User() {
    free();
}

const char* User::getUserName() const {
    accessCounter++;
    return userName;
}

size_t User::getAccessCounter() const {
    return accessCounter;
}

void User::setUserName(const char* userName) {
    if (!userName) {
        return;
    }

    if (this->userName) {
        delete[] this->userName;
    }

    copyUserName(userName);
}

void User::setPassword(const char* password) {
    if (!password) {
        return;
    }

    if (this->password) {
        delete[] this->password;
    }

    copyUserName(password);
}

void User::free() {
    delete[] userName;
    delete[] password;
    accessCounter = 0;
    userName = password = nullptr;
}

void User::copyFrom(const User& other) {
    copyUserName(other.userName);
    copyPassword(other.password);
}

void User::writeToFile(std::ofstream& out) const {
    writeDynamicCharArrayToFile(out, userName);
    writeDynamicCharArrayToFile(out, password);
    out.write((const char*)&accessCounter, sizeof(accessCounter));
}

void User::readFromFile(std::ifstream& in) {
    readDynamicCharArrayFromFile(in, userName);
    readDynamicCharArrayFromFile(in, password);
    in.read((char*)&accessCounter, sizeof(accessCounter));
}