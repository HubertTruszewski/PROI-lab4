#pragma once
#include <iostream>
#include <string>

class Shape
{
public:
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	virtual void print(std::ostream& stream) const = 0;
	bool operator>(const Shape& sh) const noexcept;
	bool operator>=(const Shape& sh) const noexcept;
	bool operator<(const Shape& sh) const noexcept;
	bool operator<=(const Shape& sh) const noexcept;
	bool operator==(const Shape& sh) const noexcept;
	bool operator!=(const Shape& sh) const noexcept;
	virtual ~Shape() = default;
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
	virtual void print(std::ostream& stream) const;
};

class Circle : public Shape
{
private:
	double R;
public:
	Circle(double R);
	virtual double getPerimeter() const noexcept;
	virtual double getArea() const noexcept;
	virtual void print(std::ostream& stream) const;
};

class Square : public Shape
{
private:
	double a;
public:
	Square(double a);
	virtual double getPerimeter() const noexcept;
	virtual double getArea() const noexcept;
	virtual void print(std::ostream& stream) const;
};

std::ostream& operator<<(std::ostream& stream, const Shape& sh);