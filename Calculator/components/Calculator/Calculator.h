
#pragma once

#include <string>
#include <lib\computations.h>

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
            this->tableLayoutPanel1->Size = System::Drawing::Size(488, 568);
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
            this->ClientSize = System::Drawing::Size(520, 600);
            this->Controls->Add(this->tableLayoutPanel1);
            this->Name = L"Calculator";
            this->Padding = System::Windows::Forms::Padding(16);
            this->Text = L"Form1";
            this->Load += gcnew System::EventHandler(this, &Calculator::Form1_Load);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
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

        System::Void Form1_Load(System::Object ^ sender, System::EventArgs ^ e)
        {
        }

        System::Void tableLayoutPanel1_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
        {
        }

        System::Void tableLayoutPanel2_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
        {
        }

      private:
        System::String ^ value = L"";

        System::Void Keyboard_KeyPress(System::Object ^, Keyboard::KeyPressedEventArgs ^ e)
        {
            if (e->key == Keyboard::Key::CLEAR) {
                value = value->Substring(0, value->Length - 1);
            } else {
                value += gcnew System::String(static_cast<char>(e->key), 1);
            }

            long double out;
            System::String ^ result;
            if (compute(Calculator::toStdString(value), 10, out)) {
                result = L"Error";
            } else {
                result = out.ToString();
            }
            this->textBox1->Text = value + System::Environment::NewLine + L"=" + result;
        }

      private:
        System::Void keyboard1_Load(System::Object ^ sender, System::EventArgs ^ e)
        {
        }
    };
} // namespace Calculator
