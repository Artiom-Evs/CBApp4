#include <Windows.h>
#include "MainForm.h"
#include "DataController.h"

using namespace System;
using namespace System::Net;
using namespace System::Net::Http;
using namespace System::Collections::Generic;
using namespace System::Threading;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;
using namespace CBApp4;
using namespace ParserApp::Models;

MainForm::MainForm(void)
{
	InitializeComponent();
	this->data = gcnew DataController();
	this->data->DataLoadingCompleted += gcnew DataLoadingEventHandler(this, &MainForm::DataController_DataLoaded);
	this->Shown += gcnew EventHandler(this, &MainForm::MainForm_Shown);
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
	this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
	this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
	this->panel1 = (gcnew System::Windows::Forms::Panel());
	this->button4 = (gcnew System::Windows::Forms::Button());
	this->button3 = (gcnew System::Windows::Forms::Button());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
	this->panel2 = (gcnew System::Windows::Forms::Panel());
	this->label1 = (gcnew System::Windows::Forms::Label());
	this->listBox1 = (gcnew System::Windows::Forms::ListBox());
	this->button6 = (gcnew System::Windows::Forms::Button());
	this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
	this->splitContainer1->Panel1->SuspendLayout();
	this->splitContainer1->Panel2->SuspendLayout();
	this->splitContainer1->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
	this->splitContainer2->Panel1->SuspendLayout();
	this->splitContainer2->Panel2->SuspendLayout();
	this->splitContainer2->SuspendLayout();
	this->tabControl1->SuspendLayout();
	this->tabPage1->SuspendLayout();
	this->panel1->SuspendLayout();
	this->tabPage2->SuspendLayout();
	this->panel2->SuspendLayout();
	this->SuspendLayout();
	// 
	// splitContainer1
	// 
	this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
	this->splitContainer1->IsSplitterFixed = true;
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
	this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
	// 
	// button1
	// 
	this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left));
	this->button1->AutoSize = true;
	this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->button1->Location = System::Drawing::Point(4, 0);
	this->button1->Margin = System::Windows::Forms::Padding(6);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(140, 46);
	this->button1->TabIndex = 0;
	this->button1->Text = L"Меню";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
	// 
	// splitContainer2
	// 
	this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->splitContainer2->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
	this->splitContainer2->IsSplitterFixed = true;
	this->splitContainer2->Location = System::Drawing::Point(0, 0);
	this->splitContainer2->Margin = System::Windows::Forms::Padding(4);
	this->splitContainer2->Name = L"splitContainer2";
	// 
	// splitContainer2.Panel1
	// 
	this->splitContainer2->Panel1->Controls->Add(this->tabControl1);
	// 
	// splitContainer2.Panel2
	// 
	this->splitContainer2->Panel2->Controls->Add(this->webBrowser1);
	this->splitContainer2->Size = System::Drawing::Size(952, 602);
	this->splitContainer2->SplitterDistance = 320;
	this->splitContainer2->SplitterWidth = 6;
	this->splitContainer2->TabIndex = 0;
	// 
	// tabControl1
	// 
	this->tabControl1->Controls->Add(this->tabPage1);
	this->tabControl1->Controls->Add(this->tabPage2);
	this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->tabControl1->Location = System::Drawing::Point(0, 0);
	this->tabControl1->Multiline = true;
	this->tabControl1->Name = L"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->Size = System::Drawing::Size(320, 602);
	this->tabControl1->TabIndex = 5;
	// 
	// tabPage1
	// 
	this->tabPage1->Controls->Add(this->panel1);
	this->tabPage1->Location = System::Drawing::Point(4, 41);
	this->tabPage1->Name = L"tabPage1";
	this->tabPage1->Padding = System::Windows::Forms::Padding(3);
	this->tabPage1->Size = System::Drawing::Size(312, 557);
	this->tabPage1->TabIndex = 0;
	this->tabPage1->Text = L"tabPage1";
	this->tabPage1->UseVisualStyleBackColor = true;
	// 
	// panel1
	// 
	this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->panel1->Controls->Add(this->button4);
	this->panel1->Controls->Add(this->button3);
	this->panel1->Controls->Add(this->button2);
	this->panel1->Location = System::Drawing::Point(6, 6);
	this->panel1->Name = L"panel1";
	this->panel1->Size = System::Drawing::Size(300, 675);
	this->panel1->TabIndex = 4;
	// 
	// button4
	// 
	this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button4->Location = System::Drawing::Point(3, 95);
	this->button4->Name = L"button4";
	this->button4->Size = System::Drawing::Size(294, 40);
	this->button4->TabIndex = 3;
	this->button4->Text = L"Выход";
	this->button4->UseVisualStyleBackColor = true;
	this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
	// 
	// button3
	// 
	this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button3->Location = System::Drawing::Point(3, 49);
	this->button3->Name = L"button3";
	this->button3->Size = System::Drawing::Size(294, 40);
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
	this->button2->Size = System::Drawing::Size(294, 40);
	this->button2->TabIndex = 1;
	this->button2->Text = L"Расписание групп";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
	// 
	// tabPage2
	// 
	this->tabPage2->Controls->Add(this->panel2);
	this->tabPage2->Location = System::Drawing::Point(4, 41);
	this->tabPage2->Name = L"tabPage2";
	this->tabPage2->Padding = System::Windows::Forms::Padding(3);
	this->tabPage2->Size = System::Drawing::Size(312, 557);
	this->tabPage2->TabIndex = 1;
	this->tabPage2->Text = L"tabPage2";
	this->tabPage2->UseVisualStyleBackColor = true;
	// 
	// panel2
	// 
	this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
		| System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->panel2->Controls->Add(this->label1);
	this->panel2->Controls->Add(this->listBox1);
	this->panel2->Controls->Add(this->button6);
	this->panel2->Location = System::Drawing::Point(6, 6);
	this->panel2->Name = L"panel2";
	this->panel2->Size = System::Drawing::Size(300, 546);
	this->panel2->TabIndex = 5;
	// 
	// label1
	// 
	this->label1->AutoSize = true;
	this->label1->Location = System::Drawing::Point(3, 55);
	this->label1->Name = L"label1";
	this->label1->Size = System::Drawing::Size(93, 32);
	this->label1->TabIndex = 1;
	this->label1->Text = L"label1";
	// 
	// listBox1
	// 
	this->listBox1->Anchor = System::Windows::Forms::AnchorStyles::None;
	this->listBox1->FormattingEnabled = true;
	this->listBox1->ItemHeight = 32;
	this->listBox1->Location = System::Drawing::Point(13, 90);
	this->listBox1->Name = L"listBox1";
	this->listBox1->Size = System::Drawing::Size(274, 452);
	this->listBox1->TabIndex = 2;
	this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox1_SelectedIndexChanged);
	// 
	// button6
	// 
	this->button6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
		| System::Windows::Forms::AnchorStyles::Right));
	this->button6->Location = System::Drawing::Point(3, 3);
	this->button6->Name = L"button6";
	this->button6->Size = System::Drawing::Size(294, 40);
	this->button6->TabIndex = 0;
	this->button6->Text = L"Назад";
	this->button6->UseVisualStyleBackColor = true;
	this->button6->Click += gcnew System::EventHandler(this, &MainForm::button6_Click);
	// 
	// webBrowser1
	// 
	this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->webBrowser1->Location = System::Drawing::Point(0, 0);
	this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
	this->webBrowser1->Name = L"webBrowser1";
	this->webBrowser1->Size = System::Drawing::Size(626, 602);
	this->webBrowser1->TabIndex = 0;
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
	this->tabControl1->ResumeLayout(false);
	this->tabPage1->ResumeLayout(false);
	this->panel1->ResumeLayout(false);
	this->tabPage2->ResumeLayout(false);
	this->panel2->ResumeLayout(false);
	this->panel2->PerformLayout();
	this->ResumeLayout(false);
}
String^ MainForm::CreatePageText(Entity^ entity) {
	String^ pageText = "";

	pageText += "<!DOCTYPE html><html><body><div>";

	pageText += "<h1>" + entity->Name + "</h1>";
	pageText += "<h2>" + entity->Date + "</h2>";

	for each (ParserApp::Models::Day ^ d in entity->Days) {
		pageText += CreateDayText(d);
	}

	pageText += "</div></body></html>";

	return pageText;
}
String^ MainForm::CreateDayText(ParserApp::Models::Day^ day) {
	String^ dayText = "";

	dayText += "<h3>" + day->Date + "</h3><div>";

	for each (array<String^> ^ l in day->Lessons) {
		dayText += "<p>" + l[0] + " " + l[1];
	}

	dayText += "</div><br>";

	return dayText;
}

