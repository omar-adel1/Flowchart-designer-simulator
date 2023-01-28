#include "Output.h"
Point p;
// this is the constructor of the class OUTPUT where the initial screen appear, just like the setup
Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1100;	// the width of the window that is gonna appear to the user
	UI.height = 700;	// the height of the window that is gonna appear to the user
	UI.wx = 100;		// the x position of where that window is gonna appear to the user on the screen
	UI.wy = 5;			// the y position of there that window is gonna appear to the user on the screen

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StBrWdth = 45;		//status bar width
	UI.TlBrWdth = 70;		//tool bar width
	UI.MnItWdth = 40;		//item width (button width ya3ny)

	//button start = 25, end at TlBrWidth in y direction
	//button start = 7, width = 38 pixel x direction

	UI.DrawClr = BLUE;	//THE SHAPES TO BE DRAWN COLOR
	UI.HiClr = RED;		//HIGHLIGHTED SHAPE COLOR
	UI.MsgClr = BLACK;		//STATUS BAR TEXT COLOR

	UI.ASSGN_WDTH = 150;	// ASSIGNMENT RECT. WIDTH
	UI.ASSGN_HI = 50;		// ASSIGNMENT RECH. HEIGHT

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);	//creates the ui window of dimensions (UI.width, UI.height) at position (UI.wx, UI.wy)

	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");	// title of the window
	pWind->SetPen(PURPLE, 3);		// sets the pen to draw with a purple color and font width of 3. any drawn lines will be drawn using this format.
	CreateDesignToolBar();			//
	CreateStatusBar();				//
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateStatusBar()
{
	pWind->DrawImage("images\\StatusBar.jpg", 0, UI.height - UI.StBrWdth);
	pWind->DrawImage("images\\Input.jpg", 882, 80);
	//pWind->DrawLine(0, UI.height-UI.StBrWdth, UI.width, UI.height-UI.StBrWdth);
	// draws a line starting from position (0, UI.height - UI.status bar width) and ends at (UI.width "the end of the window", UI.height - UI.status bar width "same Y position")
	// this is gonna result in a horizontal straight line)

}
//////////////////////////////////////////////////////////////////////////////////////////

//Draws the Design Menu
void Output::CreateDesignToolBar()
{
	UI.AppMode = DESIGN;	//Design Mode
	int i = 0;	// counter for different screens. In the design mode case, the counter is 0. otherwise, simulation mode would be 1 for example.

	//fill the tool bar 
	// this function uses ready made images to display, instead of drawing basic shapes which will lead to a coding hassle
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.TlBrWdth);

	pWind->DrawImage("images\\DesignToolBar.jpg", 6, 6);
	pWind->DrawImage("images\\Simul.jpg", 890, 25);
	pWind->DrawImage("images\\Exit.jpg", 990, 25);
	//pWind is a pointer of type window
	//inside the DrawImage function, just write the "folder name" \\ "image name", then the X,Y positions
}

