
#include <iostream>
#include <stdlib.h>
#include <ctime>

void higherLowerD20() {
    std::cout << "\n\nHello, welcome to Higher Lower, guess if the next roll\n";
    std::cout << "Press 'Q' to quit";
    int dice1, dice2, score;
    char guess;
    dice1 = rand() % 20 + 1;
    std::cout << "The current roll is: " << dice1<< "H or L\n";
    std::cin >> guess;
    score = 0;
    while (std::toupper(guess) != 'Q') {
        dice2 = rand() % 20 + 1;
        if (dice1 == dice2) {
            std::cout << "The roll was the same.\n";
        } else if (dice1 < dice2 && std::toupper(guess) == 'H') {
            std::cout << "Correct! the roll was: " << dice2 << "\n";
            score++;
        } else if (dice1 > dice2 && std::toupper(guess) == 'L') {
            std::cout << "Correct! the roll was: " << dice2 << "\n";
            score++;
        }else {
            std::cout << "Wrong, sorry the roll was: " << dice2 << "\n";
        }
        dice1 = dice2;
        std::cout << "The current roll is: " << dice1 << " H or L, your score is: " << score << "\n";
        std::cin >> guess;
    }
}

void guessD6AI() {
    std::cout << "\n\nHello, welcome to Fight the AI, be a better guesser than a bot\n";
    std::cout << "the rolls will be between 1 and 6\n";
    int guess, aiguess, dice1, score, aiscore;
    dice1 = rand() % 6 + 1;
    aiguess = rand() % 6 + 1;
    std::cout << "guess 10 to return to the main menu, whats your first guess: \n";
    std::cin >> guess;
    score = 0;
    aiscore = 0;
    while (guess != 10) {
        if (guess != dice1 && aiguess != dice1) {
            std::cout << "Both Wrong";
        } else if (guess == dice1 && aiguess == dice1) {
            std::cout << "Both Correct";
            score++, aiscore++;
        } else if (guess == dice1 && aiguess != dice1) {
            std::cout << "Player Won";
            score++;
        }else {
            std::cout << "Computer Won";
            aiscore++;
        }
        std::cout << ", the roll was:" << dice1 << " score:" << score << " AI score:" << aiscore << " guess again!\n";
        std::cin >> guess;
        dice1 = rand() % 6 + 1;
        aiguess = rand() % 6 + 1;
    }
}

void findTheValue() {
    std::cout << "\n\nHello, welcome to find the value between 1 and 50, get to the answer as fast as possible\n";
    int guess, guessCount, dice1;
    dice1 = rand() % 50 + 1;
    std::cout << "guess 100 to return to the main menu, whats your first guess: \n";
    std::cin >> guess;
    guessCount = 1;
    while (guess != 100) {
        if (guess == dice1) {
            std::cout << "Correct, wow that took:" << guessCount << " guesses, lets go again!\n";
            dice1 = rand() % 50 + 1;
        }
        else if (guess < dice1) {
            std::cout << "Too low, try again\n";
            guessCount++;
        }else {
            std::cout << "Too high, try again\n";
            guessCount++;
        }
        std::cin >> guess;
    }
}

int main(){
    int selection;
    std::srand(std::time(0));
    while (true) {
        std::cout << "Hello, welcome to the world of numbers!\n";
        std::cout << "Enter 1 for Higher or Lower, 2 for Guess vs AI, 3 for Find the value\n";
        std::cout << "type 0 To quit\n";
        std::cin >> selection;
        if (selection == 1) {
            higherLowerD20();
        } else if (selection == 2) {
            guessD6AI();
        } else if (selection == 3) {
            findTheValue();
        } else if (selection == 0) {
            break;
        } else {
            std::cout << "Sorry, I didn't understand that press 0 to quit";
        }
    }
    std::cout << "Goodbye";
}
