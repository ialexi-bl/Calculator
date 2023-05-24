
#pragma once

#include <string>
#include <vector>
#include <lib\math-parser.h>
#include <lib\formatting.hpp>

namespace Calculator
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace Calculator;

  public
    ref class Calculator : public System::Windows::Forms::Form
    {
      public:
        Calculator(void)
        {
            InitializeComponent();
        }

      protected:
        ~Calculator()
        {
            if (components) {
                delete components;
            }
        }

      private:
        System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel1;
        System::Windows::Forms::TextBox ^ textBox1;

      private:
        Calculator::Keyboard ^ keyboard1;

        System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->keyboard1 = (gcnew Keyboard());
            this->tableLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            //
            // tableLayoutPanel1
            //
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50))
            );
            this->tableLayoutPanel1->Controls->Add(this->textBox1, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->keyboard1, 0, 1);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(16, 16);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 2;
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25))
            );
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 75))
            );
            this->tableLayoutPanel1->Size = System::Drawing::Size(488, 648);
            this->tableLayoutPanel1->TabIndex = 0;
            //
            // textBox1
            //
            this->textBox1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 32));
            this->textBox1->Location = System::Drawing::Point(0, 0);
            this->textBox1->Margin = System::Windows::Forms::Padding(0, 0, 0, 16);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->ReadOnly = true;
            this->textBox1->Size = System::Drawing::Size(488, 126);
            this->textBox1->TabIndex = 0;
            this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
            this->textBox1->KeyPress += gcnew KeyPressEventHandler(this, &Calculator::Form_KeyPress);
            this->textBox1->KeyDown += gcnew KeyEventHandler(this, &Calculator::Form_KeyDown);
            //
            // keyboard1
            //
            this->keyboard1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->keyboard1->Location = System::Drawing::Point(3, 145);
            this->keyboard1->Name = L"keyboard1";
            this->keyboard1->Size = System::Drawing::Size(482, 420);
            this->keyboard1->TabIndex = 1;
            this->keyboard1->Load += gcnew System::EventHandler(this, &Calculator::keyboard1_Load);
            this->keyboard1->KeyPressed +=
                gcnew System::EventHandler<Keyboard::KeyPressedEventArgs ^>(this, &Calculator::Keyboard_KeyPress);
            //
            // Calculator
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(520, 648);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Name = L"Calculator";
            this->Padding = System::Windows::Forms::Padding(16);
            this->Text = L"Calculator";
            this->Load += gcnew System::EventHandler(this, &Calculator::Form1_Load);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            this->KeyPress += gcnew KeyPressEventHandler(this, &Calculator::Form_KeyPress);
            this->KeyDown += gcnew KeyEventHandler(this, &Calculator::Form_KeyDown);
            this->ResumeLayout(false);
        }
#pragma endregion
      private:
        static std::wstring toStdString(System::String ^ str)
        {
            std::wstring result = L"";
            auto e = str->GetEnumerator();
            while (e->MoveNext()) {
                result += e->Current;
            }
            return result;
        }

        System::Void Form1_Load(System::Object ^, System::EventArgs ^)
        {
        }

        System::Void tableLayoutPanel1_Paint(System::Object ^, System::Windows::Forms::PaintEventArgs ^)
        {
        }

        System::Void tableLayoutPanel2_Paint(System::Object ^, System::Windows::Forms::PaintEventArgs ^)
        {
        }

      private:
        System::String ^ value = L"";

        int ComputeValue(System::String ^ next_value, System::String ^ &result)
        {
            long double out;
            int code = 0;
            
            switch (Math::compute(Calculator::toStdString(next_value), 7, out)) {
            case 0:
                result = gcnew System::String(Formatting::toBase(out, 7).c_str());
                break;
            case 10:
                result = L"Overflow";
                code = 1;
                break;
            default:
                result = L"Error";
            }

            return code;
        }

        System::Void handleKeyPress(Keyboard::Key key)
        {
            System::String ^ result;

            if (key == Keyboard::Key::CLEAR) {
                if (value->Length > 0) {
                    value = value->Substring(0, value->Length - 1);
                }
                ComputeValue(value, result);
            } else if (key == Keyboard::Key::CLEAR_EVERYTHING) {
                value = gcnew System::String(L"");
                ComputeValue(value, result);
            } else if (key == Keyboard::Key::COMPUTE) {
                ComputeValue(value, result);
                value = result;
            } else {
                System::String ^ next_value = value + static_cast<wchar_t>(key);

                if (ComputeValue(next_value, result)) {
                    return;
                }
                value = next_value;
            }

            this->textBox1->Text = value + System::Environment::NewLine + L"=" + result;
        }

        System::Void Keyboard_KeyPress(System::Object ^, Keyboard::KeyPressedEventArgs ^ e)
        {
            handleKeyPress(e->key);
        }

        System::Void Form_KeyPress(System::Object ^, KeyPressEventArgs ^ e)
        {
            switch (e->KeyChar) {
            case static_cast<char>(Keys::D0):
                handleKeyPress(Keyboard::Key::ZERO);
                break;
            case static_cast<char>(Keys::D1):
                handleKeyPress(Keyboard::Key::ONE);
                break;
            case static_cast<char>(Keys::D2):
                handleKeyPress(Keyboard::Key::TWO);
                break;
            case static_cast<char>(Keys::D3):
                handleKeyPress(Keyboard::Key::THREE);
                break;
            case static_cast<char>(Keys::D4):
                handleKeyPress(Keyboard::Key::FOUR);
                break;
            case static_cast<char>(Keys::D5):
                handleKeyPress(Keyboard::Key::FIVE);
                break;
            case '6':
                handleKeyPress(Keyboard::Key::SIX);
                break;
            case '/':
                handleKeyPress(Keyboard::Key::DIVIDE);
                break;
            case '*':
                handleKeyPress(Keyboard::Key::MULTIPLY);
                break;
            case '-':
                handleKeyPress(Keyboard::Key::MINUS);
                break;
            case '+':
                handleKeyPress(Keyboard::Key::PLUS);
                break;
            case static_cast<char>(Keys::Enter):
            case '=':
                handleKeyPress(Keyboard::Key::COMPUTE);
                break;
            case '.':
            case ',':
                handleKeyPress(Keyboard::Key::POINT);
                break;
            }
        }

        System::Void Form_KeyDown(System::Object ^, KeyEventArgs ^ e)
        {
            switch (e->KeyCode) {
            case Keys::Back:
            case Keys::Delete:
                auto v = Control::ModifierKeys;
                auto d = Control::ModifierKeys & Keys::Control;
                handleKeyPress(
                    e->Control ? Keyboard::Key::CLEAR_EVERYTHING : Keyboard::Key::CLEAR
                );
                break;
            }
        }

      private:
        System::Void keyboard1_Load(System::Object ^, System::EventArgs ^)
        {
        }
    };
} // namespace Calculator
