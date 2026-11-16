/*
    Lab Assignment - Word Frequency Counter

    This program demonstrates a basic HashMap structure. 
    It is implemented in C++ instead of Java.

    Key features:
    - Read and proccess users input
    - convert all words to lowercase and ignore punctuation
    - Function to display HashMap Key and value
    - Function to display most frequent word

    Created by:
    - Adam Huynh
    - CS 236 Fall Semester, LAVC
    - 11/15/2026

    GitHub repository:
    - https://github.com/daTaHere/lavc-cs236--adv-data-structs
*/


#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// ======================   Prototype  ===============================
unordered_map<string, int> processInput(const string& userInput, string& mostFrequent);
void displayWordCount(const unordered_map<string, int>& wordCounts);
void getMostFrequent(const unordered_map<string, int>& wordCounts, const string& mostFrequent);


int main() {
    string userInput;
    unordered_map<string, int> wordCounts;
    string mostFrequent;

    cout << "Enter a sentence or short paragraph:" << endl;
    getline(cin, userInput);

    wordCounts = processInput(userInput, mostFrequent);
    displayWordCount(wordCounts);
    getMostFrequent(wordCounts,mostFrequent);

    return 0;
}

// ========== function def =====================

// Returns hashmap and most frequent word
unordered_map<string, int> processInput(const string& userInput, string& mostFrequent) {
    int maxCount = 0;
    string currentWord;
    unordered_map<string, int> wordCounts;

    // Handle empty input
    if (userInput.empty())
        return wordCounts;

    // Build each word one character at a time.
    for (char character : userInput) {
        if (isalpha(static_cast<unsigned char>(character))) {
            currentWord += static_cast<char>(
                tolower(static_cast<unsigned char>(character))
                );
        }
        else if (!currentWord.empty()) {
            int currentCount = ++wordCounts[currentWord];

            if (currentCount > maxCount) {
                maxCount = currentCount;
                mostFrequent = currentWord;
            }
            
            currentWord.clear();
        }
    }

    // Count the final word.
    if (!currentWord.empty()) {
        int currentCount = ++wordCounts[currentWord];

        if (currentCount > maxCount) {
            maxCount = currentCount;
            mostFrequent = currentWord;
        }
    }

    return wordCounts;
}

// Display all elements Key/Value
void displayWordCount(const unordered_map<string, int>& wordCounts) {
    cout << "\nWord counts:" << endl;
    for (const auto& entry : wordCounts) {
        cout << entry.first << " -> " << entry.second << endl;
    }
}

// Display Key/Value of most frequent word
void getMostFrequent(const unordered_map<string, int>& wordCounts, const string& mostFrequent) {
    
    cout << "\nMost frequent word: " << (wordCounts.empty() ? "None" : mostFrequent) << endl;
    cout << "Count: " << (wordCounts.empty() ? 0 : wordCounts.at(mostFrequent)) << endl;
}
