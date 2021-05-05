#define _USE_MATH_DEFINES
#include "ShapesLib.h"
#include <cmath>
#include <stdexcept>

static const double EPSILON = 0.1;


bool Shape::operator>(const Shape& sh) const noexcept
{
	double area1 = this->getArea();
	double area2 = sh.getArea();
	if (abs(area1 - area2) < EPSILON)
		return false;
	if (area1 > area2)
		return true;
	return false;
}

bool Shape::operator>=(const Shape& sh) const noexcept
{
	return (*this == sh || *this > sh);
}

bool Shape::operator<(const Shape& sh) const noexcept
{
	double area1 = this->getArea();
	double area2 = sh.getArea();
	if (abs(area1 - area2) < EPSILON)
		return false;
	if (area1 < area2)
		return true;
	return false;
}

bool Shape::operator<=(const Shape& sh) const noexcept
{
	return (*this == sh || *this < sh);
}

bool Shape::operator==(const Shape& sh) const noexcept
{
	double area1 = this->getArea();
	double area2 = sh.getArea();
	if (abs(area1 - area2) < EPSILON)
		return true;
	return false;
}

bool Shape::operator!=(const Shape& sh) const noexcept
{
	return !(*this == sh);
}

Rectangle::Rectangle(double a, double b)
{
	if (a <= 0 || b <= 0)
		throw std::out_of_range("Dimensions can't be below or equal zero");
	this->a = a;
	this->b = b;
}

double Rectangle::getPerimeter() const noexcept
{
	return 2 * (this->a + this->b);
}

double Rectangle::getArea() const noexcept
{
	return this->a * this->b;
}

void Rectangle::print(std::ostream& stream) const
{
	stream << "This is Rectangle. The perimeter is ";
	stream << this->getPerimeter() << " and the area is " << this->getArea();
}

Circle::Circle(double R)
{
	if (R <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->R = R;
}

double Circle::getPerimeter() const noexcept
{
	return 2 * M_PI * this->R;
}

double Circle::getArea() const noexcept
{
	return M_PI * pow(this->R, 2);
}

void Circle::print(std::ostream& stream) const
{
	stream << "This is Circle. The perimeter is ";
	stream << this->getPerimeter() << " and the area is " << this->getArea();
}

Square::Square(double a)
{
	if (a <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->a = a;
}

double Square::getPerimeter() const noexcept
{
	return 4 * this->a;
}

double Square::getArea() const noexcept
{
	return pow(this->a, 2);
}

void Square::print(std::ostream& stream) const
{
	stream << "This is Square. The perimeter is ";
	stream << this->getPerimeter() << " and the area is " << this->getArea();
}

std::ostream& operator<<(std::ostream& stream, const Shape& sh)
{
	sh.print(stream);
	return stream;
}
