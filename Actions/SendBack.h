#ifndef SEND_BACK_H
#define SEND_BACK_H
#include "Action.h"

class SENDTOBACK : public Action
{

public:
	// Constructor of Send to Bacck Class
	SENDTOBACK(ApplicationManager* pApp);

	//Read Function to Read Ellipse parameters
	virtual void ReadActionParameters();

	//Execution Function For Send To Back Class
	virtual void Execute();
};

#endif
