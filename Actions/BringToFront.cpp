#include "BringToFront.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CFigure.h"

// Constructor of Bring to front Class
BRINGTOFRONT::BRINGTOFRONT(ApplicationManager* pApp) :Action(pApp)
{}

void BRINGTOFRONT::ReadActionParameters()
{}

//Execution Function For Bring To Front Class
void BRINGTOFRONT::Execute()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();
	pGUI->GetPointClicked(P1.x, P1.y);
	CFigure* chosenFIG = pManager->GetFigure(P1.x, P1.y);

	if ((chosenFIG != NULL) && (chosenFIG->IsSelected()))
	{
		pManager->Bring_Front(chosenFIG);
		pGUI->PrintMessage("Brought to Front");

	}
	else
		pGUI->PrintMessage("Please,	First Select a figure");

}
