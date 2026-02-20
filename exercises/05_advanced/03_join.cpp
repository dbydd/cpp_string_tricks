#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// Manual join function - join vector of strings with delimiter
string join(const vector<string>& parts, const string& delim) {
    // TODO: Implement join function
    // Hint: use a loop and append delimiter between elements
    return ""; // FIX THIS
}

int main() {
    // Test basic join
    vector<string> v1 = {"Hello", "World"};
    string j1 = join(v1, " ");
    assert(j1 == "Hello World");
    
    // Test join with comma
    vector<string> v2 = {"a", "b", "c"};
    string j2 = join(v2, ",");
    assert(j2 == "a,b,c");
    
    // Test join with empty vector
    vector<string> v3;
    string j3 = join(v3, "-");
    assert(j3 == "");
    
    // Test join with single element
    vector<string> v4 = {"only"};
    string j4 = join(v4, " ");
    assert(j4 == "only");
    
    // Test: Practical use - date parts
    vector<string> date = {"2024", "01", "15"};
    string j5 = join(date, "/");
    assert(j5 == "2024/01/15");
    
    // Test: Join with empty string delimiter
    vector<string> v5 = {"a", "b", "c"};
    string j6 = join(v5, "");
    assert(j6 == "abc");
    
    // Test: Multiple chars delimiter
    vector<string> v6 = {"start", "middle", "end"};
    string j7 = join(v6, " -> ");
    assert(j7 == "start -> middle -> end");
    
    cout << "03_join.cpp: All assertions passed!" << endl;
    return 0;
}
