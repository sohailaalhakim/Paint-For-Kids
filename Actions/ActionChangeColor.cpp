#include "ActionChangeColor.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

//Todo:: Sohaile ->


ActionChangeColor::ActionChangeColor(ApplicationManager* pApp, ChangeColorFun* CurrentAction) :
	Action(pApp), SelectedFun(CurrentAction)
{}

//Execute the action
void ActionChangeColor::Execute()
{
	switch (*SelectedFun)
	{
	case BORDER_SHAPE_FUN:
		return ChangeBorderShapeColor();
		break;
	case FILLED_SHAPE_FUN:
		return ChangeFilledShapeColor();
		break;
	case BACK_GROUND_FUN:
		return ChangeBackGroundColor();
		break;
	}

	//ahmed
	pManager->setLastSaveState(false);
}
//Execute Change Border Shape Color
void ActionChangeColor::ChangeBorderShapeColor()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Pick Border Shape Color ..");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();
	if (pManager->AnySelected()) {
		pManager->changeFigDrawColor(P1);
	}
	else {
		pGUI->changeCrntDrawColor(P1);
	}
}
//Execute Change Filled Shape Color
void ActionChangeColor::ChangeFilledShapeColor()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Pick Filled Shape Color ..");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();
	if (pManager->AnySelected()) {
		pManager->changeFigFillColor(P1);
	}
	else {
		pGUI->changeCrntFillColor(P1);
	}
}
//Execute Change Back-Ground Color
void ActionChangeColor::ChangeBackGroundColor()
{
	Point P1;
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("Pick Back-Ground Color ..");
	pGUI->GetPointClicked(P1.x, P1.y);
	pGUI->ClearStatusBar();
	pGUI->changeCrntBackGroungColor(P1);
}
