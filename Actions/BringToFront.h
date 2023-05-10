#ifndef BRING_TO_BACK_H
#define BRING_TO_BACK_H
#include "Action.h"

class BRINGTOFRONT : public Action
{

public:
	// Constructor of Bring to front Class
	BRINGTOFRONT(ApplicationManager* pApp);

	//Read Function to Read Ellipse parameters
	virtual void ReadActionParameters();

	//Execution Function For Bring To Front Class
	virtual void Execute();
};

#endif
