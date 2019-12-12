
#include "MyForm.h"

using namespace System;

[STAThreadAttribute]

int main()
{
	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::Run(gcnew Menu::MyForm()); //simple command that ties the project with name Menu to the MyForm
	return 0;
}

//written by: Tony Mendoza
//tested by: Tony Mendoza
//debugged by: Tony Mendoza

