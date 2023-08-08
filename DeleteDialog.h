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
	/// Summary for DeleteDialog
	/// </summary>
	public ref class DeleteDialog : public System::Windows::Forms::Form
	{
		MainWindow^ m;
	public:
		DeleteDialog(MainWindow^ m)
		{
			InitializeComponent();
			this->m = m;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DeleteDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ BankNameField;
	private: System::Windows::Forms::MaskedTextBox^ PassportField;
	private: System::Windows::Forms::Label^ PasportLabel;
	private: System::Windows::Forms::Button^ deleteButton;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->BankNameField = (gcnew System::Windows::Forms::TextBox());
			this->PassportField = (gcnew System::Windows::Forms::MaskedTextBox());
			this->PasportLabel = (gcnew System::Windows::Forms::Label());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(32, 97);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 20);
			this->label1->TabIndex = 34;
			this->label1->Text = L"Название банка";
			// 
			// BankNameField
			// 
			this->BankNameField->Location = System::Drawing::Point(36, 120);
			this->BankNameField->Name = L"BankNameField";
			this->BankNameField->Size = System::Drawing::Size(456, 26);
			this->BankNameField->TabIndex = 33;
			// 
			// PassportField
			// 
			this->PassportField->Location = System::Drawing::Point(36, 44);
			this->PassportField->Mask = L"0000 000000";
			this->PassportField->Name = L"PassportField";
			this->PassportField->ResetOnPrompt = false;
			this->PassportField->Size = System::Drawing::Size(456, 26);
			this->PassportField->TabIndex = 32;
			// 
			// PasportLabel
			// 
			this->PasportLabel->AutoSize = true;
			this->PasportLabel->Location = System::Drawing::Point(32, 21);
			this->PasportLabel->Name = L"PasportLabel";
			this->PasportLabel->Size = System::Drawing::Size(74, 20);
			this->PasportLabel->TabIndex = 31;
			this->PasportLabel->Text = L"Паспорт";
			// 
			// deleteButton
			// 
			this->deleteButton->Location = System::Drawing::Point(36, 219);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(456, 45);
			this->deleteButton->TabIndex = 35;
			this->deleteButton->Text = L"Удалить";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &DeleteDialog::deleteButton_Click);
			// 
			// DeleteDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(531, 388);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->BankNameField);
			this->Controls->Add(this->PassportField);
			this->Controls->Add(this->PasportLabel);
			this->Name = L"DeleteDialog";
			this->Text = L"DeleteDialog";
			this->Load += gcnew System::EventHandler(this, &DeleteDialog::DeleteDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void deleteButton_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void DeleteDialog_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
