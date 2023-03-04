#pragma once
#include <string>

char shift_char_uncipher(char c, int rshift);
std::string decryptCaesar(std::string ciphertext, int rshift);
char get_char_uncipher(int input, bool is_upper);
std::string decryptVigenere(std::string ciphertext, std::string keyword);