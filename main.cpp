/** 
* Spring 2023 - Lab 06
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include <iostream>
#include <iomanip>
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

int main() 
{
    std::cout << "Enter plaintext: Hello, World!";
    std::string plaintext = "Hello, World!"; 

    std::cout << "\n= Caesar =" << std::endl;
    std::cout << "Enter shift" << std::setw(8) << ": 10" << std::endl; 
    int shift = 10; 

    std::cout << "Ciphertext" << std::setw(7) << ": " << encryptCaesar(plaintext, shift) << std::endl;
    std::cout << "Decrypted" << std::setw(8) << ": " << decryptCaesar(encryptCaesar(plaintext, shift), shift) << std::endl;

    std::cout << "\n= Vigenere =" << std::endl;
    std::cout << "Enter keyword" << std::setw(8) << ": cake" << std::endl; 
    std::string keyword = "cake"; 

    std::cout << "Ciphertext" << std::setw(7) << ": " << encryptVigenere(plaintext, keyword) << std::endl; 
    std::cout << "Decrypted" << std::setw(8) << ": " << decryptVigenere(encryptVigenere(plaintext, keyword), keyword) << std::endl;

    std::cout << "\n ============================================ \n"; 

    std::cout << "Enter plaintext: Lab 06 is Complete";
    plaintext = "Lab 06 is Complete"; 


    std::cout << "\n= Caesar =" << std::endl;
    std::cout << "Enter shift" << std::setw(8) << ": 30" << std::endl; 
    shift = 30; 

    std::cout << "Ciphertext" << std::setw(7) << ": " << encryptCaesar(plaintext, shift) << std::endl;
    std::cout << "Decrypted" << std::setw(8) << ": " << decryptCaesar(encryptCaesar(plaintext, shift), shift) << std::endl;

    std::cout << "\n= Vigenere =" << std::endl;
    std::cout << "Enter keyword" << std::setw(8) << ": Hello!" << std::endl; 
    keyword = "Hello!"; 

    std::cout << "Ciphertext" << std::setw(7) << ": " << encryptVigenere(plaintext, keyword) << std::endl; 
    std::cout << "Decrypted" << std::setw(8) << ": " << decryptVigenere(encryptVigenere(plaintext, keyword), keyword) << std::endl;


    return 0;
}