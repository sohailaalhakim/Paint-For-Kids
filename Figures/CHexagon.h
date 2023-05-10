#ifndef CHexagon_H
#define CHexagon_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point TopLeftCorner;
	int length;
	int height; 
public:
	CHexagon();
	CHexagon(Point, int, int, GfxInfo FigureGfxInfo); 
	virtual void DrawMe(GUI* pOut) const;
	
	
	bool isInside(int x, int y);
	void Resize(GUI* pGUI, float size);
	float AreaTriangle(float, float, float, float, float, float);

	virtual void SetID(int id);
	string PrintInfo(GUI* pOut)const;
	//Turky
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	
};


#endif
