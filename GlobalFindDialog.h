#pragma once
#include"MainWindow.h"
namespace Credit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GlobalFindDialog
	/// </summary>
	public ref class GlobalFindDialog : public System::Windows::Forms::Form
	{
		MainWindow^ m;
	public:

		GlobalFindDialog(MainWindow^ m)
		{
			InitializeComponent();
			this->m = m;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GlobalFindDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MaskedTextBox^ PassportField;
	private: System::Windows::Forms::Label^ PasportLabel;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ BankNameField;
	private: System::Windows::Forms::Button^ findButton;
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
			this->PassportField = (gcnew System::Windows::Forms::MaskedTextBox());
			this->PasportLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BankNameField = (gcnew System::Windows::Forms::TextBox());
			this->findButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// PassportField
			// 
			this->PassportField->Location = System::Drawing::Point(71, 125);
			this->PassportField->Mask = L"0000 000000";
			this->PassportField->Name = L"PassportField";
			this->PassportField->ResetOnPrompt = false;
			this->PassportField->Size = System::Drawing::Size(456, 26);
			this->PassportField->TabIndex = 33;
			// 
			// PasportLabel
			// 
			this->PasportLabel->AutoSize = true;
			this->PasportLabel->Location = System::Drawing::Point(67, 102);
			this->PasportLabel->Name = L"PasportLabel";
			this->PasportLabel->Size = System::Drawing::Size(74, 20);
			this->PasportLabel->TabIndex = 34;
			this->PasportLabel->Text = L"Паспорт";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(67, 173);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 20);
			this->label1->TabIndex = 35;
			this->label1->Text = L"Название банка";
			// 
			// BankNameField
			// 
			this->BankNameField->Location = System::Drawing::Point(71, 196);
			this->BankNameField->Name = L"BankNameField";
			this->BankNameField->Size = System::Drawing::Size(456, 26);
			this->BankNameField->TabIndex = 36;
			// 
			// findButton
			// 
			this->findButton->Location = System::Drawing::Point(71, 264);
			this->findButton->Name = L"findButton";
			this->findButton->Size = System::Drawing::Size(456, 45);
			this->findButton->TabIndex = 37;
			this->findButton->Text = L"Найти";
			this->findButton->UseVisualStyleBackColor = true;
			this->findButton->Click += gcnew System::EventHandler(this, &GlobalFindDialog::findButton_Click);
			// 
			// GlobalFindDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(590, 448);
			this->Controls->Add(this->findButton);
			this->Controls->Add(this->BankNameField);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->PasportLabel);
			this->Controls->Add(this->PassportField);
			this->Name = L"GlobalFindDialog";
			this->Text = L"GlobalFindDialog";
			this->Load += gcnew System::EventHandler(this, &GlobalFindDialog::GlobalFindDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void GlobalFindDialog_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void findButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
