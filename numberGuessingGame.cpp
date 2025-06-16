# include <iostream>
# include <cstdlib> // For using rand() and srand()
# include <ctime> // For using time()
# include <fstream> // For File I/O
using namespace std;

int main(){
    // The random number genarator
    srand(time(0));

    // Generate random numbers numberss between 0 to 99
    int generateNumber = rand() % 100;
    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have selected a number between 0 to 99. Try to guess it!" << endl;

    while(true){
        cout << "Enter your number: " << endl;
        cin >> userGuess;
        if(userGuess < generateNumber){
            cout << "Too low! Try again" << endl;
            attempts++;
        } else if(userGuess > generateNumber){
            cout << "Too high! Try again" << endl;
            attempts++;
        } else{
            cout << "🥳 Congratulations! You guessed the number in " << attempts << " attempts." << endl;
            break;
        }
    }
    ofstream txt_file("numberGuessingGame.txt", ios::app);
    txt_file << "You guessed " << generateNumber << " in " << attempts << " attempts.";
    return 0;
}