#include "ActionOpen.h"

#include "..\ApplicationManager.h"

#include "..\GUI\GUI.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CRect.h"
#include "..\Figures\CTria.h"
#include "..\Figures\CElips.h"
#include "..\Figures\CHexagon.h"
#include <iostream>
//Turky
ActionOpen::ActionOpen(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionOpen::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();



	


	pGUI->PrintMessage("Open File : Enter file name...");
//	string fileName = "ahmedTurky.txt";
	string fileName = pGUI->GetSrting() + ".txt";
	pManager->clearInterface();
	pGUI->ClearStatusBar();

	ifstream fin(fileName);
	if (fin.fail())
	{
		pGUI->PrintMessage("No file with such a name : "+ fileName);
	}else{ 
	pManager->loadAll(fin);
	int FigCount;
	fin >> FigCount;
	int figureType;
	//int flag = 1; 

	for (int i = 0;i < FigCount; i++) {
		fin >> figureType;
		CFigure* fig;
		switch (figureType)
		{
		case LINE:
			fig = new CLine();
			fig->Load(fin);
			pManager->AddFigure(fig);
			break;
		case SQR:
			 fig = new CSquare();
			 fig->Load(fin);
			pManager->AddFigure(fig);
			break;
		case RECTANGLE:
			 fig = new CRect();
			 fig->Load(fin);
			pManager->AddFigure(fig);
			break;
		case TRIANGLE:
			fig = new CTria();
			fig->Load(fin);
			pManager->AddFigure(fig);
			break;
		case ELLIPSE:
			fig = new CElips();
			fig->Load(fin);
			pManager->AddFigure(fig);
			break;
		case HEXAGON:
			fig = new CHexagon();
			fig->Load(fin);
			pManager->AddFigure(fig);
			break;
		}
	}
	}
	/*	do {
			fin >> figureType;
			cout << figureType << "type" <<endl;
		//	switch (figureType)
		//	{
		//	case SQR:
			CSquare* sqr  = new CSquare();
			sqr->Load(fin);
			pManager->AddFigure(sqr);
			pGUI->PrintMessage("ADD");
	//		break;
		//	default:
		//		flag = 0;
		//	break;
		//	}
		} while (flag == 1);
		*/

		//ahmed
	pManager->setLastSaveState(true);
}
