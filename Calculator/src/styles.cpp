#include <pch.h>
#include "styles.h"

namespace Calculator
{
    namespace Styles
    {
        System::Drawing::Font ^ getDefaultFont(float size) {
            return gcnew System::Drawing::Font(
                L"Courier New",
                size,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
        }
    }
} // namespace Calculator