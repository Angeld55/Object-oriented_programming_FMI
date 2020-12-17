#include "Farm.hpp"

using namespace std;
int main()
{
    Farm f(4);
    f.AddCat("Cat1");
    f.AddCat("Cat2");
    f.AddCow("Cow1");
    f.AddDog("Dog1");
    
    f.RoarAll();
}
