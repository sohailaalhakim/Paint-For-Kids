#include "ActionDelete.h"
#include "..\ApplicationManager.h"
#include "..\GUI\GUI.h"
#include "WinUser.h"
#include <string>
#include <string.h>
#include <iostream>
//----------------------------Try Deletev02-------------------------
ActionDelete::ActionDelete(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionDelete::Execute()
{
    GUI* pGUI = pManager->GetGUI();
    //--------v2-----------------
    if (pManager->AnySelected()) //check if there is a figure selected
    {
        //opening a dialuge box to confirm deletion
        int msgboxID = MessageBoxW(
            NULL,
            (LPCWSTR)L"Delete?!\n",
            (LPCWSTR)L"Confirm Delete",
            MB_ICONWARNING | MB_YESNOCANCEL | MB_DEFBUTTON2
        );
        switch (msgboxID)
        {
        case IDYES://case of confirmation
            pGUI->ClearDrawArea();
            pManager->DeleteFigure();
            pGUI->ClearStatusBar();
            break;
        case IDCANCEL://case of cnacel or deny the deletion
        case IDNO:
            pGUI->PrintMessage("Deletion canceled!");
            break;
        }

    }
    else
    {
        //message to user to ask him to select a shape
        pGUI->PrintMessage("please select a figure first");
    }
    //ahmed
    pManager->setLastSaveState(false);
}