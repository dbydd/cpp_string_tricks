#include <iostream>
#include <string>
#include <regex>
#include <cassert>
using namespace std;

int main() {
    string email1 = "test@example.com";
    regex emailPattern(""); // FIX THIS
    
    bool isEmail = regex_match(email1, emailPattern);
    assert(isEmail == true);
    
    string badEmail = "not-an-email";
    bool isBadEmail = regex_match(badEmail, emailPattern);
    assert(isBadEmail == false);
    
    string phone = "123-456-7890";
    regex phonePattern(""); // FIX THIS
    
    bool isPhone = regex_match(phone, phonePattern);
    assert(isPhone == true);
    
    string word = "hello";
    regex wordPattern(""); // FIX THIS
    
    bool isWord = regex_match(word, wordPattern);
    assert(isWord == true);
    
    string url = "https://google.com";
    regex urlPattern(""); // FIX THIS
    
    bool isUrl = regex_match(url, urlPattern);
    assert(isUrl == true);
    
    cout << "01_match.cpp: All assertions passed!" << endl;
    return 0;
}
