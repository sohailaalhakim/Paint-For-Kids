#include "ActionPickFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\CMUgraphicsLib\colors.cpp" 
#include "..\GUI\GUI.h"
#include "..\Figures\CElips.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CRect.h"
#include "..\Figures\CFigure.h"

#include "iostream"

ActionPickFillFigure::ActionPickFillFigure(ApplicationManager* pApp) :Action(pApp)
{
	no_colors = 0;
	rightSelect = 0;
	wrongSelect = 0;

	for (int i = 0; i < 6; i++)
	{
		colors[i] = 0;		
	}
}

color ActionPickFillFigure::coloreSelected(CFigure* Fig)
{
	if (Fig->GetGfxInfo().isFilled)
	{
		if (Fig->GetGfxInfo().FillClr == _LIGHTSKYBLUE)
			return _LIGHTSKYBLUE;
		else if (Fig->GetGfxInfo().FillClr == _DarkYELLOW)
			return _DarkYELLOW;
		else if (Fig->GetGfxInfo().FillClr == _RED)
			return _RED;
		else if (Fig->GetGfxInfo().FillClr == _PURPLE)
			return _PURPLE;
		else if (Fig->GetGfxInfo().FillClr == _LIGHTGREEN)
			return _LIGHTGREEN;
	}
	return BLACK;
}

//Calculate the Score
void ActionPickFillFigure::calcScore(int Score)
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	//print message for the player 
	string Message;

	if (Score == 1)
	{
		rightSelect++;
		Message = "Right!, Your score is: " + to_string(rightSelect) + " Right, and " + to_string(wrongSelect) + " Wrong.";
	}
	else if (Score == 2)
	{
		wrongSelect++;
		Message = "Wrong!, Your score is: " + to_string(rightSelect) + " Right, and " + to_string(wrongSelect) + " Wrong.";
	}
	else
	{
		if (rightSelect > wrongSelect)
		{
			Message = "Congratulations You win!, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
		}
		else if (rightSelect == wrongSelect && rightSelect != 0)
		{
			Message = "Try again it's Draw!, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
		}
		else
		{
			Message = "Hard Luck,Try again!, Your score is : " + to_string(rightSelect) + " Right, and : " + to_string(wrongSelect) + " Wrong.";
		}

	}

	pGUI->PrintMessage(Message);

}

void ActionPickFillFigure::GetFilledShape()
{
	for (int i = 0; i < pManager->getFigCount(); i++) {
		Fig = pManager->DrawnFigs(i);

		// counting colors exists
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == _LIGHTSKYBLUE)
				colors[0]++;
			else if (Fig->GetGfxInfo().FillClr == _DarkYELLOW)
				colors[1]++;
			else if (Fig->GetGfxInfo().FillClr == _RED)
				colors[2]++;
			else if (Fig->GetGfxInfo().FillClr == _PURPLE)
				colors[3]++;
			else if (Fig->GetGfxInfo().FillClr == _LIGHTGREEN)
				colors[4]++;
		}
		else
		{
			colors[5]++;
		} 
	}

	for (int i = 0; i < 6; i++)
		if (colors[i] != 0)
		{
			no_colors++;
		}
}

//Execute the action
void ActionPickFillFigure::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();

	/*pGUI->ClearStatusBar();*/

	GetFilledShape();

	if (no_colors > 1)
	{
		CFigure* clickedFig;
		// get random number in the range 0 to figCount
		rand_fig_no = rand() % pManager->getFigCount();
		Fig = pManager->DrawnFigs(rand_fig_no);


		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == _LIGHTSKYBLUE)
			{
				picked_color_no = colors[0];
				pGUI->PrintMessage("Pick all LIGHTSKYBLUE shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == _DarkYELLOW)
			{
				picked_color_no = colors[1];
				pGUI->PrintMessage("Pick all DarkYELLOW shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == _RED)
			{
				picked_color_no = colors[2];
				pGUI->PrintMessage("Pick all RED shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == _PURPLE)
			{
				picked_color_no = colors[3];
				pGUI->PrintMessage("Pick all PURPLE shapes !");
			}
			else if (Fig->GetGfxInfo().FillClr == _LIGHTGREEN)
			{
				picked_color_no = colors[4];
				pGUI->PrintMessage("Pick all LIGHTGREEN shapes !");
			}
		}
		else
		{
			picked_color_no = colors[5];
			pGUI->PrintMessage("Pick all UNFILLED shapes !");
		}

		while (picked_color_no > 0)
		{
			pGUI->GetPointClicked(p.x, p.y);

			if (p.y > UI.ToolBarHeight || p.x > (UI.MenuItemWidth * PLAY_ITM_COUNT))
			{
				clickedFig = pManager->GetFigure(p.x, p.y);
				if (clickedFig != NULL)
				{
					// unfilled shape
					if (!(Fig->GetGfxInfo().isFilled) && !(clickedFig->GetGfxInfo().isFilled))
					{
						calcScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}

					// filled color with specific color
					else if (clickedFig->GetGfxInfo().isFilled && clickedFig->GetGfxInfo().FillClr == coloreSelected(Fig))
					{
						calcScore(1);
						clickedFig->Hide();
						pManager->UpdateInterface();
						picked_color_no--;
					}
					else
					{
						calcScore(2);
						clickedFig->Hide();
						pManager->UpdateInterface();
					}
				}
			}
			else {
				picked_color_no = -1;
				pGUI->ClearStatusBar();
			}
		}
		// end the clicked
		if (picked_color_no == 0)
		{
			calcScore(3);
		}
	}

	else
	{
		pGUI->PrintMessage("You must have at least two types of figures to play ! ");
	}

	for (int i = 0; i < pManager->getFigCount(); i++)
	{
		pManager->DrawnFigs(i)->Show();
	}
	pManager->UpdateInterface();
	

}