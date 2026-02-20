#include <iostream>
#include <string>
#include <regex>
#include <cassert>
using namespace std;

int main() {
    // regex_replace: replace pattern matches
    
    // TODO: Replace all digits with 'X'
    string s1 = "abc123def456";
    regex digitRx(""); // FIX THIS - pattern for digit
    
    string r1 = regex_replace(s1, digitRx, "X");
    assert(r1 == "abcXXXdefXXX");
    
    // TODO: Replace all spaces with underscore
    string s2 = "hello world test";
    regex spaceRx(""); // FIX THIS
    
    string r2 = regex_replace(s2, spaceRx, "_");
    assert(r2 == "hello_world_test");
    
    // TODO: Reformat date YYYY-MM-DD to DD/MM/YYYY
    string date = "2024-01-15";
    regex dateRx(""); // FIX THIS - capture groups
    
    string r3 = regex_replace(date, dateRx, "$3/$2/$1");
    assert(r3 == "15/01/2024");
    
    // TODO: Replace "bad" with "good" (case insensitive)
    string s4 = "This is BAD and bad";
    regex badRx(""); // FIX THIS - use regex_constants::icase
    
    string r4 = regex_replace(s4, badRx, "good");
    assert(r4 == "This is good and good");
    
    // TODO: Extract and replace using $1, $2
    string s5 = "John Doe";
    regex nameRx(""); // FIX THIS - (\\w+) (\\w+)
    
    string r5 = regex_replace(s5, nameRx, "$2, $1");
    assert(r5 == "Doe, John");
    
    cout << "03_replace.cpp: All assertions passed!" << endl;
    return 0;
}
