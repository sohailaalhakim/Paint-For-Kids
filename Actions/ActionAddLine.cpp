
#include "../Actions/ActionAddLine.h" 
#include "../Figures/CLine.h"
#include "../ApplicationManager.h"
#include "../GUI/GUI.h"


ActionAddLine::ActionAddLine(ApplicationManager* pApp) :Action(pApp) {}

//Execute the action
void ActionAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo LineGfxInfo;
	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	LineGfxInfo.FillClr = pGUI->getCrntFillColor();
	LineGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read LINE data from the user

	pGUI->PrintMessage("New Line: Click at the first point");

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

	pGUI->PrintMessage("New Line: Click at the second point");

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


	//Step 3 - Create a LINE with the parameters read from the user
	CLine* R = new CLine(P1, P2, LineGfxInfo);

	//Step 4 - Add the LINE to the list of figures
	pManager->AddFigure(R);

	//ZIENAB
	pGUI->PrintMessage(R->PrintInfo(pGUI));

	//ahmed
	pManager->setLastSaveState(false);
}
