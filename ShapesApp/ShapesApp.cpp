#include <iostream>
#include <vector>
#include "../MyCollection/List.h"
#include "../MyCollection/ShapeCollection.h"
#include "../ShapesLib/ShapesLib.h"

int main()
{

	ShapeCollection sh;
	sh.append(new Square(5));
	sh.append(new Circle(6));
	sh.append(new Rectangle(3, 5));
	sh += new Rectangle(1, 5);
	sh += new Square(4);
	sh += new Circle(3);
	
	for (auto i : sh)
	{
		std::cout << *i << std::endl;
	}

	std::cout << sh;

	return 0;
}