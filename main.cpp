#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <functional>
#include <time.h>
#include <stdlib.h>


using namespace std;


void DelayedReveal(function<void(int roll_, int prediction_)> func_showResult_, int delayNum_, int input_);

int main()
{
	srand(unsigned int(time(NULL)));

	int inpuntNum = 0;
	cout << "0か1を入力";
	scanf_s("%d", &inpuntNum);

	auto func_showResult = [](int roll_,int prediction_ ) 
	{
		if (roll_ % 2 == prediction_)
		{
			cout << "正解" << endl;
		}

		else
		{
			cout << "不正解" << endl;
		}
	};


	DelayedReveal(func_showResult, 3, inpuntNum);


	return 0;
}

void DelayedReveal(function<void(int roll_, int prediction_)> func_showResult_, int delayNum_, int input_)
{
	std::this_thread::sleep_for(std::chrono::seconds(delayNum_));

	int roll = rand() % 6 + 1;


	func_showResult_(roll, input_);
}

