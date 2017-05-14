#include"Graph.h"
#include"GUI.h"
#include"Window.h"
#include<iostream>

using namespace std;
using namespace Graph_lib;

//QAQ:
//if you find something wrong with this program, please contact qq1737078184
//thanks

//(x,y)is the start point of the block, order is the repeat times of this function, win is the window which the block is attached
void draw_blocks(double x, double y, double length, int order, Window& win);
//error class
class axis_error{};
class order_error{};
class block_length_error{};

int main()
{	
		try 
		{
			int x = 0;
			int y = 0;
			int length = 0;
			int order = 0;
			cout << "Enter x and y:";
			cin >> x >> y;
			if (x < 0 || y < 0) throw axis_error();
			cout << endl << "Enter the length: ";
			cin >> length;
			if (length < 0) throw block_length_error();				
			cout << endl << "Enter the order:";
			cin >> order;
			if (order < 0) throw order_error();
			//order have to plus 1 because the function needs one more time to meet the requirement of the homework
			order = order + 1;
			Window win(Point(100, 200), 600, 600, "Blocks");
			draw_blocks(x, y, length, order, win);
			return gui_main();
		}
		catch (axis_error) { cerr << "x and y must be greater than zero" << endl; }
		catch (block_length_error) { cerr << "the length must be greater than zero" << endl; }
		catch (order_error) { cerr << "order must be greater than zero" << endl; }
		
}

void draw_blocks(double x, double y, double length, int order, Window & win)
{
	if (order == 0) return;
	else
	{	
		//creator a new block
		Point p1(x, y);
		Point p2(x + length, y + length);
		Rectangle *block=new Rectangle(p1,p2);
		win.attach(*block);
		//
		order--;
		//draw four small blocks inside		
		for (int i = 0; i < 4; i++)
		{				
			draw_blocks(x + length / 4 * (3 - i), y + length / 4 * i, length / 4, order, win);			
		}		
	}
}
