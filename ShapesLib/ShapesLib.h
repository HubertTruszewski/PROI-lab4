#pragma once

class Shape
{
public:
	virtual double getPerimeter() const = 0;
	virtual double getArea() const = 0;
	bool operator>(const Shape& sh) const;
	bool operator<(const Shape& sh) const;
	bool operator==(const Shape& sh) const;
	bool operator!=(const Shape& sh) const;
};

class Rectangle : public Shape
{
private:
	double a;
	double b;
public:
	Rectangle(double a, double b);
	virtual double getPerimeter() const;
	virtual double getArea() const;
};

class Circle : public Shape
{
private:
	double R;
public:
	Circle(double R);
	virtual double getPerimeter() const;
	virtual double getArea() const;
};

class Square : public Shape
{
private:
	double a;
public:
	Square(double a);
	virtual double getPerimeter() const;
	virtual double getArea() const;
};
