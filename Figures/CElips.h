#ifndef CElips_H
#define CElips_H

#include "CFigure.h"

class CElips : public CFigure
{
private:
	Point firstPoint;
	Point secondPoint;
public:
	CElips();
	CElips(Point, Point, GfxInfo FigureGfxInfo);
	virtual void DrawMe(GUI* pOut) const;
	bool isInside(int x, int y);
	void Resize(GUI* pGUI, float size);

	//ZIenab
	virtual void SetID(int id);
	string PrintInfo(GUI* pOut)const;
	//Turky
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

#endif