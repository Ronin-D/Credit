#pragma once
#include<iostream>
namespace Credit {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		int loaded = 0;
		int HTStartSize = -1;
		MainWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ ListView;
	protected:

	protected:
	private: System::Windows::Forms::ColumnHeader^ ColumnPassport;
	private: System::Windows::Forms::ColumnHeader^ ColumnBankName;
	private: System::Windows::Forms::ColumnHeader^ ColumnInterestRate;
	private: System::Windows::Forms::ColumnHeader^ ColumnMaturityTime;
	private: System::Windows::Forms::ColumnHeader^ ColumnSum;
	private: System::Windows::Forms::GroupBox^ OperationList;

	private: System::Windows::Forms::Button^ GlobalFind;



	private: System::Windows::Forms::Label^ BankNameLabel;
	private: System::Windows::Forms::TextBox^ BankFindline;
	private: System::Windows::Forms::Button^ BankNameFind;



	private: System::Windows::Forms::Label^ InterestRateLabel;
	private: System::Windows::Forms::Label^ MaturityTimeLabel;






	private: System::Windows::Forms::Button^ InterestRateFind;
	private: System::Windows::Forms::Button^ MaturityTimeFind;





	private: System::Windows::Forms::Button^ Delete;

	private: System::Windows::Forms::Button^ Add;

	private: System::Windows::Forms::MenuStrip^ TopToolMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ ProgrammTools;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenTool;
	private: System::Windows::Forms::ToolStripMenuItem^ CloseTool;
	private: System::Windows::Forms::ToolStripMenuItem^ SaveTool;
	private: System::Windows::Forms::ToolStripMenuItem^ SaveAsTool;
	private: System::Windows::Forms::ToolStripMenuItem^ ExitTool;


	private: System::Windows::Forms::ToolStripMenuItem^ DebugTools;






	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedToolGroup;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedHT;

	private: System::Windows::Forms::ToolStripMenuItem^ DebugAVLBankName;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugAVLInterestRate;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugAVLMaturityTime;





	private: System::Windows::Forms::MaskedTextBox^ InterestRateFindline;
	private: System::Windows::Forms::MaskedTextBox^ SumFindLine;


	private: System::Windows::Forms::MaskedTextBox^ MaturityRateFindLine;


