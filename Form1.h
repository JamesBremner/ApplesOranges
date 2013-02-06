#pragma once

#include "cDB.h"
#include "AddChoice.h"

namespace applesoranges {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			dcd::theModel.critTree.myView = CritTreeView;
			dcd::theModel.critTree.Clear();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listChoices;
	protected: 

	private: System::Windows::Forms::ColumnHeader^  Choice;
	private: System::Windows::Forms::ColumnHeader^  TotalScore;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TreeView^  CritTreeView;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  CritWeightTextBox;

	private: System::Windows::Forms::TextBox^  CritNameTextBox;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  ScoreChoiceOnCriterion;
	private: System::Windows::Forms::TextBox^  ScoreTextBox;
	private: System::Windows::Forms::Button^  AddChild;
	private: System::Windows::Forms::Button^  AddSib;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  AddChoice;


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
			this->listChoices = (gcnew System::Windows::Forms::ListView());
			this->Choice = (gcnew System::Windows::Forms::ColumnHeader());
			this->TotalScore = (gcnew System::Windows::Forms::ColumnHeader());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->CritTreeView = (gcnew System::Windows::Forms::TreeView());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->AddChild = (gcnew System::Windows::Forms::Button());
			this->AddSib = (gcnew System::Windows::Forms::Button());
			this->CritWeightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->CritNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->ScoreTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ScoreChoiceOnCriterion = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->AddChoice = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listChoices
			// 
			this->listChoices->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {this->Choice, this->TotalScore});
			this->listChoices->Location = System::Drawing::Point(19, 52);
			this->listChoices->Name = L"listChoices";
			this->listChoices->Size = System::Drawing::Size(300, 395);
			this->listChoices->TabIndex = 0;
			this->listChoices->UseCompatibleStateImageBehavior = false;
			this->listChoices->View = System::Windows::Forms::View::Details;
			this->listChoices->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listChoices_SelectedIndexChanged);
			// 
			// Choice
			// 
			this->Choice->Text = L"Choice";
			this->Choice->Width = 211;
			// 
			// TotalScore
			// 
			this->TotalScore->Text = L"Total Score";
			this->TotalScore->Width = 85;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->AddChoice);
			this->groupBox1->Location = System::Drawing::Point(12, 26);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(326, 472);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Choices";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->CritTreeView);
			this->groupBox2->Location = System::Drawing::Point(360, 26);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(300, 472);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Criteria";
			// 
			// CritTreeView
			// 
			this->CritTreeView->Location = System::Drawing::Point(7, 26);
			this->CritTreeView->Name = L"CritTreeView";
			this->CritTreeView->Size = System::Drawing::Size(287, 419);
			this->CritTreeView->TabIndex = 0;
			this->CritTreeView->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::CritTreeView_AfterSelect);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->AddChild);
			this->groupBox3->Controls->Add(this->AddSib);
			this->groupBox3->Controls->Add(this->CritWeightTextBox);
			this->groupBox3->Controls->Add(this->CritNameTextBox);
			this->groupBox3->Controls->Add(this->label2);
			this->groupBox3->Controls->Add(this->label1);
			this->groupBox3->Location = System::Drawing::Point(667, 26);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(211, 472);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Criterion";
			// 
			// AddChild
			// 
			this->AddChild->Location = System::Drawing::Point(119, 91);
			this->AddChild->Name = L"AddChild";
			this->AddChild->Size = System::Drawing::Size(75, 23);
			this->AddChild->TabIndex = 5;
			this->AddChild->Text = L"Add Child";
			this->AddChild->UseVisualStyleBackColor = true;
			this->AddChild->Click += gcnew System::EventHandler(this, &Form1::AddChild_Click);
			// 
			// AddSib
			// 
			this->AddSib->Location = System::Drawing::Point(10, 92);
			this->AddSib->Name = L"AddSib";
			this->AddSib->Size = System::Drawing::Size(75, 23);
			this->AddSib->TabIndex = 4;
			this->AddSib->Text = L"Add Sibling";
			this->AddSib->UseVisualStyleBackColor = true;
			this->AddSib->Click += gcnew System::EventHandler(this, &Form1::AddSib_Click);
			// 
			// CritWeightTextBox
			// 
			this->CritWeightTextBox->Location = System::Drawing::Point(69, 53);
			this->CritWeightTextBox->Name = L"CritWeightTextBox";
			this->CritWeightTextBox->Size = System::Drawing::Size(100, 20);
			this->CritWeightTextBox->TabIndex = 3;
			// 
			// CritNameTextBox
			// 
			this->CritNameTextBox->Location = System::Drawing::Point(69, 26);
			this->CritNameTextBox->Name = L"CritNameTextBox";
			this->CritNameTextBox->Size = System::Drawing::Size(100, 20);
			this->CritNameTextBox->TabIndex = 2;
			this->CritNameTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::CritNameTextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Weight";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Name";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->ScoreTextBox);
			this->groupBox4->Controls->Add(this->ScoreChoiceOnCriterion);
			this->groupBox4->Location = System::Drawing::Point(12, 518);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(648, 66);
			this->groupBox4->TabIndex = 4;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Score Choice on Criterion";
			// 
			// ScoreTextBox
			// 
			this->ScoreTextBox->Location = System::Drawing::Point(355, 29);
			this->ScoreTextBox->Name = L"ScoreTextBox";
			this->ScoreTextBox->Size = System::Drawing::Size(100, 20);
			this->ScoreTextBox->TabIndex = 2;
			this->ScoreTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::ScoreTextBox_TextChanged);
			// 
			// ScoreChoiceOnCriterion
			// 
			this->ScoreChoiceOnCriterion->AutoSize = true;
			this->ScoreChoiceOnCriterion->Location = System::Drawing::Point(7, 29);
			this->ScoreChoiceOnCriterion->Name = L"ScoreChoiceOnCriterion";
			this->ScoreChoiceOnCriterion->Size = System::Drawing::Size(135, 13);
			this->ScoreChoiceOnCriterion->TabIndex = 1;
			this->ScoreChoiceOnCriterion->Text = L"Select Choice and Criterion";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->fileToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(879, 24);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(100, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::saveFileDialog1_FileOk);
			// 
			// AddChoice
			// 
			this->AddChoice->Location = System::Drawing::Point(36, 437);
			this->AddChoice->Name = L"AddChoice";
			this->AddChoice->Size = System::Drawing::Size(75, 23);
			this->AddChoice->TabIndex = 0;
			this->AddChoice->Text = L"Add";
			this->AddChoice->UseVisualStyleBackColor = true;
			this->AddChoice->Click += gcnew System::EventHandler(this, &Form1::AddChoice_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(879, 596);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->listChoices);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Apples or Oranges";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	    openFileDialog1->ShowDialog();

			 } 
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

			 // read project file
			 cAODB db;
			 std::wstring path =  msclr::interop::marshal_as<std::wstring>(openFileDialog1->FileName);
			 db.OpenProjectFile( path, CritTreeView );
			
			 // display model
			 FillChoices();

		 }
