#include "CHexagon.h"
#include <iostream>
#include <string>

CHexagon::CHexagon()
{
	figureType = HEXAGON;

}
CHexagon::CHexagon(Point P1, int len, int _height, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	TopLeftCorner = P1;
	length = len;
	height = _height ;
	this->Selected = false;
	figureType = HEXAGON;

}
bool CHexagon::isInside(int x, int y)
{
	// if inside inner rectangle
	if (x >= TopLeftCorner.x && x <= TopLeftCorner.x + length && y >= TopLeftCorner.y && y <= TopLeftCorner.y + height)
		return true;

	float sideTrianglesArea = AreaTriangle(TopLeftCorner.x, TopLeftCorner.y, TopLeftCorner.x, TopLeftCorner.y + height, TopLeftCorner.x - 0.5 * length, TopLeftCorner.y + 0.5 * height);
	// if inside left side triangle
	// left triangle >> (x,y), (x, y+h), (x-0.5l, y+0.5h)
	float Area1 = AreaTriangle(x, y, TopLeftCorner.x, TopLeftCorner.y + height, TopLeftCorner.x - 0.5 * length, TopLeftCorner.y + 0.5 * height);
	float Area2 = AreaTriangle(TopLeftCorner.x, TopLeftCorner.y, x, y, TopLeftCorner.x - 0.5 * length, TopLeftCorner.y + 0.5 * height);
	float Area3 = AreaTriangle(TopLeftCorner.x, TopLeftCorner.y, TopLeftCorner.x, TopLeftCorner.y + height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;
	// if inside right side triangle
	// right triangle >> (x+l,y), (x+l, y+h), (x+1.5l, y+0.5h)
	Area1 = AreaTriangle(x, y, TopLeftCorner.x + length, TopLeftCorner.y + height, TopLeftCorner.x + 1.5 * length, TopLeftCorner.y + 0.5 * height);
	Area2 = AreaTriangle(TopLeftCorner.x + length, TopLeftCorner.y, x, y, TopLeftCorner.x + 1.5 * length, TopLeftCorner.y + 0.5 * height);
	Area3 = AreaTriangle(TopLeftCorner.x + length, TopLeftCorner.y, TopLeftCorner.x + length, TopLeftCorner.y + height, x, y);
	if (Area1 + Area2 + Area3 == sideTrianglesArea)
		return true;

	return false;
}

float CHexagon::AreaTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5);
}

void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawHexagon(TopLeftCorner, length, height, FigGfxInfo, Selected);
}

void CHexagon::Resize(GUI* pGUI, float size)
{

	float length_test = length * size;
	float height_test = height * size;
	if ((TopLeftCorner.y + height_test) > UI.height - UI.StatusBarHeight
		|| (TopLeftCorner.x + length_test * 1.5) > UI.width
		|| (TopLeftCorner.x - length_test * 0.5) < 1)
	{
		pGUI->PrintMessage("Hexagon size will be more than Drawing Area");

	}
	else if (length_test < 20 || height_test < 20)
	{
		pGUI->PrintMessage("Hexagon size will be very small");

	}
	else
	{
		length = length_test;
		height = height_test;
		
	}

}
void CHexagon::SetID(int id)
{
	ID = id;
}

string CHexagon::PrintInfo(GUI* pGUI)const
{
	string ind = to_string(ID);
	string x1 = to_string(TopLeftCorner.x);
	string y1 = to_string(TopLeftCorner.y);
	string l = to_string(length);
	string h = to_string(height);

	return ("HEXAGON :-  ID: " + ind + " , FirstPoint: (" + x1 + ", " + y1 + ")" + " , LENGTH: " + l + " , HEIGHT: " + h );

}


void CHexagon::Save(ofstream& OutFile) {
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
	OutFile << height;
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

void  CHexagon::Load(ifstream& Infile) {
	Infile >> ID;
	Infile >> TopLeftCorner.x;
	Infile >> TopLeftCorner.y;
	Infile >> length;
	Infile >> height;

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
