#pragma once
#include<iostream>
namespace Credit {

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
	private: System::Windows::Forms::ListView^ BookedListView;
	protected:
	private: System::Windows::Forms::ColumnHeader^ ColumnPassport;
	private: System::Windows::Forms::ColumnHeader^ ColumnBankName;
	private: System::Windows::Forms::ColumnHeader^ ColumnInterestRate;
	private: System::Windows::Forms::ColumnHeader^ ColumnMaturityTime;
	private: System::Windows::Forms::ColumnHeader^ ColumnSum;
	private: System::Windows::Forms::GroupBox^ BookedOperationList;
	private: System::Windows::Forms::Button^ BookedGlobalFind;
	private: System::Windows::Forms::MaskedTextBox^ BookedpasportFindline;
	private: System::Windows::Forms::Label^ BookedVacancyLabel;
	private: System::Windows::Forms::TextBox^ BookedVacancyFindline;
	private: System::Windows::Forms::Button^ BookedVacancyFind;
	private: System::Windows::Forms::Label^ BookedSpecializationLabel;
	private: System::Windows::Forms::TextBox^ BookedSpecializationFindline;
	private: System::Windows::Forms::Label^ BookedCompanyLabel;
	private: System::Windows::Forms::TextBox^ BookedCompanyFindline;
	private: System::Windows::Forms::Label^ BookedPasportLabel;
	private: System::Windows::Forms::Button^ BookedSpecializationFind;
	private: System::Windows::Forms::Button^ BookedCompanyFind;
	private: System::Windows::Forms::Button^ BookedPasportFind;
	private: System::Windows::Forms::Button^ BookedDelete;
	private: System::Windows::Forms::Button^ BokedAdd;
	private: System::Windows::Forms::MenuStrip^ TopToolMenu;
	private: System::Windows::Forms::ToolStripMenuItem^ ProgrammTools;
	private: System::Windows::Forms::ToolStripMenuItem^ OpenTool;
	private: System::Windows::Forms::ToolStripMenuItem^ CloseTool;
	private: System::Windows::Forms::ToolStripMenuItem^ SaveTool;
	private: System::Windows::Forms::ToolStripMenuItem^ SaveAsTool;
	private: System::Windows::Forms::ToolStripMenuItem^ ExitTool;
	private: System::Windows::Forms::ToolStripMenuItem^ ReferenceTools;
	private: System::Windows::Forms::ToolStripMenuItem^ AboutTool;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugTools;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugOffersToolGroup;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugOffersHT;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugOffersRBTVcancy;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugOffersRBTSpecialization;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugOffersRBTCompany;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugOffersRBTSallary;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedToolGroup;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedHT;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedAVLTVacancy;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedAVLTSpecialization;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedAVLTCompany;
	private: System::Windows::Forms::ToolStripMenuItem^ DebugBookedAVLTPasport;







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
			this->BookedListView = (gcnew System::Windows::Forms::ListView());
			this->ColumnPassport = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnBankName = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnInterestRate = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnMaturityTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnSum = (gcnew System::Windows::Forms::ColumnHeader());
			this->BookedOperationList = (gcnew System::Windows::Forms::GroupBox());
			this->BookedGlobalFind = (gcnew System::Windows::Forms::Button());
			this->BookedpasportFindline = (gcnew System::Windows::Forms::MaskedTextBox());
			this->BookedVacancyLabel = (gcnew System::Windows::Forms::Label());
			this->BookedVacancyFindline = (gcnew System::Windows::Forms::TextBox());
			this->BookedVacancyFind = (gcnew System::Windows::Forms::Button());
			this->BookedSpecializationLabel = (gcnew System::Windows::Forms::Label());
			this->BookedSpecializationFindline = (gcnew System::Windows::Forms::TextBox());
			this->BookedCompanyLabel = (gcnew System::Windows::Forms::Label());
			this->BookedCompanyFindline = (gcnew System::Windows::Forms::TextBox());
			this->BookedPasportLabel = (gcnew System::Windows::Forms::Label());
			this->BookedSpecializationFind = (gcnew System::Windows::Forms::Button());
			this->BookedCompanyFind = (gcnew System::Windows::Forms::Button());
			this->BookedPasportFind = (gcnew System::Windows::Forms::Button());
			this->BookedDelete = (gcnew System::Windows::Forms::Button());
			this->BokedAdd = (gcnew System::Windows::Forms::Button());
			this->TopToolMenu = (gcnew System::Windows::Forms::MenuStrip());
			this->ProgrammTools = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OpenTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->CloseTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SaveAsTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ExitTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ReferenceTools = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->AboutTool = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugTools = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugOffersToolGroup = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugOffersHT = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugOffersRBTVcancy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugOffersRBTSpecialization = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugOffersRBTCompany = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugOffersRBTSallary = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedToolGroup = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedHT = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedAVLTVacancy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedAVLTSpecialization = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedAVLTCompany = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DebugBookedAVLTPasport = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->BookedOperationList->SuspendLayout();
			this->TopToolMenu->SuspendLayout();
			this->SuspendLayout();
			// 
			// BookedListView
			// 
			this->BookedListView->AutoArrange = false;
			this->BookedListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->ColumnPassport,
					this->ColumnBankName, this->ColumnInterestRate, this->ColumnMaturityTime, this->ColumnSum
			});
			this->BookedListView->FullRowSelect = true;
			this->BookedListView->GridLines = true;
			this->BookedListView->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->BookedListView->HideSelection = false;
			this->BookedListView->Location = System::Drawing::Point(221, 63);
			this->BookedListView->Name = L"BookedListView";
			this->BookedListView->Size = System::Drawing::Size(1529, 707);
			this->BookedListView->TabIndex = 3;
			this->BookedListView->UseCompatibleStateImageBehavior = false;
			this->BookedListView->View = System::Windows::Forms::View::Details;
			this->BookedListView->SelectedIndexChanged += gcnew System::EventHandler(this, &MainWindow::BookedListView_SelectedIndexChanged);
			// 
			// ColumnPassport
			// 
			this->ColumnPassport->Text = L"Пасспорт клиента";
			this->ColumnPassport->Width = 100;
			// 
			// ColumnBankName
			// 
			this->ColumnBankName->Text = L"Название банка";
			this->ColumnBankName->Width = 100;
			// 
			// ColumnInterestRate
			// 
			this->ColumnInterestRate->Text = L"Процентная ставка";
			this->ColumnInterestRate->Width = 100;
			// 
			// ColumnMaturityTime
			// 
			this->ColumnMaturityTime->Text = L"Срок погашения";
			this->ColumnMaturityTime->Width = 100;
			// 
			// ColumnSum
			// 
			this->ColumnSum->Text = L"Сумма";
			this->ColumnSum->Width = 100;
			// 
			// BookedOperationList
			// 
			this->BookedOperationList->Controls->Add(this->BookedGlobalFind);
			this->BookedOperationList->Controls->Add(this->BookedpasportFindline);
			this->BookedOperationList->Controls->Add(this->BookedVacancyLabel);
			this->BookedOperationList->Controls->Add(this->BookedVacancyFindline);
			this->BookedOperationList->Controls->Add(this->BookedVacancyFind);
			this->BookedOperationList->Controls->Add(this->BookedSpecializationLabel);
			this->BookedOperationList->Controls->Add(this->BookedSpecializationFindline);
			this->BookedOperationList->Controls->Add(this->BookedCompanyLabel);
			this->BookedOperationList->Controls->Add(this->BookedCompanyFindline);
			this->BookedOperationList->Controls->Add(this->BookedPasportLabel);
			this->BookedOperationList->Controls->Add(this->BookedSpecializationFind);
			this->BookedOperationList->Controls->Add(this->BookedCompanyFind);
			this->BookedOperationList->Controls->Add(this->BookedPasportFind);
			this->BookedOperationList->Controls->Add(this->BookedDelete);
			this->BookedOperationList->Controls->Add(this->BokedAdd);
			this->BookedOperationList->Location = System::Drawing::Point(12, 52);
			this->BookedOperationList->Name = L"BookedOperationList";
			this->BookedOperationList->Size = System::Drawing::Size(203, 747);
			this->BookedOperationList->TabIndex = 4;
			this->BookedOperationList->TabStop = false;
			this->BookedOperationList->Text = L"Операции";
			// 
			// BookedGlobalFind
			// 
			this->BookedGlobalFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedGlobalFind->Location = System::Drawing::Point(5, 147);
			this->BookedGlobalFind->Name = L"BookedGlobalFind";
			this->BookedGlobalFind->Size = System::Drawing::Size(193, 51);
			this->BookedGlobalFind->TabIndex = 16;
			this->BookedGlobalFind->Text = L"Поиск";
			this->BookedGlobalFind->UseVisualStyleBackColor = true;
			// 
			// BookedpasportFindline
			// 
			this->BookedpasportFindline->Location = System::Drawing::Point(6, 637);
			this->BookedpasportFindline->Mask = L"0000 000000";
			this->BookedpasportFindline->Name = L"BookedpasportFindline";
			this->BookedpasportFindline->ResetOnPrompt = false;
			this->BookedpasportFindline->Size = System::Drawing::Size(193, 26);
			this->BookedpasportFindline->TabIndex = 15;
			// 
			// BookedVacancyLabel
			// 
			this->BookedVacancyLabel->AutoSize = true;
			this->BookedVacancyLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedVacancyLabel->Location = System::Drawing::Point(6, 284);
			this->BookedVacancyLabel->Name = L"BookedVacancyLabel";
			this->BookedVacancyLabel->Size = System::Drawing::Size(81, 20);
			this->BookedVacancyLabel->TabIndex = 14;
			this->BookedVacancyLabel->Text = L"Вакансия";
			// 
			// BookedVacancyFindline
			// 
			this->BookedVacancyFindline->Location = System::Drawing::Point(6, 308);
			this->BookedVacancyFindline->Name = L"BookedVacancyFindline";
			this->BookedVacancyFindline->Size = System::Drawing::Size(193, 26);
			this->BookedVacancyFindline->TabIndex = 13;
			// 
			// BookedVacancyFind
			// 
			this->BookedVacancyFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedVacancyFind->Location = System::Drawing::Point(5, 338);
			this->BookedVacancyFind->Name = L"BookedVacancyFind";
			this->BookedVacancyFind->Size = System::Drawing::Size(193, 51);
			this->BookedVacancyFind->TabIndex = 12;
			this->BookedVacancyFind->Text = L"Поиск";
			this->BookedVacancyFind->UseVisualStyleBackColor = true;
			// 
			// BookedSpecializationLabel
			// 
			this->BookedSpecializationLabel->AutoSize = true;
			this->BookedSpecializationLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedSpecializationLabel->Location = System::Drawing::Point(6, 391);
			this->BookedSpecializationLabel->Name = L"BookedSpecializationLabel";
			this->BookedSpecializationLabel->Size = System::Drawing::Size(128, 20);
			this->BookedSpecializationLabel->TabIndex = 11;
			this->BookedSpecializationLabel->Text = L"Специализация";
			// 
			// BookedSpecializationFindline
			// 
			this->BookedSpecializationFindline->Location = System::Drawing::Point(6, 417);
			this->BookedSpecializationFindline->Name = L"BookedSpecializationFindline";
			this->BookedSpecializationFindline->Size = System::Drawing::Size(193, 26);
			this->BookedSpecializationFindline->TabIndex = 10;
			// 
			// BookedCompanyLabel
			// 
			this->BookedCompanyLabel->AutoSize = true;
			this->BookedCompanyLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedCompanyLabel->Location = System::Drawing::Point(5, 501);
			this->BookedCompanyLabel->Name = L"BookedCompanyLabel";
			this->BookedCompanyLabel->Size = System::Drawing::Size(84, 20);
			this->BookedCompanyLabel->TabIndex = 9;
			this->BookedCompanyLabel->Text = L"Компания";
			// 
			// BookedCompanyFindline
			// 
			this->BookedCompanyFindline->Location = System::Drawing::Point(5, 527);
			this->BookedCompanyFindline->Name = L"BookedCompanyFindline";
			this->BookedCompanyFindline->Size = System::Drawing::Size(193, 26);
			this->BookedCompanyFindline->TabIndex = 8;
			// 
			// BookedPasportLabel
			// 
			this->BookedPasportLabel->AutoSize = true;
			this->BookedPasportLabel->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedPasportLabel->Location = System::Drawing::Point(6, 610);
			this->BookedPasportLabel->Name = L"BookedPasportLabel";
			this->BookedPasportLabel->Size = System::Drawing::Size(74, 20);
			this->BookedPasportLabel->TabIndex = 7;
			this->BookedPasportLabel->Text = L"Паспорт";
			// 
			// BookedSpecializationFind
			// 
			this->BookedSpecializationFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedSpecializationFind->Location = System::Drawing::Point(5, 447);
			this->BookedSpecializationFind->Name = L"BookedSpecializationFind";
			this->BookedSpecializationFind->Size = System::Drawing::Size(193, 51);
			this->BookedSpecializationFind->TabIndex = 5;
			this->BookedSpecializationFind->Text = L"Поиск";
			this->BookedSpecializationFind->UseVisualStyleBackColor = true;
			// 
			// BookedCompanyFind
			// 
			this->BookedCompanyFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedCompanyFind->Location = System::Drawing::Point(5, 557);
			this->BookedCompanyFind->Name = L"BookedCompanyFind";
			this->BookedCompanyFind->Size = System::Drawing::Size(193, 51);
			this->BookedCompanyFind->TabIndex = 4;
			this->BookedCompanyFind->Text = L"Поиск";
			this->BookedCompanyFind->UseVisualStyleBackColor = true;
			// 
			// BookedPasportFind
			// 
			this->BookedPasportFind->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedPasportFind->Location = System::Drawing::Point(5, 667);
			this->BookedPasportFind->Name = L"BookedPasportFind";
			this->BookedPasportFind->Size = System::Drawing::Size(193, 51);
			this->BookedPasportFind->TabIndex = 3;
			this->BookedPasportFind->Text = L"Поиск";
			this->BookedPasportFind->UseVisualStyleBackColor = true;
			// 
			// BookedDelete
			// 
			this->BookedDelete->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BookedDelete->Location = System::Drawing::Point(5, 91);
			this->BookedDelete->Name = L"BookedDelete";
			this->BookedDelete->Size = System::Drawing::Size(193, 51);
			this->BookedDelete->TabIndex = 1;
			this->BookedDelete->Text = L"Удалить";
			this->BookedDelete->UseVisualStyleBackColor = true;
			// 
			// BokedAdd
			// 
			this->BokedAdd->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->BokedAdd->Location = System::Drawing::Point(5, 35);
			this->BokedAdd->Name = L"BokedAdd";
			this->BokedAdd->Size = System::Drawing::Size(193, 51);
			this->BokedAdd->TabIndex = 0;
			this->BokedAdd->Text = L"Добавить";
			this->BokedAdd->UseVisualStyleBackColor = true;
			// 
			// TopToolMenu
			// 
			this->TopToolMenu->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->TopToolMenu->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
			this->TopToolMenu->ImageScalingSize = System::Drawing::Size(28, 28);
			this->TopToolMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->ProgrammTools, this->ReferenceTools,
					this->DebugTools
			});
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
			this->OpenTool->Size = System::Drawing::Size(270, 34);
			this->OpenTool->Text = L"Открыть";
			// 
			// CloseTool
			// 
			this->CloseTool->Name = L"CloseTool";
			this->CloseTool->Size = System::Drawing::Size(270, 34);
			this->CloseTool->Text = L"Закрыть";
			// 
			// SaveTool
			// 
			this->SaveTool->Name = L"SaveTool";
			this->SaveTool->Size = System::Drawing::Size(270, 34);
			this->SaveTool->Text = L"Сохранить";
			// 
			// SaveAsTool
			// 
			this->SaveAsTool->Name = L"SaveAsTool";
			this->SaveAsTool->Size = System::Drawing::Size(270, 34);
			this->SaveAsTool->Text = L"Сохранить как...";
			// 
			// ExitTool
			// 
			this->ExitTool->Name = L"ExitTool";
			this->ExitTool->Size = System::Drawing::Size(270, 34);
			this->ExitTool->Text = L"Выход";
			// 
			// ReferenceTools
			// 
			this->ReferenceTools->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->AboutTool });
			this->ReferenceTools->Name = L"ReferenceTools";
			this->ReferenceTools->Size = System::Drawing::Size(97, 29);
			this->ReferenceTools->Text = L"Справка";
			// 
			// AboutTool
			// 
			this->AboutTool->Name = L"AboutTool";
			this->AboutTool->Size = System::Drawing::Size(227, 34);
			this->AboutTool->Text = L"О программе";
			// 
			// DebugTools
			// 
			this->DebugTools->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->DebugOffersToolGroup,
					this->DebugBookedToolGroup
			});
			this->DebugTools->Name = L"DebugTools";
			this->DebugTools->Size = System::Drawing::Size(95, 29);
			this->DebugTools->Text = L"Отладка";
			// 
			// DebugOffersToolGroup
			// 
			this->DebugOffersToolGroup->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->DebugOffersHT,
					this->DebugOffersRBTVcancy, this->DebugOffersRBTSpecialization, this->DebugOffersRBTCompany, this->DebugOffersRBTSallary
			});
			this->DebugOffersToolGroup->Name = L"DebugOffersToolGroup";
			this->DebugOffersToolGroup->Size = System::Drawing::Size(504, 34);
			this->DebugOffersToolGroup->Text = L"Справочник \"Предложения\"";
			// 
			// DebugOffersHT
			// 
			this->DebugOffersHT->Name = L"DebugOffersHT";
			this->DebugOffersHT->Size = System::Drawing::Size(448, 34);
			this->DebugOffersHT->Text = L"Хеш-таблица";
			// 
			// DebugOffersRBTVcancy
			// 
			this->DebugOffersRBTVcancy->Name = L"DebugOffersRBTVcancy";
			this->DebugOffersRBTVcancy->Size = System::Drawing::Size(448, 34);
			this->DebugOffersRBTVcancy->Text = L"Красно-чёрное дерево (Вакансия)";
			// 
			// DebugOffersRBTSpecialization
			// 
			this->DebugOffersRBTSpecialization->Name = L"DebugOffersRBTSpecialization";
			this->DebugOffersRBTSpecialization->Size = System::Drawing::Size(448, 34);
			this->DebugOffersRBTSpecialization->Text = L"Крачно-чёрное дерево (Специализация)";
			// 
			// DebugOffersRBTCompany
			// 
			this->DebugOffersRBTCompany->Name = L"DebugOffersRBTCompany";
			this->DebugOffersRBTCompany->Size = System::Drawing::Size(448, 34);
			this->DebugOffersRBTCompany->Text = L"Красно-чёрное дерево (Компания)";
			// 
			// DebugOffersRBTSallary
			// 
			this->DebugOffersRBTSallary->Name = L"DebugOffersRBTSallary";
			this->DebugOffersRBTSallary->Size = System::Drawing::Size(448, 34);
			this->DebugOffersRBTSallary->Text = L"Красно-чёрное дерево (Зарплата)";
			// 
			// DebugBookedToolGroup
			// 
			this->DebugBookedToolGroup->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->DebugBookedHT,
					this->DebugBookedAVLTVacancy, this->DebugBookedAVLTSpecialization, this->DebugBookedAVLTCompany, this->DebugBookedAVLTPasport
			});
			this->DebugBookedToolGroup->Name = L"DebugBookedToolGroup";
			this->DebugBookedToolGroup->Size = System::Drawing::Size(504, 34);
			this->DebugBookedToolGroup->Text = L"Справочник \"Забронированные предложения\"";
			// 
			// DebugBookedHT
			// 
			this->DebugBookedHT->Name = L"DebugBookedHT";
			this->DebugBookedHT->Size = System::Drawing::Size(356, 34);
			this->DebugBookedHT->Text = L"Хеш-таблица";
			// 
			// DebugBookedAVLTVacancy
			// 
			this->DebugBookedAVLTVacancy->Name = L"DebugBookedAVLTVacancy";
			this->DebugBookedAVLTVacancy->Size = System::Drawing::Size(356, 34);
			this->DebugBookedAVLTVacancy->Text = L"АВЛ-дерево (Вакансия)";
			// 
			// DebugBookedAVLTSpecialization
			// 
			this->DebugBookedAVLTSpecialization->Name = L"DebugBookedAVLTSpecialization";
			this->DebugBookedAVLTSpecialization->Size = System::Drawing::Size(356, 34);
			this->DebugBookedAVLTSpecialization->Text = L"АВЛ-дерево (Специализация)";
			// 
			// DebugBookedAVLTCompany
			// 
			this->DebugBookedAVLTCompany->Name = L"DebugBookedAVLTCompany";
			this->DebugBookedAVLTCompany->Size = System::Drawing::Size(356, 34);
			this->DebugBookedAVLTCompany->Text = L"АВЛ-дерево (Компания)";
			// 
			// DebugBookedAVLTPasport
			// 
			this->DebugBookedAVLTPasport->Name = L"DebugBookedAVLTPasport";
			this->DebugBookedAVLTPasport->Size = System::Drawing::Size(356, 34);
			this->DebugBookedAVLTPasport->Text = L"АВЛ-дереов (Паспорт)";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1762, 858);
			this->Controls->Add(this->TopToolMenu);
			this->Controls->Add(this->BookedOperationList);
			this->Controls->Add(this->BookedListView);
			this->Name = L"MainWindow";
			this->Text = L"MainWindow";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->BookedOperationList->ResumeLayout(false);
			this->BookedOperationList->PerformLayout();
			this->TopToolMenu->ResumeLayout(false);
			this->TopToolMenu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BookedListView_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