Void MainForm::button1_Click(Object^ sender, EventArgs^ e)
{
	this->splitContainer2->Panel1Collapsed = !this->splitContainer2->Panel1Collapsed;
}
Void MainForm::button2_Click(Object^ sender, EventArgs^ e)
{
	if (this->data->IsLoaded) {
		this->selectedEntities = this->data->Groups->Entities;
		this->listBox1->DataSource = this->selectedEntities;
		this->label1->Text = this->data->Groups->Name;
		this->tabControl1->SelectedIndex = 1;
	}
}
Void MainForm::button3_Click(Object^ sender, EventArgs^ e)
{
	if (this->data->IsLoaded) {
		this->selectedEntities = this->data->Teachers->Entities;
		this->listBox1->DataSource = this->selectedEntities;
		this->label1->Text = this->data->Teachers->Name;
		this->tabControl1->SelectedIndex = 1;
	}
}
void MainForm::button4_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
}
Void MainForm::button5_Click(Object^ sender, EventArgs^ e)
{
	this->data->StartLoading();
}
Void MainForm::button6_Click(Object^ sender, EventArgs^ e) {
	this->tabControl1->SelectedIndex = 0;
}
Void MainForm::listBox1_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
	ListBox^ listBox = (ListBox^)sender;
	this->webBrowser1->DocumentText = CreatePageText(this->selectedEntities[listBox->SelectedIndex]);
}
Void MainForm::comboBox1_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
	ComboBox^ listBox = (ComboBox^)sender;
	this->webBrowser1->DocumentText = CreatePageText(((Entity^)listBox->SelectedItem));
}

void MainForm::DataController_DataLoaded() {
	List<Entity^>^ entities = gcnew List<Entity^>();
	entities->AddRange(this->data->Groups->Entities);
	entities->AddRange(this->data->Teachers->Entities);

	this->comboBox1->DataSource = entities;

	MessageBox::Show("Загрузка завершена!");
}
void MainForm::MainForm_Shown(Object^ sender, EventArgs^ e) {
	this->data->StartLoading();
}
void MainForm::MainForm_ExceptionOccurred(Object^ sender, ThreadExceptionEventArgs^ e) {
	//MessageBox::Show(e->Exception->ToString());
	
	if (e->Exception->Data->Count > 0) {
		for each (DictionaryEntry de in e->Exception->Data) {
			MessageBox::Show(de.Value->ToString());
		}
	}
}

[STAThread]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::ThreadException += gcnew ThreadExceptionEventHandler(MainForm::MainForm_ExceptionOccurred);
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);

	return 0;
}
