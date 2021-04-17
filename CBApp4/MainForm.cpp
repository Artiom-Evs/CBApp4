#include <Windows.h>
#include "MainForm.h"
#include "DataController.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Http;
using namespace System::Threading::Tasks;
using namespace CBApp4;

MainForm::MainForm(void)
{
	InitializeComponent();
	this->data = gcnew DataController();
	this->data->DataLoadingCompleted += gcnew DataLoadingEventHandler(this, &MainForm::DataLoadedHandler);
}
MainForm::~MainForm()
{
	if (components)
	{
		delete components;
	}
}
void MainForm::InitializeComponent(void)
{
	this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
	this->button5 = (gcnew System::Windows::Forms::Button());
	this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
	this->panel1 = (gcnew System::Windows::Forms::Panel());
	this->button4 = (gcnew System::Windows::Forms::Button());
	this->button3 = (gcnew System::Windows::Forms::Button());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->listView1 = (gcnew System::Windows::Forms::ListView());
	this->panel2 = (gcnew System::Windows::Forms::Panel());
	this->button6 = (gcnew System::Windows::Forms::Button());
	this->listBox1 = (gcnew System::Windows::Forms::ListBox());
	this->label1 = (gcnew System::Windows::Forms::Label());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
	this->splitContainer1->Panel1->SuspendLayout();
	this->splitContainer1->Panel2->SuspendLayout();
	this->splitContainer1->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
	this->splitContainer2->Panel1->SuspendLayout();
	this->splitContainer2->Panel2->SuspendLayout();
	this->splitContainer2->SuspendLayout();
	this->panel1->SuspendLayout();
	this->panel2->SuspendLayout();
	this->SuspendLayout();
	// 
	// splitContainer1
	// 
	this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->splitContainer1->Location = System::Drawing::Point(0, 0);
	this->splitContainer1->Margin = System::Windows::Forms::Padding(4);
	this->splitContainer1->Name = L"splitContainer1";
	this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
	// 
	// splitContainer1.Panel1
	// 
	this->splitContainer1->Panel1->AccessibleRole = System::Windows::Forms::AccessibleRole::StatusBar;
	this->splitContainer1->Panel1->Controls->Add(this->button5);
	this->splitContainer1->Panel1->Controls->Add(this->comboBox1);
	this->splitContainer1->Panel1->Controls->Add(this->button1);
	// 
	// splitContainer1.Panel2
	// 
	this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
	this->splitContainer1->Size = System::Drawing::Size(952, 654);
	this->splitContainer1->SplitterDistance = 46;
	this->splitContainer1->SplitterWidth = 6;
	this->splitContainer1->TabIndex = 0;
	// 
	// button5
	// 
	this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button5->Location = System::Drawing::Point(759, 0);
	this->button5->Name = L"button5";
	this->button5->Size = System::Drawing::Size(190, 46);
	this->button5->TabIndex = 2;
	this->button5->Text = L"Обновить";
	this->button5->UseVisualStyleBackColor = true;
	this->button5->Click += gcnew System::EventHandler(this, &MainForm::button5_Click);
	// 
	// comboBox1
	// 
	this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
	this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
	this->comboBox1->FormattingEnabled = true;
	this->comboBox1->Location = System::Drawing::Point(153, 3);
	this->comboBox1->Name = L"comboBox1";
	this->comboBox1->Size = System::Drawing::Size(600, 40);
	this->comboBox1->TabIndex = 1;
	// 
	// button1
	// 
	this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left));
	this->button1->AutoSize = true;
	this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->button1->Location = System::Drawing::Point(6, 0);
	this->button1->Margin = System::Windows::Forms::Padding(6);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(138, 46);
	this->button1->TabIndex = 0;
	this->button1->Text = L"Меню";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
	// 
	// splitContainer2
	// 
	this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
	this->splitContainer2->Location = System::Drawing::Point(0, 0);
	this->splitContainer2->Margin = System::Windows::Forms::Padding(4);
	this->splitContainer2->Name = L"splitContainer2";
	// 
	// splitContainer2.Panel1
	// 
	this->splitContainer2->Panel1->Controls->Add(this->panel1);
	this->splitContainer2->Panel1->Controls->Add(this->panel2);
	// 
	// splitContainer2.Panel2
	// 
	this->splitContainer2->Panel2->Controls->Add(this->listView1);
	this->splitContainer2->Size = System::Drawing::Size(952, 602);
	this->splitContainer2->SplitterDistance = 300;
	this->splitContainer2->SplitterWidth = 6;
	this->splitContainer2->TabIndex = 0;
	// 
	// panel1
	// 
	this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->panel1->Controls->Add(this->button4);
	this->panel1->Controls->Add(this->button3);
	this->panel1->Controls->Add(this->button2);
	this->panel1->Location = System::Drawing::Point(3, 0);
	this->panel1->Name = L"panel1";
	this->panel1->Size = System::Drawing::Size(296, 590);
	this->panel1->TabIndex = 3;
	// 
	// button4
	// 
	this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button4->Location = System::Drawing::Point(3, 92);
	this->button4->Name = L"button4";
	this->button4->Size = System::Drawing::Size(290, 40);
	this->button4->TabIndex = 3;
	this->button4->Text = L"Выход";
	this->button4->UseVisualStyleBackColor = true;
	this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
	// 
	// button3
	// 
	this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button3->Location = System::Drawing::Point(3, 46);
	this->button3->Name = L"button3";
	this->button3->Size = System::Drawing::Size(290, 40);
	this->button3->TabIndex = 2;
	this->button3->Text = L"Расписание преподавателей";
	this->button3->UseVisualStyleBackColor = true;
	this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
	// 
	// button2
	// 
	this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button2->Location = System::Drawing::Point(3, 3);
	this->button2->Name = L"button2";
	this->button2->Size = System::Drawing::Size(290, 40);
	this->button2->TabIndex = 1;
	this->button2->Text = L"Расписание групп";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
	// 
	// listView1
	// 
	this->listView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->listView1->HideSelection = false;
	this->listView1->Location = System::Drawing::Point(63, 0);
	this->listView1->Name = L"listView1";
	this->listView1->Size = System::Drawing::Size(488, 590);
	this->listView1->TabIndex = 0;
	this->listView1->UseCompatibleStateImageBehavior = false;
	// 
	// panel2
	// 
	this->panel2->Controls->Add(this->label1);
	this->panel2->Controls->Add(this->listBox1);
	this->panel2->Controls->Add(this->button6);
	this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->panel2->Location = System::Drawing::Point(0, 0);
	this->panel2->Name = L"panel2";
	this->panel2->Size = System::Drawing::Size(300, 602);
	this->panel2->TabIndex = 4;
	// 
	// button6
	// 
	this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button6->Location = System::Drawing::Point(3, 0);
	this->button6->Name = L"button6";
	this->button6->Size = System::Drawing::Size(293, 43);
	this->button6->TabIndex = 0;
	this->button6->Text = L"Назад";
	this->button6->UseVisualStyleBackColor = true;
	// 
	// listBox1
	// 
	this->listBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->listBox1->FormattingEnabled = true;
	this->listBox1->ItemHeight = 32;
	this->listBox1->Location = System::Drawing::Point(12, 92);
	this->listBox1->Name = L"listBox1";
	this->listBox1->Size = System::Drawing::Size(284, 484);
	this->listBox1->TabIndex = 1;
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Location = System::Drawing::Point(12, 54);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(93, 32);
	this->label1->TabIndex = 2;
	this->label1->Text = L"label1";
	// 
	// MainForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(16, 32);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(952, 654);
	this->Controls->Add(this->splitContainer1);
	this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->Margin = System::Windows::Forms::Padding(4);
	this->Name = L"MainForm";
	this->Text = L"ColledgeBrowser v4";
	this->splitContainer1->Panel1->ResumeLayout(false);
	this->splitContainer1->Panel1->PerformLayout();
	this->splitContainer1->Panel2->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
	this->splitContainer1->ResumeLayout(false);
	this->splitContainer2->Panel1->ResumeLayout(false);
	this->splitContainer2->Panel2->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
	this->splitContainer2->ResumeLayout(false);
	this->panel1->ResumeLayout(false);
	this->panel2->ResumeLayout(false);
	this->panel2->PerformLayout();
	this->ResumeLayout(false);

}

Void MainForm::button1_Click(Object^ sender, EventArgs^ e)
{
	this->splitContainer2->Panel1Collapsed = !this->splitContainer2->Panel1Collapsed;
}
Void MainForm::button2_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}
Void MainForm::button3_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}
void MainForm::button4_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}

Void MainForm::button5_Click(Object^ sender, EventArgs^ e)
{
	this->data->StartLoading();
}
void MainForm::DataLoadedHandler() {
	this->listBox1->Items->AddRange(this->data->Groups->Entities->ToArray());
	
	MessageBox::Show("Загрузка завершена!");
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	return 0;
}
