#include "stdafx.h"
#include "FBullCowGame.h"

using FText = std::string; // FText for immutable / unchangeable responses
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } //constructor

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetCurrentTry() const {	return MyCurrentTry; }



void FBullCowGame::Reset() 
{ 
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";




	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return; 
}
//receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;



	// loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++);
{
		// compare letters against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++)
		{

		}
			// if they match then
				// increment bulls if they're in the same place
			// otherwise
				// increment cows

}






	return BullCowCount;
}

bool FBullCowGame::IsGameWon() const { return false; }

bool FBullCowGame::IsGuessValid(std::string){ return false; }
