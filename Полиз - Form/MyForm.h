#pragma once

#include <string>
#include <msclr\marshal_cppstd.h>
#include "Arifmetic.h"

namespace ПолизForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Table tab;
	string str;
	arifmetic a;

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(17, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(784, 26);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 74);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 26);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Конвертировать в ПОЛИЗ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(17, 123);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(784, 26);
			this->textBox2->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::InactiveCaption;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->EditMode = System::Windows::Forms::DataGridViewEditMode::EditOnEnter;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Desktop;
			this->dataGridView1->Location = System::Drawing::Point(561, 169);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 4;
			this->dataGridView1->Size = System::Drawing::Size(240, 226);
			this->dataGridView1->TabIndex = 7;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox3->Location = System::Drawing::Point(367, 212);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(163, 26);
			this->textBox3->TabIndex = 5;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(367, 169);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(163, 25);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Получить ответ";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(818, 416);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		bool is_num(String^ s) 
		{
			int i = 0;
			int l;

			if (i == 0 && s[i] == '-') i = 1;
			if (s->Length > i) {
				l = 0;
				for (int i = 0; i < s->Length; i++) 
				{
					if (s[i] == ',') 
					{
						if (l == 1) return false;
						l = 1;
					}
					else if (!Char::IsNumber(s[i])) return false;
				}
			}
			return true;
		}
		void cleardataGrid() 
		{
			dataGridView1->RowCount = 0;
			dataGridView1->ColumnCount = 0;
		}
		void heightdataGrid(int k) 
		{
			if (k > 0) dataGridView1->RowTemplate->Height = 300 / k;
		}
		void addTable(int k) 
		{
			dataGridView1->RowCount = k;
			dataGridView1->ColumnCount = 2;
		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		str = msclr::interop::marshal_as<std::string>(textBox1->Text);
		a = arifmetic(str);
		int k = a.GetTableevarials()->getCount();
		cleardataGrid();
		heightdataGrid(k);
		addTable(k);
		for (int i = 0; i < k; i++) {
			string m = a.GetTableevarials()->operator[](i).GetName();
			dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(m.c_str());
			if (m > "0" && m < "9") {
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToDouble(dataGridView1->Rows[i]->Cells[0]->Value);
				dataGridView1->Rows[i]->Cells[1]->ReadOnly = true;
			}
		}
		string pol = a.GetA().GetStringPoliz();
		textBox2->Text = gcnew String(pol.c_str());
	}

private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	int i = dataGridView1->CurrentRow->Index;
	int j = dataGridView1->CurrentCell->ColumnIndex;
	str = msclr::interop::marshal_as<std::string>(textBox1->Text);
	a = arifmetic(str);
	tab = a.GetTableevarials()->operator[](i).GetValue();
	if (j == 0) { dataGridView1->Rows[i]->Cells[j]->Value = gcnew String(tab[i].GetName().c_str()); }
	string m = tab[i].GetName();
	if (m[0] > '0' && m[0] < '9') { dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(tab[i].GetName().c_str()); }
	if (j == 1) {
		float k = 0;
		if (is_num(Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value))) {
			k = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);
		}
		a.SetVar(i, k);
	}

}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	for (int i = 0; i < dataGridView1->RowCount; i++) {
		float k = 0;
		if (is_num(Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value))) {
			k = Convert::ToDouble(dataGridView1->Rows[i]->Cells[1]->Value);
		}
		a.SetVar(i, k);
	}
	float result = a.calculate();
	textBox3->Text = Convert::ToString(result);
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
