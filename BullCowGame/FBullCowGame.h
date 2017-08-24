#pragma once
#include <string>

using FString = std::string; // FString for mutable / changeable responses
using int32 = int; 

//all values initialised to 0
struct FBullCowCount // remember that structs are like classes, but all members are public by default
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:
	
	FBullCowGame(); // constructor


	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO Make a more rich return value
	bool IsGuessValid(FString); // TODO Make a more rich return value
	FBullCowCount SubmitGuess(FString);


	


// ^^ Please try and ignore this and focus on the interface above ^^
private:

	//see Reset() in FBullCowGame.cpp for initialisation

	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	
};