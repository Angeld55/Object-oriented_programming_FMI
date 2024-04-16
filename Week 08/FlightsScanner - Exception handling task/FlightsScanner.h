#pragma once
#include <fstream>

class FlightsScanner
{
	char inputFileName[1024] = "";
	char outputFileName[1024] = "";
	int sec = -1;
	unsigned lineIndex = 0;


	struct FlightRecord
	{
		char origin[64];
		char dest[64];
		unsigned amount;
	};

	void handleAirport(char* airport) const;
	void parseLine(const char* line, FlightRecord& record) const;
	bool readAndExportData(std::ifstream& input);
	void saveRecord(std::ofstream& ofs, const FlightRecord& record) const;

public:
	FlightsScanner(const char* input, const char* output, int scanInterval);
	void run();
};
