#pragma once
#include "DataController.h"

namespace CBApp4 {

	using namespace System;
	using namespace System::Net;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;	
	using namespace ParserApp::Models;
	using namespace ParserApp::Services;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void);
		static void MainForm_ExceptionOccurred(Object^ sender, ThreadExceptionEventArgs^ e);

	protected:
		~MainForm();

	private:
		DataController^ data;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ Ù‡ÈÎToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::WebBrowser^ webBrowser1;
	private: System::Windows::Forms::WebBrowser^ webBrowser2;
	private: System::Windows::Forms::ToolStripMenuItem^ ÒÔ‡‚Í‡ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;











	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void);

#pragma endregion
	private:
		String^ CreatePageText(Entity^ entity);
		String^ CreateDayText(ParserApp::Models::Day^ day);

		void MainForm_Shown(Object^ sender, EventArgs^ e);
		void DataController_DataLoaded();
		
		Void toolStripMenuItem2_Click(System::Object^ sender, System::EventArgs^ e);
		Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
		Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		Void listBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
		Void toolStripMenuItem3_Click(System::Object^ sender, System::EventArgs^ e);
		Void toolStripMenuItem4_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
