#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    // TODO: Create a string with 10 asterisks '*'
    // Hint: Use string constructor with count and character
    string stars = ""; // FIX THIS // FIX THIS
    
    assert(stars.size() == 10);
    assert(stars == "**********");
    
    // TODO: Create string "hello" 3 times concatenated
    // Hint: Use string(n, char) constructor
    string repeated = ""; // FIX THIS // FIX THIS
    
    assert(repeated.size() == 15);
    assert(repeated == "hellohellohello");
    
    cout << "01_init.cpp: All assertions passed!" << endl;
    return 0;
}
