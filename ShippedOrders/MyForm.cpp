//Written by: Andres Dominguez
//Tested by: Andres Dominguez
//Debugged by: Andres Dominguez
#include "MyForm.h"

using namespace System;

[STAThreadAttribute]

int main()
{
	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::Run(gcnew ShippedOrders::MyForm());
	return 0;
}


