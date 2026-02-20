#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool startsWith(const string& s, const string& prefix) {
    // TODO: Check if string starts with prefix
    // Use substr or compare
    return false; // FIX THIS
}

bool endsWith(const string& s, const string& suffix) {
    // TODO: Check if string ends with suffix
    return false; // FIX THIS
}

string stripPrefix(const string& s, const string& prefix) {
    // TODO: Remove prefix if present, return rest
    return s; // FIX THIS
}

string stripSuffix(const string& s, const string& suffix) {
    // TODO: Remove suffix if present, return rest
    return s; // FIX THIS
}

int main() {
    // startsWith tests
    assert(startsWith("Hello World", "Hello") == true);
    assert(startsWith("Hello World", "hello") == false);  // case sensitive
    assert(startsWith("Hello World", "Hello World") == true);
    assert(startsWith("Hello", "Hello World") == false);
    assert(startsWith("Hello", "") == true);
    assert(startsWith("", "a") == false);
    
    // endsWith tests
    assert(endsWith("Hello World", "World") == true);
    assert(endsWith("Hello World", "world") == false);  // case sensitive
    assert(endsWith("Hello World", "Hello World") == true);
    assert(endsWith("World", "Hello World") == false);
    assert(endsWith("Hello", "") == true);
    assert(endsWith("", "a") == false);
    
    // stripPrefix tests
    assert(stripPrefix("Hello World", "Hello") == " World");
    assert(stripPrefix("Hello World", "X") == "Hello World");  // no strip
    assert(stripPrefix("Hello", "Hello") == "");
    
    // stripSuffix tests
    assert(stripSuffix("Hello World", "World") == "Hello ");
    assert(stripSuffix("Hello World", "X") == "Hello World");  // no strip
    assert(stripSuffix("World", "World") == "");
    
    cout << "05_prefix_suffix.cpp: All assertions passed!" << endl;
    return 0;
}
