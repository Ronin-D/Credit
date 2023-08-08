#include "AddDialog.h"
#include <msclr\marshal_cppstd.h>
#include <iostream>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;

System::Void Credit::AddDialog::confirmButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	msclr::interop::marshal_context context;
	string passport = context.marshal_as<std::string>(PassportField->Text);
	string bankName = context.marshal_as<std::string>(BankNameField->Text);
	string interestRate = context.marshal_as<std::string>(InterestRateField->Text);
	string duration = context.marshal_as<std::string>(DurationField->Text);
	string sum = context.marshal_as<std::string>(SumField->Text);
	if (!passport.empty() && !bankName.empty() && !interestRate.empty() && 
		!duration.empty()&&!sum.empty())
	{
		if (bankName.find('.') == string::npos)
		{
			if (sum.length() == 5)
			{
				if (duration != "0")
				{
					if (interestRate != "0")
					{
						try
						{
							size_t pos = passport.find(' ');
							int series = stoi(passport.substr(0, pos));
							passport.erase(0, pos + 1);
							int number = stoi(passport);
							m->AddItem(series, number, bankName, stoi(interestRate), stoi(duration), stoi(sum));
							this->Close();
						}
						catch (...)
						{
							MessageBox::Show("Некорректные пасспортные данные", "Уведомление");
						}
					}
					else {
						MessageBox::Show("Процентная ставка не может равняться 0", "Уведомление");
					}
				}
				else {
					MessageBox::Show("Срок погашения не может равняться 0", "Уведомление");
				}
			}
			else {
				MessageBox::Show("Сумма должна быть >=10 000", "Уведомление");
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
