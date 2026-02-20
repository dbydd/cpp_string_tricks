#include <iostream>
#include <string>
#include <string_view>
#include <cassert>
using namespace std;

int main() {
    string data = "Hello World";
    
    // TODO: Create string_view without copying - zero copy!
    string_view sv1 = ""; // FIX THIS - create from string
    
    assert(sv1 == "Hello World");
    assert(sv1.size() == 11);
    
    // TODO: Create view of only "Hello" (first 5 chars)
    string_view sv2 = ""; // FIX THIS
    
    assert(sv2 == "Hello");
    assert(sv2.size() == 5);
    
    // TODO: Create view of "World" using sv1
    string_view sv3 = ""; // FIX THIS - sv1.substr(6)
    
    assert(sv3 == "World");
    
    // TODO: Find in string_view (same methods as string)
    size_t pos = sv1.find("World");
    assert(pos == 6);
    
    // TODO: Remove prefix
    string_view sv4 = sv1;
    sv4.remove_prefix(6); // FIX THIS - remove "Hello "
    
    assert(sv4 == "World");
    
    // TODO: Remove suffix
    string_view sv5 = sv1;
    sv5.remove_suffix(6); // FIX THIS - remove "World"
    
    assert(sv5 == "Hello");
    
    // TODO: Convert string_view to string (when needed)
    string_view sv6 = "test";
    string s = ""; // FIX THIS - convert to string
    
    assert(s == "test");
    
    // TODO: Use string_view to avoid copies in substring operations
    // This is crucial for OI performance!
    string longStr = "The quick brown fox jumps over the lazy dog";
    string_view q = ""; // FIX THIS - view of "quick"
    
    assert(q == "quick");
    
    cout << "01_string_view.cpp: All assertions passed!" << endl;
    return 0;
}
