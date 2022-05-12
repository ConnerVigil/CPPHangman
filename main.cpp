#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

std::string getRandomWord() {
    std::ifstream infile;
    infile.open("/Users/connervigil/IdeaProjects/CPPHangman/Words.txt");
    if (infile.fail()) {
        std::cout << "File Could Not Be Reached";
        return 0;
    }
    std::vector<std::string> listOfWords;
    while (infile.good()) {
        std::string str;
        infile >> str;
        listOfWords.push_back(str);
    }
    infile.close();
    srand(time(0));
    unsigned int max = listOfWords.size() - 1;
    unsigned int wordNum = rand() % max;
    return listOfWords.at(wordNum);
}

char getLetterGuess() {
    char letter;
    std::cout << "Choose a letter: ";
    std::cin >> letter;
    std::cout << std::endl;
    return letter;
}

void printHangedMan() {
    std::cout << "HANGEDMAN" << std::endl << std::endl;
}

void printWordState(std::string newWord) {
    for (unsigned int i = 0; i < newWord.size(); i++) {
        std::cout << newWord.at(i);
    }
    std::cout << std::endl << std::endl;
}

void printGuessedLetters(std::vector<char> lettersGuessed) {
    std::cout << "Letters guessed: ";
    for (unsigned int i = 0; i < lettersGuessed.size(); i++) {
        std::cout << lettersGuessed.at(i) << " ";
    }
    std::cout << std::endl << std::endl;
}


int main() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Hello, welcome to hangman in C++!" << std::endl;
    std::cout << "---------------------------------" << std::endl << std::endl;

    std::string currentWord = getRandomWord();
    unsigned int wrongCount = 0;

    // Create newWord
    std::string blankWord;
    for (unsigned int i = 0; i < currentWord.size(); i++) {
        blankWord.push_back('-');
    }

    std::vector<char> lettersGuessed;
    bool wordGuessed = false;
    while (!wordGuessed) {
        printHangedMan();
        printGuessedLetters(lettersGuessed);
        printWordState(blankWord);

        // Ask player to guess
        char letterGuess = getLetterGuess();
        lettersGuessed.push_back(letterGuess);

        // if letter is in word
        for (unsigned int i = 0; i < currentWord.size(); i++) {
            if (currentWord.at(i) == letterGuess) {
                // Change - to letterGuess in newWord
                blankWord.at(i) = letterGuess;
            }
        }

        // Check if word has been guessed
        if (blankWord.find('-') == std::string::npos) {
            std::cout << "YOU WIN!" << std::endl;
            wordGuessed = true;
        }

        // Check if out of guesses
        if (wrongCount >= 6) {
            std::cout << "Sorry, you loose..." << std::endl;
            break;
        }
    }
    return 0;
}