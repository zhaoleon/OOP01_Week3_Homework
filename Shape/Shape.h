#pragma once
#ifndef __MYSHAPE__
#define __MYSHAPE__

#include <iostream>

using namespace std;

//Make a enum of shape types
enum shapeType
{
	RECT,CIRC
};

//base class
class Shape
{
private:

	int no;
	static Shape* _prototype[10];
	static int _nextSlot;

protected:

	virtual shapeType returnType() = 0;
	virtual Shape* clone() = 0;
	static void addPrototype(Shape* image)
	{
		_prototype[_nextSlot++] = image;
	}

public:

	virtual int GetArea() = 0;
	virtual void SetNo(int _no) { no = _no; };
	virtual int GetNo() { return no; };
	virtual void Draw() {};
	static Shape* findAndClone(shapeType type);
	Shape();
};

Shape* Shape::_prototype[];
int Shape::_nextSlot;

class Point
{
	int x;
	int y;
public:
	Point(int x,int y);
	Point(const Point& other);
	int GetX() const;
	int GetY() const;
	void SetX(int x);
	void SetY(int y);
};

//class Rectangle derives from class Shape
class Rectangle : public Shape
{
private:

	int width;
	int height;
	Point* leftUp;
	static Rectangle _rectangle;
	Rectangle();
	static int _count;

protected:
	Rectangle(int dummy) :Shape()
	{
		Shape::SetNo(_count++);
	}

public:
	int GetWidth();
	int GetHeight();
	virtual void Draw();
	Rectangle(int no,int x,int y,int width,int height);
	Rectangle(int no,const Point& leftUp,int width,int height);
	Rectangle(const Rectangle& other);
	Rectangle(int dummy);
	Rectangle& operator = (const Rectangle& other);
	~Rectangle();
	shapeType returnType();
	Shape* clone();
	
};

Rectangle Rectangle::_rectangle;
int Rectangle::_count = 1;

//class Circle derives from class Shape
class Circle : public Shape
{
	Point* center;
	int radius;
public:
	int GetRadius();
	virtual void Draw();
	Circle(int no,int x, int y, int radius);
	Circle(const Point& center,int no, int radius);
	Circle(const Circle& other);
	Circle& operator = (const Circle& other);
	~Circle();
};

inline Shape * Shape::findAndClone(shapeType type)
{
	for (int i = 0; i < _nextSlot; i++)
	{
		if (_prototype[i]->returnType() == type)
		{
			return _prototype[i]->clone();
		}
	}
}

//Base constructor
inline Shape::Shape()
{
	//TODO:Shape constructor...
}

//Point constructor overload
inline Point::Point(int x, int y):x(x),y(y)
{
	//TODO:Point constructor...
}

//Point constructor overload
inline Point::Point(const Point& other):x(other.GetX()),y(other.GetY())
{
	//TODO:Point copy constructor...
}

//Method to return x value
inline int Point::GetX() const
{
	return x;
}

//Method to return y value
inline int Point::GetY() const
{
	return y;
}

//Method to set x value
inline void Point::SetX(int x)
{
	x = x;
}

//Method to set y value
inline void Point::SetY(int y)
{
	y = y;
}

//Method to return height value
inline int Rectangle::GetHeight()
{
	return height;
}

inline void Rectangle::Draw()
{
	cout << "No:" << Shape::GetNo() << "    " << "X:" << leftUp->GetX() << "    " << "Y:" << leftUp->GetY() << "    " << "Width:" << GetWidth() << "    " << "Height:" << GetHeight() << endl;
}

//Method to return width value
inline int Rectangle::GetWidth()
{
	return width;
}

//constructor to register in prototype
inline Rectangle::Rectangle() :Shape()
{
	addPrototype(this);
}

//Rectangle constructor overload
inline Rectangle::Rectangle(int no,int x = 0,int y = 0, int width = 1, int height = 1):Shape(),width(width),height(height)
{
	if (leftUp==nullptr)
	{
		leftUp = new Point(x, y);
	}
	else
	{
		delete leftUp;
		leftUp = nullptr;
		leftUp = new Point(x, y);
	}
}

//Rectangle constructor overload
inline Rectangle::Rectangle(int no,const Point& otherLeftUp, int width, int height):Shape(),width(width),height(height)
{
	if (leftUp==nullptr)
	{
		leftUp = new Point(otherLeftUp);
	}
	else
	{
		delete leftUp;
		leftUp = nullptr;
		leftUp = new Point(otherLeftUp);
	}	
}

//Rectangle copy constructor
inline Rectangle::Rectangle(const Rectangle& other):Shape(other),width(other.width),height(other.height)
{
	if(other.leftUp!=nullptr)
	{
		leftUp = new Point(*(other.leftUp));
	}
	else
	{
		leftUp = nullptr;
	}
}

inline Rectangle::Rectangle(int dummy):Shape()
{
	Shape::SetNo(_count++);
}

//Rectangle assignment copy operator overload
inline Rectangle& Rectangle::operator=(const Rectangle& other)
{
	if(this==&other)
	{
		return *this;
	}
	Shape::operator=(other);
	width = other.width;
	height = other.height;
	if(leftUp!=nullptr)
	{
		if(other.leftUp!=nullptr)
		{
			*leftUp = *(other.leftUp);
		}
		else
		{
			delete leftUp;
			leftUp = nullptr;
		}
	}
	else
	{
		if(other.leftUp!=nullptr)
		{
			leftUp = new Point(*(other.leftUp));
		}
	}
	return *this;
}

//Rectangle destructor
inline Rectangle::~Rectangle()
{
	delete leftUp;
	leftUp = nullptr;
}

inline shapeType Rectangle::returnType()
{
	return RECT;
}

inline Shape * Rectangle::clone()
{
	return new Rectangle(1);
}

//Circle constructor overload
inline Circle::Circle(int no,int x, int y, int radius):Shape(),radius(radius)
{
	if(center==nullptr)
	{
		center = new Point(x, y);
	}
	else
	{
		delete center;
		center = nullptr;
		center = new Point(x, y);
	}
}

//Circle constructor overload
inline Circle::Circle(const Point& center, int no, int radius):Shape(),radius(radius)
{
	if(this->center==nullptr)
	{
		this->center = new Point(center);
	}
	else
	{
		delete this->center;
		this->center = nullptr;
		this->center = new Point(center);
	}
}

//Circle copy constructor
inline Circle::Circle(const Circle& other):Shape(other),radius(other.radius)
{
	if(other.center!=nullptr)
	{
		center = new Point(*(other.center));
	}
	else
	{
		center = nullptr;
	}
}

//Circle assignment copy operator overload
inline Circle& Circle::operator=(const Circle& other)
{
	if(this==&other)
	{
		return *this;
	}
	Shape::operator=(other);
	radius = other.radius;
	if(center!=nullptr)
	{
		if(other.center!=nullptr)
		{
			*center = *(other.center);
		}
		else
		{
			delete center;
			center = nullptr;
		}
	}
	else
	{
		if(other.center!=nullptr)
		{
			center = new Point(*(other.center));
		}
	}
	return *this;
}

//Circle destructor
inline Circle::~Circle()
{
	delete center;
	center = nullptr;
}

//Method to return radius value
inline int Circle::GetRadius()
{
	return radius;
}

inline void Circle::Draw()
{
	cout << "No:" << Shape::GetNo() << "    " << "X:" << center->GetX() << "    " << "Y:" << center->GetY() << "    " << "Radius:" << GetRadius() << endl;
}

#endif
