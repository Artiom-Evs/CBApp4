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
	this->panel1 = (gcnew System::Windows::Forms::Panel());
	this->button2 = (gcnew System::Windows::Forms::Button());
	this->button1 = (gcnew System::Windows::Forms::Button());
	this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
	this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
	this->listBox1 = (gcnew System::Windows::Forms::ListBox());
	this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
	this->listBox2 = (gcnew System::Windows::Forms::ListBox());
	this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
	this->splitContainer1->Panel1->SuspendLayout();
	this->splitContainer1->Panel2->SuspendLayout();
	this->splitContainer1->SuspendLayout();
	this->panel1->SuspendLayout();
	this->tabControl1->SuspendLayout();
	this->tabPage1->SuspendLayout();
	this->tabPage2->SuspendLayout();
	this->SuspendLayout();
	// 
	// splitContainer1
	// 
	this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->splitContainer1->IsSplitterFixed = true;
	this->splitContainer1->Location = System::Drawing::Point(0, 0);
	this->splitContainer1->Margin = System::Windows::Forms::Padding(0);
	this->splitContainer1->Name = L"splitContainer1";
	// 
	// splitContainer1.Panel1
	// 
	this->splitContainer1->Panel1->Controls->Add(this->panel1);
	// 
	// splitContainer1.Panel2
	// 
	this->splitContainer1->Panel2->Controls->Add(this->webBrowser1);
	this->splitContainer1->Size = System::Drawing::Size(778, 394);
	this->splitContainer1->SplitterDistance = 250;
	this->splitContainer1->TabIndex = 0;
	// 
	// panel1
	// 
	this->panel1->Controls->Add(this->button2);
	this->panel1->Controls->Add(this->button1);
	this->panel1->Controls->Add(this->tabControl1);
	this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->panel1->Location = System::Drawing::Point(0, 0);
	this->panel1->Margin = System::Windows::Forms::Padding(0);
	this->panel1->Name = L"panel1";
	this->panel1->Size = System::Drawing::Size(250, 394);
	this->panel1->TabIndex = 0;
	// 
	// button2
	// 
	this->button2->Location = System::Drawing::Point(5, 359);
	this->button2->Margin = System::Windows::Forms::Padding(5);
	this->button2->Name = L"button2";
	this->button2->Size = System::Drawing::Size(240, 30);
	this->button2->TabIndex = 2;
	this->button2->Text = L"Выход";
	this->button2->UseVisualStyleBackColor = true;
	this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
	// 
	// button1
	// 
	this->button1->Location = System::Drawing::Point(5, 324);
	this->button1->Name = L"button1";
	this->button1->Size = System::Drawing::Size(240, 30);
	this->button1->TabIndex = 1;
	this->button1->Text = L"Обновить";
	this->button1->UseVisualStyleBackColor = true;
	this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
	// 
	// tabControl1
	// 
	this->tabControl1->Controls->Add(this->tabPage1);
	this->tabControl1->Controls->Add(this->tabPage2);
	this->tabControl1->Location = System::Drawing::Point(5, 5);
	this->tabControl1->Margin = System::Windows::Forms::Padding(0);
	this->tabControl1->Name = L"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->Size = System::Drawing::Size(240, 314);
	this->tabControl1->TabIndex = 0;
	// 
	// tabPage1
	// 
	this->tabPage1->Controls->Add(this->listBox1);
	this->tabPage1->Location = System::Drawing::Point(4, 41);
	this->tabPage1->Name = L"tabPage1";
	this->tabPage1->Padding = System::Windows::Forms::Padding(3);
	this->tabPage1->Size = System::Drawing::Size(232, 269);
	this->tabPage1->TabIndex = 0;
	this->tabPage1->Text = L"Группы";
	this->tabPage1->UseVisualStyleBackColor = true;
	// 
	// listBox1
	// 
	this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->listBox1->FormattingEnabled = true;
	this->listBox1->ItemHeight = 32;
	this->listBox1->Location = System::Drawing::Point(3, 3);
	this->listBox1->Name = L"listBox1";
	this->listBox1->Size = System::Drawing::Size(226, 263);
	this->listBox1->TabIndex = 0;
	this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox_SelectedIndexChanged);
	// 
	// tabPage2
	// 
	this->tabPage2->Controls->Add(this->listBox2);
	this->tabPage2->Location = System::Drawing::Point(4, 41);
	this->tabPage2->Name = L"tabPage2";
	this->tabPage2->Padding = System::Windows::Forms::Padding(3);
	this->tabPage2->Size = System::Drawing::Size(232, 269);
	this->tabPage2->TabIndex = 1;
	this->tabPage2->Text = L"Преподаватели";
	this->tabPage2->UseVisualStyleBackColor = true;
	// 
	// listBox2
	// 
	this->listBox2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->listBox2->FormattingEnabled = true;
	this->listBox2->ItemHeight = 32;
	this->listBox2->Location = System::Drawing::Point(3, 3);
	this->listBox2->Margin = System::Windows::Forms::Padding(5);
	this->listBox2->Name = L"listBox2";
	this->listBox2->Size = System::Drawing::Size(226, 263);
	this->listBox2->TabIndex = 0;
	this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox_SelectedIndexChanged);
	// 
	// webBrowser1
	// 
	this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->webBrowser1->Location = System::Drawing::Point(0, 0);
	this->webBrowser1->Margin = System::Windows::Forms::Padding(5);
	this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
	this->webBrowser1->Name = L"webBrowser1";
	this->webBrowser1->Size = System::Drawing::Size(524, 394);
	this->webBrowser1->TabIndex = 0;
	// 
	// MainForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(16, 32);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(778, 394);
	this->Controls->Add(this->splitContainer1);
	this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->Margin = System::Windows::Forms::Padding(4);
	this->Name = L"MainForm";
	this->Text = L"ColledgeBrowser v4";
	this->splitContainer1->Panel1->ResumeLayout(false);
	this->splitContainer1->Panel2->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
	this->splitContainer1->ResumeLayout(false);
	this->panel1->ResumeLayout(false);
	this->tabControl1->ResumeLayout(false);
	this->tabPage1->ResumeLayout(false);
	this->tabPage2->ResumeLayout(false);
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

void MainForm::DataController_DataLoaded() {
	this->listBox1->DataSource = this->data->Groups->Entities;
	this->listBox2->DataSource = this->data->Teachers->Entities;

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

Void MainForm::listBox_SelectedIndexChanged(Object^ sender, EventArgs^ e) {
	ListBox^ listBox = (ListBox^)sender;
	List<Entity^>^ entities = (List<Entity^>^)listBox->DataSource;
	this->webBrowser1->DocumentText = CreatePageText(entities[listBox->SelectedIndex]);
}
Void MainForm::button1_Click(Object^ sender, EventArgs^ e)
{
	this->data->StartLoading();
}
void MainForm::button2_Click(Object^ sender, EventArgs^ e)
{
	this->Close();
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
