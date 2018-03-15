#pragma once

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
	Rectangle_Class(const Rectangle_Class &rect) { cout << "Copy Constructor called" << endl; }
	//Assignment Operator
	Rectangle_Class& operator = (const Rectangle_Class &rect) { cout << "Assignment Operator called" << endl; return *this; }

	//Setters
	void setRectangleSize(float, float);
	void setRectanglePos(float, float);

	//Auxiliar Collision Functions
	bool isPointInside(Point2D);
	bool isRectInside(Rectangle_Class);
};