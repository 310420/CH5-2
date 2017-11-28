#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

void mini(int grade[][EXAMS], int pupils, int tests);
void maxi(int grade[][EXAMS], int pupils, int tests);
void aver(int grade[][EXAMS], int pupils, int tests);
void printA(int grade[][EXAMS], int pupils, int tests);
void printM(void);

int main(void)
{
	void(*processGrades[4])(int[][EXAMS], int, int)
		= { printA,mini,maxi,aver };
	int choice = 0;

	int studentGrades[STUDENTS][EXAMS] = { {77,68,86,71},
	                                       {96,87,89,78},
										   {70,90,86,81}};
	while (choice != 4)
	{
		do
		{
			printM();
			scanf("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
			(*processGrades[choice])(studentGrades, STUDENTS, EXAMS);

		else
			printf("Program End.\n");
	}
	system("pause");
	return 0;
}

void printA(int grade[][EXAMS], int pupils, int tests)
{
	int i, j;

	printf("\n\t                     [0]         [1]         [2]         [3]");
	for (i = 0; i <= pupils - 1; i++)
	{
		printf("\n\tstudentGrades[%d]", i);
		for ( j = 0; j <= tests-1; j++)		
			printf("     %-7d", grade[i][j]);
	}
	printf("\n");
}

void maxi(int grade[][EXAMS], int pupils, int tests)
{
	int i, j, hiGrade =0;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grade[i][j] > hiGrade)
				hiGrade = grade[i][j];
		}
	}
	printf("\n\tThe highest grade is %d\n", hiGrade);
}

void aver(int grade[][EXAMS], int pupils, int tests)
{
	int i, j, total;
	for (i = 0; i <= pupils - 1; i++)
	{
		total = 0;
		for (j = 0; j <= tests - 1; j++)
		{
			
				total+= grade[i][j];
		}
        printf("\n\tThe average grade for student is%d is %.1f\n",
		  i+1,(double)total/tests);
	}
}

void mini(int grade[][EXAMS], int pupils, int tests)
{
	int i, j, lowGrade = 100;
	for (i = 0; i <= pupils - 1; i++)
	{
		for (j = 0; j <= tests - 1; j++)
		{
			if (grade[i][j] < lowGrade)
				lowGrade = grade[i][j];
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowGrade);
}

void printM(void)
{
	printf("\n\tEnter a choice:\n"
		   "\t  0 Print the array of grades\n"
		   "\t  1 Find the minimum grade\n"
		   "\t  2 Find the maximum grade\n"
		   "\t  3 Print the average on all"
		   " tests for each student\n"
		   "\t  4  End program\n"
		   "\t?");
}