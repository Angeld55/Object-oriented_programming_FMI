#pragma once
class HexViewer
{
	unsigned char* data;
	size_t size;

public:
	HexViewer(const char* fileName);

	HexViewer(const HexViewer&) = delete;
	HexViewer& operator=(const HexViewer&) = delete;

	void addByte(const char* byte);
	void removeLastByte();
	void changeByte(size_t index, const char* byte);

	void saveAs(const char* fileName) const;

	void print() const;
	~HexViewer();
};