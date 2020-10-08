// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The Hidden Word is: %s. "), *HiddenWord); // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else //Checking PlayerGuess
    {
        if (Input==HiddenWord)
        {
            PrintLine(TEXT("You guessed correctly!"));
            EndGame();
        }
        else
        {
            PrintLine(TEXT("Lost a life!"));
            PrintLine(TEXT("%i"), --Lives);

            if (Lives > 0)
            {
                if (Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining."), Lives);
                }
                
            }
            else
            {
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }
        }
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

void UBullCowCartridge::SetupGame()
{
    // Welcome the Player
    PrintLine(TEXT("Welcome to Bull Cow!"));

    HiddenWord = TEXT("rambo");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and \nPress enter to continue...")); // Prompt player for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again."));
}