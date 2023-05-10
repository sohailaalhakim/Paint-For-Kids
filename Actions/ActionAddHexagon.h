#ifndef ACTION_ADD_Hexagon_H
#define ACTION_ADD_Hexagon_H

#include "Action.h"

//Add Hexagon Action class
class ActionAddHexagon : public Action
{
public:
	ActionAddHexagon(ApplicationManager* pApp);

	//Add hexagon to the ApplicationManager
	virtual void Execute();

};

#endif
