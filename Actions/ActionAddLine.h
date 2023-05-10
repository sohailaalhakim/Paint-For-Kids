
#ifndef ACTION_ADD_LINE_H
#define ACTION_ADD_LINE_H

#include "Action.h"

//Add Square Action class
class ActionAddLine: public Action
{
public:
	ActionAddLine(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif#
