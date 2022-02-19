#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <iostream>
#include <string>

//g++ drill13.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o drill13 `fltk-config --ldflags --use-images`
using namespace Graph_lib;

int main()
{
	try
	{
		//ablak
		Point p1 {100,100};
		Simple_window win{p1,800,1000,"My window"};
		win.wait_for_button();
		
		//grid
		int x_size = win.x_max(); // get the size of our window
		int y_size = win.y_max()-200;
		int x_grid = 100;
		int y_grid = 100;
		Lines grid;
		for (int x=x_grid; x<x_size; x+=x_grid)
			grid.add(Point{x,0},Point{x,y_size}); // vertical line
		for (int y = y_grid; y<=y_size; y+=y_grid)
			grid.add(Point{0,y},Point{x_size,y}); // horizontal line
		win.attach(grid);
		win.wait_for_button();
		
		//piros négyszögek
		Vector_ref<Rectangle>rects;
		for (int i=0; i<=7;i++)
		{
			rects.push_back(new Rectangle {Point{i*100,i*100},100,100});
			rects[i].set_fill_color(Color::red);
			win.attach(rects[i]);
		}
		win.wait_for_button();
		
		//kép
		Image badge1 {Point{0,400},"badge.jpg"};
		Image badge2 {Point{200,600},"badge.jpg"};
		Image badge3 {Point{200,400},"badge.jpg"};
		Image badge4 {Point{0,600},"badge.jpg"};
		badge1.set_mask(Point{0,0},200,200);
		badge2.set_mask(Point{200,200},200,200);
		badge3.set_mask(Point{200,0},200,200);
		badge4.set_mask(Point{0,200},200,200);
		win.attach(badge1);
		win.attach(badge2);
		win.attach(badge3);
		win.attach(badge4);
		win.wait_for_button();
		
		//square to square
		
		int x=0;
		int y=0;
		while(true)
		{
			Image doge {Point{x,y},"doge.jpg"};
			doge.set_mask(Point{0,0},100,100);
			win.attach(doge);
			x+=100;
			if(x==x_size)
			{
			x=0;
			y+=100;
			}
			if(y==y_size)
			y=0;
			win.wait_for_button();
			
			
		}
		



	}
	catch(exception& e) 
	{
	cerr<<"exception: "<<e.what()<<'\n';
	return 1;
	
	
	}
	catch(...) {
	cerr<<"error\n";
	return 2;
	}
}