	private: System::Windows::Forms::Label^ SumLabel;
	private: System::Windows::Forms::Button^ SumFind;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugAVLSum;











	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ListView = (gcnew System::Windows::Forms::ListView());
			this->ColumnPassport = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnBankName = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnInterestRate = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnMaturityTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnSum = (gcnew System::Windows::Forms::ColumnHeader());
			this->OperationList = (gcnew System::Windows::Forms::GroupBox());
			this->SumFindLine = (gcnew System::Windows::Forms::MaskedTextBox());
			this->MaturityRateFindLine = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SumLabel = (gcnew System::Windows::Forms::Label());
			this->SumFind = (gcnew System::Windows::Forms::Button());
			this->InterestRateFindline = (gcnew System::Windows::Forms::MaskedTextBox());
			this->GlobalFind = (gcnew System::Windows::Forms::Button());
			this->BankNameLabel = (gcnew System::Windows::Forms::Label());
			this->BankFindline = (gcnew System::Windows::Forms::TextBox());
			this->BankNameFind = (gcnew System::Windows::Forms::Button());
			this->InterestRateLabel = (gcnew System::Windows::Forms::Label());
			this->MaturityTimeLabel = (gcnew System::Windows::Forms::Label());
			this->InterestRateFind = (gcnew System::Windows::Forms::Button());
			this->MaturityTimeFind = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->Add = (gcnew System::Windows::Forms::Button());
			this->TopToolMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->ProgrammTools = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CloseTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveAsTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugTools = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedToolGroup = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedHT = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugAVLBankName = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugAVLInterestRate = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugAVLMaturityTime = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugAVLSum = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OperationList->SuspendLayout();
			this->TopToolMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// ListView
			// 
			this->ListView->AutoArrange = false;
			this->ListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->ColumnPassport, this->ColumnBankName,
					this->ColumnInterestRate, this->ColumnMaturityTime, this->ColumnSum
			});
			this->ListView->FullRowSelect = true;
			this->ListView->GridLines = true;
			this->ListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->ListView->HideSelection = false;
			this->ListView->Location = System::Drawing::Point(221, 63);
			this->ListView->Name = L"ListView";
			this->ListView->Size = System::Drawing::Size(1529, 777);
			this->ListView->TabIndex = 3;
			this->ListView->UseCompatibleStateImageBehavior = false;
			this->ListView->View = System::Windows::Forms::View::Details;
			this->ListView->Visible = false;
			this->ListView->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::BookedListView_SelectedIndexChanged);
			// 
			// ColumnPassport
			// 
			this->ColumnPassport->Text = L"Пасспорт клиента";
			this->ColumnPassport->Width = 194;
			// 
			// ColumnBankName
			// 
			this->ColumnBankName->Text = L"Название банка";
			this->ColumnBankName->Width = 175;
			// 
			// ColumnInterestRate
			// 
			this->ColumnInterestRate->Text = L"Процентная ставка";
			this->ColumnInterestRate->Width = 189;
			// 
			// ColumnMaturityTime
			// 
			this->ColumnMaturityTime->Text = L"Срок погашения";
			this->ColumnMaturityTime->Width = 207;
			// 
			// ColumnSum
			// 
			this->ColumnSum->Text = L"Сумма";
			this->ColumnSum->Width = 100;
			// 
			// OperationList
			// 
			this->OperationList->Controls->Add(this->SumFindLine);
			this->OperationList->Controls->Add(this->MaturityRateFindLine);
			this->OperationList->Controls->Add(this->SumLabel);
			this->OperationList->Controls->Add(this->SumFind);
			this->OperationList->Controls->Add(this->InterestRateFindline);
			this->OperationList->Controls->Add(this->GlobalFind);
			this->OperationList->Controls->Add(this->BankNameLabel);
			this->OperationList->Controls->Add(this->BankFindline);
			this->OperationList->Controls->Add(this->BankNameFind);
			this->OperationList->Controls->Add(this->InterestRateLabel);
			this->OperationList->Controls->Add(this->MaturityTimeLabel);
			this->OperationList->Controls->Add(this->InterestRateFind);
			this->OperationList->Controls->Add(this->MaturityTimeFind);
			this->OperationList->Controls->Add(this->Delete);
			this->OperationList->Controls->Add(this->Add);
			this->OperationList->Location = System::Drawing::Point(12, 52);
			this->OperationList->Name = L"OperationList";
			this->OperationList->Size = System::Drawing::Size(203, 806);
			this->OperationList->TabIndex = 4;
			this->OperationList->TabStop = false;
			this->OperationList->Text = L"Операции";
			this->OperationList->Visible = false;
			// 
			// SumFindLine
			// 
			this->SumFindLine->Location = System::Drawing::Point(6, 705);
			this->SumFindLine->Mask = L"0000000";
			this->SumFindLine->Name = L"SumFindLine";
			this->SumFindLine->ResetOnPrompt = false;
			this->SumFindLine->Size = System::Drawing::Size(193, 26);
			this->SumFindLine->TabIndex = 22;
			// 
			// MaturityRateFindLine
			// 
			this->MaturityRateFindLine->Location = System::Drawing::Point(4, 583);
			this->MaturityRateFindLine->Mask = L"0000000";
			this->MaturityRateFindLine->Name = L"MaturityRateFindLine";
			this->MaturityRateFindLine->ResetOnPrompt = false;
			this->MaturityRateFindLine->Size = System::Drawing::Size(193, 26);
			this->MaturityRateFindLine->TabIndex = 21;
			// 
			// SumLabel
			// 
			this->SumLabel->AutoSize = true;
			this->SumLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->SumLabel->Location = System::Drawing::Point(6, 681);
			this->SumLabel->Name = L"SumLabel";
			this->SumLabel->Size = System::Drawing::Size(58, 20);
			this->SumLabel->TabIndex = 20;
			this->SumLabel->Text = L"Сумма";
			// 
			// SumFind
			// 
			this->SumFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->SumFind->Location = System::Drawing::Point(6, 737);
			this->SumFind->Name = L"SumFind";
			this->SumFind->Size = System::Drawing::Size(193, 51);
			this->SumFind->TabIndex = 18;
			this->SumFind->Text = L"Поиск";
			this->SumFind->UseVisualStyleBackColor = true;
			this->SumFind->Click += gcnew System::EventHandler(this, &MainWindow::SumFind_Click);
			// 
			// InterestRateFindline
			// 
			this->InterestRateFindline->Location = System::Drawing::Point(6, 473);
			this->InterestRateFindline->Mask = L"0000000";
			this->InterestRateFindline->Name = L"InterestRateFindline";
			this->InterestRateFindline->ResetOnPrompt = false;
			this->InterestRateFindline->Size = System::Drawing::Size(193, 26);
			this->InterestRateFindline->TabIndex = 17;
			// 
			// GlobalFind
			// 
			this->GlobalFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->GlobalFind->Location = System::Drawing::Point(9, 148);
			this->GlobalFind->Name = L"GlobalFind";
			this->GlobalFind->Size = System::Drawing::Size(193, 51);
			this->GlobalFind->TabIndex = 16;
			this->GlobalFind->Text = L"Поиск";
			this->GlobalFind->UseVisualStyleBackColor = true;
			this->GlobalFind->Click += gcnew System::EventHandler(this, &MainWindow::GlobalFind_Click);
			// 
			// BankNameLabel
			// 
			this->BankNameLabel->AutoSize = true;
			this->BankNameLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BankNameLabel->Location = System::Drawing::Point(6, 342);
			this->BankNameLabel->Name = L"BankNameLabel";
			this->BankNameLabel->Size = System::Drawing::Size(131, 20);
			this->BankNameLabel->TabIndex = 14;
			this->BankNameLabel->Text = L"Название банка";
			// 
			// BankFindline
			// 
			this->BankFindline->Location = System::Drawing::Point(6, 366);
			this->BankFindline->Name = L"BankFindline";
			this->BankFindline->Size = System::Drawing::Size(193, 26);
			this->BankFindline->TabIndex = 13;
			// 
			// BankNameFind
			// 
			this->BankNameFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BankNameFind->Location = System::Drawing::Point(5, 396);
			this->BankNameFind->Name = L"BankNameFind";
			this->BankNameFind->Size = System::Drawing::Size(193, 51);
			this->BankNameFind->TabIndex = 12;
			this->BankNameFind->Text = L"Поиск";
			this->BankNameFind->UseVisualStyleBackColor = true;
			this->BankNameFind->Click += gcnew System::EventHandler(this, &MainWindow::BankNameFind_Click);
			// 
			// InterestRateLabel
			// 
			this->InterestRateLabel->AutoSize = true;
			this->InterestRateLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->InterestRateLabel->Location = System::Drawing::Point(6, 449);
			this->InterestRateLabel->Name = L"InterestRateLabel";
			this->InterestRateLabel->Size = System::Drawing::Size(158, 20);
			this->InterestRateLabel->TabIndex = 11;
			this->InterestRateLabel->Text = L"Процентная ставка";
			// 
			// MaturityTimeLabel
			// 
			this->MaturityTimeLabel->AutoSize = true;
			this->MaturityTimeLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->MaturityTimeLabel->Location = System::Drawing::Point(5, 559);
			this->MaturityTimeLabel->Name = L"MaturityTimeLabel";
			this->MaturityTimeLabel->Size = System::Drawing::Size(133, 20);
			this->MaturityTimeLabel->TabIndex = 9;
			this->MaturityTimeLabel->Text = L"Срок погашения";
			// 
			// InterestRateFind
			// 
			this->InterestRateFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->InterestRateFind->Location = System::Drawing::Point(5, 505);
			this->InterestRateFind->Name = L"InterestRateFind";
			this->InterestRateFind->Size = System::Drawing::Size(193, 51);
			this->InterestRateFind->TabIndex = 5;
			this->InterestRateFind->Text = L"Поиск";
			this->InterestRateFind->UseVisualStyleBackColor = true;
			this->InterestRateFind->Click += gcnew System::EventHandler(this, &MainWindow::InterestRateFind_Click);
			// 
			// MaturityTimeFind
			// 
			this->MaturityTimeFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->MaturityTimeFind->Location = System::Drawing::Point(5, 615);
			this->MaturityTimeFind->Name = L"MaturityTimeFind";
			this->MaturityTimeFind->Size = System::Drawing::Size(193, 51);
			this->MaturityTimeFind->TabIndex = 4;
			this->MaturityTimeFind->Text = L"Поиск";
			this->MaturityTimeFind->UseVisualStyleBackColor = true;
			this->MaturityTimeFind->Click += gcnew System::EventHandler(this, &MainWindow::MaturityTimeFind_Click);
			// 
			// Delete
			// 
			this->Delete->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Delete->Location = System::Drawing::Point(5, 91);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(193, 51);
			this->Delete->TabIndex = 1;
			this->Delete->Text = L"Удалить";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &MainWindow::Delete_Click);
			// 
			// Add
			// 
			this->Add->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Add->Location = System::Drawing::Point(5, 35);
			this->Add->Name = L"Add";
			this->Add->Size = System::Drawing::Size(193, 51);
			this->Add->TabIndex = 0;
			this->Add->Text = L"Добавить";
			this->Add->UseVisualStyleBackColor = true;
			this->Add->Click += gcnew System::EventHandler(this, &MainWindow::Add_Click);
			// 
			// TopToolMenu
			// 
			this->TopToolMenu->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->TopToolMenu->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->TopToolMenu->ImageScalingSize = System::Drawing::Size(28, 28);
			this->TopToolMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->ProgrammTools, this->DebugTools });
			this->TopToolMenu->Location = System::Drawing::Point(0, 0);
			this->TopToolMenu->Name = L"TopToolMenu";
			this->TopToolMenu->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->TopToolMenu->Size = System::Drawing::Size(1762, 33);
			this->TopToolMenu->TabIndex = 5;
			this->TopToolMenu->Text = L"Инструменты";
			// 
			// ProgrammTools
			// 
			this->ProgrammTools->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->OpenTool,
					this->CloseTool, this->SaveTool, this->SaveAsTool, this->ExitTool
			});
			this->ProgrammTools->Name = L"ProgrammTools";
			this->ProgrammTools->Size = System::Drawing::Size(125, 29);
			this->ProgrammTools->Text = L"Программа";
			// 
			// OpenTool
			// 
			this->OpenTool->Name = L"OpenTool";
			this->OpenTool->Size = System::Drawing::Size(244, 34);
			this->OpenTool->Text = L"Открыть";
			this->OpenTool->Click += gcnew System::EventHandler(this, &MainWindow::OpenTool_Click);
			// 
			// CloseTool
			// 
			this->CloseTool->Name = L"CloseTool";
			this->CloseTool->Size = System::Drawing::Size(244, 34);
			this->CloseTool->Text = L"Закрыть";
			this->CloseTool->Click += gcnew System::EventHandler(this, &MainWindow::CloseTool_Click);
			// 
			// SaveTool
			// 
			this->SaveTool->Name = L"SaveTool";
			this->SaveTool->Size = System::Drawing::Size(244, 34);
			this->SaveTool->Text = L"Сохранить";
			this->SaveTool->Click += gcnew System::EventHandler(this, &MainWindow::SaveTool_Click);
			// 
			// SaveAsTool
			// 
			this->SaveAsTool->Name = L"SaveAsTool";
			this->SaveAsTool->Size = System::Drawing::Size(244, 34);
			this->SaveAsTool->Text = L"Сохранить как...";
			this->SaveAsTool->Click += gcnew System::EventHandler(this, &MainWindow::SaveAsTool_Click);
			// 
			// ExitTool
			// 
			this->ExitTool->Name = L"ExitTool";
			this->ExitTool->Size = System::Drawing::Size(244, 34);
			this->ExitTool->Text = L"Выход";
			this->ExitTool->Click += gcnew System::EventHandler(this, &MainWindow::ExitTool_Click);
			// 
			// DebugTools
			// 
			this->DebugTools->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->DebugBookedToolGroup });
			this->DebugTools->Name = L"DebugTools";
			this->DebugTools->Size = System::Drawing::Size(95, 29);
			this->DebugTools->Text = L"Отладка";
			// 
			// DebugBookedToolGroup
			// 
			this->DebugBookedToolGroup->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->DebugBookedHT,
					this->DebugAVLBankName, this->DebugAVLInterestRate, this->DebugAVLMaturityTime, this->DebugAVLSum
			});
			this->DebugBookedToolGroup->Name = L"DebugBookedToolGroup";
			this->DebugBookedToolGroup->Size = System::Drawing::Size(304, 34);
			this->DebugBookedToolGroup->Text = L"Справочник \"Кредиты\"";
			// 
			// DebugBookedHT
			// 
			this->DebugBookedHT->Name = L"DebugBookedHT";
			this->DebugBookedHT->Size = System::Drawing::Size(387, 34);
			this->DebugBookedHT->Text = L"Хеш-таблица";
			this->DebugBookedHT->Click += gcnew System::EventHandler(this, &MainWindow::DebugHT_Click);
			// 
			// DebugAVLBankName
			// 
			this->DebugAVLBankName->Name = L"DebugAVLBankName";
			this->DebugAVLBankName->Size = System::Drawing::Size(387, 34);
			this->DebugAVLBankName->Text = L"АВЛ-дерево (Название банка)";
			this->DebugAVLBankName->Click += gcnew System::EventHandler(this, &MainWindow::DebugAVLBankName_Click);
			// 
			// DebugAVLInterestRate
			// 
			this->DebugAVLInterestRate->Name = L"DebugAVLInterestRate";
			this->DebugAVLInterestRate->Size = System::Drawing::Size(387, 34);
			this->DebugAVLInterestRate->Text = L"АВЛ-дерево (Процентная ставка)";
			this->DebugAVLInterestRate->Click += gcnew System::EventHandler(this, &MainWindow::DebugAVLInterestRate_Click);
			// 
			// DebugAVLMaturityTime
			// 
			this->DebugAVLMaturityTime->Name = L"DebugAVLMaturityTime";
			this->DebugAVLMaturityTime->Size = System::Drawing::Size(387, 34);
			this->DebugAVLMaturityTime->Text = L"АВЛ-дерево (Срок погашения)";
			this->DebugAVLMaturityTime->Click += gcnew System::EventHandler(this, &MainWindow::DebugAVLMaturityTime_Click);
			// 
			// DebugAVLSum
			// 
			this->DebugAVLSum->Name = L"DebugAVLSum";
			this->DebugAVLSum->Size = System::Drawing::Size(387, 34);
			this->DebugAVLSum->Text = L"АВЛ-дерево (Сумма)";
			this->DebugAVLSum->Click += gcnew System::EventHandler(this, &MainWindow::DebugAVLSum_Click);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1762, 858);
			this->Controls->Add(this->TopToolMenu);
			this->Controls->Add(this->OperationList);
			this->Controls->Add(this->ListView);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->OperationList->ResumeLayout(false);
			this->OperationList->PerformLayout();
			this->TopToolMenu->ResumeLayout(false);
			this->TopToolMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BookedListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void Add_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void Delete_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void GlobalFind_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void BankNameFind_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void InterestRateFind_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void MaturityTimeFind_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SumFind_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void OpenTool_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void CloseTool_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SaveTool_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void SaveAsTool_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ExitTool_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void ReferenceTools_Click(System::Object^ sender, System::EventArgs^ e);
public: System::Void  AddItem(int series, int number, string bankName, int interestRate, int duration, int sum);


private: System::Void DebugHT_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DebugAVLBankName_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DebugAVLInterestRate_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DebugAVLMaturityTime_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DebugAVLSum_Click(System::Object^ sender, System::EventArgs^ e);
};
}
