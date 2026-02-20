#include <iostream>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

int main() {
    // Simulate input: "Hello World"
    // This exercise demonstrates the difference between >> and getline
    
    istringstream input("Hello World");
    
    // TODO: Use >> to read first word (stops at whitespace)
    string word = ""; // FIX THIS - should be "Hello"
    
    assert(word == "Hello");
    
    // TODO: Read the rest of the line using getline
    istringstream input2("Hello World");
    string line = "";
    getline(input2, line); // FIX THIS - should read "Hello World"
    
    assert(line == "Hello World");
    
    // TODO: Read only first 5 characters of "Hello World"
    istringstream input3("Hello World");
    string partial = "";
    getline(input3, partial, ' '); // FIX THIS - delim is ' ', should get "Hello"
    
    assert(partial == "Hello");
    
    // TODO: Read second word after "Hello "
    istringstream input4("Hello World");
    string ignoreFirst, secondWord;
    input4 >> ignoreFirst;  // Skip "Hello"
    getline(input4, secondWord); // FIX THIS - should get " World" then trim
    
    // Alternative: use >> again
    istringstream input5("Hello World");
    string w1, w2;
    input5 >> w1 >> w2; // FIX THIS - w2 should be "World"
    
    assert(w2 == "World");
    
    cout << "04_io.cpp: All assertions passed!" << endl;
    return 0;
}
