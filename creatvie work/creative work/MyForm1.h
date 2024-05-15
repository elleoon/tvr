#pragma once
#include <stdlib.h>
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "MyForm5.h"
#include "MyForm6.h"
#include "MyForm7.h"
#include "MyForm8.h"
#include "MyForm9.h"
#include "MyForm10.h"
#include "MyForm11.h"
#include "MyForm12.h"
#include "MyForm13.h"
#include "MyForm14.h"
#include "MyForm15.h"
#include "MyForm16.h"
#include "MyForm17.h"
#include "MyForm18.h"





using namespace std;
namespace Творческаяработаа {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::Button^ nazad;
	private: System::Windows::Forms::Button^ dalee;
	private: System::Windows::Forms::Button^ konec;



		   String^ Min;
		   static int Second = 0;
		   static int Minute = 15;
		   String^ sec;
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			next(this->n);
		}
	private: bool previousAnswerYes = false;
	private: int n = 0;
	private: System::Windows::Forms::Timer^ timer1;
	private: int count = 0;
	private: int j = 0;
	private: int k = 0;
	private: int i = 0;
	private: bool flag1 = false;
	private: bool flag2 = false;
	private: bool flag3 = false;
	private: bool flag4 = false;
	private: int flagcount = 0;


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ text_numberquestions;
	private: System::Windows::Forms::Label^ text_questions;
	protected:

	private: System::Windows::Forms::CheckBox^ da_Box;
	private: System::Windows::Forms::CheckBox^ net_Box;


	private: System::Windows::Forms::Label^ time_label;

	private: System::ComponentModel::IContainer^ components;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->text_numberquestions = (gcnew System::Windows::Forms::Label());
			this->text_questions = (gcnew System::Windows::Forms::Label());
			this->da_Box = (gcnew System::Windows::Forms::CheckBox());
			this->net_Box = (gcnew System::Windows::Forms::CheckBox());
			this->time_label = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->nazad = (gcnew System::Windows::Forms::Button());
			this->dalee = (gcnew System::Windows::Forms::Button());
			this->konec = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// text_numberquestions
			// 
			this->text_numberquestions->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->text_numberquestions->BackColor = System::Drawing::Color::Transparent;
			this->text_numberquestions->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->text_numberquestions->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->text_numberquestions->Location = System::Drawing::Point(12, 7);
			this->text_numberquestions->Name = L"text_numberquestions";
			this->text_numberquestions->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->text_numberquestions->Size = System::Drawing::Size(126, 69);
			this->text_numberquestions->TabIndex = 0;
			this->text_numberquestions->Text = L"1/40";
			this->text_numberquestions->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// text_questions
			// 
			this->text_questions->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->text_questions->BackColor = System::Drawing::Color::Transparent;
			this->text_questions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->text_questions->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->text_questions->Location = System::Drawing::Point(78, 141);
			this->text_questions->Margin = System::Windows::Forms::Padding(3);
			this->text_questions->Name = L"text_questions";
			this->text_questions->Size = System::Drawing::Size(726, 237);
			this->text_questions->TabIndex = 1;
			this->text_questions->Text = L"questions";
			this->text_questions->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->text_questions->Click += gcnew System::EventHandler(this, &MyForm1::text_questions_Click);
			// 
			// da_Box
			// 
			this->da_Box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->da_Box->AutoSize = true;
			this->da_Box->BackColor = System::Drawing::Color::Transparent;
			this->da_Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->da_Box->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->da_Box->Location = System::Drawing::Point(180, 400);
			this->da_Box->Name = L"da_Box";
			this->da_Box->Size = System::Drawing::Size(116, 65);
			this->da_Box->TabIndex = 2;
			this->da_Box->Text = L"Да";
			this->da_Box->UseVisualStyleBackColor = false;
			this->da_Box->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::da_Box_CheckedChanged);
			// 
			// net_Box
			// 
			this->net_Box->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->net_Box->AutoSize = true;
			this->net_Box->BackColor = System::Drawing::Color::Transparent;
			this->net_Box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 39.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->net_Box->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->net_Box->Location = System::Drawing::Point(571, 400);
			this->net_Box->Name = L"net_Box";
			this->net_Box->Size = System::Drawing::Size(137, 65);
			this->net_Box->TabIndex = 3;
			this->net_Box->Text = L"Нет";
			this->net_Box->UseVisualStyleBackColor = false;
			this->net_Box->CheckedChanged += gcnew System::EventHandler(this, &MyForm1::net_Box_CheckedChanged);
			// 
			// time_label
			// 
			this->time_label->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->time_label->AutoSize = true;
			this->time_label->BackColor = System::Drawing::Color::Transparent;
			this->time_label->Font = (gcnew System::Drawing::Font(L"Berlin Sans FB", 24.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->time_label->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->time_label->Location = System::Drawing::Point(747, 23);
			this->time_label->Name = L"time_label";
			this->time_label->Size = System::Drawing::Size(104, 37);
			this->time_label->TabIndex = 6;
			this->time_label->Text = L"00:00";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			// 
			// nazad
			// 
			this->nazad->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->nazad->BackColor = System::Drawing::Color::Transparent;
			this->nazad->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->nazad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->nazad->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->nazad->Location = System::Drawing::Point(12, 637);
			this->nazad->Name = L"nazad";
			this->nazad->Size = System::Drawing::Size(192, 57);
			this->nazad->TabIndex = 8;
			this->nazad->Text = L"Назад";
			this->nazad->UseVisualStyleBackColor = false;
			this->nazad->Click += gcnew System::EventHandler(this, &MyForm1::nazad_Click);
			// 
			// dalee
			// 
			this->dalee->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dalee->BackColor = System::Drawing::Color::Transparent;
			this->dalee->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->dalee->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dalee->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->dalee->Location = System::Drawing::Point(683, 637);
			this->dalee->Name = L"dalee";
			this->dalee->Size = System::Drawing::Size(192, 57);
			this->dalee->TabIndex = 9;
			this->dalee->Text = L"Далее";
			this->dalee->UseVisualStyleBackColor = false;
			this->dalee->Click += gcnew System::EventHandler(this, &MyForm1::dalee_Click);
			// 
			// konec
			// 
			this->konec->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->konec->BackColor = System::Drawing::Color::Transparent;
			this->konec->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->konec->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->konec->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->konec->Location = System::Drawing::Point(299, 637);
			this->konec->Name = L"konec";
			this->konec->Size = System::Drawing::Size(280, 57);
			this->konec->TabIndex = 10;
			this->konec->Text = L"Завершить тестирование";
			this->konec->UseVisualStyleBackColor = false;
			this->konec->Click += gcnew System::EventHandler(this, &MyForm1::konec_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(876, 706);
			this->Controls->Add(this->konec);
			this->Controls->Add(this->dalee);
			this->Controls->Add(this->nazad);
			this->Controls->Add(this->time_label);
			this->Controls->Add(this->net_Box);
			this->Controls->Add(this->da_Box);
			this->Controls->Add(this->text_questions);
			this->Controls->Add(this->text_numberquestions);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void next(int n) {

		this->text_numberquestions->Text = System::Convert::ToString(n + 1) + "/40";
		if (n < 10) {
			array<String^>^ questions;
			questions = gcnew array<String^>{
				"Спокойны и хладнокровны",
				"Последовательны и обстоятельны в делах",
				"Осторожны и рассудительны",
				"Умеете ждать",
				"Молчаливы и не любите зря болтать",
				"Сдержанны и терпеливы",
				"Доводите начатое дело до конца",
				"Не растрачиваете попусту сил",
				"Легко сдерживаете порывы",
				"Маловосприимчивы к одобрению и порицанию",
			};
			this->text_questions->Text = questions[n];
		}
		if (n > 9 && n < 20) {
			array<String^>^ questions1;
			questions1 = gcnew array<String^>{
				"Стеснительны и застенчивы",
				"Теряетесь в новой обстановке",
				"Затрудняетесь установить контакт с новыми людьми",
				"Не верите в свои силы",
				"Легко переносите одиночество",
				"Чувствуете подавленность и растерянность при неудачах",
				"Склонны уходить в себя",
				"Быстро утомляетесь",
				"Обладаете тихой речью, иногда снижающейся до шепота",
				"Впечатлительны до слезливости",
			};
			this->text_questions->Text = questions1[n-10];
		}
		if (n > 19 && n < 30) {
			array<String^>^ questions2;
			questions2 = gcnew array<String^>{
				"Неусидчивы, суетливы",
				"Невыдержанны, вспыльчивы",
				"Нетерпеливы",
				"Резки и прямолинейны в отношениях с людьми",
				"Решительны и инициативны",
				"Упрямы",
				"Находчивы в споре",
				"Работаете рывками",
				"Склонны к риску",
				"Незлопамятны и необидчивы",
			};
			this->text_questions->Text = questions2[n - 20];
		}
		if (n > 29 && n < 40) {
			array<String^>^ questions3;
			questions3 = gcnew array<String^>{
				"Веселы и жизнерадостны",
				"Энергичны и деловиты",
				"Часто не доводите начатое дело до конца",
				"Склонны переоценивать себя",
				"Способны быстро схватывать новое",
				"Неустойчивы в интересах и склонностях",
				"Легко переживаете неудачи и неприятности",
				"Легко приспосабливаетесь к различным обстоятельствам",
				"С увлечением беретесь за любое новое дело",
				"Выносливы и работоспособны",
			};
			this->text_questions->Text = questions3[n - 30];
		}
	}
	private: System::Void da_Box_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (da_Box->Checked) {
			net_Box->Checked = false;
		}
	}
private: System::Void net_Box_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (net_Box->Checked) {
		da_Box->Checked = false;
	}
}

private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (Second == 0) {
		Minute = Minute - 1;
		Second = 60;
	}
	Second--;
	if (Minute == 0 && Second == 0) {
		Second = 0;
		Minute = 15;
		this->n = 0;
		this->count = 0;
		this->j = 0;
		this->k = 0;
		this->i = 0;
		next(this->n);
	}
	sec = Convert::ToString(Second);
	Min = Convert::ToString(Minute);
	if (Second < 10) {
		time_label->Text = Min + ":0" + sec;
	}
	else {
		time_label->Text = Min + ":" + sec;
	}

}

	private: System::Void dalee_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->n < 39) {
			previousAnswerYes = da_Box->Checked;
			if (da_Box->Checked == true) {
				if (n < 10) {
					count++;
				}
				if (n > 9 && n < 20) {
					j++;
				}
				if (n > 19 && n < 30) {
					k++;
				}
				if (n > 29 && n < 49) {
					i++;
				}
			}
			else {
				count = count;
				j = j;
				k = k;
				i = i;
			}
			next(this->n + 1);
			net_Box->Checked = false;
			da_Box->Checked = false;
			this->n = n + 1;
		}
		else {
			if (this->n == 39) {
				previousAnswerYes = da_Box->Checked;
				if (da_Box->Checked == true) {
					i++;
					dalee->Enabled = false;
					if (count >= 7) {
						flag1 = true;
					}
					if (j >= 7) {
						flag2 = true;
					}
					if (k >= 7) {
						flag3 = true;
					}
					if (i >= 7) {
						flag4 = true;
					}
				}
				else {
					count = count;
					j = j;
					k = k;
					i = i;
					dalee->Enabled = false;
					if (count >= 7) {
						flag1 = true;
					}
					if (j >= 7) {
						flag2 = true;
					}
					if (k >= 7) {
						flag3 = true;
					}
					if (i >= 7) {
						flag4 = true;
					}
				}
			}
		}
		if (flag1 ==true) {
			flagcount++;
		}
		if (flag2 == true) {
			flagcount++;
		}
		if (flag3 == true) {
			flagcount++;
		}
		if (flag4 == true) {
			flagcount++;
		}
}
private: System::Void nazad_Click(System::Object^ sender, System::EventArgs^ e) {
	if (n != 0 && n < 40) {
		nazad->Enabled = true;
		dalee->Enabled = true;
		if (previousAnswerYes) {
			count--;
		}
		net_Box->Checked = false;
		da_Box->Checked = false;
		next(this->n - 1);
		this->n = n - 1;
	}
}
	private: System::Void konec_Click(System::Object^ sender, System::EventArgs^ e) {
		if (flagcount == 0 || flagcount >= 3) {
			MyForm18^ f18 = gcnew MyForm18();
			f18->Show();
			MyForm1::Hide();
		}
		else {
			if (flag1 == true) {
				MyForm2^ f3 = gcnew MyForm2();
				f3->Show();
				MyForm1::Hide();
				if (flag3 == true && flag1 == true) {
					f3->Hide();
				}
				if (flag1 == true && flag2 == true) {
					f3->Hide();
				}
				if (flag1 == true && flag4 == true) {
					f3->Hide();
				}
			}
			if (flag2 == true) {
				MyForm3^ f4 = gcnew MyForm3();
				f4->Show();
				MyForm1::Hide();
				if (flag2 == true && flag3 == true) {
					f4->Hide();
				}
				if (flag2 == true && flag1 == true) {
					f4->Hide();
				}
				if (flag2 == true && flag4 == true) {
					f4->Hide();
				}
			}
			if (flag3 == true) {
				MyForm4^ f5 = gcnew MyForm4();
				f5->Show();
				MyForm1::Hide();
				if (flag3 == true && flag2 == true) {
					f5->Hide();
				}
				if (flag3 == true && flag1 == true) {
					f5->Hide();
				}
				if (flag3 == true && flag4 == true) {
					f5->Hide();
				}
			}
			if (flag4 == true) {

				MyForm5^ f6 = gcnew MyForm5();
				f6->Show();
				MyForm1::Hide();
				if (flag4 == flag1) {
					f6->Hide();
				}
				if (flag4 == flag2) {
					f6->Hide();
				}
				if (flag4 == flag3) {
					f6->Hide();
				}
			}
			if (flag3 == true && flag2 == true) {
				MyForm6^ f7 = gcnew MyForm6();
				f7->Show();
				MyForm1::Hide();
				if (j > k) {
					f7->Hide();

				}
			}
			if (flag3 == true && flag2 == true && j > k) {
				MyForm7^ f8 = gcnew MyForm7();
				f8->Show();
				MyForm1::Hide();
			}
			if (flag3 == true && flag1 == true) {
				MyForm8^ f9 = gcnew MyForm8();
				f9->Show();
				MyForm1::Hide();
				if (count > k) {
					f9->Hide();
				}
			}
			if (flag3 == true && flag1 == true && count > k) {
				MyForm9^ f10 = gcnew MyForm9();
				f10->Show();
				MyForm1::Hide();

			}
			if (flag3 == true && flag4 == true) {
				MyForm10^ f11 = gcnew MyForm10();
				f11->Show();
				MyForm1::Hide();
				if (i > k) {
					f11->Hide();
				}

			}
			if (flag3 == true && flag4 == true && i > k) {
				MyForm11^ f12 = gcnew MyForm11();
				f12->Show();
				MyForm1::Hide();

			}
			if (flag2 == true && flag1 == true) {
				MyForm12^ f13 = gcnew MyForm12();
				f13->Show();
				MyForm1::Hide();
				if (count > j) {
					f13->Hide();
				}

			}
			if (flag2 == true && flag1 == true && count > j) {
				MyForm13^ f14 = gcnew MyForm13();
				f14->Show();
				MyForm1::Hide();

			}
			if (flag2 == true && flag4 == true) {
				MyForm14^ f15 = gcnew MyForm14();
				f15->Show();
				MyForm1::Hide();
				if (i > j) {
					f15->Hide();
				}

			}
			if (flag2 == true && flag4 == true && i > j) {
				MyForm15^ f16 = gcnew MyForm15();
				f16->Show();
				MyForm1::Hide();


			}
			if (flag1 == true && flag4 == true) {
				MyForm16^ f17 = gcnew MyForm16();
				f17->Show();
				MyForm1::Hide();
				if (i > count) {
					f17->Hide();
				}

			}
			if (flag1 == true && flag4 == true && i > count) {
				MyForm17^ f18 = gcnew MyForm17();
				f18->Show();
				MyForm1::Hide();

			}

		}
	}
private: System::Void text_questions_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
