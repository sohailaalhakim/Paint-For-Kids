#include "CElips.h"

CElips::CElips()
{
	figureType = ELLIPSE;
}
CElips::CElips(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	firstPoint = P1;
	secondPoint = P2;
	figureType = ELLIPSE;

}


void CElips::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Rect on the screen	
	pGUI->DrawElips(firstPoint, secondPoint, FigGfxInfo, Selected);


}

bool CElips::isInside(int x, int y)
{
	Point center;
	center.x = 0.5 * (firstPoint.x + secondPoint.x);
	center.y = 0.5 * (firstPoint.y + secondPoint.y);
	float a = abs(firstPoint.x - secondPoint.x) / 2;
	float b = abs(firstPoint.y - secondPoint.y) / 2;
	float check = (pow(x - center.x, 2) / pow(a, 2)) + (pow(y - center.y, 2) / pow(b, 2));
	if (check <= 1)
		return true;

	return false;

}


// Zienab
void CElips::SetID(int id)
{
	ID = id;
}

string CElips::PrintInfo(GUI* pGUI)const
{
	string ind = to_string(ID);
	string x1 = to_string(firstPoint.x);
	string y1 = to_string(firstPoint.y);
	string x2 = to_string(secondPoint.x);
	string y2 = to_string(secondPoint.y);

	return ("Elipse :-  ID: " + ind + " , FirstPoint: (" + x1 + ", " + y1 + ")" + " , SecondPoint: (" + x2 + ", " + y2 + ")");

}


void CElips::Save(ofstream& OutFile) {
	OutFile << figureType;
	OutFile << ' ';
	OutFile << ID;
	OutFile << ' ';
	OutFile << firstPoint.x;
	OutFile << ' ';
	OutFile << firstPoint.y;
	OutFile << ' ';
	OutFile << secondPoint.x;
	OutFile << ' ';
	OutFile << secondPoint.y;
	OutFile << ' ';
	OutFile << int(FigGfxInfo.DrawClr.ucRed);
	OutFile << ' ';
	OutFile << int(FigGfxInfo.DrawClr.ucGreen);
	OutFile << ' ';
	OutFile << int(FigGfxInfo.DrawClr.ucBlue);
	OutFile << ' ';
	if (FigGfxInfo.isFilled) {
		OutFile << int(FigGfxInfo.FillClr.ucRed);
		OutFile << ' ';
		OutFile << int(FigGfxInfo.FillClr.ucGreen);
		OutFile << ' ';
		OutFile << int(FigGfxInfo.FillClr.ucBlue);
	}
	else {
		OutFile << -1;
	}
	OutFile << "\n";

}

void  CElips::Load(ifstream& Infile) {
	Infile >> ID;
	Infile >> firstPoint.x;
	Infile >> firstPoint.y;
	Infile >> secondPoint.x;
	Infile >> secondPoint.y;
	int ucRed, ucGreen, ucBlue;
	Infile >> ucRed;
	Infile >> ucGreen;
	Infile >> ucBlue;
	color drawColor = color(ucRed, ucGreen, ucBlue);
	FigGfxInfo.DrawClr = drawColor;
	Infile >> ucRed;
	if (ucRed == -1)
	{
		FigGfxInfo.isFilled = false;

	}
	else {

		Infile >> ucGreen;
		Infile >> ucBlue;
		color fillColor = color(ucRed, ucGreen, ucBlue);
		this->ChngFillClr(fillColor);
	}
	// FigGfxInfo.FillClr = fillColor;
	FigGfxInfo.BorderWdth = 3;
	SetSelected(false);
}

void CElips::Resize(GUI* pGUI, float size)
{
	

	Point test1 = firstPoint, test2 = secondPoint;
	if (size == .5) size = -0.5;
	else if (size == .25) size = -(4.0 / 3);
	else if (size == 2) size = 1;
	else size = 4;


	// half radius (horizontal x && vertical y)
	float deltaX, deltaY;
	deltaX = 0.5 * (secondPoint.x - firstPoint.x);
	deltaY = 0.5 * (secondPoint.y - firstPoint.y);



	test1.x -= deltaX * size;
	test2.x += deltaX * size;
	test1.y -= deltaY * size;
	test2.y += deltaY * size;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Ellips size will be more than Drawing Area");
	}
	else if (((test2.x - test1.x) / 2) < 15 || ((test2.y - test1.y) / 2) < 10)
	{
		pGUI->PrintMessage("Ellips size will be very small");
	}
	else
	{
		firstPoint = test1;
		secondPoint = test2;

	}
	
}