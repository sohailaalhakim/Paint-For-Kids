#ifndef CRect_H
#define CRect_H

#include "CFigure.h"

class CRect : public CFigure
{
private:
	Point TopLeftCorner;
	Point BottomRightCorner;
public:
	CRect();
	CRect(Point, Point, GfxInfo FigureGfxInfo);
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
