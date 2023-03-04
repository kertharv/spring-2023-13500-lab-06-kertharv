/** 
* Spring 2023 - Lab 06
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#include "caesar.h"
#include <array>
#include <string>   


const std::array<char, 26> upper = 
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const std::array<char, 26> lower = 
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 

char shiftChar(char c, int rshift) 
{  
    int shift = rshift % 26; 

    if(shift < 0) 
    { 
        // returns letter for negative shift
        for(int i = 0; i < 26; i++) 
        { 
            if(c == upper[i] && i + shift < 0)
            { 
                return upper[26 + i + shift];
            } 
            else if(c == lower[i] && i + shift < 0) 
            { 
                return lower[26 + i + shift];
            } 
            else if(upper[i] == c) 
            { 
                return upper[i + shift]; 
            } 
            else if(lower[i] == c) 
            { 
                return lower[i + shift];
            } 
        }
    } 
    else 
    { 
        for(int i = 0; i < 26; i++) 
        { 
            if(c == upper[i] && i + shift > 25) 
            {
                return upper[(shift + i) - 26];
            } 
            else if(c == lower[i] && i + shift > 25) 
            { 
                return lower[(shift + i) - 26];
            } 
            else if(upper[i] == c) 
            { 
                return upper[i + shift]; 
            } 
            else if(lower[i] == c) 
            { 
                return lower[i + shift];
            } 
        }
    }
    
    return c;
}

std::string encryptCaesar(std::string plaintext, int rshift) 
{ 
    std::string result = "";
    for(int i = 0; i < plaintext.length(); i++) 
    { 
        result = result + shiftChar(plaintext.at(i), rshift); 
    }

    return result;
}