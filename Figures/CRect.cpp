#include "CRect.h"
CRect::CRect() :CFigure()
{
	figureType = RECTANGLE;
}

CRect::CRect(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	BottomRightCorner = P2;
	figureType = RECTANGLE;
}


void CRect::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Rect on the screen	
	pGUI->DrawRect(TopLeftCorner, BottomRightCorner, FigGfxInfo, Selected);
}
bool CRect::isInside(int x, int y)
{
	if ((x >= min(TopLeftCorner.x, BottomRightCorner.x) && x <= max(TopLeftCorner.x, BottomRightCorner.x)
		&& y >= min(TopLeftCorner.y, BottomRightCorner.y) && y <= max(TopLeftCorner.y, BottomRightCorner.y)))
	{
		return true;
	}
	return false;
}


// Zienab
void CRect::SetID(int id)
{
	ID = id;
}

string CRect::PrintInfo(GUI* pGUI)const
{
	double _side1 = abs(TopLeftCorner.x - BottomRightCorner.x);
	double _dia = sqrt((pow(abs(TopLeftCorner.x - BottomRightCorner.x), 2) + pow(abs(TopLeftCorner.y - BottomRightCorner.y), 2)));
	double _area = _side1 * sqrt(abs((pow(_dia, 2)) - (pow(_side1, 2))));

	string ind = to_string(ID);
	string x1 = to_string(TopLeftCorner.x);
	string y1 = to_string(TopLeftCorner.y);
	string x2 = to_string(BottomRightCorner.x);
	string y2 = to_string(BottomRightCorner.y);
	string Area = to_string(_area);
	string side1 = to_string(_side1);
	string dia = to_string(_dia);

	return ("Rectangle :-  ID:" + ind + " ,UpperLeftPoint: (" + x1 + ", " + y1 + ")" + " ,LowerRightBottom: (" + x2 + ", " + y2 + ")" + " ,Diameter:" + dia + " ,Height : " + side1 + " ,Area: " + Area);


}

void CRect::Save(ofstream& OutFile) {
	OutFile << figureType;
	OutFile << ' ';
	OutFile << ID;
	OutFile << ' ';
	OutFile << TopLeftCorner.x;
	OutFile << ' ';
	OutFile << TopLeftCorner.y;
	OutFile << ' ';
	OutFile << BottomRightCorner.x;
	OutFile << ' ';
	OutFile << BottomRightCorner.y;
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

void  CRect::Load(ifstream& Infile) {

	Infile >> ID;
	Infile >> TopLeftCorner.x;
	Infile >> TopLeftCorner.y;
	Infile >> BottomRightCorner.x;
	Infile >> BottomRightCorner.y;

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

void CRect::Resize(GUI* pGUI, float size)
{
	Point test1 = TopLeftCorner, test2 = BottomRightCorner;
	if (size == .5) size = -0.5;
	else if (size == .25) size = -(4.0 / 3);
	else if (size == 2) size = 1;
	else size = 4;

	test1.x = min(TopLeftCorner.x, BottomRightCorner.x);
	test1.y = min(TopLeftCorner.y, BottomRightCorner.y);
	test2.x = max(TopLeftCorner.x, BottomRightCorner.x);
	test2.y = max(TopLeftCorner.y, BottomRightCorner.y);

	TopLeftCorner = test1;
	BottomRightCorner = test2;
	// half radius (horizontal x && vertical y)
	float deltaX, deltaY;
	deltaX = 0.5 * (BottomRightCorner.x - TopLeftCorner.x);
	deltaY = 0.5 * (BottomRightCorner.y - TopLeftCorner.y);



	test1.x -= deltaX * size;
	test2.x += deltaX * size;
	test1.y -= deltaY * size;
	test2.y += deltaY * size;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Rectangle size will be more than Drawing Area");
	}
	else if (((test2.x - test1.x) / 2) < 15 || ((test2.y - test1.y) / 2) < 10)
	{
		pGUI->PrintMessage("Rectangle size will be very small");
	}
	else
	{
		TopLeftCorner = test1;
		BottomRightCorner = test2;

	}

}