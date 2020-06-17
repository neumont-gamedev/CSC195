// NumberGuess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    srand((unsigned int)time(0));

    cout << "What's the maximum number? ";
    int maxNum;
    cin >> maxNum;

    char playAgain;
    do
    {
        int answer = (rand() % maxNum) + 1; // get random answer
        cout << "Answer: " << answer << endl;

        int numOfLives = 5;
        int guess;
        do {
            cout << "You have " << numOfLives << " lives\n";
            cout << "Guess the number: ";
            while (!(cin >> guess) || (guess < 1 || guess > maxNum)) 
            {
                cin.clear();
                cin.ignore(80, '\n');
                cout << "Invald input\n";
                cout << "Guess the number: ";
            }

            cout << "You Guessed: " << guess << endl;
            if (guess > answer) 
            {
                std::cout << "TOO HIGH!\n";
                numOfLives--;
            }
            else if (guess < answer) 
            {
                std::cout << "TOO LOW!\n";
                numOfLives--;
            }

        } while (guess != answer && numOfLives > 0); // repeat the loop if the guess != answer or the number of lives is > 0

        if (guess == answer) 
        {
            std::cout << "Correct! You win!!\n";
        }
        else 
        {
            std::cout << "You Lose!\n";
        }
        std::cout << "Do you wish to play again?\n";
        while (!(cin >> playAgain) || !(playAgain == 'y' || playAgain == 'n')) 
        {
            cin.clear();
            cin.ignore(80, '\n');
            cout << "Invald input\n";
            cout << "Guess the number: ";
        }

    } while (playAgain == 'Y' || playAgain == 'y');

}
