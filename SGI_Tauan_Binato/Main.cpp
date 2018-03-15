
#include <iostream>
#include<stdio.h>
using namespace std;

/* Creating a Point2D Class*/
class Point2D
{
public:
	float x, y;
	Point2D(float _x, float _y) { x = _x; y = _y; }
};


/* Creating Rectangle Class */
class Rectangle_Class
{
	//Default private variables.
	float width, height;
	float pos_x, pos_y;

	
public:
	//Constructor
	Rectangle_Class(float x, float y, float w, float h);
	//Cpy Constructor
	Rectangle_Class(const Rectangle_Class &rect) { cout << "Copy Constructor called" <<endl; }
	//Assignment Operator
	Rectangle_Class& operator = (const Rectangle_Class &rect) { cout << "Assignment Operator called" << endl; return *this; }

	//Setters
	void setRectangleSize(float, float);
	void setRectanglePos(float, float);

	//Auxiliar Collision Functions
	bool isPointInside(Point2D);
	bool isRectInside(Rectangle_Class);
};


/*Constructor implementations*/
Rectangle_Class::Rectangle_Class(float x, float y , float w , float h)
{
	cout << "Constructor called" << endl;
	setRectangleSize(w, h);
	setRectanglePos(x, y);
}


/*Methods implementations*/
void Rectangle_Class::setRectangleSize(float w, float h)
{
	width = w;
	height = h;
	return;
}
void Rectangle_Class::setRectanglePos(float x, float y)
{
	pos_x = x;
	pos_y = y;
	return;
}

bool Rectangle_Class::isPointInside(Point2D p)
{
	//Checking for horizontal
	if (p.x >= pos_x && p.x <= pos_x + width)
	{
		//Checking for vertical
		if (p.y >= pos_y && p.y <= pos_y + height)
		{
			cout << "Point inside rectangle detected" << endl;
			return true;
		}
	}
	cout << "Point is not inside rectangle" << endl;
	return false;
}

bool Rectangle_Class::isRectInside(Rectangle_Class rect)

{			//Checking Horizontal and Vertical 
	if (    (pos_x < rect.pos_x + rect.width) && (pos_x + width > rect.pos_x)
		&& (pos_y < rect.pos_y + rect.height) && (pos_y + rect.height > rect.pos_y)   )
		{
			cout << "Rectangle collision detected!" << endl;
			return true;
		}
	cout << "Rectangle collision NOT detected" << endl;
	return false;
}



int main()
{
	/*
	Rectangle_Class rect1(0,0,10,10);
	Rectangle_Class rect2(1, 1, 5, 5);
	rect2 = rect1;
	Rectangle_Class rect3 = rect1;
	*/

	Rectangle_Class rect(1, 1, 5, 5);
	Point2D point(5, 3);
	rect.isPointInside(point);
	Rectangle_Class rect2(4, 5, 5, 5);
	rect.isRectInside(rect2);

	getchar();
	

	return 0;
}