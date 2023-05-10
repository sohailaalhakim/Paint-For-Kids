#define ACTION_SWITCH_TO_DRAW_H

#include "Action.h"
class ActionSwitchToDraw : public Action
{
public:
	ActionSwitchToDraw(ApplicationManager* pApp);

	virtual void Execute();
};