#pragma once
#include <iostream>
#include <string>

class Shape
{
protected:
	std::string name;
public:
	std::string getName() const;
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	bool operator>(const Shape& sh) const noexcept;
	bool operator>=(const Shape& sh) const noexcept;
	bool operator<(const Shape& sh) const noexcept;
	bool operator<=(const Shape& sh) const noexcept;
	bool operator==(const Shape& sh) const noexcept;
	bool operator!=(const Shape& sh) const noexcept;
};

class Rectangle : public Shape
{
private:
	double a;
	double b;
public:
	Rectangle(double a, double b);
	virtual double getPerimeter() const noexcept;
	virtual double getArea() const noexcept;
};

class Circle : public Shape
{
private:
	double R;
public:
	Circle(double R);
	virtual double getPerimeter() const noexcept;
	virtual double getArea() const noexcept;
};

class Square : public Shape
{
private:
	double a;
public:
	Square(double a);
	virtual double getPerimeter() const noexcept;
	virtual double getArea() const noexcept;
};

std::ostream& operator<<(std::ostream& stream, const Shape& sh);