#include "ShapeCollection.h"

double ShapeCollection::minPerimeter() const
{
	double perimeter = 0;
	for (auto it = this->begin(); it != this->end(); ++it)
	{
		if (it == this->begin())
			perimeter = (*it)->getPerimeter();
		else
		{
			if ((*it)->getPerimeter() < perimeter)
			{
				perimeter = (*it)->getPerimeter();
			}
		}
	}
	return perimeter;
}

double ShapeCollection::maxPerimeter() const
{
	double perimeter = 0;
	for (auto it = this->begin(); it != this->end(); ++it)
	{
		if (it == this->begin())
			perimeter = (*it)->getPerimeter();
		else
		{
			if ((*it)->getPerimeter() > perimeter)
			{
				perimeter = (*it)->getPerimeter();
			}
		}
	}
	return perimeter;
}

double ShapeCollection::avgPerimeter() const
{
	double perimeter = 0;
	for (auto it = this->begin(); it != this->end(); ++it)
	{
		perimeter += (*it)->getPerimeter();
	}
	perimeter /= this->size();
	return perimeter;
}


double ShapeCollection::minArea() const
{
	double area = 0;
	for (auto it = this->begin(); it != this->end(); ++it)
	{
		if (it == this->begin())
			area = (*it)->getArea();
		else
		{
			if ((*it)->getArea() < area)
			{
				area = (*it)->getArea();
			}
		}
	}
	return area;
}

double ShapeCollection::maxArea() const
{
	double area = 0;
	for (auto it = this->begin(); it != this->end(); ++it)
	{
		if (it == this->begin())
			area = (*it)->getArea();
		else
		{
			if ((*it)->getArea() > area)
			{
				area = (*it)->getArea();
			}
		}
	}
	return area;
}

double ShapeCollection::avgArea() const
{
	double area = 0;
	for (auto it = this->begin(); it != this->end(); ++it)
	{
		area += (*it)->getArea();
	}
	area /= this->size();
	return area;
}


std::ostream& operator<<(std::ostream& stream, const ShapeCollection& col)
{
	if (col.size() == 0)
	{
		stream << "This collection is empty" << std::endl;
	}
	else
	{
		stream << "Informations about elements in this collection:" << std::endl;
		stream << "Minimal perimeter is " << col.minPerimeter() << ", maximal is " << col.maxPerimeter() << std::endl;
		stream << "Average perimeter is " << col.avgPerimeter() << std::endl;
		stream << "Minimal area is " << col.minArea() << ", maximal is " << col.maxArea() << std::endl;
		stream << "Average area is " << col.avgArea() << std::endl;
	}
	return stream;
}