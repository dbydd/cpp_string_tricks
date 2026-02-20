#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    // Number to string conversions (essential for OI)
    
    // TODO: Convert integer 12345 to string
    string numStr = ""; // FIX THIS - use to_string
    
    assert(numStr == "12345");
    assert(numStr.size() == 5);
    
    // TODO: Convert double 3.14159 to string
    string piStr = ""; // FIX THIS
    
    assert(piStr == "3.141590");
    
    // TODO: Convert string "12345" to integer
    int num = 0; // FIX THIS - use stoi
    
    assert(num == 12345);
    
    // TODO: Convert string "123.45" to double
    double d = 0.0; // FIX THIS - use stod
    
    assert(d > 123.44 && d < 123.46);
    
    // TODO: Convert string "12345" to long long
    long long ll = 0; // FIX THIS - use stoll
    
    assert(ll == 12345LL);
    
    // TODO: Parse "123abc" - stoi stops at first invalid char
    string mixed = "123abc";
    size_t pos = 0;
    int parsed = stoi(mixed, &pos); // FIX THIS - pos should be 3
    
    assert(parsed == 123);
    assert(pos == 3);
    
    // TODO: Handle invalid conversion - use try-catch
    string bad = "abc";
    int errVal = -1;
    try {
        int x = stoi(bad); // Should throw
        errVal = x;
    } catch (...) {
        errVal = -1; // Expected
    }
    assert(errVal == -1);
    
    cout << "04_numbers.cpp: All assertions passed!" << endl;
    return 0;
}
