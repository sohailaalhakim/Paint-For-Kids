#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point TopLeftCorner;	
	int length;
public:
	CSquare();
	CSquare(Point , int, GfxInfo FigureGfxInfo );
	virtual void DrawMe(GUI* pOut) const;
	bool isInside(int x, int y);
	//Afnan
	void Resize(GUI* pGUI, float size);

	//ZIenab
	virtual void SetID(int id);
	string PrintInfo(GUI* pOut)const;

	//Turky
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif