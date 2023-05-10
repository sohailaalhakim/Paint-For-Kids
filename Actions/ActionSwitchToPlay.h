#define ACTION_SWITCH_TO_PLAY_H

#include "Action.h"
class ActionSwitchToPlay : public Action
{
public:
	ActionSwitchToPlay(ApplicationManager* pApp);

	virtual void Execute();
};