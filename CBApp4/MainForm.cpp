#include "pch.h"
#include "MainForm.h"
#include <Windows.h>

using namespace CBApp4;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	return 0;
}
