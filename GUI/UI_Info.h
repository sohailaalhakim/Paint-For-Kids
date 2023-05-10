#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY,	//Playing mode
	MODE_SIZE,  // Afnan Resize  v02
};
enum SizeMenuItem // The items of size Afnan Resize v02
{
	ITM_BACK1,
	ITM_QUARTER,
	ITM_HALF,
	ITM_DOUBLE,
	ITM_QUADRUPLE,

	SIZE_ITM_COUNT
};
enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_LINE,        //Line item in menu
	ITM_SQUR,		//Square item in menu
	ITM_RECT,		//RECT item in menu
	ITM_TRIA,       //TRIA item in menu
	ITM_ELPS,		//Ellipse item in menu
	// Turky
	ITM_HEX,
	BORDER_SHAPE,
	FILLED_SHAPE,
	BACK_GROUND,
	ITM_SELECT,
	ITM_DELETE,
	ITM_RESIZE,
	ITM_SEND_BACK,
	ITM_BRINGTOFRONT,
	ITM_SAVE,
	ITM_OPEN,
	//--- Sohaila ---
	ITM_TO_PLAY,
	//TODO: Add more items names here
	ALL_COLORS,
	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	// icon to swtich between draw mode and play mode
	ITM_SELECT_TYPE,		// to selecte figure by type
	ITM_SELECT_FILL,		// to selecte figure by fill
	ITM_SELECT_Type_FILL,	// to selecte figure by fill and type
	ITM_SWICH_DRAW,			// switch item in menu
	ITM_EXIT2,				//Exit item

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	//Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	int isFilled; 
	/// Add more members if needed
	
}UI;	//create a global object UI

#endif