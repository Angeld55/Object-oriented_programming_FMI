#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

namespace globalConstants
{
    const size_t VALUE_MAX_SIZE = 20;
    const size_t ROW_MAX_ELEMENTS = 10;
    const size_t MAX_ROWS_COUNT = 250;
}

struct Value
{
    char str[globalConstants::VALUE_MAX_SIZE] = "";
};
struct Row
{
    Value values[globalConstants::ROW_MAX_ELEMENTS];
    size_t valuesCount = 0;
};

struct CsvFile
{
    Row columnsNames;
    Row rows[globalConstants::MAX_ROWS_COUNT];
    size_t rowsCount = 0;
};

Row readRow(std::ifstream& ifs)
{
    char buff[1024];
    ifs.getline(buff, 1024);
    std::stringstream ss(buff);

    Row currentRow;
    while (!ss.eof())
    {
        size_t& valuesCount = currentRow.valuesCount;
        ss.getline(currentRow.values[valuesCount++].str,
            globalConstants::VALUE_MAX_SIZE, ',');
    }
    return currentRow;
}

CsvFile parseFromFile(const char* str)
{
    std::ifstream input(str);
    if (!input.is_open())
        throw std::exception("Error");

    CsvFile resultFile;

    resultFile.columnsNames = readRow(input);

    while (!input.eof())
        resultFile.rows[resultFile.rowsCount++] = readRow(input);

    input.close();
    return resultFile;
}

void printRow(const Row& row)
{
    for (int i = 0; i < row.valuesCount; i++)
        std::cout << std::left << std::setw(20) << row.values[i].str;
    std::cout << std::endl;
}


void print(const CsvFile& fileToPrint)
{
    printRow(fileToPrint.columnsNames);
    for (int i = 0; i < fileToPrint.rowsCount; i++)
        printRow(fileToPrint.rows[i]);
}

void saveCsvRow(const Row& row, std::ofstream& ofs)
{
    for (int i = 0; i < row.valuesCount; i++)
    {
        ofs << row.values[i].str;
        if (i != row.valuesCount - 1)
            ofs << ",";
    }
    ofs << std::endl;
}

void saveCsvToFile(const CsvFile& file, const char* fileName)
{
    std::ofstream ofs(fileName);
    if (!ofs.is_open())
        return;
    saveCsvRow(file.columnsNames, ofs);
    for (int i = 0; i < file.rowsCount; i++)
        saveCsvRow(file.rows[i], ofs);
    ofs.close();
}

int getColumnIndex(const CsvFile& csvFile, const char* columnName)
{
    for (int i = 0; i < csvFile.columnsNames.valuesCount; i++)
    {
        if (strcmp(csvFile.columnsNames.values[i].str, columnName) == 0)
            return i;
    }
    return -1;
}

bool changeValue(CsvFile& csvFile, const char* columnName, const char* valueToChange, const char* changeWith)
{
    int columnIndex = getColumnIndex(csvFile, columnName);
    if (columnIndex == -1)
        return false;
    for (int i = 0; i < csvFile.rowsCount; i++)
    {
        if (strcmp(csvFile.rows[i].values[columnIndex].str, valueToChange) == 0)
        {
            strcpy_s(csvFile.rows[i].values[columnIndex].str, globalConstants::VALUE_MAX_SIZE, changeWith);
            return true;
        }
    }
    return false;
}

int main()
{
    CsvFile myFile = parseFromFile("students.csv");

    print(myFile);

    //changing the name of Katerina to Petya
    changeValue(myFile, "Ime", "Katerina", "Petya");

    saveCsvToFile(myFile, "students_new.csv");
}
