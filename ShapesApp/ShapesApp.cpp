#include <iostream>
#include "../MyCollection/List.h"

int main()
{
	List<int> list;
	list.append(5);
	list.append(6);
	list.append(7);
	list.append(8);
	list.append(9);

	auto it1 = list.begin();
	auto it2 = list.end();

	if (it1 != it2)
	{
		std::cout << "OK";
	}
	
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "Na pozycji " << i << " jest " << list.getElement(i) << std::endl;
	}

	return 0;
}