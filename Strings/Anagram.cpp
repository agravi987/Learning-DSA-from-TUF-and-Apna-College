#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Method 1: Sorting approach (Time: O(n log n), Space: O(1))
bool isAnagram_Sort(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

// Method 2: Hash map approach (Time: O(n), Space: O(1))
bool isAnagram_HashMap(string s1, string s2) {
    if (s1.length() != s2.length()) return false;

    unordered_map<char, int> freq;

    for (char ch : s1) freq[ch]++;
    for (char ch : s2) freq[ch]--;

    for (auto& entry : freq) {
        if (entry.second != 0) return false;
    }

    return true;
}

int main() {
    string str1 = "listen";
    string str2 = "silent";

    cout << "Using Sorting: ";
    if (isAnagram_Sort(str1, str2))
        cout << "The strings are anagrams.\n";
    else
        cout << "The strings are not anagrams.\n";

    cout << "Using HashMap: ";
    if (isAnagram_HashMap(str1, str2))
        cout << "The strings are anagrams.\n";
    else
        cout << "The strings are not anagrams.\n";

    return 0;
}
