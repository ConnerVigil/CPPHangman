#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>


char getLetterGuess() {
    char letter;
    std::cout << "Choose a letter: ";
    std::cin >> letter;
    std::cout << std::endl;
    return letter;
}

void printHangedMan() {

}

void printWordState() {

}

void printGuessedLetters() {

}


int main() {
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Hello, welcome to hangman in C++!" << std::endl;
    std::cout << "---------------------------------" << std::endl << std::endl;

    // Get list of words
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

    // Pick a random word
    srand(time(0));
    unsigned int max = listOfWords.size() - 1;
    unsigned int wordNum = rand() % max;
    std::string currentWord = listOfWords.at(wordNum);

    std::vector<char> lettersGuessed;
    bool wordGuessed = false;
    while (!wordGuessed) {

        // Print hanged man
        // Print word state
        // Print guessed letters

        // Ask player to guess
        char letterGuess = getLetterGuess();
        lettersGuessed.push_back(letterGuess);

        // if letter in word
        if (currentWord.find(letterGuess) != std::string::npos) {

        }

    }
    return 0;
}