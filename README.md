# C-project
Headers:  

<iostream>: This header file is essential for input/output operations in C++. It provides functions like cout (for console output) and cin (for user input).  
<cstdlib>: This header offers general-purpose utilities, including rand for generating random numbers.    
<ctime>: When used with rand, this header allows seeding the random number generator with the current time, ensuring different secret numbers in each game.  
<cmath>: Although not explicitly used in this code, it provides mathematical functions that might be useful in future enhancements (e.g., calculating square root for a more efficient primality check).  
<limits>: Similarly, this header might not be directly used here, but it can be helpful in determining data type limits for robust input validation.  
isPrime Function:  
  
  This function determines whether a given integer (n) is a prime number.  
  Prime numbers: Natural numbers greater than 1 that have exactly two distinct positive divisors: 1 and itself.  
Logic:  
The function returns false if n is less than or equal to 1, as these numbers are not considered prime by definition.  
It iterates through potential divisors, starting from 2 and going up to the square root of n (since any divisor greater than the square root would have a corresponding divisor less than the square root).  
If a divisor (i) is found by checking if the remainder of n divided by i is 0 (n % i == 0), it means n is not prime, and the function returns false.  
If the loop completes without finding a divisor, it implies n has only two divisors (1 and itself), making it a prime number, and the function returns true.  
main Function:  
  
This is the starting point of the program's execution.  
Seeding the Random Number Generator:  
srand(time(0)): This line ensures that the random numbers generated for the secret number are different in each game run. The time(0) function retrieves the current system time, which is used as a seed for the rand function.  
Game Loop:  
A while loop allows the user to play multiple rounds as long as they choose to (playAgain is 'y' or 'Y').  
Inside the Loop:  
Secret Number Generation:  
secretNumber = 1 + rand() % 50;: This line generates a random number between 1 and 50 (inclusive) using rand. The 1 is added to offset the result from rand (which starts from 0), and the modulo (%) operation ensures the range stays within 50.  
Guessing Variables:  
guess: An integer variable to store the user's guess for the secret number.  
attempts: An integer variable to keep track of the number of guesses made by the user.  
maxAttempts: A constant integer variable set to 5, defining the maximum number of guesses allowed in a single round.  
Prompting the User:    
The game displays a message inviting the user to guess the secret number.  
Guessing Loop:  
Another while loop allows the user to keep guessing until they run out of attempts (attempts reaches maxAttempts) or guess correctly.  
Inside the Loop:  
User Input Validation:  
std::cin >> guess: This line attempts to read an integer from the user's input and store it in the guess variable.  
The conditional statement (if (!(std::cin >> guess) || guess < 1 || guess > 50)) checks for invalid input:  
!(std::cin >> guess): Verifies if the input was successfully read as an integer.  
guess < 1 || guess > 50: Checks if the guessed number is within the valid range (1 to 50).
If the input is invalid, an error message is displayed, and the following lines handle error correction:
std::cin.clear(): Clears the error state of the input stream (cin).
std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'): Discards any remaining invalid characters in the input buffer up to the next newline character. This ensures that the next cin attempt reads clean input.
