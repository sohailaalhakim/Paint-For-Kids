#ifndef CLine_H
#define CLine_H
#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point firstPoint;
	Point secondPoint;
public:
	CLine();
	CLine(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool isInside(int x, int y);
	void Resize(GUI* pGUI, float size);

	//ZIENAB
	virtual void SetID(int id);
	string PrintInfo(GUI* pOut)const;

	//Turky
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif

