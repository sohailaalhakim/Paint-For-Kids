#include "ActionAddElips.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CElips.h";

ActionAddElips::ActionAddElips(ApplicationManager* pApp) :Action(pApp) {}

//Execute the action
void ActionAddElips::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo ElpsGfxInfo;
	//get drawing, filling colors and pen width from the interface
	ElpsGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	if (UI.isFilled == 1) {
		ElpsGfxInfo.isFilled = true;
	}
	else {
		ElpsGfxInfo.isFilled = false;
	}
	ElpsGfxInfo.FillClr = pGUI->getCrntFillColor();
	ElpsGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Elipse data from the user

	pGUI->PrintMessage("New Elips: Click at the first point");

	//Read 1st point and store in point P1
	pGUI->GetPointClicked(P1.x, P1.y);
	if (P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = 0;
		pGUI->PrintMessage("Please, Choose a valid place.You can only draw in your drawing area");
		while (!flag)
		{
			pGUI->GetPointClicked(P1.x, P1.y);
			if (!(P1.y < UI.StatusBarHeight || P1.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}

	}

	pGUI->PrintMessage("New Elips: Click at the second point");

	//Read 2nd point and store in point P2
	pGUI->GetPointClicked(P2.x, P2.y);

	if (P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = 0;
		pGUI->PrintMessage("Please, Choose a valid place.You can only draw in your drawing area");
		while (!flag)
		{
			pGUI->GetPointClicked(P2.x, P2.y);
			if (!(P2.y < UI.StatusBarHeight || P2.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}

	}

	pGUI->ClearStatusBar();


	//Step 3 - Create a Elipse with the parameters read from the user
	CElips* R = new CElips(P1, P2, ElpsGfxInfo);

	//Step 4 - Add the Elipse to the list of figures
	pManager->AddFigure(R);
	//ZIENAB
	pGUI->PrintMessage(R->PrintInfo(pGUI));

	//ahmed
	pManager->setLastSaveState(false);
}
