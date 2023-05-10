#ifndef GUI_H
#define GUI_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"


//This class is responsible for Grphical User Interface handling
//All user input and program outputs MUST be done through this class
//No other class is allowed to perform direct i/o
class GUI	
{
public:	
	window* pWind;	//Pointer to the Graphics Window
public:
	GUI();	
	~GUI();	
	window* CreateWind(int, int, int , int) const; //creates the application window

	/////////// Input Functoinality  /////////////////
	void GetPointClicked(int &x, int &y) const;//Get coordinate where user clicks
	string GetSrting() const ;	 //Returns a string entered by the user
	ActionType MapInputToActionType() const; //Read the user click and map to an action


	/////////// Output Functoinality  ////////////////
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void CreateSizeBar() const; // create Size bar Afnan
	void CreateToolBar() const; //create tool bar for size Afnan
	void ClearToolBar() const;
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;  //Draw a Line
	void DrawSquare(Point P1, int length, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a Square
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a Rect
	void DrawTria(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const;  //Draw a Tria
	void DrawElips(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const;  //Draw a Ellipse
	void DrawHexagon(Point P1, int length, int height, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a Hexagon


	///TODO: Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	//Todo:: Sohaile ->
	void changeCrntDrawColor(Point p) const;	//change current drwawing color
	color getCrntFillColor() const;	//get current filling color

	//Todo:: Sohaile ->
	void changeCrntFillColor(Point p) const;	//change current filling color

		//Todo:: Sohaile ->
	void changeCrntBackGroungColor(Point p) const;	//change current filling color
	//Turky
	color getBkGrndColor() const;	//get current Background color
	void setCrntDrawColor(color c);
	void setCrntFillColor(color c);
	void setBkGrndColor(color c);

	int getCrntPenWidth() const;		//get current pen width

};


#endif