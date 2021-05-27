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
	this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
	this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
	this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
	this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
	this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
	this->listBox1 = (gcnew System::Windows::Forms::ListBox());
	this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
	this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
	this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
	this->listBox2 = (gcnew System::Windows::Forms::ListBox());
	this->webBrowser2 = (gcnew System::Windows::Forms::WebBrowser());
	this->ñïğàâêàToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
	this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
	this->menuStrip1->SuspendLayout();
	this->tabControl1->SuspendLayout();
	this->tabPage2->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
	this->splitContainer1->Panel1->SuspendLayout();
	this->splitContainer1->Panel2->SuspendLayout();
	this->splitContainer1->SuspendLayout();
	this->tabPage3->SuspendLayout();
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
	this->splitContainer2->Panel1->SuspendLayout();
	this->splitContainer2->Panel2->SuspendLayout();
	this->splitContainer2->SuspendLayout();
	this->SuspendLayout();
	// 
	// menuStrip1
	// 
	this->menuStrip1->GripMargin = System::Windows::Forms::Padding(2, 2, 0, 2);
	this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
	this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
		this->ôàéëToolStripMenuItem,
			this->ñïğàâêàToolStripMenuItem
	});
	this->menuStrip1->Location = System::Drawing::Point(0, 0);
	this->menuStrip1->Name = L"menuStrip1";
	this->menuStrip1->Size = System::Drawing::Size(778, 33);
	this->menuStrip1->TabIndex = 0;
	this->menuStrip1->Text = L"menuStrip1";
	// 
	// ôàéëToolStripMenuItem
	// 
	this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
		this->toolStripMenuItem1,
			this->toolStripSeparator1, this->toolStripMenuItem2
	});
	this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
	this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(69, 29);
	this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
	// 
	// toolStripMenuItem1
	// 
	this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
	this->toolStripMenuItem1->Size = System::Drawing::Size(270, 34);
	this->toolStripMenuItem1->Text = L"Îáíîâèòü";
	this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem1_Click);
	// 
	// toolStripSeparator1
	// 
	this->toolStripSeparator1->Name = L"toolStripSeparator1";
	this->toolStripSeparator1->Size = System::Drawing::Size(267, 6);
	// 
	// toolStripMenuItem2
	// 
	this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
	this->toolStripMenuItem2->Size = System::Drawing::Size(270, 34);
	this->toolStripMenuItem2->Text = L"Âûõîä";
	this->toolStripMenuItem2->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem2_Click);
	// 
	// tabControl1
	// 
	this->tabControl1->Controls->Add(this->tabPage1);
	this->tabControl1->Controls->Add(this->tabPage2);
	this->tabControl1->Controls->Add(this->tabPage3);
	this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->tabControl1->Location = System::Drawing::Point(0, 33);
	this->tabControl1->Margin = System::Windows::Forms::Padding(0);
	this->tabControl1->Name = L"tabControl1";
	this->tabControl1->SelectedIndex = 0;
	this->tabControl1->Size = System::Drawing::Size(778, 361);
	this->tabControl1->TabIndex = 1;
	// 
	// tabPage1
	// 
	this->tabPage1->Location = System::Drawing::Point(4, 41);
	this->tabPage1->Name = L"tabPage1";
	this->tabPage1->Padding = System::Windows::Forms::Padding(3);
	this->tabPage1->Size = System::Drawing::Size(770, 316);
	this->tabPage1->TabIndex = 0;
	this->tabPage1->Text = L"Ãëàâíàÿ";
	this->tabPage1->UseVisualStyleBackColor = true;
	// 
	// tabPage2
	// 
	this->tabPage2->Controls->Add(this->splitContainer1);
	this->tabPage2->Location = System::Drawing::Point(4, 41);
	this->tabPage2->Name = L"tabPage2";
	this->tabPage2->Padding = System::Windows::Forms::Padding(3);
	this->tabPage2->Size = System::Drawing::Size(770, 316);
	this->tabPage2->TabIndex = 1;
	this->tabPage2->Text = L"Ãğóïïû";
	this->tabPage2->UseVisualStyleBackColor = true;
	// 
	// splitContainer1
	// 
	this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->splitContainer1->IsSplitterFixed = true;
	this->splitContainer1->Location = System::Drawing::Point(3, 3);
	this->splitContainer1->Margin = System::Windows::Forms::Padding(0);
	this->splitContainer1->Name = L"splitContainer1";
	// 
	// splitContainer1.Panel1
	// 
	this->splitContainer1->Panel1->Controls->Add(this->listBox1);
	// 
	// splitContainer1.Panel2
	// 
	this->splitContainer1->Panel2->Controls->Add(this->webBrowser1);
	this->splitContainer1->Size = System::Drawing::Size(764, 310);
	this->splitContainer1->SplitterDistance = 200;
	this->splitContainer1->TabIndex = 0;
	// 
	// listBox1
	// 
	this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->listBox1->FormattingEnabled = true;
	this->listBox1->ItemHeight = 32;
	this->listBox1->Location = System::Drawing::Point(0, 0);
	this->listBox1->Margin = System::Windows::Forms::Padding(5);
	this->listBox1->Name = L"listBox1";
	this->listBox1->Size = System::Drawing::Size(200, 310);
	this->listBox1->TabIndex = 0;
	this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox1_SelectedIndexChanged);
	// 
	// webBrowser1
	// 
	this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
	this->webBrowser1->Location = System::Drawing::Point(0, 0);
	this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
	this->webBrowser1->Name = L"webBrowser1";
	this->webBrowser1->Size = System::Drawing::Size(560, 310);
	this->webBrowser1->TabIndex = 0;
	// 
	// tabPage3
	// 
	this->tabPage3->Controls->Add(this->splitContainer2);
	this->tabPage3->Location = System::Drawing::Point(4, 41);
	this->tabPage3->Name = L"tabPage3";
	this->tabPage3->Padding = System::Windows::Forms::Padding(3);
	this->tabPage3->Size = System::Drawing::Size(770, 316);
	this->tabPage3->TabIndex = 2;
	this->tabPage3->Text = L"Ïğåïîäàâàòåëè";
	this->tabPage3->UseVisualStyleBackColor = true;
	// 
	// splitContainer2
	// 
	this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->splitContainer2->IsSplitterFixed = true;
	this->splitContainer2->Location = System::Drawing::Point(3, 3);
	this->splitContainer2->Margin = System::Windows::Forms::Padding(0);
	this->splitContainer2->Name = L"splitContainer2";
	// 
	// splitContainer2.Panel1
	// 
	this->splitContainer2->Panel1->Controls->Add(this->listBox2);
	// 
	// splitContainer2.Panel2
	// 
	this->splitContainer2->Panel2->Controls->Add(this->webBrowser2);
	this->splitContainer2->Size = System::Drawing::Size(764, 310);
	this->splitContainer2->SplitterDistance = 200;
	this->splitContainer2->TabIndex = 0;
	// 
	// listBox2
	// 
	this->listBox2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->listBox2->FormattingEnabled = true;
	this->listBox2->ItemHeight = 32;
	this->listBox2->Location = System::Drawing::Point(0, 0);
	this->listBox2->Margin = System::Windows::Forms::Padding(5);
	this->listBox2->Name = L"listBox2";
	this->listBox2->Size = System::Drawing::Size(200, 310);
	this->listBox2->TabIndex = 0;
	this->listBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::listBox2_SelectedIndexChanged);
	// 
	// webBrowser2
	// 
	this->webBrowser2->Dock = System::Windows::Forms::DockStyle::Fill;
	this->webBrowser2->Location = System::Drawing::Point(0, 0);
	this->webBrowser2->MinimumSize = System::Drawing::Size(20, 20);
	this->webBrowser2->Name = L"webBrowser2";
	this->webBrowser2->Size = System::Drawing::Size(560, 310);
	this->webBrowser2->TabIndex = 0;
	// 
	// ñïğàâêàToolStripMenuItem
	// 
	this->ñïğàâêàToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
		this->toolStripMenuItem3,
			this->toolStripSeparator2, this->toolStripMenuItem4
	});
	this->ñïğàâêàToolStripMenuItem->Name = L"ñïğàâêàToolStripMenuItem";
	this->ñïğàâêàToolStripMenuItem->Size = System::Drawing::Size(97, 29);
	this->ñïğàâêàToolStripMenuItem->Text = L"Ñïğàâêà";
	// 
	// toolStripMenuItem3
	// 
	this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
	this->toolStripMenuItem3->Size = System::Drawing::Size(295, 34);
	this->toolStripMenuItem3->Text = L"Ïğîñìîòğåòü ñïğàâêó";
	this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem3_Click);
	// 
	// toolStripSeparator2
	// 
	this->toolStripSeparator2->Name = L"toolStripSeparator2";
	this->toolStripSeparator2->Size = System::Drawing::Size(292, 6);
	// 
	// toolStripMenuItem4
	// 
	this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
	this->toolStripMenuItem4->Size = System::Drawing::Size(295, 34);
	this->toolStripMenuItem4->Text = L"Î ïğîãğàììå";
	this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &MainForm::toolStripMenuItem4_Click);
	// 
	// MainForm
	// 
	this->AutoScaleDimensions = System::Drawing::SizeF(16, 32);
	this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
	this->ClientSize = System::Drawing::Size(778, 394);
	this->Controls->Add(this->tabControl1);
	this->Controls->Add(this->menuStrip1);
	this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(204)));
	this->MainMenuStrip = this->menuStrip1;
	this->Margin = System::Windows::Forms::Padding(4);
	this->Name = L"MainForm";
	this->Text = L"ColledgeBrowser v4";
	this->menuStrip1->ResumeLayout(false);
	this->menuStrip1->PerformLayout();
	this->tabControl1->ResumeLayout(false);
	this->tabPage2->ResumeLayout(false);
	this->splitContainer1->Panel1->ResumeLayout(false);
	this->splitContainer1->Panel2->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
	this->splitContainer1->ResumeLayout(false);
	this->tabPage3->ResumeLayout(false);
	this->splitContainer2->Panel1->ResumeLayout(false);
	this->splitContainer2->Panel2->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
	this->splitContainer2->ResumeLayout(false);
	this->ResumeLayout(false);
	this->PerformLayout();

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

	MessageBox::Show("Çàãğóçêà çàâåğøåíà!");
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

Void MainForm::toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->data->StartLoading();
}
Void MainForm::toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
Void MainForm::toolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Ñïğàâî÷íàÿ èíôîğìàöèÿ ïîêà îòñóòñòâóåò!");
}
Void MainForm::toolStripMenuItem4_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Èíôîğìàöèÿ î ïğîãğàììå ïîêà îòñóòñòâóåò!");
}
Void MainForm::listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ListBox^ listBox = (ListBox^)sender;
	List<Entity^>^ entities = (List<Entity^>^)listBox->DataSource;
	this->webBrowser1->DocumentText = CreatePageText(entities[listBox->SelectedIndex]);
}
Void MainForm::listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	ListBox^ listBox = (ListBox^)sender;
	List<Entity^>^ entities = (List<Entity^>^)listBox->DataSource;
	this->webBrowser2->DocumentText = CreatePageText(entities[listBox->SelectedIndex]);
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
