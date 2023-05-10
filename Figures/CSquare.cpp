#include "CSquare.h"

CSquare::CSquare()
{
	figureType = SQR;
}
CSquare::CSquare(Point P1, int len, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	figureType = SQR;

}
	

void CSquare::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawSquare(TopLeftCorner, length, FigGfxInfo, Selected);
	

}
bool CSquare::isInside(int x, int y)
{
	if (x >= TopLeftCorner.x && x <= (TopLeftCorner.x + length) && y >= TopLeftCorner.y && y <= (TopLeftCorner.y + length))
	{
		return true;
	}
	return false;
}

// Zienab
void CSquare::SetID(int id)
{
	ID = id;
}

string CSquare::PrintInfo(GUI* pGUI)const
{
	double _area = length * length;
	string ind = to_string(ID);
	string _length = to_string(length);
	string x1 = to_string(TopLeftCorner.x);
	string y1 = to_string(TopLeftCorner.y);
	string x2 = to_string((TopLeftCorner.x) + length);
	string y2 = to_string((TopLeftCorner.y) + length);
	string Area = to_string(_area);

	return ("Square :-  ID:" + ind + " ,FirstPoint: (" + x1 + ", " + y1 + ")" + " ,SecondPoint: (" + x2 + ", " + y2 + ")" + " ,length:" + _length + " ,Area: " + Area);

}


void CSquare::Save(ofstream& OutFile) {
	OutFile << figureType;
	OutFile << ' ';
	OutFile << ID;
	OutFile << ' ';
	OutFile << TopLeftCorner.x;
	OutFile << ' ';
	OutFile << TopLeftCorner.y;
	OutFile << ' ';
	OutFile << length;
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

void  CSquare::Load(ifstream& Infile) {
	Infile >> ID;
	Infile >> TopLeftCorner.x;
	Infile >> TopLeftCorner.y;
	Infile >> length;


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


void CSquare::Resize(GUI* pGUI, float size)
{
	float length_test = length;
	Point test1 = TopLeftCorner;
	Point test2;
	test2.x = test1.x + length;
	test2.y = test1.y + length;
	length_test *= size;
	test2.x = test1.x + length_test;
	test2.y = test1.y + length_test;

	if (test1.y < UI.ToolBarHeight || test2.y > UI.height - UI.StatusBarHeight
		|| test2.x > UI.width || test1.x < 1)
	{
		pGUI->PrintMessage("Square size will be more than Drawing Area");

	}
	else if (length_test < 20)
	{
		pGUI->PrintMessage("Square size will be very small");

	}
	else
	{
		TopLeftCorner = test1;
		length = length_test;
		//PrintInfo(pGUI);
	}


}

