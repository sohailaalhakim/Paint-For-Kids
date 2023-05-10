#include "SendBack.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CFigure.h"

// Constructor of Send to Bacck Class
SENDTOBACK::SENDTOBACK(ApplicationManager* pApp) :Action(pApp)
{}

//Read Function to Read Ellipse parameters
void SENDTOBACK::ReadActionParameters()
{}

//Execution Function For Send To Back Class
void SENDTOBACK::Execute()
{
	Point P1;

	GUI* pGUI = pManager->GetGUI();
	pGUI->GetPointClicked(P1.x, P1.y);
	CFigure* chosen = pManager->GetFigure(P1.x, P1.y);

	if ((chosen != NULL) && (chosen->IsSelected()))
	{
		pManager->Send_Back(chosen);
		pGUI->PrintMessage("Sent to Back");
	}
	else
		pGUI->PrintMessage("Please, Select a figure");

}
