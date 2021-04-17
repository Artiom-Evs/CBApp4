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
		Void button1_Click(Object^ sender, EventArgs^ e);
		Void button2_Click(Object^ sender, EventArgs^ e);
		Void button3_Click(Object^ sender, EventArgs^ e);
		Void button4_Click(Object^ sender, EventArgs^ e);
		Void button5_Click(Object^ sender, EventArgs^ e);
		
	};
}
