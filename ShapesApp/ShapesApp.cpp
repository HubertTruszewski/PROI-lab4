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
	auto it3 = list.begin();
	
	for (auto i : list)
	{
		std::cout << i << std::endl;
	}


	list.removeFromList(4);
	
	for (auto i : list)
	{
		std::cout << i << std::endl;
	}

	return 0;
}