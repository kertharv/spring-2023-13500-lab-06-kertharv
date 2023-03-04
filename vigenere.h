#pragma once 

int get_position_in_array(char input);
char get_char_cipher(int input, bool is_upper);
bool is_upper(char input);
std::string encryptVigenere(std::string plaintext, std::string keyword);