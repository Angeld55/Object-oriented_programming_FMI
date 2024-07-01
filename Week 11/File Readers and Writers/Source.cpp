#include <iostream>
#include "FilePath.h"
#include "BinaryFileReader.h"
#include "BinaryFileWriter.h"
#include "CSVFileReader.h"
#include "CSVFileWriter.h"
#include "ArrFileReader.h"
#include "ArrFileWriter.h"


void selectionSort(int* arr, size_t size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minElIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minElIndex])
                minElIndex = j;
        }

        if (minElIndex != i)
            std::swap(arr[minElIndex], arr[i]);
    }
}

FileReader* getFileReader(const MyString& str) {
    FilePath path(str);
    if (path.getExtension() == ".dat") {
        return new BinaryFileReader(str);
    }
    if (path.getExtension() == ".csv") {
        return new CSVFileReader(str);
    }
    if (path.getExtension() == ".arr") {
        return new ArrFileReader(str);
    }
    throw std::exception();
}

FileWriter* getFileWriter(const MyString& str) {
    FilePath path(str);
    if (path.getExtension() == ".dat") {
        return new BinaryFileWriter(str);
    }
    if (path.getExtension() == ".csv") {
        return new CSVFileWriter(str);
    }
    if (path.getExtension() == ".arr") {
        return new ArrFileWriter(str);
    }
    throw std::exception();
}

void transfer(const MyString& in, const MyString& out) {
    size_t size;

    FileReader* reader = getFileReader(in);
    int* arr = reader->read(size);

    selectionSort(arr, size);

    FileWriter* writer = getFileWriter(out);
    writer->write(arr, size);

    delete[] arr;
    delete reader;
    delete writer;
}

int main()
{
    transfer("numbers.dat", "numbers2.arr");
}
