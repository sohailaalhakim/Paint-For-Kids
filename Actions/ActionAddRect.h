#ifndef ACTION_ADD_RECT_H
#define ACTION_ADD_RECT_H

#include "Action.h"

//Add Square Action class
class ActionAddRect : public Action
{
public:
	ActionAddRect(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif