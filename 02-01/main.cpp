#include<iostream>
#include<format>
#include<string>
#include <typeinfo>

using namespace std;

template<typename T>
std::string FV(T v)
{
	if constexpr (std::is_same_v<T, float>)
	{
		return std::format("{}f", v);
	}
	else
	{
		return std::format("{}", v);
	}
}

template<typename T>
T Min(T a, T b)
{
	return a < b ? a : b;
}

template<typename T>
void PrintMin(T a, T b)
{
	string result = format("Type: {} -> Min({}, {}) = {}\n",
		typeid(T).name(),
		FormatValue(a),
		FormatValue(b),
		FormatValue(Min(a, b))
	);

	cout << result << endl;
}

int main()
{
	int iA = 2, iB = 5;
	float fA = 0.9999999f, fB = 1.0f;
	double dA = 7.5, dB = 7.55;

	PrintMin(iA, iB);
	PrintMin(fA, fB);
	PrintMin(dA, dB);

	return 0;
}