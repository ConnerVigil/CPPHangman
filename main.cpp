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

char getLetterGuess(std::vector<char> lettersGuessed) {
    char letter;
    bool temp = false;
    do {
        std::cout << "Choose a letter: ";
        std::cin >> letter;
        std::cout << std::endl;

        if (std::find(lettersGuessed.begin(), lettersGuessed.end(), letter) != lettersGuessed.end()) {
            /* v contains x */
            std::cout << "You have already guessed that letter, guess again." << std::endl;
            temp = true;
        } else {
            temp = false;
        }
    } while (temp);

    return letter;
}

void printHangedMan(int wrongCount) {
    std::cout << " -------"  << std::endl;
    std::cout << " |      "  << std::endl;

    if (wrongCount >= 1) {
        std::cout << " O      "  << std::endl;
    }
    if (wrongCount >= 2) {
        std::cout << "\\ ";
        if (wrongCount >= 3) {
            std::cout << "/"  << std::endl;
        } else {
            std::cout << std::endl;
        }
    }
    if (wrongCount >= 4) {
        std::cout << " |"  << std::endl;
    }
    if (wrongCount >= 5) {
        std::cout << "/ ";
        if (wrongCount >= 6) {
            std::cout << "\\"  << std::endl;
        } else {
            std::cout << std::endl;
        }
    }
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
    std::cout << std::endl;
}


int main() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Hello, welcome to hangman in C++!" << std::endl;
    std::cout << "---------------------------------" << std::endl << std::endl;

    std::string currentWord = getRandomWord();
    unsigned int wrongCount = 0;

    // Create blankWord to guess on
    std::string blankWord;
    for (unsigned int i = 0; i < currentWord.size(); i++) {
        blankWord.push_back('-');
    }

    std::vector<char> lettersGuessed;
    bool wordGuessed = false;
    while (!wordGuessed) {
        printHangedMan(wrongCount);
        printGuessedLetters(lettersGuessed);
        printWordState(blankWord);

        // Ask player to guess
        char letterGuess = getLetterGuess(lettersGuessed);
        lettersGuessed.push_back(letterGuess);

        if (currentWord.find(letterGuess) != std::string::npos) { // if letter is in word
            for (unsigned int i = 0; i < currentWord.size(); i++) {
                if (currentWord.at(i) == letterGuess) {
                    // Change - to letterGuess in newWord
                    blankWord.at(i) = letterGuess;
                }
            }
        } else { // letter is not in word
            wrongCount++;
        }

        // Check if word has been guessed
        if (blankWord.find('-') == std::string::npos) {
            std::cout << "YOU WIN!" << std::endl;
            std::cout << "The word was " << currentWord << std::endl;
            wordGuessed = true;
        }

        // Check if out of guesses
        if (wrongCount >= 6) {
            printHangedMan(wrongCount);
            std::cout << "Sorry, you loose..." << std::endl;
            std::cout << "The word was " << currentWord << std::endl;
            break;
        }
    }
    return 0;
}