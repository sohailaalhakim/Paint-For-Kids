#include "ActionPickTypeAndFillFigure.h"
#include "..\ApplicationManager.h"
#include "..\CMUgraphicsLib\colors.h" 
#include "..\GUI\GUI.h"
#include "..\Figures\CElips.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CRect.h"
#include "..\Figures\CFigure.h"
#include "..\Figures\CTria.h"
#include "iostream"

ActionPickTypeAndFillFigure::ActionPickTypeAndFillFigure(ApplicationManager* pApp) :Action(pApp)
{
	no_colors = 0;
	rightSelect = 0;
	wrongSelect = 0;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			figs[i][j] = 0;
		}
	}
}

color ActionPickTypeAndFillFigure::coloreSelected(CFigure* Fig)
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
void ActionPickTypeAndFillFigure::calcScore(int Score)
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


void ActionPickTypeAndFillFigure::GetFilledShape()
{
	for (int i = 0; i < pManager->getFigCount(); i++) {
		Fig = pManager->DrawnFigs(i);

		// counting colors exists
		if (Fig->GetGfxInfo().isFilled)
		{
			if (Fig->GetGfxInfo().FillClr == _LIGHTSKYBLUE){ 
				if (dynamic_cast<CSquare*>(Fig))
					figs[0][0]++;   //figs-> array of figures in runtime for count figures, assign every index to a figure to check then ++ 
				else if (dynamic_cast<CElips*>(Fig))
					figs[0][1]++;
				else if (dynamic_cast<CRect*>(Fig))
					figs[0][2]++;
				else if (dynamic_cast<CTria*>(Fig))
					figs[0][3]++;
			}		
			else if (Fig->GetGfxInfo().FillClr == _DarkYELLOW) {
				if (dynamic_cast<CSquare*>(Fig))
					figs[1][0]++;   //figs-> array of figures in runtime for count figures, assign every index to a figure to check then ++ 
				else if (dynamic_cast<CElips*>(Fig))
					figs[1][1]++;
				else if (dynamic_cast<CRect*>(Fig))
					figs[1][2]++;
				else if (dynamic_cast<CTria*>(Fig))
					figs[1][3]++;
			}
			else if (Fig->GetGfxInfo().FillClr == _RED){ 
				if (dynamic_cast<CSquare*>(Fig))
					figs[2][0]++;   //figs-> array of figures in runtime for count figures, assign every index to a figure to check then ++ 
				else if (dynamic_cast<CElips*>(Fig))
					figs[2][1]++;
				else if (dynamic_cast<CRect*>(Fig))
					figs[2][2]++;
				else if (dynamic_cast<CTria*>(Fig))
					figs[2][3]++;
			}
			else if (Fig->GetGfxInfo().FillClr == _PURPLE){ 
				if (dynamic_cast<CSquare*>(Fig))
					figs[3][0]++;   //figs-> array of figures in runtime for count figures, assign every index to a figure to check then ++ 
				else if (dynamic_cast<CElips*>(Fig))
					figs[3][1]++;
				else if (dynamic_cast<CRect*>(Fig))
					figs[3][2]++;
				else if (dynamic_cast<CTria*>(Fig))
					figs[3][3]++;
			}
			else if (Fig->GetGfxInfo().FillClr == _LIGHTGREEN){ 
				if (dynamic_cast<CSquare*>(Fig))
					figs[4][0]++;   //figs-> array of figures in runtime for count figures, assign every index to a figure to check then ++ 
				else if (dynamic_cast<CElips*>(Fig))
					figs[4][1]++;
				else if (dynamic_cast<CRect*>(Fig))
					figs[4][2]++;
				else if (dynamic_cast<CTria*>(Fig))
					figs[4][3]++;
			}
		}
		else
		{
			if (dynamic_cast<CSquare*>(Fig))
				figs[5][0]++;   //figs-> array of figures in runtime for count figures, assign every index to a figure to check then ++ 
			else if (dynamic_cast<CElips*>(Fig))
				figs[5][1]++;
			else if (dynamic_cast<CRect*>(Fig))
				figs[5][2]++;
			else if (dynamic_cast<CTria*>(Fig))
				figs[5][3]++;
		}
	}

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (figs[i][j] != 0)
			{
				no_colors++;
			}
		}
	}
}

