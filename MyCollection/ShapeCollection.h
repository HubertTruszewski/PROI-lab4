#pragma once
#include "List.h"
#include "../ShapesLib/ShapesLib.h"

class ShapeCollection : public List<Shape*>
{
public:
	double minPerimeter() const;
	double maxPerimeter() const;
	double avgPerimeter() const;
	double minArea() const;
	double maxArea() const;
	double avgArea() const;

};

std::ostream& operator<<(std::ostream& stream, const ShapeCollection& col);