#include "CLine.h"

CLine::CLine()
{
	figureType = LINE;
}
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	firstPoint = P1;
	secondPoint = P2;
	figureType = LINE;
	
}

void CLine::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Rect on the screen	
	pGUI->DrawLine(firstPoint, secondPoint, FigGfxInfo, Selected);


}

bool CLine::isInside(int x, int y)
{
	
	float A = abs((x * (firstPoint.y - secondPoint.y) + firstPoint.x * (secondPoint.y - y) + secondPoint.x * (y - firstPoint.y)) / 2.0);
		if (A >= 0 && A <= 1000 && (x >= min(firstPoint.x, secondPoint.x) && x <= max(firstPoint.x, secondPoint.x) && y >= min(firstPoint.y, secondPoint.y) && y <= max(firstPoint.y, secondPoint.y)))
		{
			return true;
		}
	return false;
}


// Zienab
void CLine::SetID(int id)
{
	ID = id;
}

string CLine::PrintInfo(GUI* pGUI)const
{
	string ind = to_string(ID);
	string x1 = to_string(firstPoint.x);
	string y1 = to_string(firstPoint.y);
	string x2 = to_string(secondPoint.x);
	string y2 = to_string(secondPoint.y);

	return ("LINE :-  ID: " + ind + " , FirstPoint: (" + x1 + ", " + y1 + ")" + " , SecondPoint: (" + x2 + ", " + y2 + ")");

}

void CLine::Save(ofstream& OutFile) {
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
	OutFile << "\n";

}

void  CLine::Load(ifstream& Infile) {
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

	FigGfxInfo.BorderWdth = 3;
	FigGfxInfo.isFilled = false;
	SetSelected(false);

}

void CLine::Resize(GUI* pGUI, float size)
{


}