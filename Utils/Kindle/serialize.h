#pragma once
#include"string.h"
#include"vector.hpp"
#include"Pair.hpp"
#include<fstream>

void writeString(std::ofstream& outFile, const string& str);

string readString(std::ifstream& inFile);

void writeVector(std::ofstream& outFile, const Vector<size_t>& v);

Vector<size_t> readVector(std::ifstream& inFile);
void writeCommentsToFile(std::ofstream& outFile, const Pair<string, string>& p);

Pair<string, string> readCommentsFromFile(std::ifstream& inFile);

void writeRatesToFile(std::ofstream& outFile, const Pair<string, unsigned>& comments);

Pair<string, unsigned> readRatesFromFile(std::ifstream& inFile);