#ifndef ACTION_EXIT
#define ACTION_EXIT

#include "Action.h"

//Add Square Action class
class ActionExit : public Action
{
	ActionType ActType;
public:
	ActionExit(ApplicationManager* pApp);

	//Add Square to the ApplicationManager
	virtual void Execute();

};

#endif