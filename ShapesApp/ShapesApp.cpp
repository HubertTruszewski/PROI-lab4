#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class Shape
{
public:
	virtual double perimeter() = 0;
	virtual double area() = 0;
};

class Rectangle : public Shape
{
private:
	double a;
	double b;
public:
	Rectangle(double a, double b);
	virtual double perimeter();
	virtual double area();
};

class Circle : public Shape
{
private:
	double R;
public:
	Circle(double R);
	virtual double perimeter();
	virtual double area();
};

class Square : public Shape
{
private:
	double a;
public:
	Square(double a);
	virtual double perimeter();
	virtual double area();
};

static const double EPSILON = 0.1;

Rectangle::Rectangle(double a, double b)
{
	if (a <= 0 || b <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->a = a;
	this->b = b;
}

double Rectangle::perimeter()
{
	return 2 * (this->a + this->b);
}

double Rectangle::area()
{
	return this->a * this->b;
}

Circle::Circle(double R)
{
	if (R <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->R = R;
}

double Circle::perimeter()
{
	return 2 * M_PI * this->R;
}

double Circle::area()
{
	return M_PI * pow(this->R, 2);
}

Square::Square(double a)
{
	if (a <= 0)
		throw std::out_of_range("Dimension can't be below or equal zero");
	this->a = a;
}

double Square::perimeter()
{
	return 4 * this->a;
}

double Square::area()
{
	return pow(this->a, 2);
}

bool operator>(Shape& sh1, Shape& sh)
{
	if (abs(sh1.area() - sh.area()) < EPSILON)
		return false;
	if (sh1.area() > sh.area())
		return true;
	return false;
}

bool operator<(Shape& sh1, Shape& sh)
{
	if (abs(sh1.area() - sh.area()) < EPSILON)
		return false;
	if (sh1.area() < sh.area())
		return true;
	return false;
}

bool operator==(Shape& sh1, Shape& sh)
{
	if (abs(sh1.area() - sh.area()) < EPSILON)
		return true;
	return false;
}

bool operator!=(Shape& sh1, Shape& sh)
{
	return !(sh1 == sh);
}


int main()
{
	Shape* a = new Rectangle(4, 4);
	Shape* b = new Square(4);
	bool result = false;
	result = (*a==*b);
	std::cout << result;
}
