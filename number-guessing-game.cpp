#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>
#include <string>

int main()
{
    // Random number generation
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int trials = 0;
    string user;

    cout << "\n*****Number Guessing Game!*****\n";

    cout << "\nPlease enter your name: ";
    getline(cin, user);

    cout << "\nWelcome " << user << " to the Number Guessing Game!\n";
    cout << "\nTry to guess the number between 1 and 100.\n\n";

    do
    {
        cout << "\nEnter your guess: ";
        cin >> guess;

        trials++;

        // Check if the guess is correct or not.
        if (guess == secretNumber)
        {
            cout << "\nCongratulations! " << user << ", You guessed the correct number in " << trials << " attempts.\n\n";
        }
        else if (guess < secretNumber)
        {
            cout << "\nToo low! Try again.\n";
        }
        else
        {
            cout << "\nToo high! Try again.\n";
        }

    } while (guess != secretNumber);

    return 0;
}
