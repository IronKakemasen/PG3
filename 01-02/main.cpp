#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

vector<string> Load(const std::string& filename)
{
	ifstream file(filename);

	if (!file.is_open())
	{
		printf("Can not find file\n");
		return {};
	}

	string line;
	vector<string> data;
	while (getline(file, line, ','))
	{
		data.push_back(line);
	}

	file.close();

	return data;
}

int main()
{
	auto data = Load("aaa.txt");

	sort(data.begin(), data.end());

	int i = 1;
	for (const auto& s : data)
	{
		printf("%02d: äwê–î‘çÜ %s\n", i, s.c_str());
		i++;
	}

	return 0;
}