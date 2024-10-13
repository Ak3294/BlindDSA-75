/*
Write a C++ function that finds all possible palindromic substrings of a given string.
A palindrome is a string that reads the same forward and backward. The function should return all unique palindromic substrings.

Input: s = "ababa"
output: ["a", "b", "aba", "bab", "ababa"]

*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if a given substring is a palindrome
bool isPalindrome(const string &str, int start, int end)
{
    while (start < end)
    {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

// Function to find all unique palindromic substrings
set<string> findAllPalindromes(const string &s)
{
    set<string> palindromes;
    int n = s.length();

    // Check all substrings
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (isPalindrome(s, i, j))
            {
                palindromes.insert(s.substr(i, j - i + 1));
            }
        }
    }
    return palindromes;
}

int main()
{
    string s = "ababa";

    set<string> palindromicSubstrings = findAllPalindromes(s);

    // Print all unique palindromic substrings
    cout << "Palindromic substrings are: \n";
    for (const string &p : palindromicSubstrings)
    {
        cout << p << "\n";
    }

    return 0;
}


// Optimal Solution

#include <iostream>
#include <set>
#include <string>
using namespace std;

// Function to expand around center and add palindromic substrings to the set
void expandAroundCenter(const string &s, int left, int right, set<string> &palindromes)
{
    while (left >= 0 && right < s.length() && s[left] == s[right])
    {
        palindromes.insert(s.substr(left, right - left + 1));
        left--;
        right++;
    }
}

// Function to find all unique palindromic substrings
set<string> findAllPalindromes(const string &s)
{
    set<string> palindromes;
    int n = s.length();

    for (int i = 0; i < n; ++i)
    {
        // Odd-length palindromes (centered at one character)
        expandAroundCenter(s, i, i, palindromes);
        // Even-length palindromes (centered between two characters)
        expandAroundCenter(s, i, i + 1, palindromes);
    }

    return palindromes;
}

int main()
{
    string s = "ababa";

    set<string> palindromicSubstrings = findAllPalindromes(s);

    // Print all unique palindromic substrings
    cout << "Palindromic substrings are: \n";
    for (const string &p : palindromicSubstrings)
    {
        cout << p << "\n";
    }

    return 0;
}
