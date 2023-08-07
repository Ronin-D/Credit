#pragma once

namespace Credit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FilteredWindow
	/// </summary>
	public ref class FilteredWindow : public System::Windows::Forms::Form
	{
	public:
		FilteredWindow(void)
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
		~FilteredWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ ListView;
	protected:
	private: System::Windows::Forms::ColumnHeader^ ColumnPassport;
	private: System::Windows::Forms::ColumnHeader^ ColumnBankName;
	private: System::Windows::Forms::ColumnHeader^ ColumnInterestRate;
	private: System::Windows::Forms::ColumnHeader^ ColumnMaturityTime;
	private: System::Windows::Forms::ColumnHeader^ ColumnSum;

	protected:

	public:





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
			this->ListView->Location = System::Drawing::Point(3, 1);
			this->ListView->Name = L"ListView";
			this->ListView->Size = System::Drawing::Size(1669, 649);
			this->ListView->TabIndex = 4;
			this->ListView->UseCompatibleStateImageBehavior = false;
			this->ListView->View = System::Windows::Forms::View::Details;
			this->ListView->Visible = false;
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
			// FilteredWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1668, 649);
			this->Controls->Add(this->ListView);
			this->Name = L"FilteredWindow";
			this->Text = L"FilteredWindow";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
