#ifndef DEFS_H
#define DEFS_H

//This file contais some global constants and definitions to be used in the project.

enum ActionType //The actions supported (you can add more if needed)
{
	START,
	END,
	READ,
	WRITE,
	ADD_SMPL_ASSIGN,//Add simple assignment statement
	ADD_VAR_ASSIGN,	//Add variable assignment statement
	ADD_SINGLE_OPERATOR,
	ADD_CONDITION, //Add a conditional statement (for if and while-loop statements)
	ADD_CONNECTOR, //Add a connector between two statements
	EDIT_STAT,	//Edit a statement
	ADD_COMMENT,
	SELECT,		//Select a statement, a connector

	LOAD,		//Load a graph from a file
	COPY,
	CUT,
	UNDO,
	REDO,
	DEL,		//Delete a figure(s)
	MOVE,		//Move a figure(s)
//	RESIZE,		//Resize a figure(s)
	ZOOM,

	SAVE,		//Save the whole graph to a file

	EXIT,		//Exit the application
	STATUS,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar
	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to simulatiom mode
	VERIFY,
	RUN,
	STP_STP,
	EXPORT_CODE,
	SAVE_CODE,

};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};

enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	ITM_START,
	ITM_END,
	ITM_READ,
	ITM_WRITE,
	ITM_SMPL_ASSIGN,//Add simple assignment statement
	ITM_VAR_ASSIGN,	//Add variable assignment statement
	ITM_SINGLE_OPERATOR,
	ITM_CONDITION, //Add a conditional statement (for if and while-loop statements)
	ITM_CONNECTOR, //Add a connector between two statements
	ITM_EDIT_STAT,	//Edit a statement
	ITM_COMMENT,
	ITM_SELECT,		//Select a statement, a connector

	ITM_LOAD,		//Load a graph from a file
	ITM_COPY,
	ITM_CUT,
	ITM_UNDO,
	ITM_REDO,
	ITM_DEL,		//Delete a figure(s)
	ITM_MOVE,		//Move a figure(s)
//	RESIZE,		//Resize a figure(s)
	ITM_ZOOM,

	ITM_SAVE,		//Save the whole graph to a file
	ITM_NULL,
	ITM_SIMUL,
	ITM_SIMUL2,
	ITM_NULL3,
	ITM_EXIT,
	ITM_EXIT2,		//Exit the application

	//Note: Items are ordered here as they appear in menu
	//If you change the menu items order, change the order here too

	
	ITM_DSN_CNT		//no. of design menu items ==> This should be the last line in this enum
	
};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_VERIFY,
	ITM_RUN,	//Run
	ITM_STP,	//Step by step
	ITM_CODE,
	ITM_SSAVE,
	
	//TODO:Add more items names here
	
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum
	
};




#ifndef NULL
#define NULL 0
#endif

#endif