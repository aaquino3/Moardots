#include "Controller.h"

Controller::Controller(Model model, View view)
{
	this->model = model;
	this->view = view;
}

Card Controller::dealRoleCard()
{
	return model.dealRoleCard();
}

void Controller::updateIntro()
{
	view.updateIntro(model.getTitle());
}