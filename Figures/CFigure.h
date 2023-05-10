#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\GUI.h"
#include<fstream>
//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	//Turky
	int figureType;
	/// Add more parameters if needed.
		// --- Sohaila --- 
	//For Play mood
	bool figHidden;

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	void SetSelected(bool );	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void DrawMe(GUI*) const  = 0 ;		//Draw the figure
	virtual bool isInside(int, int) = 0;        //Select Shape
	virtual void SetID(int id) = 0;

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	//virtual void Rotate() = 0;	//Rotate the figure
	//virtual void Resize() = 0;	//Resize the figure
	//virtual void Move() = 0;		//Move the figure
	virtual void Resize(GUI* pGUI, float size) = 0;	//Resize the figure Afnan
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual string PrintInfo(GUI* pOut)const = 0;	//print all figure info on the status bar

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

		//--- Sohaila --- 
   // For Play Mood
	void Hide();
	void Show();
	// sohaila 
	bool HiddenStatus() const;			//Shows Current Figure status in playmode.
	GfxInfo CFigure::GetGfxInfo();
};

#endif