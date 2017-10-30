#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int guess(void);

int main(void) {
	int guessNumber;
	
	/* Seed the number generator */
	srand((unsigned) time(NULL));
	
	/* As this program demonstrates loops, each of the three loops will 
	run once as opposed to having one loop that runs three times */
	
	/* The user starts with three guesses */
	for(guessNumber = 3; guessNumber > 2; --guessNumber)
		guess();
	
	do {
		guess();
		--guessNumber;
	} while(guessNumber > 1);
	
	while(guessNumber) {
		guess();
		--guessNumber;
	}
	
	return 0;
}

int guess(void) {
	int randomNumber, userNumber;
	
	/* Generate the random number */
	randomNumber = rand() % 10;
	
	/* Prompt the user for input to be used as their guess, then
	collect this input */
	cout << "Enter your guess:" << endl;
	cin >> userNumber;
	
	/* Output the random number and the user number */
	cout << "The random number was " << randomNumber 
		<< ", and your guess was " << userNumber << "." << endl;
	
	/* If the user has guessed the random number, end the program */
	if(userNumber == randomNumber) {
		cout << "You have guessed the random number!" << endl;
		exit(0);
	}
	/* If the user has not guessed the random number, continue */
	else
		cout << "You have not guessed the random number!" << endl;
		
	return 0;
}
