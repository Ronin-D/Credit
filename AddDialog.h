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
	/// Summary for AddDialog
	/// </summary>
	public ref class AddDialog : public System::Windows::Forms::Form
	{
		MainWindow^ m;
	public:
		AddDialog(MainWindow^ m)
		{
			InitializeComponent();
			this->m = m;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ PasportLabel;
	private: System::Windows::Forms::MaskedTextBox^ PassportField;
	protected:

	private: System::Windows::Forms::TextBox^ BankNameField;
	private: System::Windows::Forms::MaskedTextBox^ InterestRateField;
	private: System::Windows::Forms::MaskedTextBox^ DurationField;
	private: System::Windows::Forms::MaskedTextBox^ SumField;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ confirmButton;

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
			this->PasportLabel = (gcnew System::Windows::Forms::Label());
			this->PassportField = (gcnew System::Windows::Forms::MaskedTextBox());
			this->BankNameField = (gcnew System::Windows::Forms::TextBox());
			this->InterestRateField = (gcnew System::Windows::Forms::MaskedTextBox());
			this->DurationField = (gcnew System::Windows::Forms::MaskedTextBox());
			this->SumField = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// PasportLabel
			// 
			this->PasportLabel->AutoSize = true;
			this->PasportLabel->Location = System::Drawing::Point(31, 9);
			this->PasportLabel->Name = L"PasportLabel";
			this->PasportLabel->Size = System::Drawing::Size(74, 20);
			this->PasportLabel->TabIndex = 23;
			this->PasportLabel->Text = L"Паспорт";
			// 
			// PassportField
			// 
			this->PassportField->Location = System::Drawing::Point(35, 32);
			this->PassportField->Mask = L"0000 000000";
			this->PassportField->Name = L"PassportField";
			this->PassportField->ResetOnPrompt = false;
			this->PassportField->Size = System::Drawing::Size(456, 26);
			this->PassportField->TabIndex = 24;
			// 
			// BankNameField
			// 
			this->BankNameField->Location = System::Drawing::Point(35, 102);
			this->BankNameField->Name = L"BankNameField";
			this->BankNameField->Size = System::Drawing::Size(456, 26);
			this->BankNameField->TabIndex = 25;
			// 
			// InterestRateField
			// 
			this->InterestRateField->Location = System::Drawing::Point(35, 178);
			this->InterestRateField->Mask = L"00";
			this->InterestRateField->Name = L"InterestRateField";
			this->InterestRateField->ResetOnPrompt = false;
			this->InterestRateField->Size = System::Drawing::Size(456, 26);
			this->InterestRateField->TabIndex = 27;
			// 
			// DurationField
			// 
			this->DurationField->Location = System::Drawing::Point(35, 254);
			this->DurationField->Mask = L"00";
			this->DurationField->Name = L"DurationField";
			this->DurationField->ResetOnPrompt = false;
			this->DurationField->Size = System::Drawing::Size(456, 26);
			this->DurationField->TabIndex = 28;
			// 
			// SumField
			// 
			this->SumField->Location = System::Drawing::Point(35, 318);
			this->SumField->Mask = L"00000";
			this->SumField->Name = L"SumField";
			this->SumField->ResetOnPrompt = false;
			this->SumField->Size = System::Drawing::Size(456, 26);
			this->SumField->TabIndex = 29;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(31, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 20);
			this->label1->TabIndex = 30;
			this->label1->Text = L"Название банка";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(31, 155);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(158, 20);
			this->label2->TabIndex = 31;
			this->label2->Text = L"Процентная ставка";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(31, 231);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(133, 20);
			this->label3->TabIndex = 32;
			this->label3->Text = L"Срок погашения";
			this->label3->Click += gcnew System::EventHandler(this, &AddDialog::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(31, 295);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(58, 20);
			this->label4->TabIndex = 33;
			this->label4->Text = L"Сумма";
			// 
			// confirmButton
			// 
			this->confirmButton->Location = System::Drawing::Point(35, 375);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(456, 45);
			this->confirmButton->TabIndex = 34;
			this->confirmButton->Text = L"Продолжить";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew System::EventHandler(this, &AddDialog::confirmButton_Click);
			// 
			// AddDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(538, 516);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SumField);
			this->Controls->Add(this->DurationField);
			this->Controls->Add(this->InterestRateField);
			this->Controls->Add(this->BankNameField);
			this->Controls->Add(this->PassportField);
			this->Controls->Add(this->PasportLabel);
			this->Name = L"AddDialog";
			this->Text = L"AddDialog";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void confirmButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
