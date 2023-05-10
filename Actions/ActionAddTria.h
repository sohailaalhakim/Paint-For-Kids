#pragma once
#ifndef ACTION_ADD_TRIA_H
#define ACTION_ADD_TRIA_H

#include "Action.h"

//Add Square Action class
class ActionAddTria : public Action
{
public:
	ActionAddTria(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif