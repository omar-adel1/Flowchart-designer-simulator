#include "Input.h"
#include "Output.h"
#include<iostream>
#include<string>
using namespace std;


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point& P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}


string Input::GetString(Output* pO) const
{
	string Str;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13) {	//ENTER key is pressed
			pO->ClearInputBox();
			return Str;
		}
		if (Key == 8 && Str.size() != 0)	//BackSpace is pressed but this condition is needed in order to not result in a -1 sized array
			Str.resize(Str.size() - 1);
		else
			Str += Key;
		pO->PrintInputMessage(Str);
	}

}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	//TODO: add code to read a double value from the user and assign it to D	
	pO->PrintStatusMessage("Please enter a value ");
	char  Key;
	size_t a;
	int checkDecimalInt = 0;//check that user didn't type two decimal points in the same number
	double D=0;
	string str;
	while (1) {

		pWind->WaitKeyPress(Key);
		if ((Key <= 57 && Key >= 48) || Key == 46 || Key == 8 || Key == 13 || Key == 27 )
			//48-->57 represent{0 , 1 , 2 ..... 9}. 
			//46 represent decimal point.
		{
			if (Key == 46) {
				for (string::iterator it = str.begin(); it != str.end(); ++it) {
					if (*it == '.') {
						checkDecimalInt++;
					}
				}
				if (checkDecimalInt >= 2) {
					pO->PrintStatusMessage("It is not allowed into enter two decimal points ");
					checkDecimalInt = 0;
					continue;
				}

			}
			if (Key == 27)	//ESCAPE key is pressed
				return 0;	//returns nothing as user has cancelled label
			if (Key == 13) {	//ENTER key is pressed
				pO->ClearInputBox();
				return D;
			}
			if (Key == 8) //BackSpace is pressed
			{
				if (str.size() == 0)
				{
					continue;
				}
				str.resize(str.size() - 1);
			}
			else {
				str += Key;
				D = stod(str);
			}
		}
		pO->PrintInputMessage(str);
	}

	//Read a double value from the user
	D = stod(str, &a);
	return D;
	//return the double value
	/*pO->PrintStatusMessage("Please enter a value");
	double D = 0;
	string str;
	str = pWind->GetString;    // here the user will enter the value he want using get string function
	D = stod(str);  // here we will convert the string value to double value*/

}

ActionType Input::GetUserAction() const
{
	//This function reads the position where the user clicks to determine the desired action

	int x, y;
	//clicktype mouseBt;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 25 && y < UI.TlBrWdth && x < 890)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = ((x - 9) / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{

			case ITM_START: return START;
			case ITM_END: return END;
			case ITM_READ: return READ;
			case ITM_WRITE: return WRITE;
			case ITM_SMPL_ASSIGN: return ADD_SMPL_ASSIGN;
			case ITM_VAR_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_SINGLE_OPERATOR: return ADD_SINGLE_OPERATOR;
			case ITM_CONDITION: return ADD_CONDITION;
			case ITM_CONNECTOR: return ADD_CONNECTOR;
			case ITM_EDIT_STAT: return EDIT_STAT;
			case ITM_COMMENT: return ADD_COMMENT;
			case ITM_SELECT: return SELECT;
			case ITM_LOAD: return LOAD;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_DEL: return DEL;
			case ITM_MOVE: return MOVE;
			case ITM_ZOOM: return ZOOM;
			case ITM_SAVE: return SAVE;
			default: return DSN_TOOL;
			}
		}

		if (y >= 25 && y < UI.TlBrWdth && x >= 890 && x < 970)
			return SIM_MODE;

		if (y >= 25 && y < UI.TlBrWdth && x >= 990 && x < 1070)
			return EXIT;

		//[2] User clicks on the drawing area

		if (y >= UI.TlBrWdth && y < UI.height - UI.StBrWdth)
		{
			/*switch (mouseBt) {
			case LEFT_BUTTON:
				break;

			case RIGHT_BUTTON:*/
			return SELECT;	//user want to select/unselect a statement in the flowchart

		//}
		}


		//[3] User clicks on the status bar
		return STATUS;
	}

	else if (UI.AppMode == SIMULATION)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 25 && y < UI.TlBrWdth && x < 210)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = ((x - 9) / UI.MnItWdth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{

			case ITM_VERIFY: return VERIFY;
			case ITM_RUN: return RUN;
			case ITM_STP: return STP_STP;
			case ITM_CODE: return EXPORT_CODE;
			case ITM_SSAVE: return SAVE_CODE;
			}
		}

		if (y >= 25 && y < UI.TlBrWdth && x >= 890 && x < 970)
			return DSN_MODE;

		if (y >= 25 && y < UI.TlBrWdth && x >= 990 && x < 1070)
			return EXIT;


		return STATUS;
	}
}
Input::~Input()
{
}