#include "ActionExit.h"
#include "ActionSave.h"
#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "iostream"
ActionExit::ActionExit(ApplicationManager* pApp) :Action(pApp)
{
}

//Execute the action
void ActionExit::Execute()
{

	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->PrintMessage("New Square: Click at first point");
	pGUI->PrintMessage("New Square: Click at second point");
	pGUI->ClearStatusBar();


	if (!pManager->getLastSaveState()) {
		int msgboxID = MessageBoxW(
			NULL,
			(LPCWSTR)L"Do you want to save last changes ?\n",
			(LPCWSTR)L"Warning",
			MB_ICONWARNING | MB_YESNOCANCEL | MB_DEFBUTTON2
		);
			Action* newAct = NULL;
		switch (msgboxID)
		{
		case IDYES://case of confirmation
			 newAct = new ActionSave(pManager);
			 pManager->ExecuteAction(newAct);
			break;
		case IDCANCEL://case of cnacel or deny the deletion
		case IDNO:
			pGUI->PrintMessage("Closing");
			break;
		}
	}

	
	
}
