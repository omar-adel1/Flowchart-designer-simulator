#ifndef OUPTUT_H
#define OUPTUT_H

#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int);
	void CreateDesignToolBar();	//Tool bar of the design mode
	void DesignToolBarSelection(ActionType ActType);
	void CreateSimulationToolBar();//Tool bar of the simulation mode
	void SimToolBarSelection(ActionType ActType);

	void CreateStatusBar();

	Input* CreateInput(); //creates a pointer to the Input object	
	void ClearStatusBar();	//Clears the status bar
	void ClearDrawArea();	//Clears the drawing area
	void ClearInputBox();

	// -- Statements Drawing Functions
	void DrawStrt_end(Point left, int width, int height, string Text, bool Selected = true);
	void DrawRd_Wt(Point right, int  width, int  height, string Text, bool Selected=true);
	void DrawAssign(Point Left, int width, int height, string Text, bool Selected = false);
	void DrawConditionalStat(Point right, int width, int height, string Text, bool Selected = false);

	void DrawConnector(Point initial, Point end, bool Selected = false);



	void PrintStatusMessage(string msg);	//Prints a message on Status bar
	void PrintInputMessage(string msg);		//prints what the user enters in the input txt box

	~Output();
};

#endif