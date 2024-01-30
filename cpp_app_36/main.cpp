#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <string>

class Dictionary {
private:
    std::map<std::string, std::string> words;

public:
    void searchWord(const std::string& word) {
        auto it = words.find(word);
        if (it != words.end()) {
            std::cout << "Definition of '" << word << "': " << it->second << "\n";   
        }
        else {
            std::cout << "Word '" << word << "' not found in the dictionary\n";
        }
    }

    //потестувати що буде якщо немає слова 
    void addWord(const std::string& word, const std::string& definition) {
        words[word] = definition;
        std::cout << "Word '" << word << "' added to the dictionary\n";
    }

    void deleteWord(const std::string& word) {
        auto it = words.find(word);
        if (it != words.end()) {
            words.erase(it);
            std::cout << "Word '" << word << "' deleted from the dictionary\n";
        }
        else {
            std::cout << "Word '" << word << "' not found in the dictionary\n";
        }
    }

    void editWord(const std::string& word, const std::string& newDefinition) {
        auto it = words.find(word);
        if (it != words.end()) {
            it->second = newDefinition;
            std::cout << "Definition of '" << word << "' updated in the dictionary\n";
        }
        else {
            std::cout << "Word '" << word << "' not found in the dictionary\n";
        }
    }

    void readFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string word, definition;
            while (file >> word) {
                std::getline(file >> std::ws, definition);    //std::ws - skip whitespace
                words[word] = definition;
            }
            std::cout << "Dictionary loaded from file: " << filename << "\n";
            file.close();
        }
        else {
            std::cout << "Unable to open file: " << filename << "\n";
        }
    }

    void writeToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (const auto& entry : words) {
                file << entry.first << " " << entry.second << "\n";
            }
            std::cout << "Dictionary saved to file: " << filename << "\n";
            file.close();
        }
        else {
            std::cout << "Unable to open file: " << filename << "\n";
        }
    }
};

int main() {
    Dictionary dictionary;

    while (true) {
        std::cout << "1. Add a word\n";
        std::cout << "2. Delete a word\n";
        std::cout << "3. Edit a word\n";
        std::cout << "4. Search for a word\n";
        std::cout << "5. Write dictionary to file\n";
        std::cout << "6. Read dictionary from file\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

		if (choice == 1) {
			std::cout << "Enter word to add: ";
			std::string word;
			std::cin >> word;
			std::cout << "Enter definition: ";
			std::string definition;
			std::getline(std::cin >> std::ws, definition);
			dictionary.addWord(word, definition);
		}
		else if (choice == 2) {
			std::cout << "Enter word to delete: ";
			std::string word;
			std::cin >> word;
			dictionary.deleteWord(word);
		}
		else if (choice == 3) {
			std::cout << "Enter word to edit: ";
			std::string word;
			std::cin >> word;
			std::cout << "Enter new definition: ";
			std::string definition;
			std::getline(std::cin >> std::ws, definition);
			dictionary.editWord(word, definition);
		}
        else if (choice == 4) {
            std::cout << "Enter word to search: ";
            std::string word;
            std::cin >> word;
            dictionary.searchWord(word);
        }
        else if (choice == 5) {
            std::cout << "Enter filename: ";
            std::string filename;
            std::cin >> filename;
            dictionary.writeToFile(filename);
        }
		else if (choice == 6) {
			std::cout << "Enter filename: ";
			std::string filename;
			std::cin >> filename;
			dictionary.readFromFile(filename);
		}
		else if (choice == 7) {
			break;
		}
		else {
			std::cout << "Invalid choice\n";
		}
	}

    return 0;
}