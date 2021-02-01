/*
!Important - Unreal Engine uses an UpperCase CamelCode method for declaring vars etc..
*/

#include  <iostream> //preprocessor directive
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	//Expression Statements / Welcome message
	std:: cout << std :: endl; //new line
	std:: cout << "Level " << Difficulty << "! \n";
	std:: cout << "You must enter the code before you can continue..\n \n"; //easier way for new line
}

bool PlayGame(int Difficulty)
{

	PrintIntroduction(Difficulty); // calls print function

	// Declaration of 3 numbers in code
	const int CodeA = rand() % Difficulty + Difficulty + 1;
	const int CodeB = rand() % Difficulty + Difficulty + 1;
	const int Codec = rand() % Difficulty + Difficulty + 1; 

	const int CodeSum = CodeA + CodeB + Codec;
	const int CodeProduct = CodeA * CodeB * Codec;

	//Print CodeSum and CodeProduct to terminal
	std:: cout << "- There are 3 numbers in the code";
	std:: cout << "\n- The codes add up to: " << CodeSum;
	std:: cout << "\n- The codes multiply to give: " << CodeProduct << std :: endl;
	std:: cout << std :: endl; //new line

	//Store Player's guess
	int GuessA, GuessB, GuessC;
	std:: cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	// check if guess is correct
	if(GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std:: cout << "\n*** Correct :) ***"<< std::endl;
		std:: cout << "*** Keep Going! ***" << std::endl;
		std:: cout << std :: endl;
		return true;
	} 
	else 
	{
		std:: cout << "\n*** Fail :( ***" << std::endl;
		std:: cout << "*** Do try again. *** " << std::endl;
		return false;
	}
}

int main() //main function
{
	srand(time(NULL)); // create new random sequence based on time of day
	int Level = 1; // starting level
	const int MaxLevel = 10; // max levels
	while (Level <= MaxLevel)
	{
		bool LevelComp = PlayGame(Level);
		std::cin.clear(); // clears any errors
		std::cin.ignore(); // discards the buffer

		if (LevelComp)
		{
			++Level; //increment level
		}
		
	}

	// Completion Pstatement
	std:: cout << "***Congratulations on completing the game!!***" << std::endl;
	std:: cout << "***            Ctrl + C to exit            ***" << std::endl;
	return 0;
} 
