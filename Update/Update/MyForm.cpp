#include "MyForm.h"

using namespace System;

[STAThreadAttribute]

int main()
{
	Windows::Forms::Application::EnableVisualStyles();
	Windows::Forms::Application::Run(gcnew Update::MyForm());
	return 0;
}