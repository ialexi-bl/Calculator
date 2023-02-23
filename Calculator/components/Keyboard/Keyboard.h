#pragma once

#include "lib/styles.h"

namespace Calculator
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

  public
    ref class Keyboard : public System::Windows::Forms::UserControl
    {
      public: /*
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

         ref class KeyPressedEventArgs : public EventArgs
         {
           public:
             const Key key;

             KeyPressedEventArgs(const Key key) : key(key)
             {
             }
         };*/
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

            this->button_plus->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_plus->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_plus->Name = L"button_plus";
            this->button_plus->TabIndex = 0;
            this->button_plus->Text = L"+";
            this->button_plus->UseVisualStyleBackColor = true;

            this->button_minus->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_minus->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_minus->Name = L"button_minus";
            this->button_minus->TabIndex = 1;
            this->button_minus->Text = L"-";
            this->button_minus->UseVisualStyleBackColor = true;

            this->button_multiply->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_multiply->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_multiply->Name = L"button_multiply";
            this->button_multiply->TabIndex = 2;
            this->button_multiply->Text = L"×";
            this->button_multiply->UseVisualStyleBackColor = true;

            this->button_divide->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_divide->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_divide->Name = L"button_divide";
            this->button_divide->TabIndex = 3;
            this->button_divide->Text = L"÷";
            this->button_divide->UseVisualStyleBackColor = true;

            this->button_0->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_0->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_0->Name = L"button_zero";
            this->button_0->TabIndex = 13;
            this->button_0->Text = L"0";
            this->button_0->UseVisualStyleBackColor = true;

            this->button_1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_1->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_1->Name = L"button_one";
            this->button_1->TabIndex = 4;
            this->button_1->Text = L"1";
            this->button_1->UseVisualStyleBackColor = true;

            this->button_2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_2->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_2->Name = L"button_two";
            this->button_2->TabIndex = 5;
            this->button_2->Text = L"2";
            this->button_2->UseVisualStyleBackColor = true;

            this->button_3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_3->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_3->Name = L"button_three";
            this->button_3->TabIndex = 6;
            this->button_3->Text = L"3";
            this->button_3->UseVisualStyleBackColor = true;

            this->button_4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_4->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_4->Name = L"button_four";
            this->button_4->TabIndex = 8;
            this->button_4->Text = L"4";
            this->button_4->UseVisualStyleBackColor = true;

            this->button_5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_5->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_5->Name = L"button_five";
            this->button_5->TabIndex = 9;
            this->button_5->Text = L"5";
            this->button_5->UseVisualStyleBackColor = true;

            this->button_6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_6->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_6->Name = L"button_six";
            this->button_6->TabIndex = 10;
            this->button_6->Text = L"6";
            this->button_6->UseVisualStyleBackColor = true;

            this->button_sign->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_sign->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_sign->Name = L"button_sign";
            this->button_sign->TabIndex = 12;
            this->button_sign->Text = L"+/-";
            this->button_sign->UseVisualStyleBackColor = true;

            this->button_paren->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_paren->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_paren->Name = L"button_paren";
            this->button_paren->TabIndex = 7;
            this->button_paren->Text = L"()";
            this->button_paren->UseVisualStyleBackColor = true;

            this->button_clear->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_clear->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_clear->Name = L"button_clear";
            this->button_clear->TabIndex = 11;
            this->button_clear->Text = L"C";
            this->button_clear->UseVisualStyleBackColor = true;

            this->button_point->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_point->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_point->Name = L"button_point";
            this->button_point->TabIndex = 14;
            this->button_point->Text = L",";
            this->button_point->UseVisualStyleBackColor = true;

            this->button_compute->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_compute->Font = gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            );
            this->button_compute->Name = L"button_compute";
            this->button_compute->TabIndex = 15;
            this->button_compute->Text = L"=";
            this->button_compute->UseVisualStyleBackColor = true;

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

      public:
        // System::EventHandler<KeyPressedEventArgs ^> ^ KeyPressed;

      private:
        /*template <Key K> System::Void button_Click(System::Object ^, System::EventArgs ^)
        {
            KeyPressed(this, gcnew KeyPressedEventArgs(K));
        }*/
    };
} // namespace Calculator
