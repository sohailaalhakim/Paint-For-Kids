#include "ActionSave.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
//Turky
ActionSave::ActionSave(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSave::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();



	//Step 1 - Read Square data from the user

	pGUI->PrintMessage("Save File : Enter file name ...");

	//string fileName = "ahmedTurky.txt";
	string fileName = pGUI->GetSrting()+".txt";
	pGUI->ClearStatusBar();
	pManager->saveAll(fileName);
	//ahmed
	pManager->setLastSaveState(true);
}
