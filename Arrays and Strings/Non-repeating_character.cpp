/*
Problem Statement:
Given a string, find the first non-repeating character and return its index. If there is no such character, return -1.

Approach:
1.Count Frequency: First, traverse the string and store the frequency of each character using a hash map or array.
2.Find the First Non-Repeating Character: Traverse the string again to find the first character that has a frequency of 1.
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to find the first non-repeating character in a string
int firstNonRepeatingCharacter(const string &s)
{
    unordered_map<char, int> charCount;

    // Step 1: Count the frequency of each character
    for (char c : s)
    {
        charCount[c]++;
    }

    // Step 2: Find the first character with a count of 1
    for (int i = 0; i < s.length(); ++i)
    {
        if (charCount[s[i]] == 1)
        {
            return i; // Return the index of the first non-repeating character
        }
    }

    return -1; // If no non-repeating character is found
}

int main()
{
    string s = "leetcode"; // Example test case

    int index = firstNonRepeatingCharacter(s);

    if (index != -1)
    {
        cout << "The first non-repeating character is at index: " << index << endl;
    }
    else
    {
        cout << "There is no non-repeating character." << endl;
    }

    return 0;
}
