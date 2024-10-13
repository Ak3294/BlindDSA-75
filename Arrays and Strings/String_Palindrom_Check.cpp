/*
Problem Statement:
Write a function to check if a given string is a palindrome. A palindrome is a string that reads the same forward and backward, ignoring spaces, punctuation, and case.

Approach:
To check if a string is a palindrome:

Ignore non-alphanumeric characters (letters and digits).
Ignore case.
Compare the first and last characters of the string, moving inwards.
*/

#include <iostream>
#include <string>
#include <cctype> // For isalnum and tolower
using namespace std;

// Function to check if a string is a palindrome
bool isPalindrome(const string &s)
{
    int left = 0;
    int right = s.length() - 1;

    while (left < right)
    {
        // Skip non-alphanumeric characters
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        // Compare characters, ignoring case
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama"; // Example test case

    if (isPalindrome(s))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
