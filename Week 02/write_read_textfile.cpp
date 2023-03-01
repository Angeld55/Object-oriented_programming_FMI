#include <iostream>
#include <fstream>
#include <assert.h>

int main()
{
    {
        std::ofstream file("myFile.txt");
        
        if(!file.is_open())
            return -1;
    
        file << 3 << " " << 4 << " ";
        file.put('5');
    }
    {
        int a, b, c;
        std::ifstream file("myFile.txt");
        
        if(!file.is_open())
            return -1;
    
        file >> a >> b >> c;  //operator >> read to " " or "\n"
        
        std::cout << a << " " << b << " " << c;
        
        file.close();
    }
    
	
}



