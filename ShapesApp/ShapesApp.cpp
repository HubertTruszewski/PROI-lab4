#include <iostream>
#include <vector>
#include "../MyCollection/List.h"
#include "../ShapesLib/ShapesLib.h"

int main()
{
	List<Shape*> list;

	list.append(new Circle(6));
	list.append(new Square(3));
	list.append(new Rectangle(2, 6));
	list.append(new Square(5));
	list.append(new Rectangle(6, 7));
	list.append(new Circle(2));
	list.append(new Square(3));

	for (auto i : list)
	{
		std::cout << *i << std::endl;
	}


	return 0;
}