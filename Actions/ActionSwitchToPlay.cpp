#include "ActionSwitchToPlay.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"


ActionSwitchToPlay::ActionSwitchToPlay(ApplicationManager* pApp) :Action(pApp)
{}


void ActionSwitchToPlay::Execute()
{
	GUI* pGUI = pManager->GetGUI();

	pGUI->ClearToolBar();

	pGUI->CreatePlayToolBar();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Welcome to play mode!");
}