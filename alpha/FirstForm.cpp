#include "FirstForm.h"

using namespace System;

[STAThreadAttribute]	//i don't even remember what this does..

int main()
{
	Windows::Forms::Application::EnableVisualStyles();	//makes the buttons and stuff look less ugly...
	Windows::Forms::Application::Run(gcnew alpha::FirstForm());
	return 0;
}