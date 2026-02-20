#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    string s = "Hello World";
    
    // TODO: Extract first 5 characters using substr
    string first5 = ""; // FIX THIS - should be "Hello"
    
    assert(first5 == "Hello");
    
    // TODO: Extract "World" using substr with position
    string world = ""; // FIX THIS - position 6, length 5
    
    assert(world == "World");
    
    // TODO: Extract from position 6 to end
    string from6 = ""; // FIX THIS - should be "World"
    
    assert(from6 == "World");
    
    // TODO: Extract last 5 characters
    string last5 = ""; // FIX THIS - should be "World"
    
    assert(last5 == "World");
    
    // TODO: Extract middle "lo W" using substr
    // "Hello World", start=3, length=5
    string middle = ""; // FIX THIS
    
    assert(middle == "lo Wo");
    
    cout << "01_substr.cpp: All assertions passed!" << endl;
    return 0;
}
