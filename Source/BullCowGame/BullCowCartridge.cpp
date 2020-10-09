// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(TEXT("The number if possible words is: %i."), Words.Num());
    PrintLine(TEXT("The Hidden Word is: %s. "), *HiddenWord); // Debug Line

    for (int32 Index = 0; Index != 10; Index++)
    {
        if (Words[Index].Len() >=4 && Words[Index].Len() <=8)
        {
           PrintLine(TEXT("%s"), *Words[Index]);
        }
    }

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
        ProcessGuess(Input);
        
    }
}

void UBullCowCartridge::SetupGame()
{
    PrintLine(TEXT("Welcome to Bull Cow!"));

    HiddenWord = TEXT("cakes");
    Lives = HiddenWord.Len();
    bGameOver = false;

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type in your guess and \nPress enter to continue...")); // Prompt player for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("\nPress enter to play again."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{
    if (Guess == HiddenWord)
        {
            PrintLine(TEXT("You guessed correctly!"));
            EndGame();
            return;
        }
    
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The hidden word is %i letters long."), HiddenWord.Len());
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining."), Lives);
        return;
    }

    //Check if isogram
    if (!IsIsogram(Guess))
    {
        /* code */
        PrintLine(TEXT("No repeating letters, guess again!"));
        return;
    }

    // Remove life
    PrintLine(TEXT("Lost a life!"));
    --Lives;

    if (Lives <= 0)
    {
        ClearScreen();
        PrintLine(TEXT("You have no lives left!"));
        PrintLine(TEXT("The hidden word was: %s."), *HiddenWord);
        EndGame();
        return;
    }

    // Shoiw the player the bulls and the cows
    PrintLine(TEXT("Guess again, you have %i live left."), Lives);
}

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        for (int32 Comparison = Index; Comparison < Word.Len(); Comparison++)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
            
        }

    }

    return true;
}