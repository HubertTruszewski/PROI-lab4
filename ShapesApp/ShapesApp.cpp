#include <iostream>
#include <vector>
#include "../MyCollection/List.h"
#include "../MyCollection/ShapeCollection.h"
#include "../ShapesLib/ShapesLib.h"

int main()
{

	ShapeCollection sh;
	sh.append(new Circle(5));
	sh.append(new Circle(6));
	sh.append(new Circle(3));
	
	std::cout << sh;


	return 0;
}