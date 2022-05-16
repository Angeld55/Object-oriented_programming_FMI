#pragma once

template<class T, class U>
class Pair {
	T first;
	U second;
public:
	Pair() {
		first = T();
		second = U();
	}
	Pair(const T& fst, const U& snd) : first(fst), second(snd) {}

	const T& getFirst() const {
		return first;
	}

	const U& getSecond() const {
		return second;
	}

	void setFirst(const T& arg) {
		first = arg;
	}

	void setSecond(const U& arg) {
		second = arg;
	}
};