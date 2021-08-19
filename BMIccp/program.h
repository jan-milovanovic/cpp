#pragma once

#include <string>
#include <iostream>


System::String^ checkBMI(double bmi)
{
	if (bmi < 16.5)
		return "Seriously underweight";
	else if (bmi < 18.5)
		return "Underweight";
	else if (bmi < 25)
		return "Normal";
	else if (bmi < 30)
		return "Overweight";
	else
		return "Obese";
}


namespace BMIccp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	bool metric = true;

	double cm, ft, in, kg, lbs, BMI;	// optimizing 2 variables does almost nothing..


	/// <summary>
	/// Summary for program
	/// </summary>
	public ref class program : public System::Windows::Forms::Form
	{
	public:
		program(void)
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
		~program()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  kglbs;
	protected:

	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::TextBox^  cmft;

	private: System::Windows::Forms::Label^  lbl_cmft;
	private: System::Windows::Forms::TextBox^  inch;



	private: System::Windows::Forms::Label^  lbl_in;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  lbl_kglbs;
	private: System::Windows::Forms::LinkLabel^  lbl_changeIM;
	private: System::Windows::Forms::Label^  label_weight;
	private: System::Windows::Forms::Label^  label_height;
	private: System::Windows::Forms::Button^  calculator;
	private: System::Windows::Forms::RichTextBox^  status;





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
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lbl_kglbs = (gcnew System::Windows::Forms::Label());
			this->lbl_changeIM = (gcnew System::Windows::Forms::LinkLabel());
			this->label_weight = (gcnew System::Windows::Forms::Label());
			this->label_height = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->cmft = (gcnew System::Windows::Forms::TextBox());
			this->lbl_cmft = (gcnew System::Windows::Forms::Label());
			this->inch = (gcnew System::Windows::Forms::TextBox());
			this->lbl_in = (gcnew System::Windows::Forms::Label());
			this->kglbs = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->status = (gcnew System::Windows::Forms::RichTextBox());
			this->calculator = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->lbl_kglbs);
			this->groupBox1->Controls->Add(this->lbl_changeIM);
			this->groupBox1->Controls->Add(this->label_weight);
			this->groupBox1->Controls->Add(this->label_height);
			this->groupBox1->Controls->Add(this->flowLayoutPanel1);
			this->groupBox1->Controls->Add(this->kglbs);
			this->groupBox1->ForeColor = System::Drawing::Color::White;
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(288, 137);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Info";
			// 
			// lbl_kglbs
			// 
			this->lbl_kglbs->AutoSize = true;
			this->lbl_kglbs->Location = System::Drawing::Point(125, 104);
			this->lbl_kglbs->Name = L"lbl_kglbs";
			this->lbl_kglbs->Size = System::Drawing::Size(19, 13);
			this->lbl_kglbs->TabIndex = 6;
			this->lbl_kglbs->Text = L"kg";
			// 
			// lbl_changeIM
			// 
			this->lbl_changeIM->AutoSize = true;
			this->lbl_changeIM->Location = System::Drawing::Point(185, 16);
			this->lbl_changeIM->Name = L"lbl_changeIM";
			this->lbl_changeIM->Size = System::Drawing::Size(93, 13);
			this->lbl_changeIM->TabIndex = 5;
			this->lbl_changeIM->TabStop = true;
			this->lbl_changeIM->Text = L"change to imperial";
			this->lbl_changeIM->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &program::lbl_changeIM_LinkClicked);
			// 
			// label_weight
			// 
			this->label_weight->AutoSize = true;
			this->label_weight->Location = System::Drawing::Point(6, 85);
			this->label_weight->Name = L"label_weight";
			this->label_weight->Size = System::Drawing::Size(41, 13);
			this->label_weight->TabIndex = 4;
			this->label_weight->Text = L"Weight";
			// 
			// label_height
			// 
			this->label_height->AutoSize = true;
			this->label_height->Location = System::Drawing::Point(6, 25);
			this->label_height->Name = L"label_height";
			this->label_height->Size = System::Drawing::Size(38, 13);
			this->label_height->TabIndex = 3;
			this->label_height->Text = L"Height";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->cmft);
			this->flowLayoutPanel1->Controls->Add(this->lbl_cmft);
			this->flowLayoutPanel1->Controls->Add(this->inch);
			this->flowLayoutPanel1->Controls->Add(this->lbl_in);
			this->flowLayoutPanel1->Location = System::Drawing::Point(16, 41);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(262, 28);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// cmft
			// 
			this->cmft->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->cmft->Location = System::Drawing::Point(3, 3);
			this->cmft->Name = L"cmft";
			this->cmft->Size = System::Drawing::Size(100, 20);
			this->cmft->TabIndex = 1;
			// 
			// lbl_cmft
			// 
			this->lbl_cmft->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_cmft->AutoSize = true;
			this->lbl_cmft->Location = System::Drawing::Point(109, 6);
			this->lbl_cmft->Name = L"lbl_cmft";
			this->lbl_cmft->Size = System::Drawing::Size(21, 13);
			this->lbl_cmft->TabIndex = 2;
			this->lbl_cmft->Text = L"cm";
			// 
			// inch
			// 
			this->inch->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->inch->Location = System::Drawing::Point(136, 3);
			this->inch->Name = L"inch";
			this->inch->Size = System::Drawing::Size(100, 20);
			this->inch->TabIndex = 0;
			this->inch->Visible = false;
			// 
			// lbl_in
			// 
			this->lbl_in->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->lbl_in->AutoSize = true;
			this->lbl_in->Location = System::Drawing::Point(242, 6);
			this->lbl_in->Name = L"lbl_in";
			this->lbl_in->Size = System::Drawing::Size(15, 13);
			this->lbl_in->TabIndex = 3;
			this->lbl_in->Text = L"in";
			this->lbl_in->Visible = false;
			// 
			// kglbs
			// 
			this->kglbs->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->kglbs->Location = System::Drawing::Point(19, 101);
			this->kglbs->Name = L"kglbs";
			this->kglbs->Size = System::Drawing::Size(100, 20);
			this->kglbs->TabIndex = 2;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->status);
			this->groupBox2->Controls->Add(this->calculator);
			this->groupBox2->ForeColor = System::Drawing::Color::White;
			this->groupBox2->Location = System::Drawing::Point(12, 155);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(288, 162);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Status";
			// 
			// status
			// 
			this->status->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->status->ForeColor = System::Drawing::Color::White;
			this->status->Location = System::Drawing::Point(9, 19);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(273, 93);
			this->status->TabIndex = 2;
			this->status->Text = L"...";
			// 
			// calculator
			// 
			this->calculator->BackColor = System::Drawing::Color::DarkViolet;
			this->calculator->ForeColor = System::Drawing::Color::White;
			this->calculator->Location = System::Drawing::Point(6, 118);
			this->calculator->Name = L"calculator";
			this->calculator->Size = System::Drawing::Size(276, 38);
			this->calculator->TabIndex = 1;
			this->calculator->Text = L"Calculate BMI";
			this->calculator->UseVisualStyleBackColor = false;
			this->calculator->Click += gcnew System::EventHandler(this, &program::calculator_Click);
			// 
			// program
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(16)), static_cast<System::Int32>(static_cast<System::Byte>(16)),
				static_cast<System::Int32>(static_cast<System::Byte>(16)));
			this->ClientSize = System::Drawing::Size(313, 328);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"program";
			this->Text = L"BMI Calculator";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void calculator_Click(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		if (metric)
		{
			cm = Convert::ToDouble(this->cmft->Text);
			kg = Convert::ToDouble(this->kglbs->Text);

			BMI = kg / Math::Pow(cm / 100, 2);
		}
		else
		{
			in = Convert::ToInt16(this->cmft->Text) * 12;
			in += Convert::ToInt16(this->inch->Text);
			lbs = Convert::ToDouble(this->kglbs->Text);

			BMI = 703 * lbs / (in * in);
		}
		this->status->Rtf = "{\\rtf1\\ansi \\b0 Your bmi is " + (float)((int)(BMI * 100)) / 100 +
							"\\line\\line This classifies you as {\\rtf1\\ansi \\b " + checkBMI(BMI) + " \\b0}";
	}
	catch (...)
	{
		this->status->Rtf = "{\\rtf1\\ansi \\b You fucked something up. \\b0}";
	}
}

private: System::Void lbl_changeIM_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
{
	metric = !metric;

	if (!metric)
	{
		this->lbl_cmft->Text = L"ft";
		this->lbl_in->Visible = true;
		this->inch->Visible = true;
		this->lbl_kglbs->Text = L"lbs";

		this->lbl_changeIM->Text = L"change to metric";
	}
	else
	{
		this->lbl_cmft->Text = L"cm";
		this->lbl_in->Visible = false;
		this->inch->Visible = false;
		this->lbl_kglbs->Text = L"kg";

		this->lbl_changeIM->Text = L"change to metric";
	}
}
};
}
