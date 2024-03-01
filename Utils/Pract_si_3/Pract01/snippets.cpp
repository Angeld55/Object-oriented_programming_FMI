#include <iostream>
//Initialization of enum class

namespace day {
    enum class Day
    {
        MONDAY, //0
        TUESDAY, //1
        WEDNESDAY, //2
        THURSDAY, //3
        FRIDAY, //4
        SATURDAY, //5
        SUNDAY, //6
        UNKNOWN //default case
    };

    Day initDay(int num) {
        switch (num) {
            case 0: return Day::MONDAY;
            case 1: return Day::TUESDAY;
            case 2: return Day::WEDNESDAY;
            case 3: return Day::THURSDAY;
            case 4: return Day::FRIDAY;
            case 5: return Day::SATURDAY;
            case 6: return Day::SUNDAY;
            default: return Day::UNKNOWN;
        }
    }

    void printDay(Day day) {
        using std::cout;
        using std::endl;
        switch (day) {
            case Day::MONDAY: cout << "Monday" << endl; break;
            case Day::TUESDAY: cout << "Tuesday" << endl; break;
            case Day::WEDNESDAY: cout << "Wednesday" << endl; break;
            case Day::THURSDAY: cout << "Thursday" << endl; break;
            case Day::FRIDAY: cout << "Friday" << endl; break;
            case Day::SATURDAY: cout << "Saturday" << endl; break;
            case Day::SUNDAY: cout << "Sunday" << endl; break;
            default: cout << "Unknown day" << endl; break;
        }
    }
}

int main()
{
    using namespace day;

    int n;
    std::cin >> n;
    Day d = initDay(n);
    printDay(d);
}
