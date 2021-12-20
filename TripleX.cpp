#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
    //prints out certain messages to the terminal.
    std::cout << "\n\nYou are a Death Row inmate breaking out of the prison...\nYour currently on level " << Difficulty << "\nYou need to enter the correct codes to breakout..." << std::endl;
}

bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);
    //declares vars.
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //prints out the CodeSum and CodeProduct of vars to the terminal.
    std::cout << "\nThere are 3 numbers in the code\nThe codes add-up to : " << CodeSum << "\nThe codes multiply to give : " << CodeProduct <<std::endl;

    //Store player guess.
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the player guesses are correct.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\nYou progress to the next level." << std::endl;
        return true;
    } else {
        std::cout << "\nInvalid code, the alarm goes off...\nYour breakout attempt failed, that's going to be a week in a isolation cell." << std::endl;
        return false;
    }
}

int main() {
    srand(time(NULL)); //Create new random sequence based on time of day.
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors.
        std::cin.ignore(); //Discards the buffer.

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }
    std::cout << "You broke out, freedom!!!" << std::endl;
    return 0;
}