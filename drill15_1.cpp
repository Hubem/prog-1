//g++ drill15_1.cpp ./GUI/Graph.cpp ./GUI/Window.cpp ./GUI/GUI.cpp ./GUI/Simple_window.cpp -o drill15_1 `fltk-config --ldflags --use-images`

#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"
#include <iostream>
#include <string>

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) { return x/2;}
double square(double x) { return x*x;}
double sloping_cos(double x) {return slope(x)+cos(x);}


int main()
{
	try
	{
		int xmax =600; int ymax =600;
		Point p1 {100,100};
		Simple_window win{p1,xmax,ymax,"Function Graphs"};
		win.wait_for_button();
		
		
		
		Point origo{xmax/2,ymax/2};
		int xlength=400;
		int ylength=400;
		
		
		
		Axis x{Axis::x,Point{100,ymax/2},xlength,20,"1=20 pixels"};
		x.set_color(Color::red);
		Axis y{Axis::y,Point{xmax/2,ylength+100},ylength,20,"1=20 pixels"};
		y.set_color(Color::red);
		win.attach(x); 
		win.attach(y); 
		
		win.wait_for_button();
		
		Function elso{one,-10,11,origo,400,20,20};
		win.attach(elso);
		win.wait_for_button();
		
		Function masodik{slope,-10,11,origo,400,20,20};
		Text label{Point{100,(ymax/2)+80},"x/2"};
		win.attach(masodik);
		win.attach(label);
		win.wait_for_button();
		
		Function harmadik{square,-10,11,origo,400,20,20};
		win.attach(harmadik);
		win.wait_for_button();
		
		Function negyedik{cos,-10,11,origo,400,20,20};
		negyedik.set_color(Color::blue);
		win.attach(negyedik);
		win.wait_for_button();
		
		Function otodik{sloping_cos,-10,11,origo,400,20,20};
		win.attach(otodik);
		
		
		win.wait_for_button();


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

