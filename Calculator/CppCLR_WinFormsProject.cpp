#include "pch.h"

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }

#include "components/Calculator/Calculator.h"

using namespace System::Windows::Forms;

[STAThread] int main() {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Calculator::Calculator());
    return 0;
}