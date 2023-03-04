/** 
* Spring 2023 - Lab 06
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include <iostream>
#include <string>

int main() 
{ 
    std::string line = "Low :3 Man"; 
    for(int i = 0; i < line.length(); i++) 
    { 
        std::cout << line.at(i) << " " << (int)line.at(i) << std::endl;
    }

    return 0;
}