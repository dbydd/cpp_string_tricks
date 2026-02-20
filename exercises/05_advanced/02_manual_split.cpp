#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// Manual split function - essential for OI since STL doesn't have it!
// Returns vector of strings split by delimiter
vector<string> split(const string& s, char delim) {
    vector<string> result;
    // TODO: Implement split function
    // Hint: use find and substr in a loop
    return result; // FIX THIS
}

int main() {
    // Test split by space
    string s1 = "Hello World";
    vector<string> parts1 = split(s1, ' ');
    assert(parts1.size() == 2);
    assert(parts1[0] == "Hello");
    assert(parts1[1] == "World");
    
    // Test split by comma
    string s2 = "a,b,c,d";
    vector<string> parts2 = split(s2, ',');
    assert(parts2.size() == 4);
    assert(parts2[0] == "a");
    assert(parts2[3] == "d");
    
    // Test split with no delimiter found
    string s3 = "abc";
    vector<string> parts3 = split(s3, ',');
    assert(parts3.size() == 1);
    assert(parts3[0] == "abc");
    
    // Test split with empty result
    string s4 = "";
    vector<string> parts4 = split(s4, ',');
    assert(parts4.size() == 0);
    
    // Test split by slash
    string s5 = "2024/01/15";
    vector<string> parts5 = split(s5, '/');
    assert(parts5.size() == 3);
    assert(parts5[0] == "2024");
    assert(parts5[1] == "01");
    assert(parts5[2] == "15");
    
    // Test: consecutive delimiters
    string s6 = "a,,b";
    vector<string> parts6 = split(s6, ',');
    assert(parts6.size() == 3);
    assert(parts6[1] == "");
    
    cout << "02_manual_split.cpp: All assertions passed!" << endl;
    return 0;
}
