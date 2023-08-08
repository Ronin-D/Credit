#include "MainWindow.h"
#include <msclr\marshal_cppstd.h>
#include"ViewModel.h"
#include"FilteredWindow.h"
#include"AVLDebugWindow.h"
#include"HTDebugWindow.h"
#include"GreetingWindow.h"
#include"AddDialog.h"
#include"GlobalFindDialog.h"
#include"DeleteDialog.h"

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

	if (viewModel.hashTable != nullptr)
	{
		viewModel.hashTable->erase();
	}
}

System::Void Credit::MainWindow::MainWindow_Load(System::Object^ sender, System::EventArgs^ e)
{
	GreetingWindow^ greetingDialog = gcnew GreetingWindow(this);
	greetingDialog->ShowDialog();
	if (HTStartSize == -1)
	{
		HTStartSize = -1;
		MessageBox::Show("Размеры хеш-таблиц не указаны или указаны некорректно.", "ОШИБКА", MessageBoxButtons::OK, MessageBoxIcon::Error);
		Application::Exit();

		return System::Void();

	}

	return System::Void();
}

System::Void Credit::MainWindow::Add_Click(System::Object^ sender, System::EventArgs^ e)
{
	AddDialog^ dialog = gcnew AddDialog(this);
	dialog->ShowDialog();
	return System::Void();
}

System::Void Credit::MainWindow::Delete_Click(System::Object^ sender, System::EventArgs^ e)
{
	DeleteDialog^ dialog = gcnew DeleteDialog(this);
	dialog->ShowDialog();
	return System::Void();
}

