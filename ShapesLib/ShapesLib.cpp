#define _USE_MATH_DEFINES
#include "ShapesLib.h"
#include <cmath>
#include <stdexcept>

static const double EPSILON = 0.1;

bool Shape::operator>(const Shape& sh) const
{
	double area1 = this->getArea();
	double area2 = sh.getArea();
	if (abs(area1 - area2) < EPSILON)
		return false;
	if (area1 > area2)
		return true;
	return false;
}

bool Shape::operator<(const Shape& sh) const
{
	double area1 = this->getArea();
	double area2 = sh.getArea();
	if (abs(area1 - area2) < EPSILON)
		return false;
	if (area1 < area2)
		return true;
	return false;
}

bool Shape::operator==(const Shape& sh) const
{
	double area1 = this->getArea();
	double area2 = sh.getArea();
	if (abs(area1 - area2) < EPSILON)
		return true;
	return false;
}

bool Shape::operator!=(const Shape& sh) const
{
	return !(*this == sh);
}

Rectangle::Rectangle(double a, double b)
{
	if (a <= 0 || b <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->a = a;
	this->b = b;
}

double Rectangle::getPerimeter() const
{
	return 2 * (this->a + this->b);
}

double Rectangle::getArea() const
{
	return this->a * this->b;
}

Circle::Circle(double R)
{
	if (R <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->R = R;
}

double Circle::getPerimeter() const
{
	return 2 * M_PI * this->R;
}

double Circle::getArea() const
{
	return M_PI * pow(this->R, 2);
}

Square::Square(double a)
{
	if (a <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->a = a;
}

double Square::getPerimeter() const
{
	return 4 * this->a;
}

double Square::getArea() const
{
	return pow(this->a, 2);
}
