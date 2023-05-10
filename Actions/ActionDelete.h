#ifndef ACTION_DELETE_H
#define ACTION_DELETE_H

#include "Action.h"
//------Delete v02---------
//Add Square Action class
class ActionDelete : public Action
{
public:
	ActionDelete(ApplicationManager* pApp);

	//excute selection
	virtual void Execute();

};

#endif
