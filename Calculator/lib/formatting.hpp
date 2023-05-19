#pragma once

#include <string>
#include "math-parser.h"

namespace Calculator
{
    namespace Formatting
    {
        std::wstring toStdWstring(System::String ^ str);
        std::wstring toBase(long double value, int base);
    }
}
