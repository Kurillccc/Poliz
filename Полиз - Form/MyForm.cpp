#include "Myform.h"

#include <iostream>
#include "Arifmetic.h"
using namespace std;

// (a * b / c ^ (x ^ 2 - y ^ 2) + c ^ (x + y) ^ a * b) - 17

using namespace System;
using namespace System::Windows::Forms;

void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(true);
    ПолизForm::MyForm form;
    Application::Run(% form);
}