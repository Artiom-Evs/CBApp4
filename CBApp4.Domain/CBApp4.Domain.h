#pragma once

using namespace System;

namespace CBApp4Domain {
	public ref class Class1
	{
	public:
		String^ _name;

		Class1() {
			this->_name = gcnew String("");
		}

		String^ GetName() {
			return this->_name;
		}

		Void SetName(String^ name) {
			this->_name = name;
		}
	};
}
