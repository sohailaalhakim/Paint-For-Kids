#include "ActionAddRect.h"

#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "..\Figures\CRect.h";

ActionAddRect::ActionAddRect(ApplicationManager * pApp) :Action(pApp) {}

//Execute the action
void ActionAddRect::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();


	GfxInfo RectGfxInfo;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pGUI->getCrntDrawColor();
	if (UI.isFilled == 1) {
		RectGfxInfo.isFilled = true;
	}
	else {
		RectGfxInfo.isFilled = false;
	}
	RectGfxInfo.FillClr = pGUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pGUI->getCrntPenWidth();


	//Step 1 - Read Rect data from the user

	pGUI->PrintMessage("New Rect: Click at the point of Top-Left Corner");

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

	pGUI->PrintMessage("New Rect: Click at the point of Bottom-Right Corner");
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


	//Step 3 - Create a Rect with the parameters read from the user
	CRect* R = new CRect(P1, P2, RectGfxInfo);

	//Step 4 - Add the Rect to the list of figures
	pManager->AddFigure(R);

	pGUI->PrintMessage(R->PrintInfo(pGUI));

	//ahmed
	pManager->setLastSaveState(false);
}
