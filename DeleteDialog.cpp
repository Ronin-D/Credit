#include "DeleteDialog.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

System::Void Credit::DeleteDialog::deleteButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context context;
	string passport = context.marshal_as<std::string>(PassportField->Text);
	string bankName = context.marshal_as<std::string>(BankNameField->Text);
	if (!passport.empty() && !bankName.empty())
	{
		if (bankName.find('.') == string::npos)
		{
			if (passport.size() == 11)
			{
				size_t pos = passport.find(' ');
				int series = stoi(passport.substr(0, pos));
				passport.erase(0, pos + 1);
				int number = stoi(passport);
				m->DeleteItem(series, number, bankName);
				this->Close();
			}
			else
			{
				MessageBox::Show("Некорректные пасспортные данные", "Уведомление");
			}
		}
		else {
			MessageBox::Show("поля не должны содержать символ . ", "Уведомление");
		}
	}
	else {
		MessageBox::Show("Все поля должны быть заполнены", "Уведомление");
	}
	return System::Void();
}
