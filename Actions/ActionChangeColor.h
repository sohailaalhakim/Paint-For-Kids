#ifndef Action_Change_Color_H
#define Action_Change_Color_H
#include "Action.h"

//Todo:: Sohaile ->


enum ChangeColorFun
{
	BORDER_SHAPE_FUN, FILLED_SHAPE_FUN, BACK_GROUND_FUN
};

//Add Square Action class
class ActionChangeColor : public Action
{
private:
	// Enum ChangeColor To Select Change Color Funcation
	ChangeColorFun* SelectedFun;
public:
	ActionChangeColor(ApplicationManager* pApp, ChangeColorFun*);

	//Add Square to the ApplicationManager
	virtual void Execute();
	void ChangeBorderShapeColor();
	void ChangeFilledShapeColor();
	void ChangeBackGroundColor();
};

#endif#pragma once
