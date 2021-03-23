#include "pch.h"
#include <Windows.h>


using namespace System;
using namespace System::Threading::Tasks;

using namespace CBApp4Domain;

int Func()
{
	Class1 ^c1 = gcnew Class1();
	c1->SetName("Вася Пупкин приветствует тебя!");

	Console::WriteLine(c1->GetName());

	return 0;
}
