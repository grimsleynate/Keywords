// Keywords.cpp 
// Nathaniel Grimsley
// 10/21/2018

//we include the necessary dependencies to run this program.
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//this is our main function, where execution begins and ends.
int main()
{
	//we start by creating a variable to keep the game loop going.
	char playAgain = 'y';
	//we create an enumerator to store the fields in the game
	//the last enumeration stores the number of fields.
	enum fields {WORD, HINT, NUM_FIELDS};
	//we create a constant integer to store how large we want our array.
	const int NUM_WORDS = 10;
	//we create and fill out an array to store our words and hints.
	//the first dimension is equal to the number of words we have
	//and the second array is equal to the number of fields we have (word and hint, 2)
	const string WORDS[NUM_WORDS][NUM_FIELDS] =
	{
		{"elucidate", "Can I make this any CLEARER?"},
		{"malaise", "This is pretty SICK, huh?"},
		{"obfuscate", "Am I just CONFUSING you?"},
		{"perfunctory", "I wouldn't be so CARELESS, this is difficult!"},
		{"scintillating", "Oh my am I CLEVER."},
		{"vitriol", "Are you feeling a little BITTER yet?"},
		{"sycophant", "You aren't going to FLATTER the answers out of me."},
		{"pusillanimous", "My Mom told me not to be AFRAID of big words."},
		{"bloviate", "I'm not BOASTING, but I didn't make this easy."},
		{"pervicacious", "Wow, aren't you quite STUBBORN!"}
	};

	//we want to start the game loop now so all of our random numbers are different every time.
	while (playAgain == 'y')
	{
		//we seed the random number generator before we use the rand() function.
		srand(static_cast<unsigned int>(time(0)));

		//we are going to grab three random words from the array
		int choice1 = (rand() % NUM_WORDS);
		int choice2 = (rand() % NUM_WORDS);
		int choice3 = (rand() % NUM_WORDS);

		//we want to create a variable to store the number of correct answers.
		int numRight = 0;

		//we protect ourselves from having duplicate words
		while (choice1 == choice2 || choice1 == choice3 || choice2 == choice3)
		{
			choice1 = (rand() % NUM_WORDS);
			choice2 = (rand() % NUM_WORDS);
			choice3 = (rand() % NUM_WORDS);
		}

		//we store the words and hints we randomly picked for the game.
		//we do this by accessing the array of WORDS we created.
		//We then make the index of the first array equal to the index of the word we just picked.
		//The second array is equal to what field you want (the WORD field)
		string theWord1 = WORDS[choice1][WORD];
		//we do the same for the HINT field
		string theHint1 = WORDS[choice1][HINT];
		string theWord2 = WORDS[choice2][WORD];
		string theHint2 = WORDS[choice2][HINT];
		string theWord3 = WORDS[choice3][WORD];
		string theHint3 = WORDS[choice3][HINT];

		//we jumble the words that we chose
		//to start, we create a new string to store the jumbled version of the word.
		string jumble1 = theWord1;
		//we store the length of the string for later use.
		int length1 = jumble1.size();
		//now we create a for loop to iterate through every letter of the word.
		for (int i = 0; i < length1; ++i)
		{
			//we pick a random letter in the string
			int index1 = (rand() % length1);
			//we pick another random letter.
			int index2 = (rand() % length1);
			//we store the letter from the first random index we chose.
			char temp = jumble1[index1];
			//now we switch the characters in the string.
			jumble1[index1] = jumble1[index2];
			jumble1[index2] = temp;
		}
		//we do this two more times for the other words.
		string jumble2 = theWord2;
		//we store the length of the string for later use.
		int length2 = jumble2.size();
		//now we create a for loop to iterate through every letter of the word.
		for (int i = 0; i < length2; ++i)
		{
			//we pick a random letter in the string
			int index1 = (rand() % length2);
			//we pick another random letter.
			int index2 = (rand() % length2);
			//we store the letter from the first random index we chose.
			char temp = jumble2[index1];
			//now we switch the characters in the string.
			jumble2[index1] = jumble2[index2];
			jumble2[index2] = temp;
		}

		string jumble3 = theWord3;
		//we store the length of the string for later use.
		int length3 = jumble3.size();
		//now we create a for loop to iterate through every letter of the word.
		for (int i = 0; i < length3; ++i)
		{
			//we pick a random letter in the string
			int index1 = (rand() % length3);
			//we pick another random letter.
			int index2 = (rand() % length3);
			//we store the letter from the first random index we chose.
			char temp = jumble3[index1];
			//now we switch the characters in the string.
			jumble3[index1] = jumble3[index2];
			jumble3[index2] = temp;
		}

		//now we welcome the player and introduce the game.
		cout << "\t\t\tWelcome to Keyword.\n\n";
		cout << "You and your fellow recruits are tasked with unscrambling these\n";
		cout << "low tech scrambled keywords. Good luck.";
		cout << "\n*************************************************************************\n\n";
		cout << "Enter 'hint' for a hint.\n";
		cout << "Enter 'skip' to skip the current keyword.\n\n";
		cout << "Your first scrambled keyword is: " << jumble1;

		//we create a string to store the user's guess
		string guess;
		cout << "\n\nYour guess: ";
		cin >> guess;

		//while the user's input is wrong and they also didn't type skip
		while ((guess != theWord1) && (guess != "skip"))
		{
			//if the user's input is 'help' instead
			if (guess == "hint")
			{
				//print out the word's hint
				cout << theHint1;
			}
			//otherwise the word is wrong, so let them know.
			else
			{
				cout << "Incorrect. Try again recruit.";
			}
			//ask them again until they get it right or type skip.
			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		//if the guess is right, let the user know.
		if (guess == theWord1) 
		{
			cout << "\nCongratulations recruit, you are correct.\n";
			numRight++;
		}

		//Let the user know what the next scrambled word is.
		cout << "\nYour second scrambled word is: " << jumble2;
		//now we ask for the user's guess again.
		cout << "\n\nYour guess: ";
		cin >> guess;

		//while the user's input is wrong and they also didn't type skip
		while ((guess != theWord2) && (guess != "skip"))
		{
			//if the user types 'help'
			if (guess == "hint")
			{
				//print this word's hint
				cout << theHint2;
			}
			//otherwise, the word is wrong so let them know.
			else
			{
				cout << "Incorrect. Try again recruit.";
			}
			//ask them again until they get it right or they type skip.
			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		//if the guess is right, let the user know.
		if (guess == theWord2)
		{
			cout << "\nCongratulations recruit, you are correct.\n";
			numRight++;
		}

		//Let the user know what the final scrambled word is.
		cout << "\nYour final scrambled word is: " << jumble3;
		//we ask for the user's guess again.
		cout << "\n\nYour guess: ";
		cin >> guess;

		//while the user's input is wrong and they also didn't type skip.
		while ((guess != theWord3) && (guess != "skip"))
		{
			//if the user types "help"
			if (guess == "hint")
			{
				//print this word's hint
				cout << theHint3;
			}
			//otherwise, the word is wrong so let them know.
			else
			{
				cout << "Incorrect. Try again recruit.";
			}
			//ask again until they get it right or type skip
			cout << "\n\nYour guess: ";
			cin >> guess;
		}

		//if the guess is right, let the user know.
		if (guess == theWord3)
		{
			cout << "\nCongratulations recruit, you are correct.\n";
			numRight++;
		}

		//we output the results and ask them if they would like to play again.
		cout << "\n\n**********************************************************";
		cout << "\nWord 1: " << theWord1;
		cout << "\nWord 2: " << theWord2;
		cout << "\nWord 3: " << theWord3;
		cout << "\n\nNumber Correct: " << numRight << " out of 3";
		cout << "\n\nPlay again? (y/n)";
		cin >> playAgain; 
	}
	return 0;
}