void Output::DesignToolBarSelection(ActionType Actype) {
	ActionType ActType2;
	ActType2 = Actype;

	switch (Actype)
	{
	case START:
		pWind->DrawImage("images\\Start.jpg", 6, 6);
		PrintStatusMessage("To Start your flowchart , Click anywhere.");
		break;

	case END:
		pWind->DrawImage("images\\End.jpg", 6, 6);
		PrintStatusMessage("To END your flowchart , Click anywhere.");
		break;

	case READ:
		pWind->DrawImage("images\\Read.jpg", 6, 6);
		PrintStatusMessage("To read an input , Click anywhere.");
		break;

	case WRITE:
		pWind->DrawImage("images\\Write.jpg", 6, 6);
		PrintStatusMessage("To write an output on the screen , Click anywhere.");
		break;

	case ADD_SMPL_ASSIGN:
		pWind->DrawImage("images\\SmplAssign.jpg", 6, 6);
		PrintStatusMessage("To add simple assignment statement , Click anywhere.");
		break;

	case ADD_VAR_ASSIGN:
		pWind->DrawImage("images\\VarAssign.jpg", 6, 6);
		PrintStatusMessage("To add variable assignment statement , Click anywhere.");
		break;

	case ADD_SINGLE_OPERATOR:
		pWind->DrawImage("images\\OpAssign.jpg", 6, 6);
		PrintStatusMessage("To add operational assignment statement , Click anywhere.");
		break;

	case ADD_CONDITION:
		pWind->DrawImage("images\\If.jpg", 6, 6);
		PrintStatusMessage("To add conditional statement , Click anywhere.");
		break;

	case ADD_CONNECTOR:
		pWind->DrawImage("images\\Connector.jpg", 6, 6);
		PrintStatusMessage("To add a connector , Click on two shapes to connect.");
		break;

	case EDIT_STAT:
		pWind->DrawImage("images\\Edit.jpg", 6, 6);
		PrintStatusMessage("To edit a statement , Click on the statement.");
		break;

	case ADD_COMMENT:
		pWind->DrawImage("images\\Comment.jpg", 6, 6);
		PrintStatusMessage("To add a comment , Click anywhere.");
		break;

	case SELECT:
		pWind->DrawImage("images\\Cursor.jpg", 6, 6);
		PrintStatusMessage("Click on the Drawing area, Click anywhere.");
		break;

	case LOAD:
		pWind->DrawImage("images\\Open.jpg", 6, 6);
		PrintStatusMessage("Open a file from computer.");
		break;

	case COPY:
		pWind->DrawImage("images\\Copy.jpg", 6, 6);
		PrintStatusMessage("Select an object to copy.");
		break;

	case CUT:
		pWind->DrawImage("images\\Cut.jpg", 6, 6);
		PrintStatusMessage("Select an object to cut.");
		break;

	case UNDO:
		pWind->DrawImage("images\\Undo.jpg", 6, 6);
		PrintStatusMessage("Undoed");
		break;

	case REDO:
		pWind->DrawImage("images\\Redo.jpg", 6, 6);
		PrintStatusMessage("Redoed");
		break;

	case DEL:
		pWind->DrawImage("images\\Delete.jpg", 6, 6);
		PrintStatusMessage("Select an object to delete.");
		break;

	case MOVE:
		pWind->DrawImage("images\\Move.jpg", 6, 6);
		PrintStatusMessage("Select an object to move.");
		break;

	case ZOOM:
		pWind->DrawImage("images\\Zoom.jpg", 6, 6);
		PrintStatusMessage("Zoom: to zoom in left click on the mouse. To zoom out, right click on the mouse.");
		break;

	case SAVE:
		pWind->DrawImage("images\\Save.jpg", 6, 6);
		PrintStatusMessage("Flowchart Saved Successfully.");
		break;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateSimulationToolBar()
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//clr screen
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.TlBrWdth);

	pWind->DrawImage("images\\SimulationToolBar.jpg", 6, 6);
	pWind->DrawImage("images\\Desi.jpg", 890, 25);
	pWind->DrawImage("images\\Exit.jpg", 990, 25);
}

void Output::SimToolBarSelection(ActionType Actype) {
	ActionType ActType2;
	ActType2 = Actype;

	switch (Actype)
	{
	case VERIFY:
		pWind->DrawImage("images\\Verify.jpg", 6, 6);
		PrintStatusMessage("Code Verified, no errors found.");
		break;

	case RUN:
		pWind->DrawImage("images\\Run.jpg", 6, 6);
		PrintStatusMessage("Running the flow chart is in process....");
		break;

	case STP_STP:
		pWind->DrawImage("images\\F10.jpg", 6, 6);
		PrintStatusMessage("To debug your chart, move with the up and down arrows.");
		break;

	case EXPORT_CODE:
		pWind->DrawImage("images\\ExportC.jpg", 6, 6);
		PrintStatusMessage("Code Exported Successfully.");
		break;

	case SAVE_CODE:
		pWind->DrawImage("images\\SimulSave.jpg", 6, 6);
		PrintStatusMessage("Code Saved Successfully.");
		break;

	}
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearStatusBar()
{
	pWind->DrawImage("images\\StatusBar.jpg", 0, UI.height - UI.StBrWdth);

	//Clear Status bar by overwriting the image
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearInputBox() {
	pWind->DrawImage("images\\Input.jpg", 882, 80);
}


//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea()
{
	pWind->SetPen(WHITE, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.TlBrWdth + 5, UI.width, UI.height - UI.StBrWdth);

	// or we can re-upload the background image 

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintStatusMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar for no overloading

	pWind->SetPen(UI.MsgClr, 50);		// to set the text color
	pWind->SetFont(16, BOLD, BY_NAME, "Arial");   // to set the font size and type by name
	pWind->DrawString(10, UI.height - (int)(UI.StBrWdth - 8), msg);	// draw the text at X,Y
}

void Output::PrintInputMessage(string msg)	//Prints a message on status bar
{
	ClearInputBox();	//First clear the status bar for no overloading

	pWind->SetPen(UI.MsgClr, 50);		// to set the text color
	pWind->SetFont(16, BOLD, BY_NAME, "Arial");   // to set the font size and type by name
	pWind->DrawString(900, 118, msg);	// draw the text at X,Y
}

//======================================================================================//
//								Statements Drawing Functions								//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)	//LEFT stands for left top point
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);

}
//////////////////////////////////////////////////////////////////////////////////////////

