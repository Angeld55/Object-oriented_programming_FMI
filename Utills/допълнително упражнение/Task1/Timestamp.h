#pragma once
struct Timestamp {
	bool isLogin;
	unsigned short hour;
	unsigned short minutes;
	unsigned short seconds;

	int toSeconds() const;
};