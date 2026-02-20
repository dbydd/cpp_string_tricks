#include <iostream>
#include <string>
#include <cassert>
using namespace std;

// Trim functions - remove whitespace from ends

string trim(const string& s) {
    // TODO: Implement trim - remove leading and trailing whitespace
    // Hint: find_first_not_of and find_last_not_of
    return s; // FIX THIS
}

string trimLeft(const string& s) {
    // TODO: Remove leading whitespace only
    return s; // FIX THIS
}

string trimRight(const string& s) {
    // TODO: Remove trailing whitespace only
    return s; // FIX THIS
}

int main() {
    // Test trim both sides
    string t1 = "  hello  ";
    assert(trim(t1) == "hello");
    
    // Test trim with tabs and spaces
    string t2 = "\t  world  \n";
    assert(trim(t2) == "world");
    
    // Test trimLeft
    string t3 = "   hello";
    assert(trimLeft(t3) == "hello");
    
    // Test trimRight
    string t4 = "hello   ";
    assert(trimRight(t4) == "hello");
    
    // Test no whitespace
    string t5 = "hello";
    assert(trim(t5) == "hello");
    
    // Test only whitespace
    string t6 = "   ";
    assert(trim(t6) == "");
    
    // Test empty string
    string t7 = "";
    assert(trim(t7) == "");
    
    cout << "04_trim.cpp: All assertions passed!" << endl;
    return 0;
}
