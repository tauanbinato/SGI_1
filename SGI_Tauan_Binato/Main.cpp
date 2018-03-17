#include "Header.h"

/*Constructor implementation*/

Rectangle_Class::Rectangle_Class()
{
	cout << "Default constructor called" << endl;
}

Rectangle_Class::Rectangle_Class(float x, float y , float w , float h)
{
	cout << "Constructor called" << endl;
	setRectangleSize(w, h);
	setRectanglePos(x, y);
}

Rectangle_Class::~Rectangle_Class()
{
	cout << "Rectangle Destroyed." << endl;
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
/* End Methods implementations*/


int main()
{
	/* Uncomment this to test diferent types of constructor.
	Rectangle_Class rect1(0,0,10,10);
	Rectangle_Class rect5(1, 1, 5, 5);
	rect5 = rect1;
	Rectangle_Class rect3 (rect1);
	*/

	/*Testing point collision and rectangle collision*/
	Rectangle_Class rect(1, 1, 5, 5);
	Point2D point(5, 3);
	rect.isPointInside(point);
	Rectangle_Class rect2(4, 5, 5, 5);
	rect.isRectInside(rect2);

	auto myRectangle = unique_ptr<Rectangle_Class>(new Rectangle_Class(1,1,2,2));
	auto myRectangle2 = shared_ptr<Rectangle_Class>(new Rectangle_Class(1, 1, 2, 2));
	

	cout << myRectangle2.use_count() << endl;

	getchar(); // Used to hold console.
	

	return 0;
}