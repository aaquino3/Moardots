#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "Model.h"
#include "View.h"
class Controller
{
    private:
        Model model;
		View view;

    public:
        Controller(Model, View);
		Card dealRoleCard();


		// updates
		void updateIntro();
};
#endif // _CONTROLLER_H