//Execute the action
void ActionPickTypeAndFillFigure::Execute()
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
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_color_no = figs[0][0];
					pGUI->PrintMessage("Pick up all the LIGHTSKYBLUE Squares !");
				}
				else if (dynamic_cast<CElips*>(Fig))
				{
					picked_color_no = figs[0][1];
					pGUI->PrintMessage("Pick up all the LIGHTSKYBLUE Ellipses !");
				}
				else if (dynamic_cast<CRect*>(Fig))
				{
					picked_color_no = figs[0][2];
					pGUI->PrintMessage("Pick up all the LIGHTSKYBLUE Rectangle !");
				}
				else if (dynamic_cast<CTria*>(Fig))
				{
					picked_color_no = figs[0][3];
					pGUI->PrintMessage("Pick up all the LIGHTSKYBLUE Triangles !");
				}

			}
			else if (Fig->GetGfxInfo().FillClr == _DarkYELLOW)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_color_no = figs[1][0];
					pGUI->PrintMessage("Pick up all the DARKYELLOW Squares !");
				}
				else if (dynamic_cast<CElips*>(Fig))
				{
					picked_color_no = figs[1][1];
					pGUI->PrintMessage("Pick up all the DARKYELLOW Ellipses !");
				}
				else if(dynamic_cast<CRect*>(Fig))
				{
					picked_color_no = figs[1][2];
					pGUI->PrintMessage("Pick up all the DARKYELLOW Rectangle !");
				}
				else if (dynamic_cast<CTria*>(Fig))
				{
					picked_color_no = figs[1][3];
					pGUI->PrintMessage("Pick up all the DARKYELLOW Triangles !");
				}
			}
			else if (Fig->GetGfxInfo().FillClr == _RED)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_color_no = figs[2][0];
					pGUI->PrintMessage("Pick up all the RED Squares !");
				}
				else if (dynamic_cast<CElips*>(Fig))
				{
					picked_color_no = figs[2][1];
					pGUI->PrintMessage("Pick up all the RED Ellipses !");
				}
				else if(dynamic_cast<CRect*>(Fig))
				{
					picked_color_no = figs[2][2];
					pGUI->PrintMessage("Pick up all the RED Rectangle !");
				}
				else if (dynamic_cast<CTria*>(Fig))
				{
					picked_color_no = figs[2][3];
					pGUI->PrintMessage("Pick up all the RED Triangles !");
				}
			}
			else if (Fig->GetGfxInfo().FillClr == _PURPLE)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_color_no = figs[3][0];
					pGUI->PrintMessage("Pick up all the PURPLE Squares !");
				}
				else if (dynamic_cast<CElips*>(Fig))
				{
					picked_color_no = figs[3][1];
					pGUI->PrintMessage("Pick up all the PURPLE Ellipses !");
				}
				else if (dynamic_cast<CRect*>(Fig))
				{
					picked_color_no = figs[3][2];
					pGUI->PrintMessage("Pick up all the PURPLE Rectangle !");
				}
				else if (dynamic_cast<CTria*>(Fig))
				{
					picked_color_no = figs[3][3];
					pGUI->PrintMessage("Pick up all the PURPLE Triangles !");
				}

			}
			else if (Fig->GetGfxInfo().FillClr == _LIGHTGREEN)
			{
				if (dynamic_cast<CSquare*>(Fig))
				{
					picked_color_no = figs[4][0];
					pGUI->PrintMessage("Pick up all the LIGHTGREEN Squares !");
				}
				else if (dynamic_cast<CElips*>(Fig))
				{
					picked_color_no = figs[4][1];
					pGUI->PrintMessage("Pick up all the LIGHTGREEN Ellipses !");
				}
				else if (dynamic_cast<CRect*>(Fig))
				{
					picked_color_no = figs[4][2];
					pGUI->PrintMessage("Pick up all the LIGHTGREEN Rectangle !");
				}
				else if (dynamic_cast<CTria*>(Fig))
				{
					picked_color_no = figs[4][3];
					pGUI->PrintMessage("Pick up all the LIGHTGREEN Triangles !");
				}

			}
		}
		else
		{
			if (dynamic_cast<CSquare*>(Fig))
			{
				picked_color_no = figs[5][0];
				pGUI->PrintMessage("Pick up all the UNFILLED Squares !");
			}
			else if (dynamic_cast<CElips*>(Fig))
			{
				picked_color_no = figs[5][1];
				pGUI->PrintMessage("Pick up all the UNFILLED Ellipses !");
			}
			else if(dynamic_cast<CRect*>(Fig))
			{
				picked_color_no = figs[5][2];
				pGUI->PrintMessage("Pick up all the UNFILLED Rectangle !");
			}
			else if (dynamic_cast<CTria*>(Fig))
			{
				picked_color_no = figs[5][3];
				pGUI->PrintMessage("Pick up all the UNFILLED Triangles !");
			}
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

						if ((dynamic_cast<CSquare*>(clickedFig)) && (dynamic_cast<CSquare*>(Fig)))
						{
							calcScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_color_no--;
						}
						else if ((dynamic_cast<CElips*>(clickedFig)) && (dynamic_cast<CElips*>(Fig)))
						{
							calcScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_color_no--;
						}
						else if ((dynamic_cast<CRect*>(clickedFig)) && (dynamic_cast<CRect*>(Fig)))
						{
							calcScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_color_no--;
						}
						else if ((dynamic_cast<CTria*>(clickedFig)) && (dynamic_cast<CTria*>(Fig)))
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

					// filled color with specific color
					else if (clickedFig->GetGfxInfo().isFilled && clickedFig->GetGfxInfo().FillClr == coloreSelected(Fig))
					{

						if ((dynamic_cast<CSquare*>(clickedFig)) && (dynamic_cast<CSquare*>(Fig)))
						{
							calcScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_color_no--;
						}
						else if ((dynamic_cast<CElips*>(clickedFig)) && (dynamic_cast<CElips*>(Fig)))
						{
							calcScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_color_no--;
						}
						else if ((dynamic_cast<CRect*>(clickedFig)) && (dynamic_cast<CRect*>(Fig)))
						{
							calcScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_color_no--;
						}
						else if ((dynamic_cast<CTria*>(clickedFig)) && (dynamic_cast<CTria*>(Fig)))
						{
							calcScore(1);
							clickedFig->Hide();
							pManager->UpdateInterface();
							picked_color_no--;
						}
						else {
							calcScore(2);
							clickedFig->Hide();
							pManager->UpdateInterface();
						}
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