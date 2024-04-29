#include <iostream> // Include header for input/output operations
#include <cstdlib>  // Include header for random number generation
#include <ctime>    // Include header for time-related functions

// (Optional headers not currently used are commented out)
// #include <cmath>
// #include <limits>

bool isPrime(int n) { // Function to check if a number is prime
  if (n <= 1) {         // Base case: Numbers 1 or less are not prime
    return false;
  }
  for (int i = 2; i <= sqrt(n); ++i) { // Loop from 2 to square root of n
    if (n % i == 0) {                   // If a divisor is found, return false
      return false;
    }
  }
  return true;                         // If no divisor found, return true (prime)
}

int main() {
  srand(time(0)); // Seed the random number generator with current time

  char playAgain = 'y'; // Variable to store user's choice (play again)

  std::cout << "||  Welcome to Number Detective Game  ||: \n";
  std::cout << "  \n\n";
  std::cout << "||  Guess the Mystery Number!   ||\n\n";

  while (playAgain == 'y' || playAgain == 'Y') { // Loop for playing again
    int secretNumber = 1 + rand() % 50; // Generate random number (1-50)
    int guess;
    int attempts = 0;
    const int maxAttempts = 5; // Allow 5 attempts

    std::cout << "I have selected a random number between 1 and 50. Can you guess it?\n";

    while (attempts < maxAttempts) {
      std::cout << "Enter your guess (between 1 and 50): ";
      if (!(std::cin >> guess) || guess < 1 || guess > 50) {
        std::cout << "Invalid input! Please enter a number between 1 and 50.\n";
        std::cin.clear();                 // Clear error flag for input stream
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        continue;
      }

      attempts++;

      if (guess == secretNumber) {
        std::cout << "Congratulations! You guessed the number " << secretNumber << " correctly in " << attempts << " attempts.\n";
        break;
      } else if (guess < secretNumber) {
        std::cout << "Too low! ";
      } else {
        std::cout << "Too high! ";
      }

      // Provide hints about the secret number
      if (secretNumber % 2 == 0)
        std::cout << "Hint: The number is even. ";
      else
        std::cout << "Hint: The number is odd. ";

      if (secretNumber % 3 == 0)
        std::cout << "It is divisible by 3. ";
      else if (secretNumber % 5 == 0)
        std::cout << "It is divisible by 5. ";
      else
        std::cout << "It is not divisible by 3 or 5. ";

      if (isPrime(secretNumber))
        std::cout << "It is a prime number. ";

      std::cout << "Try again.\n";
    }

    if (attempts == maxAttempts) {
      std::cout << "Sorry, you've run out of attempts. The correct number was: " << secretNumber << std::endl;
    }

    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> playAgain;
  }

  std::cout << "\nThanks for playing Number Detective! Goodbye.\n";

  return 0;
}