public:

	void FillChoices(void)
	{
		listChoices->Items->Clear();
		foreach( dcd::cChoice& choice, dcd::theModel.theChoice ) {
			ListViewItem^ item = gcnew ListViewItem( msclr::interop::marshal_as<System::String ^>(choice.myName.c_str()), 0 );
			item->SubItems->Add(dcd::theModel.theScore.getScore(choice,*dcd::theModel.critTree.getRoot()->getCrit()).ToString());
			listChoices->Items->Add( item );
		}
	}
	void FillScoreChoiceOnCriterion()
	{
		ScoreChoiceOnCriterion->Text = "Score choice " + 
			msclr::interop::marshal_as<System::String ^>(dcd::theModel.theChoice.getSelected().myName) +
			" on criterion " +
			msclr::interop::marshal_as<System::String ^>(dcd::theModel.critTree.getSelectedCriterion()->getName());
		ScoreTextBox->Text = dcd::theModel.theScore.getScore(
			dcd::theModel.theChoice.getSelected(),
			*dcd::theModel.critTree.getSelectedCriterion() ).ToString();
	}
private: System::Void CritTreeView_AfterSelect(System::Object^  sender, System::Windows::Forms::TreeViewEventArgs^  e) {

			 dcd::cCriterion * crit = ((dcd::cCritTreeNode^)e->Node)->getCrit();
			 dcd::theModel.critTree.setSelected( crit );
			 CritNameTextBox->Text = msclr::interop::marshal_as<System::String ^>(crit->getName());
			 CritWeightTextBox->Text = msclr::interop::marshal_as<System::String ^>(crit->getWeight());
			 FillScoreChoiceOnCriterion();
		 }

private: System::Void listChoices_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if( ! listChoices->SelectedItems->Count )
				 return;
			 dcd::theModel.theChoice.setSelected( listChoices->Items->IndexOf( listChoices->SelectedItems[0] ) );
			 FillScoreChoiceOnCriterion();
		 }
		 /**

		 User has entered a score for the current choice on current criterion

		 */
private: System::Void ScoreTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 // assume blamk means zero
			 if( ScoreTextBox->Text == L"" )
				 ScoreTextBox->Text = L"0";

			 // save the new score
			 dcd::theModel.theScore.Set(
				 dcd::cScore(
					dcd::theModel.theChoice.getSelected(),
					*dcd::theModel.critTree.getSelectedCriterion(),
					(float)Convert::ToDouble(ScoreTextBox->Text) ) );

			 // recalculate total score
			 dcd::theModel.ReCalculate( CritTreeView );

			 // display results
			 FillChoices();
		 }
		 /** Add sibling to current criterion */
private: System::Void AddSib_Click(System::Object^  sender, System::EventArgs^  e) {
			 dcd::theModel.critTree.AddASibling();
		 }
		  /** Add child to current criterion */
private: System::Void AddChild_Click(System::Object^  sender, System::EventArgs^  e) {
			 dcd::theModel.critTree.AddAChild();
		 }
		 /** User editing criterion name */
private: System::Void CritNameTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 msclr::interop::marshal_context ^ context = gcnew msclr::interop::marshal_context();
			 dcd::theModel.critTree.getSelectedCriterion()->setName(  context->marshal_as<const wchar_t *>(CritNameTextBox->Text) );
			 CritTreeView->SelectedNode->Text = CritNameTextBox->Text;
		 }
		 /** Save model */
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			saveFileDialog1->ShowDialog();
		 }
private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
			 cAODB db;
			 std::wstring path =  msclr::interop::marshal_as<std::wstring>(saveFileDialog1->FileName);
			 db.SaveProjectFile( path, CritTreeView );

		 }
private: System::Void AddChoice_Click(System::Object^  sender, System::EventArgs^  e) {
			 AddChoiceDlg^ dlg = gcnew AddChoiceDlg();
			 dlg->ShowDialog();
			 msclr::interop::marshal_context ^ context = gcnew msclr::interop::marshal_context();
			 dcd::theModel.theChoice.Add( dcd::cChoice( context->marshal_as<const wchar_t *>(dlg->textBox1->Text) ) );
			 FillChoices();
		 }
};
}

 