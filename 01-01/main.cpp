#include <stdio.h>
#include <list>
#include <cstring>
using namespace std;

void P(list<const char*>& stations, const char* year)
{
	int i = 1;
	printf("%s ”N\n", year);
	for (auto it = stations.begin(); it != stations.end(); ++it, ++i)
	{
		printf("JY%2d: %s\n", i, *it);
	}
	printf("\n");
}

bool I(list<const char*>& stations, const char* targetStation, const char* insertStation)
{
	for (auto it = stations.begin(); it != stations.end(); ++it)
	{
		if (strcmp(*it, targetStation) == 0)
		{
			++it;
			stations.insert(it, insertStation);
			return true;
		}
	}
	return false;
}

int main()
{
	list<const char*> stations = 
	{
		"Tokyo", "Kanda", "Akihabara", "Okachimachi", "Ueno", "Uguisudani", "Nippori","Tabata",
		"Komagome", "Sugamo", "Otsuka", "Ikebukuro", "Mejiro", "Takadanobaba", "Shin-Okubo", "Shinjuku", "Yoyogi",
		"Harajuku", "Shibuya", "Ebisu", "Meguro", "Gotanda", "Osaki", "Shinagawa", "Tamachi",
		"Hamamatsucho", "Shimabashi", "Yurakucho"
	};

	P(stations, "1970");

	if (!I(stations, "Nippori", "Nishi-Nippori"))
	{
		printf("‘}“ü‘ÎÛ‚Ì‰w \"%s\" ‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B\n", "Nippori");
	}

	P(stations, "2019");
	
	if (!I(stations, "Shinagawa", "Takanawa Gateway"))
	{
		printf("‘}“ü‘ÎÛ‚Ì‰w \"%s\" ‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½B\n", "Shinagawa");
	}
	
	P(stations, "2022");

	return 0;
}