System::Void Credit::MainWindow::GlobalFind_Click(System::Object^ sender, System::EventArgs^ e)
{
	GlobalFindDialog^ dialog = gcnew GlobalFindDialog(this);
	dialog->ShowDialog();
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


		ListView->Items->Clear();
		clearDatafields();

		msclr::interop::marshal_context context;

		offers_opened = true;

		viewModel.path = context.marshal_as<std::string>(OpenOffers.FileName);

		 viewModel.readData(viewModel.path, HTStartSize);
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
				<< viewModel.data[i]->sum;
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
				<< viewModel.data[i]->sum;
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

System::Void Credit::MainWindow::AddItem(int series, int number, string bankName, int interestRate, int duration, int sum)
{
	if (viewModel.data.size() < HTStartSize)
	{
		HashTable::Data* credit = new HashTable::Data();
		
		credit->bankName = bankName;
		credit->series = series;
		credit->interestRate = interestRate;
		credit->number = number;
		credit->duration = duration;
		credit->sum = sum;
		credit->index = viewModel.data.size();

		if (viewModel.hashTable->find(credit) == -1)
		{
			viewModel.data.push_back(credit);
			viewModel.bankNameTree.addNewNode(bankName, credit->index);
			viewModel.interestRateTree.addNewNode(viewModel.interestRateToString(credit->interestRate), credit->index);
			viewModel.maturityTimeTree.addNewNode(viewModel.durationToString(credit->duration), credit->index);
			viewModel.sumTree.addNewNode(viewModel.sumToString(credit->sum), credit->index);

			viewModel.hashTable->put(credit);

			ListViewItem^ lvi = gcnew ListViewItem(gcnew String(series.ToString() + " " + number.ToString()));
			lvi->SubItems->Add(gcnew String(bankName.c_str()));
			lvi->SubItems->Add(gcnew String((interestRate.ToString())));
			lvi->SubItems->Add(gcnew String((duration.ToString())));
			lvi->SubItems->Add(gcnew String((sum.ToString())));

			ListView->Items->Add(lvi);
		}
		else {
			MessageBox::Show("Элемент уже есть в таблице", "Уведомление");
		}
	}
	else {
		MessageBox::Show("Таблица переполненна", "Уведомление");
	}

	return System::Void();
}

System::Void Credit::MainWindow::DeleteItem(int series, int number, string bankName)
{
	HashTable::Data* credit = new HashTable::Data();

	credit->bankName = bankName;
	credit->series = series;
	credit->number = number;
	int findRes = viewModel.hashTable->find(credit);
	if (findRes != -1)
	{
		/*BookedData::Data::BookedOffer* item = new BookedData::Data::BookedOffer();
		item->company = company;
		item->specialization = specialization;
		item->vacancy = vacancy;
		item->passport.series = series;
		item->passport.number = number;*/

		auto deleteItem = viewModel.hashTable->table[findRes].second;

		//BookedDatafields.data.erase(BookedDatafields.data.begin()+deleteItem->index);
		//swap

		auto tmp = viewModel.data.back();
		viewModel.data[viewModel.data.size() - 1] = viewModel.data[deleteItem->index];
		viewModel.data[deleteItem->index] = tmp;


		viewModel.bankNameTree.deleteNode(deleteItem->bankName, deleteItem->index);
		viewModel.interestRateTree.deleteNode(viewModel.interestRateToString(deleteItem->interestRate), deleteItem->index);
		viewModel.maturityTimeTree.deleteNode(viewModel.durationToString(deleteItem->duration), deleteItem->index);
		viewModel.sumTree.deleteNode(viewModel.sumToString(deleteItem->sum), deleteItem->index);

		viewModel.bankNameTree.changeLastIndex(tmp->bankName,
			viewModel.data.size() - 1, deleteItem->index);
		viewModel.interestRateTree.changeLastIndex(viewModel.interestRateToString(deleteItem->interestRate),
			viewModel.data.size() - 1, deleteItem->index);
		viewModel.maturityTimeTree.changeLastIndex(viewModel.durationToString(deleteItem->duration),
			viewModel.data.size() - 1, deleteItem->index);
		viewModel.sumTree.changeLastIndex(viewModel.sumToString(deleteItem->sum),
			viewModel.data.size() - 1, deleteItem->index);

		//перестроить таблицу
		auto temp1 = ListView->Items[deleteItem->index];
		ListView->Items->Remove(temp1);

		int cnt = ListView->Items->Count - 1;
		if (cnt > 0)
		{
			auto temp2 = ListView->Items[ListView->Items->Count - 1];
			ListView->Items->Remove(temp2);
			if (deleteItem->index > cnt)
			{
				deleteItem->index--;
			}
			ListView->Items->Insert(deleteItem->index, temp2);
			ListView->Items[deleteItem->index] = temp2;
		}

	/*	SHT::HTBookedOffer* htItemLast = new SHT::HTBookedOffer();
		htItemLast->company = tmp->company;
		htItemLast->specialization = tmp->specialization;
		htItemLast->vacancy = tmp->vacancy;
		htItemLast->passport.series = tmp->passport.series;
		htItemLast->passport.number = tmp->passport.number;*/

		int save = deleteItem->index;
		viewModel.hashTable->changeLastIndex(tmp, save);
		viewModel.hashTable->remove(credit);

		viewModel.data.pop_back();

	}
	else {
		MessageBox::Show("Запись не найдена", "Уведомление");
	}

	return System::Void();
}

System::Void Credit::MainWindow::GlobalFindItem(int series, int number, string bankName)
{
	msclr::interop::marshal_context context;
	FilteredWindow^ fw = gcnew FilteredWindow();
	HashTable::Data* credit = new HashTable::Data();

	credit->bankName = bankName;
	credit->series = series;
	credit->number = number;
	int index = viewModel.hashTable->find(credit);
	if (index != -1)
	{
		auto item = viewModel.hashTable->table[index].second;

		ListViewItem^ lvi = gcnew ListViewItem(gcnew String(series.ToString() + " " + number.ToString()));
		lvi->SubItems->Add(gcnew String(bankName.c_str()));
		lvi->SubItems->Add(gcnew String((item->interestRate.ToString())));
		lvi->SubItems->Add(gcnew String((item->duration.ToString())));
		lvi->SubItems->Add(gcnew String((item->sum.ToString())));

		fw->ListView->Items->Add(lvi);
		fw->ShowDialog();
	}
	else {
		MessageBox::Show("Элемент не найден", "Уведомление");
	}
	return System::Void();
}


System::Void Credit::MainWindow::DebugHT_Click(System::Object^ sender, System::EventArgs^ e)
{
	HTDebugWindow^ htdw = gcnew HTDebugWindow();

	if (viewModel.hashTable != nullptr)
	{
		int i = 0;
		for (size_t i = 0; i < viewModel.hashTable->size; i++)
		{
			auto elem = viewModel.hashTable->table[i];

			ListViewItem^ lvi = gcnew ListViewItem(gcnew String(to_string(i).c_str()));
			lvi->Text = gcnew String(i.ToString());
			lvi->SubItems->Add(gcnew String(elem.first.ToString()));

			if (viewModel.hashTable->table[i].first != 0)
			{
				lvi->SubItems->Add(gcnew String((viewModel.hashTable->hashFun(elem.second).ToString())));
				lvi->SubItems->Add(gcnew String(to_string(elem.second->index).c_str()));
				string val = to_string(elem.second->series) + "." + to_string(elem.second->number) +
					"." + elem.second->bankName + "." + to_string(elem.second->interestRate) + "."
					+ to_string(elem.second->duration) + "." + to_string(elem.second->sum);
				lvi->SubItems->Add(gcnew String(val.c_str()));

			}
			else
			{
				string emptstr = "";
				lvi->SubItems->Add(gcnew String(emptstr.c_str()));
				lvi->SubItems->Add(gcnew String(emptstr.c_str()));
				lvi->SubItems->Add(gcnew String(emptstr.c_str()));
			}
			htdw->HTListView->Items->Add(lvi);
		}
	}

	htdw->ShowDialog();
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
