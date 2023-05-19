#pragma once

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
      public:
        enum class Key {
            ZERO = '0',
            ONE = '1',
            TWO = '2',
            THREE = '3',
            FOUR = '4',
            FIVE = '5',
            SIX = '6',
            MINUS = '-',
            PLUS = '+',
            MULTIPLY = '*',
            DIVIDE = '/',
            CLEAR = 'c',
            CLEAR_EVERYTHING = 'e',
            PAREN_OPEN = '(',
            PAREN_CLOSE = ')',
            POINT = ',',
            COMPUTE = '='
        };

        ref class KeyPressedEventArgs : public EventArgs
        {
          public:
            const Key key;

            KeyPressedEventArgs(const Key key) : key(key)
            {
            }
        };

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

      private:
        System::Windows::Forms::Button ^ button_paren_close;

        System::Windows::Forms::Button ^ button_4;
        System::Windows::Forms::Button ^ button_5;
        System::Windows::Forms::Button ^ button_6;

        System::Windows::Forms::Button ^ button_point;


      private:
        System::Windows::Forms::Button ^ button_paren_open;

      private:
      private:
        System::Windows::Forms::Button ^ button_0;

      private:
        System::Windows::Forms::TableLayoutPanel ^ tableLayoutPanel1;

      private:
        System::Windows::Forms::Button ^ button_clear;

      private:
        System::Windows::Forms::Button ^ button_clear_everything;

      private:
        System::Windows::Forms::Button ^ button_compute;

      private:


      private:


        System::ComponentModel::Container ^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->button_compute = (gcnew System::Windows::Forms::Button());
            this->button_plus = (gcnew System::Windows::Forms::Button());
            this->button_minus = (gcnew System::Windows::Forms::Button());
            this->button_multiply = (gcnew System::Windows::Forms::Button());
            this->button_divide = (gcnew System::Windows::Forms::Button());
            this->button_1 = (gcnew System::Windows::Forms::Button());
            this->button_2 = (gcnew System::Windows::Forms::Button());
            this->button_3 = (gcnew System::Windows::Forms::Button());
            this->button_paren_close = (gcnew System::Windows::Forms::Button());
            this->button_4 = (gcnew System::Windows::Forms::Button());
            this->button_5 = (gcnew System::Windows::Forms::Button());
            this->button_6 = (gcnew System::Windows::Forms::Button());
            this->button_paren_open = (gcnew System::Windows::Forms::Button());
            this->button_0 = (gcnew System::Windows::Forms::Button());
            this->button_point = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->button_clear_everything = (gcnew System::Windows::Forms::Button());
            this->button_clear = (gcnew System::Windows::Forms::Button());
            this->tableLayoutPanel2->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
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
            this->tableLayoutPanel2->Controls->Add(this->button_compute, 3, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_plus, 3, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_minus, 3, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_multiply, 2, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_divide, 3, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_1, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_2, 1, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_3, 2, 1);
            this->tableLayoutPanel2->Controls->Add(this->button_paren_close, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_4, 0, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_5, 1, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_6, 2, 2);
            this->tableLayoutPanel2->Controls->Add(this->button_paren_open, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->button_0, 1, 3);
            this->tableLayoutPanel2->Controls->Add(this->button_point, 2, 3);
            this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel1, 0, 3);
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
            this->button_compute->Location = System::Drawing::Point(474, 420);
            this->button_compute->Name = L"button_compute";
            this->button_compute->Size = System::Drawing::Size(153, 136);
            this->button_compute->TabIndex = 16;
            this->button_compute->Text = L"=";
            this->button_compute->UseVisualStyleBackColor = true;
            this->button_compute->Click += gcnew System::EventHandler(this, &Keyboard::button_compute_Click);
            //
            // button_plus
            //
            this->button_plus->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_plus->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_plus->Location = System::Drawing::Point(474, 281);
            this->button_plus->Name = L"button_plus";
            this->button_plus->Size = System::Drawing::Size(153, 133);
            this->button_plus->TabIndex = 0;
            this->button_plus->Text = L"+";
            this->button_plus->UseVisualStyleBackColor = true;
            this->button_plus->Click += gcnew System::EventHandler(this, &Keyboard::button_plus_Click);
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
            this->button_minus->Location = System::Drawing::Point(474, 142);
            this->button_minus->Name = L"button_minus";
            this->button_minus->Size = System::Drawing::Size(153, 133);
            this->button_minus->TabIndex = 1;
            this->button_minus->Text = L"-";
            this->button_minus->UseVisualStyleBackColor = true;
            this->button_minus->Click += gcnew System::EventHandler(this, &Keyboard::button_minus_Click);
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
            this->button_multiply->Location = System::Drawing::Point(317, 3);
            this->button_multiply->Name = L"button_multiply";
            this->button_multiply->Size = System::Drawing::Size(151, 133);
            this->button_multiply->TabIndex = 2;
            this->button_multiply->Text = L"×";
            this->button_multiply->UseVisualStyleBackColor = true;
            this->button_multiply->Click += gcnew System::EventHandler(this, &Keyboard::button_multiply_Click);
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
            this->button_divide->Location = System::Drawing::Point(474, 3);
            this->button_divide->Name = L"button_divide";
            this->button_divide->Size = System::Drawing::Size(153, 133);
            this->button_divide->TabIndex = 3;
            this->button_divide->Text = L"÷";
            this->button_divide->UseVisualStyleBackColor = true;
            this->button_divide->Click += gcnew System::EventHandler(this, &Keyboard::button_divide_Click);
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
            this->button_1->Location = System::Drawing::Point(3, 142);
            this->button_1->Name = L"button_1";
            this->button_1->Size = System::Drawing::Size(151, 133);
            this->button_1->TabIndex = 4;
            this->button_1->Text = L"1";
            this->button_1->UseVisualStyleBackColor = true;
            this->button_1->Click += gcnew System::EventHandler(this, &Keyboard::button_1_Click);
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
            this->button_2->Location = System::Drawing::Point(160, 142);
            this->button_2->Name = L"button_2";
            this->button_2->Size = System::Drawing::Size(151, 133);
            this->button_2->TabIndex = 5;
            this->button_2->Text = L"2";
            this->button_2->UseVisualStyleBackColor = true;
            this->button_2->Click += gcnew System::EventHandler(this, &Keyboard::button_2_Click);
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
            this->button_3->Location = System::Drawing::Point(317, 142);
            this->button_3->Name = L"button_3";
            this->button_3->Size = System::Drawing::Size(151, 133);
            this->button_3->TabIndex = 6;
            this->button_3->Text = L"3";
            this->button_3->UseVisualStyleBackColor = true;
            this->button_3->Click += gcnew System::EventHandler(this, &Keyboard::button_3_Click);
            //
            // button_paren_close
            //
            this->button_paren_close->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_paren_close->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_paren_close->Location = System::Drawing::Point(160, 3);
            this->button_paren_close->Name = L"button_paren_close";
            this->button_paren_close->Size = System::Drawing::Size(151, 133);
            this->button_paren_close->TabIndex = 7;
            this->button_paren_close->Text = L")";
            this->button_paren_close->UseVisualStyleBackColor = true;
            this->button_paren_close->Click += gcnew System::EventHandler(this, &Keyboard::button_paren_close_Click);
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
            this->button_4->Location = System::Drawing::Point(3, 281);
            this->button_4->Name = L"button_4";
            this->button_4->Size = System::Drawing::Size(151, 133);
            this->button_4->TabIndex = 8;
            this->button_4->Text = L"4";
            this->button_4->UseVisualStyleBackColor = true;
            this->button_4->Click += gcnew System::EventHandler(this, &Keyboard::button_4_Click);
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
            this->button_5->Location = System::Drawing::Point(160, 281);
            this->button_5->Name = L"button_5";
            this->button_5->Size = System::Drawing::Size(151, 133);
            this->button_5->TabIndex = 9;
            this->button_5->Text = L"5";
            this->button_5->UseVisualStyleBackColor = true;
            this->button_5->Click += gcnew System::EventHandler(this, &Keyboard::button_5_Click);
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
            this->button_6->Location = System::Drawing::Point(317, 281);
            this->button_6->Name = L"button_6";
            this->button_6->Size = System::Drawing::Size(151, 133);
            this->button_6->TabIndex = 10;
            this->button_6->Text = L"6";
            this->button_6->UseVisualStyleBackColor = true;
            this->button_6->Click += gcnew System::EventHandler(this, &Keyboard::button_6_Click);
            //
            // button_paren_open
            //
            this->button_paren_open->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_paren_open->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_paren_open->Location = System::Drawing::Point(3, 3);
            this->button_paren_open->Name = L"button_paren_open";
            this->button_paren_open->Size = System::Drawing::Size(151, 133);
            this->button_paren_open->TabIndex = 12;
            this->button_paren_open->Text = L"(";
            this->button_paren_open->UseVisualStyleBackColor = true;
            this->button_paren_open->Click += gcnew System::EventHandler(this, &Keyboard::button_paren_open_Click);
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
            this->button_0->Location = System::Drawing::Point(160, 420);
            this->button_0->Name = L"button_0";
            this->button_0->Size = System::Drawing::Size(151, 136);
            this->button_0->TabIndex = 13;
            this->button_0->Text = L"0";
            this->button_0->UseVisualStyleBackColor = true;
            this->button_0->Click += gcnew System::EventHandler(this, &Keyboard::button_0_Click);
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
            this->button_point->Location = System::Drawing::Point(317, 420);
            this->button_point->Name = L"button_point";
            this->button_point->Size = System::Drawing::Size(151, 136);
            this->button_point->TabIndex = 14;
            this->button_point->Text = L",";
            this->button_point->UseVisualStyleBackColor = true;
            this->button_point->Click += gcnew System::EventHandler(this, &Keyboard::button_point_Click);
            //
            // tableLayoutPanel1
            //
            this->tableLayoutPanel1->ColumnCount = 1;
            this->tableLayoutPanel1->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50))
            );
            this->tableLayoutPanel1->ColumnStyles->Add(
                (gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50))
            );
            this->tableLayoutPanel1->Controls->Add(this->button_clear_everything, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->button_clear, 0, 0);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(3, 420);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 2;
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50))
            );
            this->tableLayoutPanel1->RowStyles->Add(
                (gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50))
            );
            this->tableLayoutPanel1->Size = System::Drawing::Size(151, 136);
            this->tableLayoutPanel1->TabIndex = 15;
            //
            // button_clear_everything
            //
            this->button_clear_everything->Dock = System::Windows::Forms::DockStyle::Fill;
            this->button_clear_everything->Font = (gcnew System::Drawing::Font(
                L"Courier New",
                32,
                System::Drawing::FontStyle::Regular,
                System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)
            ));
            this->button_clear_everything->Location = System::Drawing::Point(3, 71);
            this->button_clear_everything->Name = L"button_clear_everything";
            this->button_clear_everything->Size = System::Drawing::Size(145, 62);
            this->button_clear_everything->TabIndex = 13;
            this->button_clear_everything->Text = L"CE";
            this->button_clear_everything->UseVisualStyleBackColor = true;
            this->button_clear_everything->Click += gcnew System::EventHandler(this, &Keyboard::button1_Click);
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
            this->button_clear->Location = System::Drawing::Point(3, 3);
            this->button_clear->Name = L"button_clear";
            this->button_clear->Size = System::Drawing::Size(145, 62);
            this->button_clear->TabIndex = 12;
            this->button_clear->Text = L"C";
            this->button_clear->UseVisualStyleBackColor = true;
            this->button_clear->Click += gcnew System::EventHandler(this, &Keyboard::button_clear_Click_1);
            //
            // Keyboard
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->Controls->Add(this->tableLayoutPanel2);
            this->Name = L"Keyboard";
            this->Size = System::Drawing::Size(630, 559);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

      public:
        System::EventHandler<KeyPressedEventArgs ^> ^ KeyPressed;

      private:
        System::Void handleKeyPress(Key key)
        {
            if (KeyPressed) {
                KeyPressed(this, gcnew KeyPressedEventArgs(key));
            }
        }

        System::Void button_plus_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::PLUS);
        }

      private:
        System::Void button_minus_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::MINUS);
        }

      private:
        System::Void button_multiply_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::MULTIPLY);
        }

      private:
        System::Void button_divide_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::DIVIDE);
        }

      private:
        System::Void button_1_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::ONE);
        }

      private:
        System::Void button_2_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::TWO);
        }

      private:
        System::Void button_3_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::THREE);
        }

      private:
        System::Void button_paren_close_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::PAREN_CLOSE);
        }

      private:
        System::Void button_4_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::FOUR);
        }

      private:
        System::Void button_5_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::FIVE);
        }

      private:
        System::Void button_6_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::SIX);
        }

      private:
        System::Void button_clear_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::CLEAR);
        }

      private:
        System::Void button_0_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::ZERO);
        }

      private:
        System::Void button_point_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::POINT);
        }

      private:
        System::Void button_paren_open_Click(System::Object ^, System::EventArgs ^)
        {
            handleKeyPress(Key::PAREN_OPEN);
        }

      private:
        System::Void button_clear_Click_1(System::Object ^ sender, System::EventArgs ^ e)
        {
            handleKeyPress(Key::CLEAR);
        }

      private:
        System::Void button1_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            handleKeyPress(Key::CLEAR_EVERYTHING);
        }

      private:
        System::Void button_compute_Click(System::Object ^ sender, System::EventArgs ^ e)
        {
            handleKeyPress(Key::COMPUTE);
        }
    };
} // namespace Calculator
