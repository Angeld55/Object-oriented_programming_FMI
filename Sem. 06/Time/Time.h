class Time
{
	size_t hours;
	size_t mins;
	size_t seconds;

	size_t convertTimeToSeconds();
	void setTimeBySeconds(size_t);

public:
	Time();
	Time(size_t hours, size_t mins, size_t seconds);
 

	size_t getHours();
	size_t getMins();
	size_t getSeconds();
	void setHours(size_t hours);
	void setMins(size_t mins);
	void setSeconds(size_t seconds);

	void addSeconds(size_t seconds);
	void addMinutes(size_t seconds);
	void addHours(size_t seconds);

	void print();
};