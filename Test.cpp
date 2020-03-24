/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    text = "xxx pe yyy";
    CHECK(find(text, "be") == string("pe"));
    CHECK(find(text, "pe") == string("be"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    /* Add more checks here */
}
TEST_CASE("Test replacement of v and w") {
    string text = "xxx vorry yyy";
    CHECK(find(text, "worry") == string("vorry"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    text = "xxx pe yyy";
    CHECK(find(text, "be") == string("pe"));
    CHECK(find(text, "pe") == string("be"));
    /* Add more checks here */
}

TEST_CASE("Test replacement of v and w") {
    string text = "Fast, good, cheap pick any two";
    CHECK(find(text, "Fast") == string("vorry"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    text = "xxx pe yyy";
    CHECK(find(text, "be") == string("pe"));
    CHECK(find(text, "pe") == string("be"));
    /* Add more checks here */
}

TEST_CASE("f and b and p") {
    string text ="Don’t just Pix the Bugs BIX whatever Fermitted the BUGS in the Pirst Flace";
    CHECK(find(text, "fix") == string("Pix"));
    CHECK(find(text, "bugs") == string("Bugs"));
    CHECK(find(text, "pix") == string("fix"));
    CHECK(find(text, "BIX") == string("fix"));
    CHECK(find(text, "fIX") == string("fix"));
    CHECK(find(text, "BUGS") == string("bugs"));
    CHECK(find(text, "Fermitted") == string("permitted"));
    CHECK(find(text, "Flace") == string("place"));
    text =  "Blame doesn’t fix bugs." ;
    CHECK(find(text, "flame") == string("blame"));
    CHECK(find(text, "Blame") == string("blame"));
    CHECK(find(text, "pix") == string("fix"));
    CHECK(find(text, "Bix") == string("fix"));
    CHECK(find(text, "fIX") == string("fix"));
    CHECK(find(text, "BUGS") == string("bugs"));
    CHECK(find(text, "fUGS") == string("bugs"));
    
}