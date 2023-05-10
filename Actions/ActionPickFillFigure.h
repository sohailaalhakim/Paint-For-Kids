#ifndef ACTION_PICK_FILL_FIGURE_H
#define ACTION_PICK_FILL_FIGURE_H


#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class ActionPickFillFigure : public Action
{
	CFigure* Fig;
	Point p;
	int  no_colors, rand_fig_no, picked_color_no, wrongSelect, rightSelect;
	int colors[6];

	color coloreSelected(CFigure*);
	void calcScore(int);
	void GetFilledShape();

public:
	ActionPickFillFigure(ApplicationManager* pApp);
	virtual void Execute();
};

#endif