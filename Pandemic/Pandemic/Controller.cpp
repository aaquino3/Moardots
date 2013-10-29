#include "Controller.h"

Controller::Controller(Model model, View view)
{
	this->model = model;
	this->view = view;
}


void Controller::updateIntro()
{
	view.updateIntro(model.getTitle());
}

void Controller::updateGetNumOfPlayers()
{
	model.setNumberOfPlayers(view.updateGetNumOfPlayers());
}

void Controller::updateDisplayNumOfPlayers()
{
	view.printNumOfPlayers(model.getNumberOfPlayers());
}