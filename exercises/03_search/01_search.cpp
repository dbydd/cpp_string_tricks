#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int main() {
    string s = "Hello World Hello";
    
    // TODO: Find first occurrence of "Hello"
    size_t first = 999; // FIX THIS
    
    assert(first == 0);
    
    // TODO: Find second occurrence of "Hello" (starting after pos 5)
    size_t second = 999; // FIX THIS
    
    assert(second == 12);
    
    // TODO: Find from end using rfind
    size_t rfirst = 999; // FIX THIS - rfind finds from right
    
    assert(rfirst == 12);
    
    // TODO: Find first of any character in "aeiou" using find_first_of
    size_t firstVowel = 999; // FIX THIS
    
    assert(firstVowel == 1);  // 'e'
    
    // TODO: Find last of any character in "aeiou" using find_last_of
    size_t lastVowel = 999; // FIX THIS
    
    assert(lastVowel == 14);  // 'o' in second "Hello"
    
    // TODO: Find first not of characters in "He" 
    // Should skip "He" and find 'l'
    size_t notHe = 999; // FIX THIS
    
    assert(notHe == 2);  // 'l'
    
    // TODO: Compare strings - case sensitive
    string a = "abc";
    string b = "abd";
    int cmp = 2; // FIX THIS - use compare()
    
    assert(cmp < 0);  // "abc" < "abd"
    
    // TODO: Compare only first 3 chars
    string c = "abcxyz";
    string d = "abdxyz";
    int cmp3 = 2; // FIX THIS - compare(0, 3, ...)
    
    assert(cmp3 < 0);
    
    cout << "01_search.cpp: All assertions passed!" << endl;
    return 0;
}
