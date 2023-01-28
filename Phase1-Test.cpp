#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{

	Point P;
	Point P2;

	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();

	//----------------------------------------------------------------------------------------------------



		//TODO: Add code to draw different Connectors here

		//TODO: Add code here to 
		// 1- Read a string from the user and print it

		// 2- Read a double value from the user and print it


	ActionType ActType;

	do
	{
		ActType = pIn->GetUserAction();
		string Read;
		string Write;
		string SA;
		string VA;
		string SO;
		string Cond;
		switch (ActType)
		{
		case START:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	//Wait for any click

			if (P.y >= UI.TlBrWdth) {
				pOut->DrawStrt_end(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "START", 0);

			}
			break;

		case END:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	//Wait for any click

			if (P.y >= UI.TlBrWdth) {
				pOut->DrawStrt_end(P, UI.ASSGN_WDTH, UI.ASSGN_HI, "END", 0);
			}
			break;

		case READ:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	     //Wait for any click
			if (P.y >= UI.TlBrWdth) {
				pOut->DrawRd_Wt(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ", 0);	     //draw the shape empty first
				pOut->PrintStatusMessage("Please enter the value of the X variable: ");
				Read = pIn->GetString(pOut);
				pOut->DrawRd_Wt(P, UI.ASSGN_WDTH, UI.ASSGN_HI, Read, 0);		//fill it with sentence from user
			}
			break;

		case WRITE:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	//Wait for any click

			if (P.y >= UI.TlBrWdth) {
				pOut->DrawRd_Wt(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ", 0);		//draw the shape empty first
				pOut->PrintStatusMessage("Please enter the message to be printed: ");
				Write = pIn->GetString(pOut);
				pOut->DrawRd_Wt(P, UI.ASSGN_WDTH, UI.ASSGN_HI, Write, 0);     //fill it with sentence from user
			}
			break;

		case ADD_SMPL_ASSIGN:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	//Wait for any click

			if (P.y >= UI.TlBrWdth) {
				pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ");
				pOut->PrintStatusMessage("Enter the simple assignment statement:");
				SA = to_string(pIn->GetValue(pOut));
				if (stod(SA)) {
					pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, SA);
				}
				else {
					SA = pIn->GetString(pOut);
					pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, SA);
				}
			}
			break;


		case ADD_VAR_ASSIGN:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	//Wait for any click

			if (P.y >= UI.TlBrWdth) {
				pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ");
				pOut->PrintStatusMessage("Enter the variable assignment statement:");
				VA = pIn->GetString(pOut);
				pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, VA);
			}
			break;

		case ADD_SINGLE_OPERATOR:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	//Wait for any click

			if (P.y >= UI.TlBrWdth) {
				pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, " ");
				pOut->PrintStatusMessage("Enter a statement with single operator:");
				SO = pIn->GetString(pOut);
				pOut->DrawAssign(P, UI.ASSGN_WDTH, UI.ASSGN_HI, SO);
			}
			break;

		case ADD_CONDITION:
			pOut->DesignToolBarSelection(ActType);
			pIn->GetPointClicked(P);	//Wait for any click

			if (P.y >= UI.TlBrWdth) {
				pOut->DrawConditionalStat(P, UI.ASSGN_WDTH, UI.ASSGN_HI + 20, " ");
				pOut->PrintStatusMessage("Enter the Condition:");
				Cond = pIn->GetString(pOut);
				pOut->DrawConditionalStat(P, UI.ASSGN_WDTH, UI.ASSGN_HI + 20, Cond);
			}
			break;

		case ADD_CONNECTOR:
			pOut->DesignToolBarSelection(ActType);

			pIn->GetPointClicked(P);	//Wait for any click
			if (P.y >= UI.TlBrWdth) {
				pOut->PrintStatusMessage("Select the second node to connect");
				pIn->GetPointClicked(P2);
				pOut->DrawConnector(P, P2, false);
			}

			break;

		case EDIT_STAT:
			pOut->DesignToolBarSelection(ActType);
			break;

		case ADD_COMMENT:
			pOut->DesignToolBarSelection(ActType);
			break;

		case SELECT:
			pOut->DesignToolBarSelection(ActType);
			break;

		case LOAD:
			pOut->DesignToolBarSelection(ActType);
			break;

		case COPY:
			pOut->DesignToolBarSelection(ActType);
			break;

		case CUT:
			pOut->DesignToolBarSelection(ActType);
			break;

		case UNDO:
			pOut->DesignToolBarSelection(ActType);
			break;

		case REDO:
			pOut->DesignToolBarSelection(ActType);
			break;

		case DEL:
			pOut->DesignToolBarSelection(ActType);
			break;

		case MOVE:
			pOut->DesignToolBarSelection(ActType);
			break;

		case ZOOM:
			pOut->DesignToolBarSelection(ActType);
			break;

		case SAVE:
			pOut->DesignToolBarSelection(ActType);
			break;

		case EXIT:
			break;

		case STATUS:
			pOut->PrintStatusMessage("Action: a click on the Status Bar, Click anywhere");
			break;

		case DSN_TOOL:
			pOut->PrintStatusMessage("Action: a click on the Design Tool Bar, Click anywhere");
			break;

		case SIM_MODE:
			pOut->PrintStatusMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CreateSimulationToolBar();
			break;

		case DSN_MODE:
			pOut->PrintStatusMessage("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CreateDesignToolBar();
			break;

		case VERIFY:
			pOut->PrintStatusMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->SimToolBarSelection(ActType);
			break;

		case RUN:
			pOut->PrintStatusMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->SimToolBarSelection(ActType);
			break;

		case STP_STP:
			pOut->PrintStatusMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->SimToolBarSelection(ActType);
			break;

		case EXPORT_CODE:
			pOut->PrintStatusMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->SimToolBarSelection(ActType);
			break;

		case SAVE_CODE:
			pOut->PrintStatusMessage("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->SimToolBarSelection(ActType);
			break;
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintStatusMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(P);


	delete pIn;
	delete pOut;
	return 0;
}