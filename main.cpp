#include<iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
	int const kNumStations = 30;
	std::list<string> list{
		"Osaki",
		"Gotanda",
		"Meguro",
		"Ebisu",
		"Shibuya",
		"Harajuku",
		"Yoyogi",
		"Shinjuku",
		"Shin - Ōkubo",
		"Takadanobaba",
		"Mejiro",
		"Ikebukuro",
		"Ōtsuka",
		"Sugamo",
		"Komagome",
		"Tabata",

		"Nippori",
		"Uguisudani",
		"Ueno",
		"Okachimachi",
		"Akihabara",
		"Kanda",
		"Tōkyo",
		"Yurakucho",
		"Shimbashi",
		"Hamamatsuchō",
		"Tamachi",

		"Shinagawa",
	};



	int count = 0;
	for (auto i = list.begin(); i != list.end(); ++i)
	{
		if (count == 15)
		{
			string name = "Nishi - Nippori";
			i = list.insert(i, name);
		}

		else if (count == 27)
		{
			string name = "Takanawa Gateway";
			i = list.insert(i, name);
		}

		count++;

		


	}


	for (auto i = list.begin(); i != list.end(); ++i)
	{

		cout << (*i) << endl;

	}







	



	return 0;
}