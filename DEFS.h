#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,      //Draw a Line
	DRAW_SQUARE,	//Draw a Square
	DRAW_RECT,      //Draw a RECT
	DRAW_TRIA,      //Draw a TRIA
	DRAW_ELPS,		//Draw an Ellipse
	DRAW_HEX,     //Draw a Hexagon
	DRAW_SLCT, // Select
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	RESIZE,			//Resize a figure(s)
	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	UNDO,
	REDO,
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	//Afnan Resize v02
	BACK1,
	HALF,
	QUARTER,
	DOUBLE1,
	QUADRUPLE,
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	//--- Sohaila ---
	TO_DRAW,		//Switch interface to Draw mode
	SWITCH_PLAY,	//Switch interface to Play mode

	// for play mode
	TO_PICK_TYPE,		//to selecte figure by type
	TO_PICK_FILL,		//to selecte figure by fill
	TO_PICK_TYPE_FILL,  //to selecte figure by fill and type

	///TODO: Add more action types (if needed)
};
enum figureTypes // The typ of each figure to be used in save operation
{	LINE,
	SQR,
	RECTANGLE,
	TRIANGLE,
	ELLIPSE,
	HEXAGON
};
struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif