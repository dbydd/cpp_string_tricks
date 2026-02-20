#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    string s = "Hello";
    
    // TODO: Access first character using front()
    char first = '?'; // FIX THIS - should be 'H'
    
    assert(first == 'H');
    
    // TODO: Access last character using back()
    char last = '?'; // FIX THIS - should be 'o'
    
    assert(last == 'o');
    
    // TODO: Access character at index 1 using []
    char second = '?'; // FIX THIS - should be 'e'
    
    assert(second == 'e');
    
    // TODO: Access character at index 1 using at() with bounds checking
    char second_at = '?'; // FIX THIS - should be 'e'
    
    assert(second_at == 'e');
    
    // TODO: Get character at out-of-bounds index 100 (will throw)
    // Use try-catch to catch the exception
    char val = 'x';
    try {
        val = s.at(100);
    } catch (const out_of_range& e) {
        val = 'x'; // Expected: exception thrown
    }
    assert(val == 'x');
    
    cout << "03_access.cpp: All assertions passed!" << endl;
    return 0;
}
