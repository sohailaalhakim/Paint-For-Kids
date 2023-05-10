#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"

class Action;	//Forward Declaration


//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* selectedfigure;

	//Pointers to Input and Output classes
	GUI* pGUI;

	// Turky
	Action* ActList[100];
	
	// ahmed 
	bool savedLastChange;

public:	
	ApplicationManager(); 
	~ApplicationManager();

	void Run();		//to run the application
	
	// -- Action-Related Functions
	Action* CreateAction(ActionType);
	void ExecuteAction(Action*&) ; //Execute an action
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig); //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void DeleteFigure(); //Delets A Figure
	void changeFigDrawColor(Point); //change DrawColor of a Figure
	void changeFigFillColor(Point); //change FillColor of a Figure
	bool AnySelected(); //check if selected
	int GetFigureCount() ; // Return Figure Count
	// -- Interface Management Functions	
	GUI *GetGUI() const; //Return pointer to the interface
	void UpdateInterface() const;	//Redraws all the drawing window	
	void Resize_figure(GUI* pGUI, float size) const; //Afnan Resize v02

	//---Sohaila --- 
	//For Play mode
	int ApplicationManager::getFigCount() const;
	CFigure* ApplicationManager::DrawnFigs(int i) const;

	//ZIENAB
	void Send_Back(CFigure* swapped);
	void Bring_Front(CFigure* swapped);

	//Turky
	void clearInterface();
	//Turky
	void saveAll(string fileName);
	void loadAll(ifstream& fin);
	// ahmed
	void setLastSaveState(bool);
	bool getLastSaveState();
};

#endif