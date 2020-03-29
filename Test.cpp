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


TEST_CASE("Test replacement of p ,b and f") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    text = "xxx pe yyy";
    CHECK(find(text, "be") == string("pe"));
    CHECK(find(text, "pe") == string("be"));
    text =  "Blame doesn’t fix bugs." ;
    CHECK(find(text, "flame") == string("blame"));
    CHECK(find(text, "Blame") == string("blame"));
    CHECK(find(text, "pix") == string("fix"));
    CHECK(find(text, "Bix") == string("fix"));
    CHECK(find(text, "fIX") == string("fix"));
    CHECK(find(text, "BUGS") == string("bugs"));
    CHECK(find(text, "fUGS") == string("bugs"));
    text ="Don’t just Pix the Bugs; BIX whatever Fermitted the BUGS in the Pirst Flace.";
    CHECK(find(text, "fix") == string("Pix"));
    CHECK(find(text, "bugs") == string("Bugs"));
    CHECK(find(text, "pix") == string("fix"));
    CHECK(find(text, "BIX") == string("fix"));
    CHECK(find(text, "fIX") == string("fix"));
    CHECK(find(text, "BUGS") == string("bugs"));
    CHECK(find(text, "Fermitted") == string("permitted"));
    CHECK(find(text, "Flace") == string("place"));
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
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
}

TEST_CASE("Test replacement of d and t") {
    string text = "Don’t fix it if id ain’t broke.";
    CHECK(find(text, "Don’t") == string("Don’d"));
    CHECK(find(text, "Don’t") == string("Ton’t"));
    CHECK(find(text, "Don’t") == string("don't"));
    CHECK(find(text, "id") == string("it"));
    CHECK(find(text, "it") == string("id"));
    CHECK(find(text, "ain’d") == string("ain’t"));
}

TEST_CASE("Test replacement of i and y") {
    string text = "Don’t fyx it if yt ayn’t broke.";
    CHECK(find(text, "fix") == string("fyx"));
    CHECK(find(text, "yt") == string("it"));
    CHECK(find(text, "yf") == string("if"));
    CHECK(find(text, "ayn’t") == string("ain’t"));
    CHECK(find(text, "IT") == string("it"));
    CHECK(find(text, "IF") == string("if"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "Good programmers write code for humans first and computers next.";
    CHECK(find(text, "guud") == string("good"));
    CHECK(find(text, "guod") == string("Good"));
    CHECK(find(text, "goud") == string("Good"));
    CHECK(find(text, "prUgrammers") == string("programmers"));
    CHECK(find(text, "cude") == string("code"));
    CHECK(find(text, "homans") == string("humans"));
    CHECK(find(text, "cumputers") == string("computers"));

}

TEST_CASE("Test replacement of s and z") {
    string text = "Software testers always go to heaven; they’ve already had their fair share of hell.”";
    CHECK(find(text, "zoftware") == string("Software"));
    CHECK(find(text, "tezters") == string("testers"));
    CHECK(find(text, "tezterz") == string("testers"));
    CHECK(find(text, "testerz") == string("testers"));
    CHECK(find(text, "alwayz") == string("always"));
    CHECK(find(text, "zhare") == string("share"));
 
}

TEST_CASE("Test replacement of  g and j") {
    string text = "Good programmers write code for humans first and computers next.”";
    CHECK(find(text, "jood") == string("Good"));
    CHECK(find(text, "projrammers") == string("programmers"));
    text=" If you don't know, just Google it";
    CHECK(find(text, "gust") == string("just"));
    CHECK(find(text, "JUST") == string("just"));
    CHECK(find(text, "GooGle ") == string("Google "));
    CHECK(find(text, "Joogle ") == string("Google "));
    CHECK(find(text, "JooJle ") == string("Google "));
    CHECK(find(text, "GooJle ") == string("Google "));
    CHECK(find(text, "Gogle ") != string("Google "));
}

TEST_CASE("Test replacement of c, k, q") {
    string text="Hakuna Matata! What a wonderful phrase Hakuna Matata! Ain't no passing craze";
    CHECK(find(text, "Hacuna") == string("Hakuna"));
    CHECK(find(text, "Haquna") == string("Hakuna"));
    CHECK(find(text, "Kraze") == string("craze"));
    text="I Just Can't Wait to Be King";
    CHECK(find(text, "kant") == string("Cant"));
    CHECK(find(text, "qant") == string("Cant"));
    CHECK(find(text, "cing") == string("King"));
    CHECK(find(text, "qing") == string("King"));
    CHECK(find(text, "kking") != string("King"));


}
TEST_CASE("long word")
{
    string  text= "Supercalifragilisticexpialidocious Mary Poppins";
    CHECK(find(text, "Supercalifragilisticexpialidocious") != string("Supercalifragilisticexpialidocios"));
    CHECK(find(text, "Supercalifragilisticexpialidocioos") == string("Supercalifragilisticexpialidocious")); 
    CHECK(find(text, "Supercalifrajilisticexpialidocious") == string("Supercalifragilisticexpialidocious")); 
    CHECK(find(text, "zupercalifrajilisticexpialidocious") == string("Supercalifragilisticexpialidocious")); 
    CHECK(find(text, "Superqalifragilisticexpialidokious") == string("Supercalifragilisticexpialidocious")); 

}


TEST_CASE("Test emptey text and word") {
    string text = "xxx vorry yyy";
    CHECK(find(text, "") == string("vorry"));
    text = "";
    CHECK(find(text, "be") == string("pe"));
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