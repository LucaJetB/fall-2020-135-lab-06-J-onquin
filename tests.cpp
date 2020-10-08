#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"

// add your tests here
TEST_CASE("caesar's cipher"){
    CHECK(encryptCaesar("way to go!", 5) == "bfd yt lt!");
    CHECK(encryptCaesar("andywen", 5) == "fsidbjs");
    CHECK(encryptCaesar("ANDYWEN", 5) == "FSIDBJS");
    CHECK(encryptCaesar("Andy Wen", -5) == "<i_t R`i");//???does this count as working?
    //or are special characters not allowed
}

TEST_CASE("vigenere's cipher"){
    CHECK(encryptVigenere("Hello, World!", "cake") == "Jevpq, Wyvnd!");
    CHECK(encryptVigenere("scythe of vitur@@@@", "noragami") == "fqptne an iwkux@@@@");
}

TEST_CASE("decode caesar's cipher"){
    //i believe this covers all tests
    CHECK(decryptCaesar("Fsid bjs!@#", 5) == "Andy wen!@#");
}

TEST_CASE("decode vigenere's cipher"){
    CHECK(decryptVigenere("fqptne an iwkux@@@@", "noragami") == "scythe of vitur@@@@");
    CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!");
}