// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Welcome the Player
    PrintLine(TEXT("Welcome Player!"));
    PrintLine(TEXT("Guess the four letter word!")); // Magic number Remove
    PrintLine(TEXT("Type something and then press enter!"));

    // Setting up game
    HiddenWord = TEXT("rambo"); // Set the HiddenWord 
    // Set Lives

    // Prompt player for guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Check PlayerGuess

    if (Input==HiddenWord)
    {
        PrintLine(TEXT("You guessed correctly!"));
    }
    else
    {
        PrintLine(TEXT("You guessed wrong!"));
    }

    // Check if isogram
    // Prompt to guess again
    // Check right number of characters
    // Prompt to guess again

    // Remove life

    // Check if lives > 0
    // If yes, GuessAgain
    // Show lives left
    // If no Show GameOver and HiddenWord
    // Prompt to Play Again, Press enter to play again
    // Check user input
    // PLay again or quit


    
}