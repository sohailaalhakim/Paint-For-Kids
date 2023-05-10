#pragma once
#pragma once
#ifndef ACTION_ADD_ELIPS_H
#define ACTION_ADD_ELIPS_H

#include "Action.h"

//Add Square Action class
class ActionAddElips : public Action
{
public:
	ActionAddElips(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif