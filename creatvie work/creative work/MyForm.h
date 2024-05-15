#pragma once
#include "MyForm1.h"
namespace “ворческа€работаа {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ text_label;
	private: System::Windows::Forms::Label^ text_instruction;
	private: System::Windows::Forms::Button^ start;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->text_label = (gcnew System::Windows::Forms::Label());
			this->text_instruction = (gcnew System::Windows::Forms::Label());
			this->start = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// text_label
			// 
			this->text_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->text_label->AutoSize = true;
			this->text_label->BackColor = System::Drawing::Color::Transparent;
			this->text_label->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 39.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_label->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->text_label->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->text_label->Location = System::Drawing::Point(163, 46);
			this->text_label->Name = L"text_label";
			this->text_label->Size = System::Drawing::Size(579, 58);
			this->text_label->TabIndex = 0;
			this->text_label->Text = L"‘ормула темперамента";
			// 
			// text_instruction
			// 
			this->text_instruction->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->text_instruction->AutoSize = true;
			this->text_instruction->BackColor = System::Drawing::Color::Transparent;
			this->text_instruction->Cursor = System::Windows::Forms::Cursors::Default;
			this->text_instruction->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_instruction->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->text_instruction->Location = System::Drawing::Point(49, 218);
			this->text_instruction->Name = L"text_instruction";
			this->text_instruction->Size = System::Drawing::Size(776, 208);
			this->text_instruction->TabIndex = 1;
			this->text_instruction->Text = resources->GetString(L"text_instruction.Text");
			// 
			// start
			// 
			this->start->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->start->AutoSize = true;
			this->start->BackColor = System::Drawing::Color::Transparent;
			this->start->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->start->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->start->Location = System::Drawing::Point(251, 570);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(433, 58);
			this->start->TabIndex = 2;
			this->start->Text = L"Ќачать тестирование";
			this->start->UseVisualStyleBackColor = false;
			this->start->Click += gcnew System::EventHandler(this, &MyForm::start_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PeachPuff;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(876, 706);
			this->Controls->Add(this->start);
			this->Controls->Add(this->text_instruction);
			this->Controls->Add(this->text_label);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void start_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ f2 = gcnew MyForm1();
		f2->Show();
		MyForm::Hide();
	}
};
}
