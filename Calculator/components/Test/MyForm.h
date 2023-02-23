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
    /// Summary for MyForm
    /// </summary>
  public
    ref class MyForm : public System::Windows::Forms::Form
    {
      public:
        MyForm(void)
        {
            InitializeComponent();
        }

      protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~MyForm()
        {
            if (components) {
                delete components;
            }
        }

      private:
        System::Windows::Forms::TextBox ^ textBox1;

      protected:
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
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            //
            // textBox1
            //
            this->textBox1->Font = (gcnew System::Drawing::Font(
                L"Microsoft Sans Serif",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->textBox1->Location = System::Drawing::Point(205, 165);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(100, 56);
            this->textBox1->TabIndex = 0;
            this->textBox1->Text = L"asdasd";
            //
            // MyForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(728, 674);
            this->Controls->Add(this->textBox1);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
    };
} // namespace Calculator
