// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();
    // Don't need to use FString::Printf because it is defined in Cartridge.h, but will need to use 
    // in other projects
    PrintLine(FString::Printf(TEXT("The HiddenWord is: %s."), *HiddenWord)); // Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else // Checking Playerguess
    {
        PrintLine(Input);
        if (Input == HiddenWord)
        {
            PrintLine(TEXT("Congratulations, you won!"));
            EndGame();
        }
        else
        {
            if (Input.Len() != HiddenWord.Len())
            {
                PrintLine(TEXT("The Hidden Word is %i characters long, you lost!"), HiddenWord.Len());
                EndGame();
            }
        }
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();// Set lives
    bGameOver = false;
    // We need this macro TEXT() before any screen so UE can encode it correctly
    PrintLine(TEXT("Welcome to Bull Cows game!"));
    PrintLine(TEXT("Guess the %i letters word!"), HiddenWord.Len());
    PrintLine(TEXT("Type in your guess.\nPress enter to continue..."));
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press Enter to play again."));
}