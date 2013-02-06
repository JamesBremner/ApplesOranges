#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace applesoranges {

	/// <summary>
	/// Summary for AddChoice
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AddChoiceDlg : public System::Windows::Forms::Form
	{
	public:
		AddChoiceDlg(void)
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
		~AddChoiceDlg()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^  textBox1;
	protected: 
	private: System::Windows::Forms::Button^  ADD;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ADD = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(32, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(196, 20);
			this->textBox1->TabIndex = 0;
			// 
			// ADD
			// 
			this->ADD->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->ADD->Location = System::Drawing::Point(90, 72);
			this->ADD->Name = L"ADD";
			this->ADD->Size = System::Drawing::Size(75, 23);
			this->ADD->TabIndex = 1;
			this->ADD->Text = L"ADD";
			this->ADD->UseVisualStyleBackColor = true;
			// 
			// AddChoiceDlg
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 107);
			this->Controls->Add(this->ADD);
			this->Controls->Add(this->textBox1);
			this->Name = L"AddChoiceDlg";
			this->Text = L"Add Choice";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
