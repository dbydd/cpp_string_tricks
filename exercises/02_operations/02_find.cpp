#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    string s = "Hello World";
    
    // TODO: Find "World" - returns position
    size_t pos = 999; // FIX THIS - should be 6
    
    assert(pos == 6);
    
    // TODO: Find "xyz" - not found, should return npos
    size_t notFound = 0; // FIX THIS - should use npos
    
    assert(notFound == string::npos);
    
    // TODO: Find first occurrence of 'o'
    size_t first_o = 999; // FIX THIS - should be 4
    
    assert(first_o == 4);
    
    // TODO: Find 'o' starting from position 5
    size_t second_o = 999; // FIX THIS - should be 7
    
    assert(second_o == 7);
    
    // TODO: Check if string contains "World" using find
    bool hasWorld = false; // FIX THIS - use find
    
    assert(hasWorld == true);
    
    // TODO: Check if string starts with "Hello"
    bool startsHello = false; // FIX THIS - use substr or compare
    
    assert(startsHello == true);
    
    // TODO: Check if string ends with "World"
    bool endsWorld = false; // FIX THIS
    
    assert(endsWorld == true);
    
    cout << "02_find.cpp: All assertions passed!" << endl;
    return 0;
}
