#ifndef _CONTROLLER_H
#define _CONTROLLER_H
#include "Model.h"
#include "View.h"
class Controller
{
    private:
        Model model;

    public:
        Controller(Model, View);
};
#endif // _CONTROLLER_H
