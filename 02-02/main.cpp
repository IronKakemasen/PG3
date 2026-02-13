#include<iostream>

int Salary(int hours)
{
	return hours * 1226;
}

int RecursionWage(int hour)
{
	if (hour == 1) return 100;
	else return (RecursionWage(hour - 1) * 2) - 50;
}

int RecursionSalary(int hours)
{
	if (hours <= 0)
		return 0;
	return RecursionWage(hours) + RecursionSalary(hours - 1);
}

int main()
{
	int hour = 0;
	int dafault = 0;
	int recursion = 0;

	while (dafault >= recursion)
	{
		hour++;
		dafault = Salary(hour);
		recursion = RecursionSalary(hour);

		printf("%d ŠÔ\n’Êí’À‹à %d\nÄ‹A’À‹à %d\n", hour, dafault, recursion);
	}
	printf("%d ŠÔ–Ú‚ÉÄ‹A“I’À‹à‘ÌŒn‚Ì•û‚ª–×‚©‚é\n", hour);

	return 0;
}