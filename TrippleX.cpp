#include <iostream>
#include <ctime>
void PrintIntroduction(int Difficulty);


bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    
    const int CodeA = rand() % (Difficulty + Difficulty);
    const int CodeB = rand() % (Difficulty + Difficulty);
    const int CodeC = rand() % (Difficulty + Difficulty);
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << "+ There are three numbers in the code";
    std::cout << "\n+ The numbers in the code add up to: " << CodeSum;
    std::cout << "\n+ The product of the numbers in the code is: " << CodeProduct;
       
    std::cout << "\nPlease enter your guess\n";
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
         
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Well done! You have extracted the file! Keep going!\n";
        return true;
    } 
    else
    {
        std::cout << "\n*** You entered the wrong code! Careful agent! Try again! ***\n";
        return false;
    }
}

void PrintIntroduction(int Difficulty)
{
    std::cout << "\nYou are a secret agent breaking into a level " 
              << Difficulty << " secure server room...\n"
              << "You need to enter the correct codes to continue...\n\n";        
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 2;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
    }
    std::cout << "\n*** Congratulations! you have won the game! ***\n";
    return 0;
}