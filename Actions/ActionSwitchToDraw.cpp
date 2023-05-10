#include "ActionSwitchToDraw.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"

ActionSwitchToDraw::ActionSwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{}


void ActionSwitchToDraw::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();
	pGUI->PrintMessage("Welcome to Draw mode!");
	pManager->AnySelected();
}