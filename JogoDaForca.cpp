#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <new>
#include <iostream>
#include <time.h>
#include <locale.h>

using namespace std;

void clearScreen() {
    system("CLS");
}

string getRandomWord() {
    string words[3] = {"abacaxi", "manga", "morango"};
    int randomIndex = rand() % 3;
    return words[randomIndex];
}

string getTheWordMasked(int wordSize) {
    string maskedWord;

    for (int i = 0; i < wordSize; i++) {
        maskedWord += "_";
    }

    return maskedWord;
}

void showStatus(string maskedWord, int wordSize, int remaningAttempts, string lettersTried) {
    cout << "Word: " << maskedWord << "\n";
    cout << "Word size: " << wordSize << "\n";
    cout << "Remaning attempts: " << remaningAttempts << "\n";

    cout << "Letters tried: ";
    for (int i = 0; i < lettersTried.size(); i++) {
        if (i != lettersTried.size() - 1) {
            cout << lettersTried[i] << ", ";
        } else {
            cout << lettersTried[i];
        }
    }
}

void play(int quantityOfPlayers) {
    string word;

    if (quantityOfPlayers == 1) {
        word = getRandomWord();
    } else {
        cout << "Write a word: ";
        cin >> word;
    }

    int wordSize = word.size();

    string maskedWord = getTheWordMasked(wordSize);
    cout << maskedWord;

    int attempts, maximumAttempts = 10;
    char letter;
    string lettersTried;
    string wordTried;
    bool alreadyWrot = false, rightLetter = false;

    while (word != maskedWord && maximumAttempts - attempts > 0) {
        clearScreen();

        showStatus(maskedWord, wordSize, maximumAttempts - attempts, lettersTried);

        cout << "\nType a letter or press the number 1 to try the full word: ";
        cin >> letter;

        if (letter == '1') {
            cout << "\n" << "Type the full word: ";
            cin >> wordTried;
            if (wordTried == word) {
                maskedWord = wordTried;
            } else {
                attempts = maximumAttempts;
            }
        } else {
            for (int i = 0; i < attempts; i++) {
                if (lettersTried[i] == letter) {
                    cout << "This letter has already been typed";
                    alreadyWrot = true;
                }
            }

            if (!alreadyWrot) {
                lettersTried += tolower(letter);

                for (int i = 0; i < wordSize; i++) {
                    if (word[i] == tolower(letter)) {
                        maskedWord[i] = word[i];
                        rightLetter = true;
                    }
                }

                if (rightLetter) {
                    cout << "You typed the right letter";
                } else {
                    cout << "You typed the wrong letter";
                }

                attempts++;
            }

            alreadyWrot = false;
            rightLetter = false;

        }
    }

    clearScreen();

    if (maskedWord == word) {
        cout << "Yeah bro! You got it! Congratulations \n";
        system("pause");
    } else {
        cout << "My gosh! You´re so bad... \n";
        system("pause");
    }
}

void menu() {
    int option = 0;

    do {
        clearScreen();

        cout << "Welcome to the game!" << "\n";

        cout << "1 - 1 Player" << "\n";
        cout << "2 - 2 Players" << "\n";
        cout << "3 - About" << "\n";
        cout << "4 - Close" << "\n";

        cout << "Choose a option and press ENTER: ";
        cin >> option;

        clearScreen();

        switch (option) {
            case 1:
                play(1);
                break;
            case 2:
                play(2);
                break;
            case 3:
                cout << "Game developed by Luiz Henrique Martendal in 2023 \n";
                system("pause");
                break;
            case 4:
                return;
            default:
                cout << "Invalid option! Try again\n";
                system("pause");
        }
    } while (option != 4);
}

int main() {

    setlocale(LC_ALL, "");
    srand((unsigned)time(NULL));

    menu();

    return 0;

}
