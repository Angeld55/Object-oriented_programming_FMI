#pragma once
#include"Collection.h"

class IntervalCollection : public Collection
{
private:
	int* data;
	int start;
	int end;
	
	void free();
	void copyFrom(const IntervalCollection&);
	void moveFrom(IntervalCollection&& other);
public:
	IntervalCollection(int start, int end);

	IntervalCollection(const IntervalCollection&);
	IntervalCollection(IntervalCollection&&);

	IntervalCollection& operator=(const IntervalCollection&);
	IntervalCollection& operator=(IntervalCollection&&);

	unsigned intervalLength() const;

	void add(int) override;
	void remove(int) override;
	unsigned count(int) const override;
	bool contains(int) const override;

	~IntervalCollection();
};

