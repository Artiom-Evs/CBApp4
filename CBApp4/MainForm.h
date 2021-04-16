#pragma once

namespace CBApp4 {

	using namespace System;
	using namespace System::Net;
	using namespace System::Threading::Tasks;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	
	using namespace ParserApp::Models;
	using namespace ParserApp::Services;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		String^ groupsAddress = gcnew String("http://mgke.minsk.edu.by/ru/main.aspx?guid=3791");
		String^ teachersAddress = gcnew String("http://mgke.minsk.edu.by/ru/main.aspx?guid=3811");
		ParserApp::Models::EntitiesList^ groups;
		ParserApp::Models::EntitiesList^ teachers;

		MainForm(void);

	protected:
		~MainForm();
	private:
		System::Windows::Forms::SplitContainer^ splitContainer1;
		System::Windows::Forms::SplitContainer^ splitContainer2;
		System::Windows::Forms::Button^ button1;
		System::Windows::Forms::ComboBox^ comboBox1;
		System::Windows::Forms::Button^ button5;
		System::Windows::Forms::Panel^ panel1;
		System::Windows::Forms::Button^ button4;
		System::Windows::Forms::Button^ button3;
		System::Windows::Forms::Button^ button2;
		System::Windows::Forms::ListView^ listView1;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void);

#pragma endregion
	private:
		Void button1_Click(System::Object^ sender, System::EventArgs^ e);
		Void button4_Click(System::Object^ sender, System::EventArgs^ e);
		Void MainForm::groups_DownloadStringCompleted(Object^ sender, DownloadStringCompletedEventArgs^ e);
		Void MainForm::teachers_DownloadStringCompleted(Object^ sender, DownloadStringCompletedEventArgs^ e);
		Void button5_Click(Object^ sender, EventArgs^ e);

		void SetListBox(EntitiesList^ list) {
			for (int i = 0; i < list->Entities->Count; i++) {
				//String^ text = gcnew String(list->Entities[i]->Name, 0, 10, System::Text::Encoding::GetEncoding(1251));
				//this->listView1->Items->Add(text);
			}
		}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		EntitiesList^ entities = this->groups;
		this->Close();
	}
	};
}
