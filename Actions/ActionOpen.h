#ifndef ACTION_OPEN
#define ACTION_OPEN

#include "Action.h"
//Turky
//Open(Load) Action class
class ActionOpen : public Action
{
public:
	ActionOpen(ApplicationManager* pApp);

	//Save using ApplicationManager
	virtual void Execute();

};

#endif