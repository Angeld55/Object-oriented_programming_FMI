#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

namespace GlobalConstants
{
	constexpr int FIELD_MAX_SIZE = 30;
	constexpr int MAX_FIELDS_ROW = 10;
	constexpr int ROWS_MAX_SIZE = 300;
	constexpr int BUFFER_SIZE = 1024;
	constexpr char SEP = ',';
}

typedef char Field[GlobalConstants::FIELD_MAX_SIZE];

struct Row
{
	Field fields[GlobalConstants::MAX_FIELDS_ROW];
};

struct CsvTable
{
	Row rows[GlobalConstants::ROWS_MAX_SIZE];
	size_t rowsCount = 0;
	size_t collsCount = 0;
};

size_t parseRow(const char* row, Row& toReturn)
{
	std::stringstream ss(row);

	size_t currentColumnCount = 0;
	while (!ss.eof())
	{
		ss.getline(toReturn.fields[currentColumnCount++], GlobalConstants::FIELD_MAX_SIZE, GlobalConstants::SEP);
	}
	return currentColumnCount;
}
CsvTable parseFromFile(std::istream& ifs)
{
	CsvTable result;
	char buff[GlobalConstants::BUFFER_SIZE];
	while (!ifs.eof())
	{
		ifs.getline(buff, GlobalConstants::BUFFER_SIZE);
		result.collsCount = parseRow(buff, result.rows[result.rowsCount++]);
	}
	return result;
}
CsvTable parseFromFile(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return {};
	}

	return parseFromFile(ifs);
}

void printTable(const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		for (int j = 0; j < table.collsCount; j++)
		{
			std::cout << table.rows[i].fields[j] << "          ";
		}
		std::cout << std::endl;
	}
}

void saveRowToFile(std::ostream& ofs, const Row& row, size_t collsCount)
{
	for (int i = 0; i < collsCount; i++)
	{
		ofs << row.fields[i];
		if (i != collsCount - 1)
		{
			ofs << GlobalConstants::SEP;
		}
	}
}

void saveToFile(std::ostream& ofs, const CsvTable& table)
{
	for (int i = 0; i < table.rowsCount; i++)
	{
		saveRowToFile(ofs, table.rows[i], table.collsCount);
		if (i != table.rowsCount - 1) 
		{
			ofs << std::endl;
		}
	}
}

void saveToFile(const char* fileName, const CsvTable& table)
{
	std::ofstream ofs(fileName);
	saveToFile(ofs, table);
	ofs.close();
}

int main()
{
	CsvTable csv = parseFromFile("table.csv");

	printTable(csv);
	//do something with the table....
	saveToFile("table_result.csv", csv);
}
