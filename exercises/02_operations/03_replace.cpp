#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    string s = "Hello World";
    
    // TODO: Replace "World" with "C++"
    string r1 = s; // FIX THIS - replace "World" with "C++"
    
    assert(r1 == "Hello C++");
    
    // TODO: Replace first 5 chars with "Hi"
    string r2 = s;
    r2.replace(0, 5, "Hi"); // FIX THIS - should be "Hi World"
    
    assert(r2 == "Hi World");
    
    // TODO: Erase last 6 characters
    string r3 = s;
    r3.erase(5); // FIX THIS - erase from position 5 to end
    
    assert(r3 == "Hello");
    
    // TODO: Erase " World" using erase with position/length
    string r4 = s;
    r4.erase(5, 6); // FIX THIS - erase 6 chars starting at 5
    
    assert(r4 == "Hello");
    
    // TODO: Insert "C++ " at position 6
    string r5 = s;
    r5.insert(6, "C++ "); // FIX THIS - "Hello C++ World"
    
    assert(r5 == "Hello C++ World");
    
    // TODO: Use erase+insert (or just replace) to change "Hello" to "Hi"
    string r6 = s;
    r6.erase(0, 5);
    r6.insert(0, "Hi"); // FIX THIS
    
    assert(r6 == "Hi World");
    
    cout << "03_replace.cpp: All assertions passed!" << endl;
    return 0;
}
