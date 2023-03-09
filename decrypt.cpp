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
#include <array> 
#include <iomanip>
#include "decrypt.h"
#include "vigenere.h"
#include "caesar.h"

const std::array<char, 26> upper = 
{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const std::array<char, 26> lower = 
{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 

char get_char_uncipher(int input, bool is_upper) 
{ 
    if(input < 0) 
    { 
        return is_upper ? upper[input + 26] : lower[input + 26]; 
    }

    return is_upper ? upper[input] : lower[input];
}

char shift_char_uncipher(char c, int rshift) 
{  
    int shift = rshift % 26; 

    if(shift < 0) 
    {
        for(int i = 0; i < 26; i++) 
        { 
            if(c == upper[i] && i - shift > 25) 
            {
                return upper[(i - shift) - 26];
            } 
            else if(c == lower[i] && i - shift > 25) 
            { 
                return lower[(i - shift) - 26];
            } 
            else if(upper[i] == c) 
            { 
                return upper[i - shift]; 
            } 
            else if(lower[i] == c) 
            { 
                return lower[i - shift];
            }
            
        }
    } 
    else 
    {
        for(int i = 0; i < 26; i++) 
        { 
            if(c == upper[i] && i - shift < 0) 
            {
                return upper[26 - (shift - i)];
            } 
            else if(c == lower[i] && i - shift < 0) 
            { 
                return lower[26 - (shift - i)];
            } 
            else if(upper[i] == c) 
            { 
                return upper[i - shift]; 
            } 
            else if(lower[i] == c) 
            { 
                return lower[i - shift];
            } 
        }
    }

    return c;
}

std::string decryptCaesar(std::string ciphertext, int rshift) 
{ 
    std::string result = "";
    for(int i = 0; i < ciphertext.length(); i++) 
    { 
        result += shift_char_uncipher(ciphertext.at(i), rshift); 
    }

    return result;
}


std::string decryptVigenere(std::string ciphertext, std::string keyword) 
{ 
    int keyword_count = 0; 
    std::string result = ""; 
    
    for(int i = 0; i < keyword.length(); i++) 
    { 
        int special_ascii_int = (int)keyword.at(i);
        
        if(33 <= special_ascii_int && special_ascii_int <= 64 || 91 <= special_ascii_int && special_ascii_int <= 96 || 123 <= special_ascii_int && special_ascii_int <= 126) 
        { 
            return "Impossible keyword";
        }
    }

    for(int i = 0; i < ciphertext.length(); i++) { 
        if((int)(ciphertext.at(i)) >= 65 && (int)ciphertext.at(i) <= 90 || (int)ciphertext.at(i) >= 97 && (int)(ciphertext.at(i)) <= 122) { 
            result += get_char_uncipher(get_position_in_array(ciphertext.at(i)) - 
            get_position_in_array(keyword.at(keyword_count)), is_upper(ciphertext.at(i)));
            
            keyword_count++;
        } 
        else 
        { 
            result += ciphertext.at(i); 
        }

        if(keyword_count == keyword.length()) 
        { 
            keyword_count = 0; 
        } 
    }

    return result;  
}