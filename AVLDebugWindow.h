#pragma once

#include <iostream>

using namespace std;

namespace Credit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AVLDebugWindow
	/// </summary>
	public ref class AVLDebugWindow : public System::Windows::Forms::Form
	{
	public:
		AVLDebugWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		AVLDebugWindow(string text)
		{
			InitializeComponent();

			String^ s = gcnew String(text.c_str());

			TextBox->Text = s;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AVLDebugWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ TextBox;
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
			this->TextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// TextBox
			// 
			this->TextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.857143F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->TextBox->Location = System::Drawing::Point(11, 11);
			this->TextBox->Margin = System::Windows::Forms::Padding(2);
			this->TextBox->Name = L"TextBox";
			this->TextBox->Size = System::Drawing::Size(1518, 703);
			this->TextBox->TabIndex = 1;
			this->TextBox->Text = L"";
			// 
			// AVLDebugWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1540, 698);
			this->Controls->Add(this->TextBox);
			this->Name = L"AVLDebugWindow";
			this->Text = L"AVLDebugWindow";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
