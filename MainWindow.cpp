#include "MainWindow.h"
#include <msclr\marshal_cppstd.h>
#include"ViewModel.h"

using namespace System;
using namespace System::Windows::Forms;

ViewModel viewModel;

void clearDatafields()
{
	viewModel.data.clear();

	viewModel.bankNameTree.erase();
	viewModel.interestRateTree.erase();
	viewModel.maturityTimeTree.erase();
	viewModel.sumTree.erase();

	/*if (BookedDatafields.hashTable != nullptr)
	{
		BookedDatafields.hashTable->erase();
	}*/
}

System::Void Credit::MainWindow::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::GlobalFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::BankNameFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::InterestRateFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::MaturityTimeFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::SumFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::OpenTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog OpenOffers;

	// ������ ������ ��� ���������� ��� ������ �����
	OpenOffers.Title = "������� ���� credits.txt";

	// ������ ����������� ����������, �� ������� ����������� ������
	OpenOffers.InitialDirectory = "C:\\";

	// ������ ������� �� ���������� ��� �������� �����
	OpenOffers.Filter = "��������� ���� (*.txt)|credits.txt";
	OpenOffers.FilterIndex = 1;

	// ����������� �������� ��������
	OpenOffers.ShowDialog();

	// ����� �������� �����
	bool offers_opened = false;

	//�������� ����� Offers, ���������� ����� listview
	if (OpenOffers.FileName != "")
	{


		//����� ����� ������ ��������������
		this->ListView->Visible = true;
		this->OperationList->Visible = true;// ������������� ���� �� ��������� � �������������


		/*OffersListView->Items->Clear();
		clearOffersDatafields();*/


		msclr::interop::marshal_context context;

		offers_opened = true;

		viewModel.path = context.marshal_as<std::string>(OpenOffers.FileName);

		 viewModel.readData(viewModel.path, 10);
		for (size_t i = 0; i <viewModel.data.size(); i++)
		{
			ListViewItem^ lvi = gcnew ListViewItem(gcnew String(viewModel.data[i]->series.ToString()+" "+viewModel.data[i]->number.ToString()));
			lvi->SubItems->Add(gcnew String(viewModel.data[i]->bankName.c_str()));
			lvi->SubItems->Add(gcnew String((viewModel.data[i]->interestRate.ToString())));
			lvi->SubItems->Add(gcnew String((viewModel.data[i]->duration.ToString())));
			lvi->SubItems->Add(gcnew String((viewModel.data[i]->sum.ToString())));
			ListView->Items->Add(lvi);
		}

	}

	// ����� ������ ��� ����������\�������������� �����
	if (!offers_opened)
	{
		MessageBox::Show("���� � ����� ��� ��� ���� \"offers.txt\" ������ �����������.\n���������� ������� ��� �����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	return System::Void();
}

System::Void Credit::MainWindow::CloseTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (viewModel.path.empty())
	{
		MessageBox::Show("��� �������� ������.", "������� ����", MessageBoxButtons::OK, MessageBoxIcon::Information);

		return System::Void();
	}

	if (MessageBox::Show("�� ������, ��� ������ ������� ����?\n��� ����� �������� � ������ ������������� ������.",
		"������� ����", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		viewModel.path = "";


		this->ListView->Visible = false;
		this->OperationList->Visible = false;

		ListView->Items->Clear();

		clearDatafields();
	}

	return System::Void();
}

System::Void Credit::MainWindow::SaveTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	string OffersSaveDir = viewModel.path;

	ofstream WriteOffers; //offers=credits
	WriteOffers.open(OffersSaveDir);

	if (WriteOffers.is_open())
	{

		for (int i = 0; i < viewModel.data.size(); i++)
		{
			WriteOffers << viewModel.data[i]->series
				<< "."
				<< viewModel.data[i]->number
				<< "."
				<< viewModel.data[i]->bankName
				<< "."
				<< viewModel.data[i]->interestRate
				<< "."
				<< viewModel.data[i]->duration
				<< "."
				<< viewModel.data[i]->sum
				<< "."
				<< endl;
		}
		WriteOffers.close();

		if (!WriteOffers.is_open())
		{
			MessageBox::Show("����� ��������� �������.", "��������� �����", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return System::Void();
		}
		else
		{
			MessageBox::Show("������ ��� ������ � ����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return System::Void();
		}
	}
	else
	{
		MessageBox::Show("������������ �������� ������ ��� ������ ����������� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}

	return System::Void();
}

System::Void Credit::MainWindow::SaveAsTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (viewModel.path.empty())
	{
		MessageBox::Show("��� �������� ������.", "��������� �����", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return System::Void();
	}

	SaveFileDialog SaveOffers;

	// ������ ����������� ����������, �� ������� ����������� ������
	SaveOffers.InitialDirectory = "C:\\";

	// ������ ������� �� ���������� ��� �������� �����
	SaveOffers.Filter = "��������� ���� (*.txt)|*.txt";
	SaveOffers.FilterIndex = 2;

	SaveOffers.ShowDialog();

	msclr::interop::marshal_context context;

	string OffersSaveDir = context.marshal_as<std::string>(SaveOffers.FileName);


	if (OffersSaveDir == "")
	{
		MessageBox::Show("���� � ����� �\\��� ���� �����������", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}

	ofstream WriteOffers, WriteBooked;
	WriteOffers.open(OffersSaveDir);

	if (WriteOffers.is_open() && WriteBooked.is_open())
	{

		for (int i = 0; i < viewModel.data.size(); i++)
		{
			WriteOffers << viewModel.data[i]->series
				<< "."
				<< viewModel.data[i]->number
				<< "."
				<< viewModel.data[i]->bankName
				<< "."
				<< viewModel.data[i]->interestRate
				<< "."
				<< viewModel.data[i]->duration
				<< "."
				<< viewModel.data[i]->sum
				<< "."
				<< endl;
		}
		WriteOffers.close();

		if (!WriteOffers.is_open())
		{
			MessageBox::Show("����� ��������� �������.", "��������� �����", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return System::Void();
		}
		else
		{
			MessageBox::Show("������ ��� ������ � ����.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return System::Void();
		}
	}
	else
	{
		MessageBox::Show("������������ �������� ������ ��� ������ ����������� ������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}

	return System::Void();
}

System::Void Credit::MainWindow::ExitTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("�� ������, ��� ������ �����?\n��� ����� �������� � ������ ������������� ������.",
		"������� ����", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}

	return System::Void();
}

System::Void Credit::MainWindow::ReferenceTools_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::AboutTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::DebugHT_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}


System::Void Credit::MainWindow::DebugAVLBankName_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::DebugAVLInterestRate_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::DebugAVLMaturityTime_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void Credit::MainWindow::DebugAVLSum_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
