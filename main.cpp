/** 
* Spring 2023 - Lab 06 (Lab Cipher)
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include <iostream>
#include <vector>
#include <fstream>
#include "funcs.h"

int main()
{

    std::string str = encryptCaesar("Destruction of Skyrim", 5);
    std::cout << "Encrypted string: "<< str << " = "<< solve(str) << "\n";


    return 0;
}

