#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

std::string createFile(int size) {
    std::string fileName = "input.txt";
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        std::vector<std::string> words = { "the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "flower", "presence"};
        for (int i = 0; i < size; i++) {
            outputFile << words[i % words.size()] << " ";
        }
        outputFile.close();
    }
    else {
        std::cout << "Error: Unable to create output file\n";
        fileName = "";
    }
    return fileName;
}

std::string removePunctuation(const std::string& word) {
    std::string result;
    for (char ch : word) {
        if (!ispunct(ch)) {
            result += ch;
        }
    }
    return result;
}

int main() {
    std::string inputFileName = createFile(100);
    if (inputFileName.empty()) {
        return 1;
    }

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cout << "Error: Unable to open input file\n";
        return 1;
    }

    std::map<std::string, int> wordFrequency;

    std::string word;
    while (inputFile >> word) {
        word = removePunctuation(word);

        for (char& ch : word) {
            ch = tolower(ch);
        }

        wordFrequency[word]++;
    }

    inputFile.close();

    std::cout << "Frequency Dictionary:\n";
    for (const auto& entry : wordFrequency) {
        std::cout << entry.first << ": " << entry.second << " occurrences\n";
    }

    std::string mostCommonWord;
    int maxFrequency = 0;
    for (const auto& entry : wordFrequency) {
        if (entry.second > maxFrequency) {
            mostCommonWord = entry.first;
            maxFrequency = entry.second;
        }
    }

    std::cout << "\nMost commonly used word: " << mostCommonWord << " (" << maxFrequency << " occurrences)\n";

    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "Frequency Dictionary:\n";
        for (const auto& entry : wordFrequency) {
            outputFile << entry.first << ": " << entry.second << " occurrences\n";
        }
        outputFile << "\nMost commonly used word: " << mostCommonWord << " (" << maxFrequency << " occurrences)\n";

        outputFile.close();
        std::cout << "\nResults written to output.txt\n";
    }
    else {
        std::cout << "Error: Unable to open output file\n";
        return 1;
    }

    return 0;
}
