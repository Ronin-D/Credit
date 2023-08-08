#pragma once

namespace Credit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for HTDebugWindow
	/// </summary>
	public ref class HTDebugWindow : public System::Windows::Forms::Form
	{
	public:
		HTDebugWindow(void)
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
		~HTDebugWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::ListView^ HTListView;
	protected:
	private: System::Windows::Forms::ColumnHeader^ ColumnHash;
	public:
	private: System::Windows::Forms::ColumnHeader^ ColumnStatus;
	private: System::Windows::Forms::ColumnHeader^ ColumnPrehash;
	private: System::Windows::Forms::ColumnHeader^ ColumnIndex;
	private: System::Windows::Forms::ColumnHeader^ ColumnValue;

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
			this->HTListView = (gcnew System::Windows::Forms::ListView());
			this->ColumnHash = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnStatus = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnPrehash = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnIndex = (gcnew System::Windows::Forms::ColumnHeader());
			this->ColumnValue = (gcnew System::Windows::Forms::ColumnHeader());
			this->SuspendLayout();
			// 
			// HTListView
			// 
			this->HTListView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->ColumnHash, this->ColumnStatus,
					this->ColumnPrehash, this->ColumnIndex, this->ColumnValue
			});
			this->HTListView->FullRowSelect = true;
			this->HTListView->GridLines = true;
			this->HTListView->HideSelection = false;
			this->HTListView->Location = System::Drawing::Point(11, 11);
			this->HTListView->Margin = System::Windows::Forms::Padding(2);
			this->HTListView->Name = L"HTListView";
			this->HTListView->Size = System::Drawing::Size(1425, 611);
			this->HTListView->TabIndex = 1;
			this->HTListView->UseCompatibleStateImageBehavior = false;
			this->HTListView->View = System::Windows::Forms::View::Details;
			// 
			// ColumnHash
			// 
			this->ColumnHash->Text = L"Hash";
			this->ColumnHash->Width = 66;
			// 
			// ColumnStatus
			// 
			this->ColumnStatus->Text = L"Status";
			this->ColumnStatus->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ColumnStatus->Width = 170;
			// 
			// ColumnPrehash
			// 
			this->ColumnPrehash->Text = L"Prehash";
			this->ColumnPrehash->Width = 133;
			// 
			// ColumnIndex
			// 
			this->ColumnIndex->Text = L"Index";
			this->ColumnIndex->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ColumnIndex->Width = 148;
			// 
			// ColumnValue
			// 
			this->ColumnValue->Text = L"Value";
			this->ColumnValue->Width = 243;
			// 
			// HTDebugWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1447, 633);
			this->Controls->Add(this->HTListView);
			this->Name = L"HTDebugWindow";
			this->Text = L"HTDebugWindow";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
