#include "Timestamp.h"

int Timestamp::toSeconds() const{
	return hour * 3600 + minutes * 60 + seconds;
}