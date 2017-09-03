#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void easy();
void norm();
void hard();

int main()
{
	srand(time());
	enum Complexity
	{
		EASY = 1, NORM, HARD
	};
	enum Complexity choicecomplexity = EASY;
	do
	{
		puts("Choose a difficulty:\n\n"
			"1.Easy\t(five questions).\n"
			"2.Normal (ten questions).\n"
			"3.Hard\t(fifteen questions).");
		scanf_s("%d", &choicecomplexity);
	} while (choicecomplexity < 1 || choicecomplexity > 3);
	switch (choicecomplexity)
	{
	case EASY:
		easy();
		break;
	case NORM:
		norm();
		break;
	case HARD:
		hard();
		break;
	}

	return 0;
}
void hard()
{
	int multtable[81], arrnum = 0, mult1 = 0, mult2 = 0, result = 0, score = 0, quest = 15;
	for (int firmult = 1; firmult < 10; ++firmult)
	{
		for (int secmult = 1; secmult < 10; ++secmult)
		{
			multtable[arrnum] = firmult * secmult;
			++arrnum;
		}
	}
	do
	{
		system("CLS");
		printf_s("What are the multipliers of exspression ? x ? = %d\n", result = multtable[rand() % 81]);
		puts("First multiplier:");
		scanf_s("%d", &mult1);
		puts("Second multiplier:");
		scanf_s("%d", &mult2);
		if (result == mult1 * mult2)
		{
			puts("Correct!");
			Sleep(2000);
			++score;
		}
		else
		{
			puts("Mistake.");
			Sleep(2000);
		}
	} while (--quest);
	printf_s("Your score is %.0lf.\n", (10.0 / 100.0) * (6.6 * score));
}


void norm()
{
	int mult1 = 0, result = 0, answer = 0, quest = 10;
	double	score = 0;
	do
	{
		system("CLS");
		mult1 = rand() % 9 + 1;
		result = ((rand() * 2) % 9 + 1) * mult1;
		printf_s("What a digit is skipped %d x ? = %d: ", mult1, result);
		scanf_s("%d", &answer);
		if (answer == (result / mult1))
		{
			puts("Correct!");
			Sleep(2000);
			++score;
		}
		else
		{
			puts("Mistake.");
			Sleep(2000);
		}
	} while (--quest);
	printf_s("Your score is %.0lf.\n", (10.0 / 100.0) * (10.0 * score));
}

void easy()
{
	int mult1 = 0, mult2 = 0, answer = 0, quest = 5;
	double	score = 0;
	do
	{
		system("CLS");
		printf_s("What is the product to %d x %d = ?:", mult1 = rand() % 9 + 1, mult2 = (rand() * 2) % 9 + 1);
		scanf_s("%d", &answer);
		if (answer == (mult1 * mult2))
		{
			puts("Correct!");
			Sleep(2000);
			++score;
		}
		else
		{
			puts("Mistake.");
			Sleep(2000);
		}
	} while (--quest);
	printf_s("Your score is %.0lf.\n", (10.0 / 100.0) * (20.0 * score));
}
