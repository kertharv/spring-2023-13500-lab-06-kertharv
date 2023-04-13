/** 
* Spring 2023 - Lab 06 (Lab Cipher)
* Last name: Cataluna
* First name: Kert Harvey
* GitHub username: kertharv
* Instructor: Genady Maryash
* Recitation Instructor: Prof. Zamansky
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here

TEST_CASE("Test cases for solve() function")
{
    CHECK(solve(encryptCaesar("The Nordlings has discovered our location!", 9)) == "The Nordlings has discovered our location!");
    CHECK(solve(encryptCaesar("Bring up arms with the Empire and the Emperor!", 50)) == "Bring up arms with the Empire and the Emperor!");
    CHECK(solve(encryptCaesar("I do not get it. Why is magic so discriminated against in this world", 26)) == "I do not get it. Why is magic so discriminated against in this world");
    CHECK(solve(encryptCaesar("Where is the fun in fast traveling?", 0)) == "Where is the fun in fast traveling?");
    CHECK(solve(encryptCaesar("My favorite weapon has to be the Molag Bal mace", 7)) == "My favorite weapon has to be the Molag Bal mace");
    CHECK(solve(encryptCaesar("This fire magic is out of control", 126)) == "This fire magic is out of control");
    CHECK(solve(encryptCaesar("I call upon Talos, may you bring victory to our comrades and to Skyrim", 500)) == "I call upon Talos, may you bring victory to our comrades and to Skyrim");
    CHECK(solve(encryptCaesar("The Thieves Guild literally gives me Septims of Gold for wearing a Nightingale Armor", 76)) == "The Thieves Guild literally gives me Septims of Gold for wearing a Nightingale Armor");
    CHECK(solve(encryptCaesar("By the Nine, get this atrocious weapon away from my sight!", 42)) == "By the Nine, get this atrocious weapon away from my sight!");
    CHECK(solve(encryptCaesar("I want to finish the game, but there are too many quests and it is a tiny bit overwhelming...", 1000)) == "I want to finish the game, but there are too many quests and it is a tiny bit overwhelming...");
}