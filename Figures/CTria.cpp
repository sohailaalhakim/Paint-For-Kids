#include "CTria.h"

CTria::CTria()
{
	figureType = TRIANGLE;
}
CTria::CTria(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	firstPoint = P1;
	secondPoint = P2;
	thirdPoint = P3;
	figureType = TRIANGLE;
}


void CTria::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Rect on the screen	
	pGUI->DrawTria(firstPoint, secondPoint, thirdPoint, FigGfxInfo, Selected);


}

bool CTria::isInside(int x, int y)
{



	/* Calculate area of triangle ABC */
	float A = 0.5 * abs(firstPoint.x * (secondPoint.y - thirdPoint.y) + secondPoint.x * (thirdPoint.y - firstPoint.y) + thirdPoint.x * (firstPoint.y - secondPoint.y)); //a,b,c
	/* Calculate area of triangle PBC */
	float A1 = 0.5 * abs(x * (secondPoint.y - thirdPoint.y) + secondPoint.x * (thirdPoint.y - y) + thirdPoint.x * (y - secondPoint.y)); //x,a,b
	/* Calculate area of triangle PAC */
	float A2 = 0.5 * abs(firstPoint.x * (y - thirdPoint.y) + x * (thirdPoint.y - firstPoint.y) + thirdPoint.x * (firstPoint.y - y)); //x,a,c
	/* Calculate area of triangle PAB */
	float A3 = 0.5 * abs(firstPoint.x * (secondPoint.y - y) + secondPoint.x * (y - firstPoint.y) + x * (firstPoint.y - secondPoint.y)); //x,b,c

	/* Check if sum of A1, A2 and A3 is same as A */

	return (A == A1 + A2 + A3);
}

// Zienab
void CTria::SetID(int id)
{
	ID = id;
}

string CTria::PrintInfo(GUI* pGUI)const
{
	double _area = 0.5 * abs(firstPoint.x * (secondPoint.y - thirdPoint.y) + secondPoint.x * (thirdPoint.y - firstPoint.y) + thirdPoint.x * (firstPoint.y - secondPoint.y));

	string ind = to_string(ID);
	string x1 = to_string(firstPoint.x);
	string y1 = to_string(firstPoint.y);
	string x2 = to_string(secondPoint.x);
	string y2 = to_string(secondPoint.y);
	string x3 = to_string(thirdPoint.x);
	string y3 = to_string(thirdPoint.y);
	string Area = to_string(_area);


	return ("Triangle :-  ID:" + ind + " ,FirstPoint: (" + x1 + ", " + y1 + ")" + " ,SecondPoint: (" + x2 + ", " + y2 + ")" + " ,ThirdPoint: (" + x3 + ", " + y3 + ")" + " ,Area:" + Area);


}


void CTria::Save(ofstream& OutFile) {
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
	OutFile << thirdPoint.x;
	OutFile << ' ';
	OutFile << thirdPoint.y;
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

void  CTria::Load(ifstream& Infile) {

	Infile >> ID;
	Infile >> firstPoint.x;
	Infile >> firstPoint.y;
	Infile >> secondPoint.x;
	Infile >> secondPoint.y;
	Infile >> thirdPoint.x;
	Infile >> thirdPoint.y;

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

void CTria::Resize(GUI* pGUI, float size)
{

	if (size == 0.5) size = -1;
	else if (size == 0.25) size = -(4.0 / 3);

	Point P;
	P.x = (firstPoint.x + secondPoint.x + thirdPoint.x) / 3;
	P.y = (firstPoint.y + secondPoint.y + thirdPoint.y) / 3;
	if (firstPoint.x <= P.x)
		firstPoint.x -= (P.x - firstPoint.x) * size / 2;
	else
		firstPoint.x += (firstPoint.x - P.x) * size / 2;

	if (secondPoint.x <= P.x)
		secondPoint.x -= (P.x - secondPoint.x) * size / 2;
	else
		secondPoint.x += (secondPoint.x - P.x) * size / 2;

	if (thirdPoint.x <= P.x)
		thirdPoint.x -= (P.x - thirdPoint.x) * size / 2;
	else
		thirdPoint.x += (thirdPoint.x - P.x) * size / 2;

	if (firstPoint.y <= P.y)
		firstPoint.y -= (P.y - firstPoint.y) * size / 2;
	else
		firstPoint.y += (firstPoint.y - P.y) * size / 2;

	if (secondPoint.y <= P.y)
		secondPoint.y -= (P.y - secondPoint.y) * size / 2;
	else
		secondPoint.y += (secondPoint.y - P.y) * size / 2;

	if (thirdPoint.y <= P.y)
		thirdPoint.y -= (P.y - thirdPoint.y) * size / 2;
	else
		thirdPoint.y += (thirdPoint.y - P.y) * size / 2;

	if (firstPoint.y <= UI.ToolBarHeight
		|| firstPoint.y > (UI.height - UI.StatusBarHeight)
		|| firstPoint.x > UI.width || firstPoint.x<0 ||
		secondPoint.y <= UI.ToolBarHeight || secondPoint.y>(UI.height - UI.StatusBarHeight) ||
		secondPoint.x > UI.width || secondPoint.x<0 ||
		secondPoint.y <= UI.ToolBarHeight ||
		thirdPoint.y>(UI.height - UI.StatusBarHeight) || thirdPoint.x > UI.width || thirdPoint.x < 0) {
		pGUI->PrintMessage("Triangle size will be more than Drawing Area");
	}

}