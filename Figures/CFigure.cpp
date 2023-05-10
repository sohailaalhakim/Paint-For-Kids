#include "CFigure.h"
CFigure::CFigure()
{
	figHidden = false;
}
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	figHidden = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}
//--- Sohaila ---
// For Play Mood 
//Hides Figures
void CFigure::Hide()
{
	figHidden = true;
}
//Shows Figures
void CFigure::Show()
{
	figHidden = false;
}
//Gives Current Status 
bool CFigure::HiddenStatus() const   // sohaila 
{
	return figHidden;
}
//Sends color info to playmode   
GfxInfo CFigure::GetGfxInfo()
{
	return FigGfxInfo;
}


