#include <stdio.h>
#include <stdlib.h>
#define ISSUES 5
#define RATINGS 10

void record(int i, int response);
void high(void);
void low(void);
float aver(int issue);
void display(void);

int reponses[ISSUES][RATINGS];
const char *topics[ISSUES] = {"Global Warming","The Economy","War",
							 "Health Care","Education"};

int main(void)
{
	int response, i;
	do
	{
		printf("Please rate the following topics on a scale from 1 - 10"
			   "\n 1 = least important, 10 = most important\n");
		for ( i = 0; i < ISSUES; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("? ");
				scanf("%d", &response);
			} while (response < 1 || response>10);
			record(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again.");
		scanf("%d", &response);
	} while (response != 1);
	display();
	system("pause");
	return 0;
}

void record(int issue, int rating)
{
	reponses[issue][rating - 1]++;
}

void low(void)
{
	int lowR, lowT = 0, i, j;

	for ( i = 0; i < ISSUES; i++)
	{
		int topic = 0;

		for (j = 0; j < RATINGS; j++)
			topic += reponses[i][j] * (j + 1);
		if (i==0)
			lowR = topic;
		if (lowR>topic)
		{
			lowR = topic;
			lowT = i;
		}
	}
	printf("The lowest rated topic was ");
	printf("%s",topics[lowT]);
	printf(" with a total rating of %d\n",lowR);
}

void high(void)
{
	int highR = 0, highT = 0, i, j;

	for (i = 0; i < ISSUES; i++)
	{
		int topic = 0;

		for (j = 0; j < RATINGS; j++)
			topic += reponses[i][j] * (j + 1);
		if (highR < topic)
		{
			highR = topic;
			highT = i;
		}
	}
	printf("The highest rated topic was ");
	printf("%s", topics[highT]);
	printf(" with a total rating of %d\n", highR);
}

float aver(int issue)
{
	float total = 0;
	int counter = 0, j;

	for ( j = 0; j < RATINGS; j++)
	{
		if (reponses[issue][j] != 0)
		{
			total += reponses[issue][j] * (j + 1);
			counter += reponses[issue][j];
		}
	}
	return total / counter;
}

void display(void)
{
	int i, j;
	printf("%20s", "Topic");
	for (i = 1; i <= RATINGS; i++)
		printf("%4d", i);
	printf("%20s", "Average Rating");

	for ( i = 0; i < ISSUES; i++)
	{
		printf("%20s", topics[i]);
		for (j = 0; j < RATINGS; j++)
			printf("%4d", reponses[i][j]);
		printf("%20.2f", aver(i));
	}
	high();
	low();
}