//Draw start and end statement 
void Output::DrawStrt_end(Point left, int width, int height, string Text, bool Selected) {
	int x, y;
	pWind->GetStringSize(x, y, Text);
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HiClr, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawClr, 3);	//use normal color
	//Draw the Ellipse
	pWind->DrawEllipse(left.x, left.y, left.x + 2 * 40, left.y + 2 * 20, FILLED);
	//drawing string
	pWind->SetPen(BLACK);
	pWind->DrawString(left.x + 40 - x / 2, left.y + 20 - y / 2, Text);
}
//Draw read and write  statement 
void Output::DrawRd_Wt(Point right, int  width, int  height, string Text, bool Selected) {

	//setting the parallelogram points
	int x_points[4] = { right.x, right.x - width + 22, right.x - width, right.x - 22 };
	//int x_points[4] = { right.x+22, right.x - width - 22, right.x - width-22, right.x + 22 };
	int y_points[4] = { right.y, right.y, right.y + height, right.y + height };




	// drawing the parallelogram
	if (Selected )
		pWind->SetPen(UI.DrawClr, 3);
	else
		pWind->SetPen(UI.HiClr, 3);
	pWind->DrawPolygon(x_points, y_points, 4, FILLED);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString((right.x - 140) + width / 4, (right.y) + height / 4, Text);
}
//Draw condition statement 
void Output::DrawConditionalStat(Point right, int width, int height, string Text, bool Selected) {

	int x_points[4] = { right.x + 150, (right.x + 150) - width / 2, (right.x + 150) - width, (right.x + 150) - width / 2 };
	int y_points[4] = { (right.y + 35) - height / 2, (right.y + 35), (right.y + 35) - height / 2, (right.y + 35) - height };

	//drawing rhombus highlighted or not
	if (Selected)
		pWind->SetPen(UI.DrawClr, 3);
	else
		pWind->SetPen(UI.HiClr, 3);
	pWind->DrawPolygon(x_points, y_points, 4, FILLED);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString((right.x + 15) + width / 4, (right.y - 25) + height / 4, Text);
}
//Drawing connector
void Output::DrawConnector(Point initial, Point end, bool Selected)
{
	int dis;   // Distance moved from one click to another 
	if (Selected )
		pWind->SetPen(GREEN, 2);    //setting the pen for drawing in normal or highlighted colour
	else
		pWind->SetPen(BLUE, 2);
	if (initial.x == end.x || initial.y == end.y) {      // Checking if it is in the same axis x or y
		pWind->DrawLine(initial.x, initial.y, end.x, end.y);
	}
	else {
		if (initial.x < end.x) {    // Check if the final click is in the right of the first click
			dis = end.x - initial.x;
			pWind->DrawLine(initial.x, initial.y, initial.x + dis, initial.y);     // Print the horizontal line 
			pWind->DrawLine(initial.x + dis, initial.y, initial.x + dis, end.y);   //Start from the end of the horizontal line to the second click
			if (end.y > initial.y) {
				//drawing arrow head
				pWind->DrawLine(initial.x + dis - 8, end.y - 5, initial.x + dis, end.y);
				pWind->DrawLine(initial.x + dis, end.y, initial.x + dis + 8, end.y - 5);
			}
			else {
				//drawing arrow head
                pWind->DrawLine(initial.x + dis - 8, end.y + 5, initial.x + dis, end.y);
				pWind->DrawLine(initial.x + dis, end.y, initial.x + dis + 8, end.y + 5);
			}
		}
		else {
			dis = initial.x - end.x;
			pWind->DrawLine(initial.x, initial.y, initial.x - dis, initial.y);    //Print the horizontal line 
			pWind->DrawLine(initial.x - dis, initial.y, initial.x - dis, end.y);   //Start from the end of the horizontal line to the second click 
			if (end.y > initial.y) {
				//drawing arrow head
				pWind->DrawLine(initial.x - dis + 8, end.y - 5, initial.x - dis, end.y);
				pWind->DrawLine(initial.x - dis, end.y, initial.x - dis - 8, end.y - 5);
			}
			else {
				//drawing arrow head
				pWind->DrawLine(initial.x - dis + 8, end.y + 5, initial.x - dis, end.y);
				pWind->DrawLine(initial.x - dis, end.y, initial.x - dis - 8, end.y + 5);
			}
		}
	}
}

Output::~Output()
{
	delete pWind;
}