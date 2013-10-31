#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "Model.h"
#include "View.h"

/*
Controller:
inbetween of Model and View
*/
class Controller
{
    private:
        Model model;
		View view;

    public:
        Controller(Model, View);
		Card dealRoleCard();


		// updates
		void updateIntro(); // is the title and other stuff
		void updateGetNumOfPlayers();
		void updateDisplayNumOfPlayers();

};
#endif // _CONTROLLER_H
