#ifndef ACTION_PICK_TYPE_FILL_FIGURE_H
#define ACTION_PICK_TYPE_FILL_FIGURE_H


#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"

class ActionPickTypeAndFillFigure : public Action
{
	CFigure* Fig;
	Point p;
	int  no_colors, rand_fig_no, picked_color_no, wrongSelect, rightSelect;
	int figs[6][4];

	color coloreSelected(CFigure*);
	void calcScore(int);
	void GetFilledShape();
	void GetShape();

public:
	ActionPickTypeAndFillFigure(ApplicationManager* pApp);
	virtual void Execute();
};

#endif