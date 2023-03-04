/** 
* Spring 2023 - Lab 06
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// add your tests here

TEST_CASE("Task B") 
{ 
    SUBCASE("Base cases:") 
    { 
        CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
        CHECK(encryptCaesar("Hello, World!" , 10) == "Rovvy, Gybvn!");
    }

    SUBCASE("Special cases:") 
    { 
        CHECK(encryptCaesar("!@#$%^&*()!(&)!<>?><???", 26) == "!@#$%^&*()!(&)!<>?><???");
        CHECK(encryptCaesar("117482889421", 500) == "117482889421"); 
    }

    SUBCASE("Extreme cases: ") 
    { 
        CHECK(encryptCaesar("This works!", 400) == "Drsc gybuc!");
        CHECK(encryptCaesar("To be or not to be, That is the question", 1555) == "Oj wz jm ijo oj wz, Ocvo dn ocz lpznodji");
    }

    SUBCASE("Negative rshift values:") 
    { 
        CHECK(encryptCaesar("If he had anything confidential to say", -10) == "Yv xu xqt qdojxydw sedvytudjyqb je iqo");
        CHECK(encryptCaesar("Caesar cipher: Encode and decode online", -300) == "Omqemd oubtqd: Qzoapq mzp pqoapq azxuzq");
        CHECK(encryptCaesar("Cryptii Happy Pride", -5) == "Xmtkodd Cvkkt Kmdyz");
    }
}

TEST_CASE("Task C") 
{ 
    SUBCASE("Base cases:") 
    { 
        CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
        CHECK(encryptVigenere("\\`F~-z_+=\"[]{}';:!@#v$%^&T*()<a>?,./", "test") == "\\`Y~-d_+=\"\x5b\x5d\x7b\x7d';:!@#n$%^&M*()<t>?,./");
        CHECK(encryptVigenere("This, works!", "yes") == "Rlaq, agpok!");
    }

    SUBCASE("Special cases") 
    { 
        CHECK(encryptVigenere("Hello, World!", "@#!@@*!@$UGIF*Y@") == "Impossible keyword");
        CHECK(encryptVigenere("Hello, World!", "1234567890") == "Impossible keyword");
        CHECK(encryptVigenere("Hello, World!", "EGG") == "Lkrpu, Csxrh!");
    }
}

TEST_CASE("Task D") 
{ 
    SUBCASE("Caesar Decryption using Caesar Encryption:") 
    { 
        CHECK(decryptCaesar(encryptCaesar("Hello, World!", 10), 10) == "Hello, World!");
        CHECK(decryptCaesar(encryptCaesar("To be or not to be, That is the question", 1555), 1555) == "To be or not to be, That is the question");
    }

    SUBCASE("Caesar Decryption Special Cases:") 
    { 
        CHECK(decryptCaesar(encryptCaesar("!@#$%^&*()!(&)!<>?><???", 26), 26) == "!@#$%^&*()!(&)!<>?><???");
        CHECK(decryptCaesar(encryptCaesar("Cryptii Happy Pride", -32), -32) == "Cryptii Happy Pride"); 
    }

    SUBCASE("Vigenere Decrpytion using Vigenere Encryption: ") 
    { 
        CHECK(decryptVigenere(encryptVigenere("Hello, World!", "cake"), "cake") == "Hello, World!");
        CHECK(decryptVigenere(encryptVigenere("\\`F~-z_+=\"[]{}';:!@#v$%^&T*()<a>?,./", "test"), "test") == "\\`F~-z_+=\"\x5b\x5d\x7b\x7d';:!@#v$%^&T*()<a>?,./");
        CHECK(decryptVigenere(encryptVigenere("Lab 06 Is Complete", "Hello!"), "Hello!") == "Impossible keyword");
    }

    SUBCASE("Vigenere Decryption Special Cases:") 
    { 
        CHECK(decryptVigenere(encryptVigenere("Hello, World!", "1234567890"), "1234567890") == "Impossible keyword");
        CHECK(decryptVigenere(encryptVigenere("Vigenere", "EGG"), "EGG") == "Vigenere");
    }
}