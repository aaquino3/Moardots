#include <iostream>
#include "controller.h"
using namespace std;

int main() {
	/* DATA DECLARATION AREA ___________________________ */
	// use a normal contructor for controller only when loading
	// a game, that way the customer model data can be loaded into it.
	controller * control = new controller(); // default controller initiates its own model and view.

	control->startGame();

	char h;
	cin >> h;
	return 0;
}