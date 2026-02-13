#include<iostream>

struct CircleShape
{
	float radius;
};

struct RectangleShape
{
	float width;
	float height;
};

template<typename SizeType>
class IShape
{
public:
	IShape(const SizeType& size) : size(size), area(0) {}
	virtual ~IShape() = default;
	virtual void Size() = 0;
	virtual void OutputSurface() = 0;
protected:
	SizeType size;
	float area;
};

class Circle : public IShape<CircleShape>
{
public:
	Circle(const CircleShape& size) : IShape(size) {}
	void Size() override
	{
		area = 3.14f *size.radius * size.radius;
	}
	void OutputSurface() override
	{
		std::cout << "‰~‚Ì–ÊÏ‚Í" << area << std::endl;
	}
};

struct Rectangle : public IShape<RectangleShape>
{
	Rectangle(const RectangleShape& size) : IShape(size) {}

	void Size() override
	{
		area = size.width * size.height;
	}

	void OutputSurface() override
	{
		std::cout << "‹éŒ`‚Ì–ÊÏ‚Í" << area << std::endl;
	}
};

bool PrintShape(int choice)
{
	switch (choice)
	{
	case 1:
	{
		CircleShape cShape;
		std::cout << "”¼Œa‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:";
		std::cin >> cShape.radius;
		Circle circle(cShape);
		circle.Size();
		circle.OutputSurface();
	}
	break;
	case 2:
	{
		RectangleShape rShape;
		std::cout << "•‚Æ‚‚³‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:";
		std::cin >> rShape.width >> rShape.height;
		Rectangle rectangle(rShape);
		rectangle.Size();
		rectangle.OutputSurface();
	}
	break;
	default:
		std::cout << "–³Œø‚È“ü—Í‚Å‚·" << std::endl;
		break;
	}

	std::cout << "‚à‚¤ˆê‰ñ‚â‚è‚Ü‚·‚© y / n ? :";
	char input;
	std::cin >> input;

	if (input == 'y')return true;
	else if (input == 'n')return false;
	return true;
}

int main()
{
	int choice = 0;

	do
	{
		std::cout << "1. ‰~ 2. ‹éŒ`" << std::endl;
		std::cin >> choice;
		std::cout << std::endl;

	} while (PrintShape(choice));

	return 0;
}