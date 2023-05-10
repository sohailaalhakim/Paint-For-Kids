#ifndef ACTION_SAVE
#define ACTION_SAVE

#include "Action.h"
//Turky
//Save Action class
class ActionSave : public Action
{
public:
	ActionSave(ApplicationManager* pApp);

	//Save using ApplicationManager
	virtual void Execute();

};

#endif