#pragma once
#include "List.h"
#include "../ShapesLib/ShapesLib.h"

class ShapeCollection
{
private:
	List<Shape*> container;
public:
	void append(Shape* sh);
	void operator+=(Shape* sh);
	void insert(Shape* sh, const List<Shape*>::Iterator& it);
	void remove(Shape* sh, const List<Shape*>::Iterator& it);
	List<Shape*>::Iterator begin();
	List<Shape*>::Iterator end();
	List<Shape*>::ReverseIterator rbegin();
	List<Shape*>::ReverseIterator rend();
	size_t size() const;
	double minPerimeter() const;
	double maxPerimeter() const;
	double avgPerimeter() const;
	double minArea() const;
	double maxArea() const;
	double avgArea() const;
};

std::ostream& operator<<(std::ostream& stream, const ShapeCollection& col);