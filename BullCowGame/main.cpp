/* This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user interaction. For game logic, see the FBullCowGame class.
*/


#include "stdafx.h"
#include "FBullCowGame.h"
#include <iostream>
#include <string>

using int32 = int; // leave out main as it is called by the OS, not Unreal
using FText = std::string; // FText for immutable / unchangeable responses

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //create a new game instance


// entry point for the application

int main()
{
	std::cout << BCGame.GetCurrentTry();

	bool bPlayAgain = false;
	do {

		PrintIntro();
		PlayGame();
		
		bPlayAgain = AskToPlayAgain();

	} 

	while (bPlayAgain);
	
	return 0; //exit the application
	
}



void PrintIntro() 
{

	// introduce the game
	constexpr int32 WORD_LENGTH = 9;
	// TODO add ASCII art for intro
	std::cout << "Welcome to Bulls & Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?\n";
	std::cout << std::endl;

	return;

}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	std::cout << "Maximum Tries: " << MaxTries << std::endl;

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries

	for (int32 count = 1; count <= MaxTries; count++) {
		FText Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);


		// print number of bulls and cows

		std::cout << "Bulls =" << BullCowCount.Bulls;
		std::cout << ". Cows =" << BullCowCount.Cows << std::endl;
	

	// TODO provide game summary of number of bulls and cows

	}
}

FText GetGuess() 
{
	// get the current number of tries
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << "." << std::endl;

	// get a guess from the player
	std::cout << "Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
	
	// TODO check that the guess is a valid entry

	// TODO if not valid, then print reason as to why


}

bool AskToPlayAgain()
{
	// ask the player if they want to play again
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
		
}

