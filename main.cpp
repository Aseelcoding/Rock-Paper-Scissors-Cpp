
#include <iostream>
#include<string>
#include <cmath>
#include <cstdlib>
using namespace std;
enum EnumGameResult { Win = 1, Lose = 2, Drow = 3 };
enum EnumGame { Rock = 1, Paper = 2, Scissors = 3,WrongChoice=4 };
struct StGameResultInNumber { short Win = 0, Lose = 0, Drow = 0, Rounds = 0; };
string Taps(short numberoftaps)
{
	string taps = "";
	for (int i = 1; i <= numberoftaps; i++)
	{
		taps = taps + "\t";

	}
	return taps;


}
string FinalWinner(short wins, short loses, short Drows)
{
	if (wins > loses)
	{
		system("color 2F");
		return "Payer one win ";
	}

	else if (loses > wins)
	{
		system("color 4F");
		return "Computer win ";
	}


	else
	{
		system("color 6F");
		return "Drow, no one win";
	}





}
void ShowGameResult(StGameResultInNumber ResultInNumber)
{
	cout << endl << endl << Taps(4) << "  -----------[Game Result]-----------\n";
	cout << Taps(5) << "Game Rounds : " << ResultInNumber.Rounds << endl;
	cout << Taps(5) << "Player Wins : " << ResultInNumber.Win << endl;
	cout << Taps(5) << "Computer Wins : " << ResultInNumber.Lose << endl;
	cout << Taps(5) << "Draws : " << ResultInNumber.Drow << endl;
	cout << Taps(5) << "final Winner : " << FinalWinner(ResultInNumber.Win, ResultInNumber.Lose, ResultInNumber.Drow) << endl << endl << endl;


}
short HowManyRounds()
{
	int Rounds = 0;
	do
	{
		cout << "How Many Rounds do You Want to play from 1 to 10 \n";
		cin >> Rounds;


	} while (Rounds <= 0 || Rounds > 10);
	return Rounds;

}
int RandomNumber(int From, int To)
{

	//برنامج يولد ارقام عشوائيه من رقم معين الي اخر "
	int RandomNumber = rand() % (To - From + 1) + From;

	return RandomNumber;




}
EnumGame computerChoiesFun()
{
	short numberOfChoies = RandomNumber(1, 3);
	return EnumGame(numberOfChoies);

}
EnumGame PlayerChoiceFun(short PlayerChoice)
{
		return EnumGame(PlayerChoice);
}
void ShowGameOver()
{

	cout <<endl<< Taps(4)  << "----------------------------------------" << endl;
	cout << endl << Taps(3) << "                         Game Over                " << endl;
	cout << endl << Taps(4)  << "----------------------------------------" << endl;


}
EnumGameResult WhoWin(EnumGame PlayerChoice, EnumGame ComputerChoice)
{
	if (PlayerChoice == ComputerChoice)
		return EnumGameResult::Drow;
	//computer wins
	else if (ComputerChoice == EnumGame::Rock && PlayerChoice == EnumGame::Scissors)
		return EnumGameResult::Lose;
	else if (ComputerChoice == EnumGame::Paper && PlayerChoice == EnumGame::Rock)
		return EnumGameResult::Lose;
	else if (ComputerChoice == EnumGame::Scissors && PlayerChoice == EnumGame::Paper)
		return EnumGameResult::Lose;
	else
		return EnumGameResult::Win;





}
string ReturnWhatIchose(EnumGame choice)
{
	switch (choice)
	{
	case EnumGame::Rock:
		return "Rock";
	case EnumGame::Paper:
		return "Paper";
	case EnumGame::Scissors:
		return "Scissors";


	}


}
void StartTheRounds()
{
	EnumGame computerchoice;
	short	PlayerChoice;
	short ComputerChoice;
	EnumGameResult GameResult;
	StGameResultInNumber ResultInNumber;
	short Rounds = HowManyRounds();
	for (short i = 1; i <= Rounds; i++)
	{
		cout << "\nRound [" << i << "] begins :\n";
		cout << "\nYour choice : [1]Rock,[2]Paper,[3] Scissors \n";
		cin >> PlayerChoice;
		do 
		{
			if (PlayerChoice < 1 || PlayerChoice>3)
			{
				cout << "please chose between 1 and 3 " << endl;
				cin >> PlayerChoice;
			}
		} while (PlayerChoice < 1 || PlayerChoice>3);
		
			PlayerChoiceFun(PlayerChoice);
	  

		computerchoice = computerChoiesFun();

		if (WhoWin(PlayerChoiceFun(PlayerChoice), computerchoice) == EnumGameResult::Win)
		{
			system("color 2F");
			cout << "\n----------------------Round [" << i << "]----------------------\n";
			cout << "\nPlayer one choice: " << ReturnWhatIchose(PlayerChoiceFun(PlayerChoice)) << endl;
			cout << "\nComputer  choice: " << ReturnWhatIchose(computerchoice) << endl;
			cout << "\nRound Winner : " << "Player one" << endl;
			ResultInNumber.Win = ResultInNumber.Win + 1;

		}
		else if (WhoWin(PlayerChoiceFun(PlayerChoice), computerchoice) == EnumGameResult::Drow)
		{
			system("color 6F");
			cout << "\n----------------------Round [" << i << "]----------------------\n";
			cout << "\nPlayer one choice : " << ReturnWhatIchose(PlayerChoiceFun(PlayerChoice)) << endl;
			cout << "\nComputer one choice : " << ReturnWhatIchose(computerchoice) << endl;
			cout << "\nRound Winner : " << "Drow" << endl;
			ResultInNumber.Drow = ResultInNumber.Drow + 1;



		}
		else if (WhoWin(PlayerChoiceFun(PlayerChoice), computerchoice) == EnumGameResult::Lose)
		{
			system("color 4F");
			cout << "\n----------------------Round [" << i << "]----------------------\n";
			cout << "\nPlayer one choice : " << ReturnWhatIchose(PlayerChoiceFun(PlayerChoice)) << endl;
			cout << "\nComputer one choice : " << ReturnWhatIchose(computerchoice) << endl;
			cout << "\nRound Winner : " << "computer" << endl;
			ResultInNumber.Lose = ResultInNumber.Lose + 1;




		}
	}


	ShowGameOver();
	ResultInNumber.Rounds = Rounds;
	ShowGameResult(ResultInNumber);
}
void RefreshScreen()
{
	system("cls");
	system("color 0F");



}
void StartTheGame()
{
	string answer;
	do
	{
		
		RefreshScreen();
		StartTheRounds();
		cout << "Do you want to play again ? enter 1 or y, or n or 0\n";
		cin >> answer;

	} while (answer=="y"||answer=="1"||answer=="Y");
}
int main()
{
	srand((unsigned)time(NULL));
	StartTheGame();
}

