#include "ShapeCollection.h"

double ShapeCollection::minPerimeter() const
{
	double perimeter = 0;
	for (auto it = this->container.begin(); it != this->container.end(); ++it)
	{
		if (it == this->container.begin())
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
	for (auto it = this->container.begin(); it != this->container.end(); ++it)
	{
		if (it == this->container.begin())
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
	for (auto it = this->container.begin(); it != this->container.end(); ++it)
	{
		perimeter += (*it)->getPerimeter();
	}
	perimeter /= this->container.size();
	return perimeter;
}


double ShapeCollection::minArea() const
{
	double area = 0;
	for (auto it = this->container.begin(); it != this->container.end(); ++it)
	{
		if (it == this->container.begin())
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
	for (auto it = this->container.begin(); it != this->container.end(); ++it)
	{
		if (it == this->container.begin())
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
	for (auto it = this->container.begin(); it != this->container.end(); ++it)
	{
		area += (*it)->getArea();
	}
	area /= this->container.size();
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

void ShapeCollection::append(Shape* sh)
{
	this->container.append(sh);
}

void ShapeCollection::operator+=(Shape* sh)
{
	this->container += sh;
}

void ShapeCollection::insert(Shape* sh, const List<Shape*>::Iterator& it)
{
	this->container.insert(sh, it);
}

void ShapeCollection::remove(Shape* sh, const List<Shape*>::Iterator& it)
{
	this->remove(sh, it);
}

List<Shape*>::Iterator ShapeCollection::begin()
{
	return this->container.begin();
}

List<Shape*>::Iterator ShapeCollection::end()
{
	return this->container.end();
}

List<Shape*>::ReverseIterator ShapeCollection::rbegin()
{
	return this->container.rbegin();
}

List<Shape*>::ReverseIterator ShapeCollection::rend()
{
	return this->container.rend();
}

size_t ShapeCollection::size() const
{
	return this->container.size();
}
