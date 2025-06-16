# CANTILEVER
📁 Repository for all daily tasks and assignments completed during my internship at Cantilever.

# Task 1:
# 🎯 Number Guessing Game in C++

This is a simple console-based number guessing game built using C++. It generates a random number between 0 and 99 and lets the user guess it. After every guess, it gives a hint (too high / too low) and records the total number of attempts taken.

## 📄 Features
- Random number generation
- Interactive hints (too low / too high)
- Keeps track of number of attempts
- Uses file handling to store results in `numberGuessingGame.txt`

## 🛠️ How It Works
- The program uses `rand()` seeded by the current time to generate a number
- The user is prompted to guess until they get the correct number
- Upon correct guess, result is stored in a file for future record

## 🧪 Sample Output
Welcome to the Number Guessing Game!  

I have selected a number between 0 to 99. Try to guess it!  
Enter your number:  
50  
Too low! Try again  
Enter your number:  
75  
Too high! Try again  
Enter your number:  
62  
🎉 Congratulations! You guessed the number in 3 attempts.  

