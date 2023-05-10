#include "ActionAddTria.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CTria.h";

ActionAddTria::ActionAddTria(ApplicationManager* pApp) :Action(pApp) {}

//Execute the action
void ActionAddTria::Execute()
{
	Point P1, P2, p3;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo TriGfxInfo;
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	if (UI.isFilled == 1) {
		TriGfxInfo.isFilled = true;
	}
	else {
		TriGfxInfo.isFilled = false;
	}
	TriGfxInfo.FillClr = pGUI->getCrntFillColor();
	TriGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Triangle data from the user

	pGUI->PrintMessage("New Triangle: Click at the first point");
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

	pGUI->PrintMessage("New Triangle: Click at the second point");
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

	pGUI->PrintMessage("New Triangle: Click at the third point");
	//Read 3nd point and store in point P3
	pGUI->GetPointClicked(p3.x, p3.y);

	if (p3.y < UI.StatusBarHeight || p3.y > UI.height - UI.StatusBarHeight)
	{
		bool flag = 0;
		pGUI->PrintMessage("Please, Choose a valid place.You can only draw in your drawing area");
		while (!flag)
		{
			pGUI->GetPointClicked(p3.x, p3.y);
			if (!(p3.y < UI.StatusBarHeight || p3.y > UI.height - UI.StatusBarHeight))
				flag = 1;
		}

	}

	pGUI->ClearStatusBar();


	//Step 3 - Create a Triangle with the parameters read from the user
	CTria* R = new CTria(P1, P2, p3, TriGfxInfo);

	//Step 4 - Add the Triangle to the list of figures
	pManager->AddFigure(R);

	//Zienab
	pGUI->PrintMessage(R->PrintInfo(pGUI));

	//ahmed
	pManager->setLastSaveState(false);
}
