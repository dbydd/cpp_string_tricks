#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    string a = "Hello";
    string b = "World";
    
    // TODO: Concatenate using + operator
    string c = ""; // FIX THIS - should be "HelloWorld"
    
    assert(c == "HelloWorld");
    
    // TODO: Append using += operator
    string d = "Hello";
    d += ""; // FIX THIS - append "World" to get "HelloWorld"
    
    assert(d == "HelloWorld");
    
    // TODO: Use append() method
    string e = "Hello";
    e.append(""); // FIX THIS - append "World"
    
    assert(e == "HelloWorld");
    
    // TODO: Prepend "Hello " to "World" using + operator
    // Result should be "Hello World"
    string f = ""; // FIX THIS
    
    assert(f == "Hello World");
    
    cout << "02_concat.cpp: All assertions passed!" << endl;
    return 0;
}
