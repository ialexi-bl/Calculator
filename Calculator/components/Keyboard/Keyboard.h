#pragma once

#include <src/styles.h>

namespace Calculator
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    enum class Key {
        ZERO = '0',
        ONE = '1',
        TWO = '2',
        THREE = '3',
        FOUR = '4',
        FIVE = '5',
        SIX = '6',
        SIGN = '_',
        MINUS = '0',
        PLUS = '+',
        MULTIPLY = '*',
        DIVIDE = '/',
        CLEAR = 'c',
        COMPUTE = '=',
        PAREN = '(',
        POINT = ',',
    };

  public
    ref class KeyPressedEventArgs : public EventArgs
    {
      public:
        const Key key;

        KeyPressedEventArgs(const Key key) : key(key)
        {
        }
    };

  public
    ref class Keyboard : public System::Windows::Forms::UserControl
    {

      public:
        Keyboard(void)
        {
            InitializeComponent();
        }

      protected:
        ~Keyboard()
        {
            if (components) {
                delete components;
            }
        }

      private:
        System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel2;

      protected:
      private:
        System::Windows::Forms::Button ^ button_plus;
        System::Windows::Forms::Button ^ button_minus;
        System::Windows::Forms::Button ^ button_multiply;
        System::Windows::Forms::Button ^ button_divide;
        System::Windows::Forms::Button ^ button_1;
        System::Windows::Forms::Button ^ button_2;
        System::Windows::Forms::Button ^ button_3;
        System::Windows::Forms::Button ^ button_paren;
        System::Windows::Forms::Button ^ button_4;
        System::Windows::Forms::Button ^ button_5;
        System::Windows::Forms::Button ^ button_6;
        System::Windows::Forms::Button ^ button_clear;
        System::Windows::Forms::Button ^ button_point;
        System::Windows::Forms::Button ^ button_compute;
        System::Windows::Forms::Button ^ button_sign;
        System::Windows::Forms::Button ^ button_0;

        System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->button_plus = (gcnew System::Windows::Forms::Button());
            this->button_minus = (gcnew System::Windows::Forms::Button());
            this->button_multiply = (gcnew System::Windows::Forms::Button());
            this->button_divide = (gcnew System::Windows::Forms::Button());
            this->button_1 = (gcnew System::Windows::Forms::Button());
            this->button_2 = (gcnew System::Windows::Forms::Button());
            this->button_3 = (gcnew System::Windows::Forms::Button());
            this->button_paren = (gcnew System::Windows::Forms::Button());
            this->button_4 = (gcnew System::Windows::Forms::Button());
            this->button_5 = (gcnew System::Windows::Forms::Button());
            this->button_6 = (gcnew System::Windows::Forms::Button());
            this->button_clear = (gcnew System::Windows::Forms::Button());
            this->button_point = (gcnew System::Windows::Forms::Button());
            this->button_compute = (gcnew System::Windows::Forms::Button());
            this->button_sign = (gcnew System::Windows::Forms::Button());
            this->button_0 = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel2->SuspendLayout();
            this->SuspendLayout();
            //
            // tableLayoutPanel2
            //
            this->tableLayoutPanel2->ColumnCount = 4;
            this->tableLayoutPanel2->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->Controls->Add(this->button_plus, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_minus, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_multiply, 2, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_divide, 3, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_1, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_2, 1, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_3, 2, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_paren, 3, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_4, 0, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_5, 1, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_6, 2, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_clear, 3, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_sign, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_0, 1, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_point, 2, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_compute, 3, 3);
            this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
            this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(0);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 4;
            this->tableLayoutPanel2->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel2->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20))
            );
            this->tableLayoutPanel2->Size = System::Drawing::Size(630, 559);
            this->tableLayoutPanel2->TabIndex = 2;

            InitializeButton<Key::PLUS>(this->button_plus, L"button_plus", L"+", 0);
            InitializeButton<Key::MINUS>(this->button_minus, L"button_minus", L"-", 1);
            InitializeButton<Key::MULTIPLY>(this->button_multiply, L"button_multiply", L"×", 2);
            InitializeButton<Key::DIVIDE>(this->button_divide, L"button_divide", L"÷", 3);

            InitializeButton<Key::ZERO>(this->button_0, L"button_zero", L"0", 13);
            InitializeButton<Key::ONE>(this->button_1, L"button_one", L"1", 4);
            InitializeButton<Key::TWO>(this->button_2, L"button_two", L"2", 5);
            InitializeButton<Key::THREE>(this->button_3, L"button_three", L"3", 6);
            InitializeButton<Key::FOUR>(this->button_4, L"button_four", L"4", 8);
            InitializeButton<Key::FIVE>(this->button_5, L"button_five", L"5", 9);
            InitializeButton<Key::SIX>(this->button_6, L"button_six", L"6", 10);

            InitializeButton<Key::SIGN>(this->button_sign, L"button_sign", L"+/-", 12);
            InitializeButton<Key::PAREN>(this->button_paren, L"button_paren", L"()", 7);
            InitializeButton<Key::CLEAR>(this->button_clear, L"button_clear", L"C", 11);
            InitializeButton<Key::POINT>(this->button_point, L"button_point", L",", 14);
            InitializeButton<Key::COMPUTE>(this->button_compute, L"button_compute", L"=", 15);
            //
            // Keyboard
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->tableLayoutPanel2);
            this->Name = L"Keyboard";
            this->Size = System::Drawing::Size(630, 559);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

        template <Key K>
        void InitializeButton(System::Windows::Forms::Button ^ button, System::String ^ name, System::String ^ text, int tabIndex)
        {
            button->Dock = System::Windows::Forms::DockStyle::Fill;
            button->Font = Styles::getDefaultFont();
            button->Name = name;
            button->TabIndex = tabIndex;
            button->Text = text;
            button->UseVisualStyleBackColor = true;
            button->Click += gcnew System::EventHandler(this, &Keyboard::button_Click<K>);
        }

      public:
        System::EventHandler<KeyPressedEventArgs ^> ^ KeyPressed;

      private:
        template <Key K> System::Void button_Click(System::Object ^, System::EventArgs ^)
        {
            KeyPressed(this, gcnew KeyPressedEventArgs(K));
        }
    };
} // namespace Calculator
