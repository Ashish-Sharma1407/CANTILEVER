/*
 * Two-Digit Number Guessing Game (Traditional C++ Version)
 * Author: Ashish Sharma
 * Company: Cantilever Internship Project
 * Deadline: August 15th, 2025
 * Description: A console-based guessing game where player guesses a random two-digit number (01-99)
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <iomanip>

using namespace std;

class TwoDigitGuessingGame {
private:
    int secretNumber;
    int attempts;
    int maxAttempts;
    int score;
    bool gameWon;

public:
    // Constructor
    TwoDigitGuessingGame() {
        srand(time(0)); // Seed random number generator
        resetGame();
    }

    // Reset game for new round
    void resetGame() {
        secretNumber = rand() % 99 + 1; // Generate random number between 1-99 (displayed as 01-99)
        attempts = 0;
        maxAttempts = 7; // Player gets 7 attempts
        score = 1000; // Starting score
        gameWon = false;
    }

    // Display welcome message and game rules
    void displayWelcome() {
        cout << "\n" << string(50, '=') << endl;
        cout << "\t TWO-DIGIT NUMBER GUESSING GAME" << endl;
        cout << string(50, '=') << endl;
        cout << "\nWelcome to the ultimate guessing challenge!" << endl;
        cout << "\nGame Rules:" << endl;
        cout << "1. I have selected a random two-digit number (01-99)" << endl;
        cout << "2. You have " << maxAttempts << " attempts to guess it" << endl;
        cout << "3. After each guess, I'll tell you if you need to go higher or lower" << endl;
        cout << "4. Your score decreases with each wrong guess" << endl;
        cout << "5. Try to guess with minimum attempts for maximum score!" << endl;
        cout << "\nNote: Single digit numbers are displayed with leading zero (01, 02, 03, etc.)" << endl;
        cout << "\nLet's begin! Good luck!" << endl;
        cout << string(50, '-') << endl;
    }

    // Display number with leading zero formatting
    void displayNumber(int number) {
        cout << setfill('0') << setw(2) << number;
    }

    // Get valid input from user with error handling
    int getValidInput() {
        int guess;

        while (true) {
            cout << "\nEnter your guess (01-99): ";

            if (cin >> guess) {
                // Check if number is in valid range
                if (guess >= 1 && guess <= 99) {
                    return guess;
                } else {
                    cout << "❌ Invalid input! Please enter a number between 01 and 99." << endl;
                }
            } else {
                cout << "❌ Invalid input! Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    // Process user's guess and provide feedback
    bool processGuess(int guess) {
        attempts++;
        score -= 100; // Deduct points for each attempt

        cout << "\nAttempt " << attempts << "/" << maxAttempts << ": You guessed ";
        displayNumber(guess);
        cout << endl;

        if (guess == secretNumber) {
            gameWon = true;
            cout << "\n🎉 CONGRATULATIONS! You guessed it correctly!" << endl;
            cout << "The secret number was: ";
            displayNumber(secretNumber);
            cout << endl;
            cout << "Your final score: " << max(score, 0) << " points" << endl;
            return true;
        } else {
            if (guess < secretNumber) {
                cout << "📈 Too low! Try a higher number." << endl;
            } else {
                cout << "📉 Too high! Try a lower number." << endl;
            }

            // Provide proximity hints
            int difference = abs(guess - secretNumber);
            if (difference <= 2) {
                cout << "🔥 Very close!" << endl;
            } else if (difference <= 5) {
                cout << "🌡️  Warm!" << endl;
            } else if (difference <= 10) {
                cout << "❄️  Getting colder..." << endl;
            } else {
                cout << "🧊 Very cold!" << endl;
            }

            cout << "Remaining attempts: " << (maxAttempts - attempts) << endl;
            cout << "Current score: " << max(score, 0) << " points" << endl;
            return false;
        }
    }

    // Handle game over scenario
    void gameOver() {
        if (!gameWon) {
            cout << "\n💔 Game Over! You've used all " << maxAttempts << " attempts." << endl;
            cout << "The secret number was: ";
            displayNumber(secretNumber);
            cout << endl;
            cout << "Better luck next time!" << endl;
        }
    }

    // Display game statistics
    void displayStats() {
        cout << "\n" << string(30, '-') << endl;
        cout << "GAME STATISTICS:" << endl;
        cout << "Secret Number: ";
        displayNumber(secretNumber);
        cout << endl;
        cout << "Attempts Used: " << attempts << "/" << maxAttempts << endl;
        cout << "Final Score: " << max(score, 0) << " points" << endl;
        cout << "Result: " << (gameWon ? "WIN! 🏆" : "LOSS 😔") << endl;
        cout << string(30, '-') << endl;
    }

    // Ask if player wants to play again
    bool playAgain() {
        char choice;
        cout << "\nWould you like to play again? (y/n): ";
        cin >> choice;
        return (choice == 'y' || choice == 'Y');
    }

    // Main game loop
    void playGame() {
        do {
            displayWelcome();
            resetGame();

            while (attempts < maxAttempts && !gameWon) {
                int guess = getValidInput();
                if (processGuess(guess)) {
                    break; // Player won
                }
            }

            if (!gameWon) {
                gameOver();
            }

            displayStats();

        } while (playAgain());

        cout << "\nThank you for playing! 👋" << endl;
    }
};

int main() {
    TwoDigitGuessingGame game;
    game.playGame();
    return 0;
}
