#include "formatting.hpp"
#include <cassert>
#include <cmath>

namespace Calculator
{
    namespace Formatting
    {
        std::wstring toStdWstring(System::String ^ str)
        {
            std::wstring result = L"";
            auto e = str->GetEnumerator();
            while (e->MoveNext()) {
                result += e->Current;
            }
            return result;
        }

        static std::wstring toBasePositiveInteger(long value, int base)
        {
            if (!value) {
                return L"0";
            }

            std::wstring result;
            for (long q = value; q > 0; q /= base) {
                long r = q % base;
                result = std::to_wstring(r) + result;
            }

            if (!value) {
                result += L'0';
            }
            return result;
        }

        std::wstring toBase(long double value, int base)
        {
            assert(2 <= base && base <= 10, "Only bases 2 to 10 are supported");

            if (std::isinf(value)) {
                return value > 0 ? L"Infinity" : L"-Infinity";
            }
            if (std::isnan(value)) {
                return L"Error";
            }

            bool negative = value < 0;
            if (negative) value *= -1;

            std::wstring result = negative ? L"-" : L"";

            long whole = static_cast<long>(value);
            result += toBasePositiveInteger(whole, base);

            long double decimal = (value < 0 ? -value : value) - whole;

            if (!decimal) {
                return result;
            }

            std::vector<int> decimal_result;
            int trailing_char = 0, trailing_sequence_Start = 0;
            for (int i = 0; i < 9 && decimal; i++) {
                decimal *= base;
                int digit = static_cast<int>(decimal);
                decimal_result.push_back(digit);
                decimal -= digit;

                if (digit == 0) {
                    if (trailing_char != 0) {
                        trailing_sequence_Start = i;
                    }
                    trailing_char = 0;
                } else if (digit == base - 1) {
                    if (trailing_char != 1) {
                        if (trailing_sequence_Start == 0) {
                            // Example: 1.66666666
                            trailing_sequence_Start = decimal_result.size() - 1;
                        } else {
                            trailing_sequence_Start = i - 1;
                        }
                    }
                    trailing_char = 1;
                } else {
                    trailing_char = 0;
                    trailing_sequence_Start = i + 1;
                }
            }

            result += L'.';
            int j;
            for (j = 0; j < trailing_sequence_Start; j++) {
                result += std::to_wstring(decimal_result[j]);
            }
            if (trailing_char == 1) {
                result += std::to_wstring(decimal_result[trailing_sequence_Start] + 1);
            }

            return result;
        }
    } // namespace Formatting
} // namespace Calculator
