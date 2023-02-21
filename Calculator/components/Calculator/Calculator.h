#pragma once

namespace Calculator
{

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Form1
    /// </summary>
  public
    ref class Calculator : public System::Windows::Forms::Form
    {
      public:
        Calculator(void)
        {
            InitializeComponent();
            //
            // TODO: Add the constructor code here
            //
        }

      protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Calculator()
        {
            if (components) {
                delete components;
            }
        }

      private:
        System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel1;

      private:
        System::Windows::Forms::TextBox ^ textBox1;

      private:
        System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel2;

      private:
        System::Windows::Forms::Button ^ button_plus;

      private:
        System::Windows::Forms::Button ^ button_minus;

      private:
        System::Windows::Forms::Button ^ button_divide;

      private:
        System::Windows::Forms::Button ^ button_multiply;

      private:
        System::Windows::Forms::Button ^ button_0;

      private:
        System::Windows::Forms::Button ^ button_point;

      private:
        System::Windows::Forms::Button ^ button_sign;

      private:
        System::Windows::Forms::Button ^ button_compute;

      private:
        System::Windows::Forms::Button ^ button_1;

      private:
        System::Windows::Forms::Button ^ button_clear;

      private:
        System::Windows::Forms::Button ^ button_6;

      private:
        System::Windows::Forms::Button ^ button_5;

      private:
        System::Windows::Forms::Button ^ button_4;

      private:
        System::Windows::Forms::Button ^ button_paren;

      private:
        System::Windows::Forms::Button ^ button_3;

      private:
        System::Windows::Forms::Button ^ button_2;

      private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
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
            this->tableLayoutPanel1->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->SuspendLayout();
            //
            // tableLayoutPanel1
            //
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50))
            );
            this->tableLayoutPanel1->Controls->Add(this->textBox1, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
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
            this->textBox1->Location = System::Drawing::Point(0, 0);
            this->textBox1->Margin = System::Windows::Forms::Padding(0, 0, 0, 16);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->ReadOnly = true;
            this->textBox1->Size = System::Drawing::Size(488, 126);
            this->textBox1->TabIndex = 0;
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
            this->tableLayoutPanel2->Controls->Add(this->button_point, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_compute, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_sign, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_0, 0, 3);
            this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel2->Location = System::Drawing::Point(0, 142);
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
            this->tableLayoutPanel2->Size = System::Drawing::Size(488, 426);
            this->tableLayoutPanel2->TabIndex = 1;
            this->tableLayoutPanel2->Paint +=
                gcnew System::Windows::Forms::PaintEventHandler(this, &Calculator::tableLayoutPanel2_Paint);
            //
            // button_plus
            //
            this->button_plus->AccessibleName = L"Plus";
            this->button_plus->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_plus->FlatStyle = System::Windows::Forms::FlatStyle::System;
            this->button_plus->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_plus->Location = System::Drawing::Point(3, 3);
            this->button_plus->Name = L"button_plus";
            this->button_plus->Size = System::Drawing::Size(116, 100);
            this->button_plus->TabIndex = 0;
            this->button_plus->Text = L"+";
            this->button_plus->UseVisualStyleBackColor = true;
            this->button_plus->Click += gcnew System::EventHandler(this, &Calculator::button_plus_Click);
            //
            // button_minus
            //
            this->button_minus->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_minus->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_minus->Location = System::Drawing::Point(125, 3);
            this->button_minus->Name = L"button_minus";
            this->button_minus->Size = System::Drawing::Size(116, 100);
            this->button_minus->TabIndex = 1;
            this->button_minus->Text = L"-";
            this->button_minus->UseVisualStyleBackColor = true;
            //
            // button_multiply
            //
            this->button_multiply->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_multiply->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_multiply->Location = System::Drawing::Point(247, 3);
            this->button_multiply->Name = L"button_multiply";
            this->button_multiply->Size = System::Drawing::Size(116, 100);
            this->button_multiply->TabIndex = 2;
            this->button_multiply->Text = L"×";
            this->button_multiply->UseVisualStyleBackColor = true;
            //
            // button_divide
            //
            this->button_divide->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_divide->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_divide->Location = System::Drawing::Point(369, 3);
            this->button_divide->Name = L"button_divide";
            this->button_divide->Size = System::Drawing::Size(116, 100);
            this->button_divide->TabIndex = 3;
            this->button_divide->Text = L"÷";
            this->button_divide->UseVisualStyleBackColor = true;
            //
            // button_1
            //
            this->button_1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_1->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_1->Location = System::Drawing::Point(3, 109);
            this->button_1->Name = L"button_1";
            this->button_1->Size = System::Drawing::Size(116, 100);
            this->button_1->TabIndex = 16;
            this->button_1->Text = L"1";
            this->button_1->UseVisualStyleBackColor = true;
            //
            // button_2
            //
            this->button_2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_2->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_2->Location = System::Drawing::Point(125, 109);
            this->button_2->Name = L"button_2";
            this->button_2->Size = System::Drawing::Size(116, 100);
            this->button_2->TabIndex = 9;
            this->button_2->Text = L"2";
            this->button_2->UseVisualStyleBackColor = true;
            //
            // button_3
            //
            this->button_3->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_3->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_3->Location = System::Drawing::Point(247, 109);
            this->button_3->Name = L"button_3";
            this->button_3->Size = System::Drawing::Size(116, 100);
            this->button_3->TabIndex = 10;
            this->button_3->Text = L"3";
            this->button_3->UseVisualStyleBackColor = true;
            //
            // button_paren
            //
            this->button_paren->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_paren->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_paren->Location = System::Drawing::Point(369, 109);
            this->button_paren->Name = L"button_paren";
            this->button_paren->Size = System::Drawing::Size(116, 100);
            this->button_paren->TabIndex = 11;
            this->button_paren->Text = L"()";
            this->button_paren->UseVisualStyleBackColor = true;
            //
            // button_4
            //
            this->button_4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_4->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_4->Location = System::Drawing::Point(3, 215);
            this->button_4->Name = L"button_4";
            this->button_4->Size = System::Drawing::Size(116, 100);
            this->button_4->TabIndex = 12;
            this->button_4->Text = L"4";
            this->button_4->UseVisualStyleBackColor = true;
            //
            // button_5
            //
            this->button_5->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_5->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_5->Location = System::Drawing::Point(125, 215);
            this->button_5->Name = L"button_5";
            this->button_5->Size = System::Drawing::Size(116, 100);
            this->button_5->TabIndex = 13;
            this->button_5->Text = L"5";
            this->button_5->UseVisualStyleBackColor = true;
            //
            // button_6
            //
            this->button_6->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_6->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_6->Location = System::Drawing::Point(247, 215);
            this->button_6->Name = L"button_6";
            this->button_6->Size = System::Drawing::Size(116, 100);
            this->button_6->TabIndex = 14;
            this->button_6->Text = L"6";
            this->button_6->UseVisualStyleBackColor = true;
            //
            // button_clear
            //
            this->button_clear->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_clear->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_clear->Location = System::Drawing::Point(369, 215);
            this->button_clear->Name = L"button_clear";
            this->button_clear->Size = System::Drawing::Size(116, 100);
            this->button_clear->TabIndex = 15;
            this->button_clear->Text = L"C";
            this->button_clear->UseVisualStyleBackColor = true;
            //
            // button_point
            //
            this->button_point->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_point->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_point->Location = System::Drawing::Point(247, 321);
            this->button_point->Name = L"button_point";
            this->button_point->Size = System::Drawing::Size(116, 102);
            this->button_point->TabIndex = 6;
            this->button_point->Text = L",";
            this->button_point->UseVisualStyleBackColor = true;
            //
            // button_compute
            //
            this->button_compute->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_compute->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_compute->Location = System::Drawing::Point(369, 321);
            this->button_compute->Name = L"button_compute";
            this->button_compute->Size = System::Drawing::Size(116, 102);
            this->button_compute->TabIndex = 4;
            this->button_compute->Text = L"=";
            this->button_compute->UseVisualStyleBackColor = true;
            //
            // button_sign
            //
            this->button_sign->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_sign->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_sign->Location = System::Drawing::Point(3, 321);
            this->button_sign->Name = L"button_sign";
            this->button_sign->Size = System::Drawing::Size(116, 102);
            this->button_sign->TabIndex = 5;
            this->button_sign->Text = L"+/-";
            this->button_sign->UseVisualStyleBackColor = true;
            //
            // button_0
            //
            this->button_0->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_0->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_0->Location = System::Drawing::Point(125, 321);
            this->button_0->Name = L"button_0";
            this->button_0->Size = System::Drawing::Size(116, 102);
            this->button_0->TabIndex = 7;
            this->button_0->Text = L"0";
            this->button_0->UseVisualStyleBackColor = true;
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
            this->tableLayoutPanel2->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion
      private:
        System::Void Form1_Load(System::Object ^ sender, System::EventArgs ^ e)
        {
        }

      private:
        System::Void tableLayoutPanel1_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
        {
        }

      private:
        System::Void tableLayoutPanel2_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
        {
        }

      private:
        int i = 0;
        System::Void button_plus_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            i++;
            this->button_plus->Text = i.ToString();
        }
    };
} // namespace Calculator
