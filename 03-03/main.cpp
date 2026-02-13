#include<iostream>
using namespace std;

struct Human
{
	virtual void Update();

};

struct Elfe :public Human
{
	virtual void Update()override {};

};

struct Dwarf :public Human
{
	virtual void Update()override {};

};

int main()
{
	Elfe e;
	Dwarf d;

	e.Update();
	d.Update();






	return 0;
}