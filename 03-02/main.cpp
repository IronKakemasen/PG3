#include<iostream>
#include<typeinfo>
using namespace std;

template<typename T>
struct TempClass
{
	static T Min(T a, T b)
	{
		return a < b ? a : b;
	}
};

int main()
{
	cout << TempClass<int>::Min(0, 12);
	cout << TempClass<double>::Min(0.1, 12.0);
	cout << TempClass<float>::Min(0.0f, 12.0f);

	return 0;
}
