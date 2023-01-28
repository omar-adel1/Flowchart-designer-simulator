#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\DEFS.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)
	
	int width, height;	//Window width and height
	int wx, wy;			//Window starting coordinates

	int StBrWdth;		//Status Bar Width
	int TlBrWdth;		//Tool Bar Width
	int MnItWdth;		//Menu Item Width
	
	color DrawClr;		//Drawing color
	color HiClr;		//Highlighting color
	color MsgClr;		//Messages color

	int ASSGN_WDTH;		//Assignment statement default width
	int ASSGN_HI;		//Assignment statement default height
	
}UI;	//create a single global object UI

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0)	//constructor
	{
		x = a;	y = b;
	}
	void p_set(int a, int b)
	{
		x = a;   y = b;
	}
	bool operator!=(Point p)
	{
		if (x != p.x && y != p.y)
			return true;
		else
			return false;
	}

};
enum f_direction
{
	horizontal, vertical
};   //indicator to the direction that the arrow will start with it from the initial point

#endif