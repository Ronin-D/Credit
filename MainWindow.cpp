#include "MainWindow.h"
#include <msclr\marshal_cppstd.h>
#include"ViewModel.h"
#include"FilteredWindow.h"
#include"AVLDebugWindow.h"
#include"HTDebugWindow.h"

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

	if (BankFindline->Text == "")
	{
		return System::Void();
	}
	int compareCnt = 1;
	msclr::interop::marshal_context context;
	string bankName= context.marshal_as<std::string>(BankFindline->Text);
	FilteredWindow^ fw = gcnew FilteredWindow();
	auto foundItems = viewModel.FindByBankName(bankName, compareCnt);
	if (foundItems.size() != 0)
	{
		for (size_t i = 0; i < foundItems.size(); i++)
		{

			ListViewItem^ lvi = gcnew ListViewItem(gcnew String(foundItems[i]->series.ToString() + " " + foundItems[i]->number.ToString()));
			lvi->SubItems->Add(gcnew String(foundItems[i]->bankName.c_str()));
			lvi->SubItems->Add(gcnew String((foundItems[i]->interestRate.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->duration.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->sum.ToString())));
			fw->ListView->Items->Add(lvi);
		}
		fw->Text = gcnew String("количество сравнений: " + compareCnt.ToString());
		fw->ShowDialog();
	}
	else {
		MessageBox::Show("Запись не найдена", "Уведомление");
	}

	return System::Void();
}

System::Void Credit::MainWindow::InterestRateFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (InterestRateFindline->Text == "")
	{
		return System::Void();
	}
	int compareCnt = 1;
	msclr::interop::marshal_context context;
	int interestRate = stoi(context.marshal_as<std::string>(InterestRateFindline->Text));
	FilteredWindow^ fw = gcnew FilteredWindow();
	auto foundItems = viewModel.FindByInterestRate(interestRate, compareCnt);
	if (foundItems.size() != 0)
	{
		for (size_t i = 0; i < foundItems.size(); i++)
		{

			ListViewItem^ lvi = gcnew ListViewItem(gcnew String(foundItems[i]->series.ToString() + " " + foundItems[i]->number.ToString()));
			lvi->SubItems->Add(gcnew String(foundItems[i]->bankName.c_str()));
			lvi->SubItems->Add(gcnew String((foundItems[i]->interestRate.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->duration.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->sum.ToString())));
			fw->ListView->Items->Add(lvi);
		}
		fw->Text = gcnew String("количество сравнений: " + compareCnt.ToString());
		fw->ShowDialog();
	}
	else {
		MessageBox::Show("Запись не найдена", "Уведомление");
	}

	return System::Void();
}

System::Void Credit::MainWindow::MaturityTimeFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MaturityRateFindLine->Text == "")
	{
		return System::Void();
	}
	int compareCnt = 1;
	msclr::interop::marshal_context context;
	int duration = stoi(context.marshal_as<std::string>(MaturityRateFindLine->Text));
	FilteredWindow^ fw = gcnew FilteredWindow();
	auto foundItems = viewModel.FindByMaturityTime(duration, compareCnt);
	if (foundItems.size() != 0)
	{
		for (size_t i = 0; i < foundItems.size(); i++)
		{

			ListViewItem^ lvi = gcnew ListViewItem(gcnew String(foundItems[i]->series.ToString() + " " + foundItems[i]->number.ToString()));
			lvi->SubItems->Add(gcnew String(foundItems[i]->bankName.c_str()));
			lvi->SubItems->Add(gcnew String((foundItems[i]->interestRate.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->duration.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->sum.ToString())));
			fw->ListView->Items->Add(lvi);
		}
		fw->Text = gcnew String("количество сравнений: " + compareCnt.ToString());
		fw->ShowDialog();
	}
	else {
		MessageBox::Show("Запись не найдена", "Уведомление");
	}

	return System::Void();
}

System::Void Credit::MainWindow::SumFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (SumFindLine->Text == "")
	{
		return System::Void();
	}
	int compareCnt = 1;
	msclr::interop::marshal_context context;
	int sum = stoi(context.marshal_as<std::string>(SumFindLine->Text));
	FilteredWindow^ fw = gcnew FilteredWindow();
	auto foundItems = viewModel.FindBySum(sum, compareCnt);
	if (foundItems.size() != 0)
	{
		for (size_t i = 0; i < foundItems.size(); i++)
		{

			ListViewItem^ lvi = gcnew ListViewItem(gcnew String(foundItems[i]->series.ToString() + " " + foundItems[i]->number.ToString()));
			lvi->SubItems->Add(gcnew String(foundItems[i]->bankName.c_str()));
			lvi->SubItems->Add(gcnew String((foundItems[i]->interestRate.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->duration.ToString())));
			lvi->SubItems->Add(gcnew String((foundItems[i]->sum.ToString())));
			fw->ListView->Items->Add(lvi);
		}
		fw->Text = gcnew String("количество сравнений: " + compareCnt.ToString());
		fw->ShowDialog();
	}
	else {
		MessageBox::Show("Запись не найдена", "Уведомление");
	}

	return System::Void();
}

