#include "GreetingWindow.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

System::Void Credit::GreetingWindow::confirmButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context context;

	try
	{
		if (HTSize->Text != "")
		{
			m->HTStartSize = stoi(context.marshal_as<std::string>(HTSize->Text));
		}
	}
	catch (...)
	{

	}

	if (m->HTStartSize != -1)
	{
		this->Close();
	}
	else
	{
		MessageBox::Show("Не все поля заполнены", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}
	return System::Void();
}
