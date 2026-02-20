#include <iostream>
#include <string>
#include <regex>
#include <cassert>
using namespace std;

int main() {
    // regex_search: find pattern within string
    
    // TODO: Find all digits in "abc123def456"
    string nums = "abc123def456";
    regex digitPattern(""); // FIX THIS - pattern for single digit \d
    
    smatch match;
    string::const_iterator it = nums.cbegin();
    int count = 0;
    while (regex_search(it, nums.cend(), match, digitPattern)) {
        count++;
        it = match.suffix().first;
    }
    assert(count == 6);  // 6 digits
    
    // TODO: Find all words (alphanumeric sequences)
    string text = "hello world 123";
    regex wordPattern(""); // FIX THIS - pattern for word \w+
    
    int wordCount = 0;
    it = text.cbegin();
    while (regex_search(it, text.cend(), match, wordPattern)) {
        wordCount++;
        it = match.suffix().first;
    }
    assert(wordCount == 3);  // hello, world, 123
    
    // TODO: Find all email-like patterns
    string data = "Contact: test@test.com or admin@site.org";
    regex emailPattern(""); // FIX THIS - simple email pattern
    
    int emailCount = 0;
    it = data.cbegin();
    while (regex_search(it, data.cend(), match, emailPattern)) {
        emailCount++;
        it = match.suffix().first;
    }
    assert(emailCount == 2);  // 2 emails
    
    cout << "02_search.cpp: All assertions passed!" << endl;
    return 0;
}