System::Void Credit::MainWindow::OpenTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog OpenOffers;

	// Задает тайтлы для диалоговых окн выбора файла
	OpenOffers.Title = "Открыть файл credits.txt";

	// Задает изначальную директорию, на которой открывается диалог
	OpenOffers.InitialDirectory = "C:\\";

	// Задают фильтры по расширению или названию файла
	OpenOffers.Filter = "Текстовый файл (*.txt)|credits.txt";
	OpenOffers.FilterIndex = 1;

	// поочередное открытие диалогов
	OpenOffers.ShowDialog();

	// флаги открытия файла
	bool offers_opened = false;

	//Открытие файла Offers, заполнение полей listview
	if (OpenOffers.FileName != "")
	{


		//Вывод общей панели взаимодействия
		this->ListView->Visible = true;
		this->OperationList->Visible = true;// визуализирует поле со вкладками и инструментами


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

	// Вывод ошибок при неоткрытии\некорректности файла
	if (!offers_opened)
	{
		MessageBox::Show("Путь к файлу или сам файл \"offers.txt\" указан некорректно.\nПопробуйте указать его снова.", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	return System::Void();
}

System::Void Credit::MainWindow::CloseTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (viewModel.path.empty())
	{
		MessageBox::Show("Нет открытых файлов.", "Закрыть файл", MessageBoxButtons::OK, MessageBoxIcon::Information);

		return System::Void();
	}

	if (MessageBox::Show("Вы уерены, что хотите закрыть файл?\nЭто может привести к потере несохраненных данных.",
		"Закрыть файл", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
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
			MessageBox::Show("Файлы сохранены успешно.", "Сохранить файлы", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return System::Void();
		}
		else
		{
			MessageBox::Show("Ошибка при записи в файл.", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return System::Void();
		}
	}
	else
	{
		MessageBox::Show("Некорректное открытие файлов для записи сохраненных данных.", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}

	return System::Void();
}

System::Void Credit::MainWindow::SaveAsTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (viewModel.path.empty())
	{
		MessageBox::Show("Нет открытых файлов.", "Сохранить файлы", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return System::Void();
	}

	SaveFileDialog SaveOffers;

	// Задает изначальную директорию, на которой открывается диалог
	SaveOffers.InitialDirectory = "C:\\";

	// Задают фильтры по расширению или названию файла
	SaveOffers.Filter = "Текстовый файл (*.txt)|*.txt";
	SaveOffers.FilterIndex = 2;

	SaveOffers.ShowDialog();

	msclr::interop::marshal_context context;

	string OffersSaveDir = context.marshal_as<std::string>(SaveOffers.FileName);


	if (OffersSaveDir == "")
	{
		MessageBox::Show("Путь к файлу и\\или файл некорректен", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
			MessageBox::Show("Файлы сохранены успешно.", "Сохранить файлы", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return System::Void();
		}
		else
		{
			MessageBox::Show("Ошибка при записи в файл.", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return System::Void();
		}
	}
	else
	{
		MessageBox::Show("Некорректное открытие файлов для записи сохраненных данных.", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return System::Void();
	}

	return System::Void();
}

System::Void Credit::MainWindow::ExitTool_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Вы уерены, что хотите выйти?\nЭто может привести к потере несохраненных данных.",
		"Закрыть файл", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
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

//[ DEBUG ]
System::Void Credit::MainWindow::DebugAVLBankName_Click(System::Object^ sender, System::EventArgs^ e)
{
	string text = viewModel.bankNameTree.print(5);
	AVLDebugWindow^ dialog = gcnew AVLDebugWindow(text);
	dialog->ShowDialog();
	return System::Void();
}

System::Void Credit::MainWindow::DebugAVLInterestRate_Click(System::Object^ sender, System::EventArgs^ e)
{
	string text = viewModel.interestRateTree.print(5);
	AVLDebugWindow^ dialog = gcnew AVLDebugWindow(text);
	dialog->ShowDialog();
	return System::Void();
}

System::Void Credit::MainWindow::DebugAVLMaturityTime_Click(System::Object^ sender, System::EventArgs^ e)
{
	string text = viewModel.maturityTimeTree.print(5);
	AVLDebugWindow^ dialog = gcnew AVLDebugWindow(text);
	dialog->ShowDialog();
	return System::Void();
}

System::Void Credit::MainWindow::DebugAVLSum_Click(System::Object^ sender, System::EventArgs^ e)
{
	string text = viewModel.sumTree.print(5);
	AVLDebugWindow^ dialog = gcnew AVLDebugWindow(text);
	dialog->ShowDialog();
	return System::Void();
}
