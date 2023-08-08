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
	/// Summary for GreetingDialog
	/// </summary>
	public ref class GreetingWindow : public System::Windows::Forms::Form
	{
		MainWindow^ m;
	public:
		GreetingWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		GreetingWindow(MainWindow^ m)
		{
			InitializeComponent();
			this->m = m;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GreetingWindow()
		{
			if (components)
			{
				delete components;
			}
		}



	protected:

	private: System::Windows::Forms::Button^ confirmButton;
	private: System::Windows::Forms::MaskedTextBox^ HTSize;


	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->HTSize = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// confirmButton
			// 
			this->confirmButton->Location = System::Drawing::Point(16, 227);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(335, 52);
			this->confirmButton->TabIndex = 2;
			this->confirmButton->Text = L"Подтвердить";
			this->confirmButton->UseVisualStyleBackColor = true;
			this->confirmButton->Click += gcnew System::EventHandler(this, &GreetingWindow::confirmButton_Click);
			// 
			// HTSize
			// 
			this->HTSize->Location = System::Drawing::Point(15, 152);
			this->HTSize->Mask = L"99999";
			this->HTSize->Name = L"HTSize";
			this->HTSize->Size = System::Drawing::Size(335, 26);
			this->HTSize->TabIndex = 3;
			this->HTSize->ValidatingType = System::Int32::typeid;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 128);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(89, 20);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Размер ХТ";
			// 
			// GreetingDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 438);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->HTSize);
			this->Controls->Add(this->confirmButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GreetingDialog";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GreetingDialog";
			this->Load += gcnew System::EventHandler(this, &GreetingWindow::GreetingDialog_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void confirmButton_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void GreetingDialog_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
