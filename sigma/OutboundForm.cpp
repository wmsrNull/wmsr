/*
written by: Alejandro Vasquez
tested by: Alejandro Vasquez
debugged by: Alejandro Vasquez

*/

#include "OutboundForm.h"

using namespace System;
[STAThreadAttribute]	//this is necessary for some reason

int main()
{
	Windows::Forms::Application::EnableVisualStyles();				//makes the window use newer button designs and etc.
	Windows::Forms::Application::Run(gcnew sigma::OutboundForm());	//i have this automatically opening storage form due to bugs...
	return 0;
}