#pragma once
#include "EntradaProduto.h"
#include "CadastroProduto.h"
#include "MostraEstoque.h"
#include "LeProduto.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <vcclr.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


namespace PA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Sumário para MostraEstoque
	/// </summary>
	public ref class MostraEstoque : public System::Windows::Forms::Form
	{
	public:
		MostraEstoque(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~MostraEstoque()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Codigo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Nome;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Atual;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ EstoqueMinimo;





	protected:

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte ao Designer - não modifique 
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Codigo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Nome = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Atual = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EstoqueMinimo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Estoque";
			this->label1->Click += gcnew System::EventHandler(this, &MostraEstoque::label1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 228);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Voltar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MostraEstoque::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Codigo,
					this->Nome, this->Atual, this->EstoqueMinimo
			});
			this->dataGridView1->Location = System::Drawing::Point(3, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(279, 173);
			this->dataGridView1->TabIndex = 12;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MostraEstoque::dataGridView1_CellContentClick_1);
			// 
			// Codigo
			// 
			this->Codigo->HeaderText = L"Codigo";
			this->Codigo->Name = L"Codigo";
			this->Codigo->ReadOnly = true;
			this->Codigo->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Codigo->Width = 40;
			// 
			// Nome
			// 
			this->Nome->HeaderText = L"Nome";
			this->Nome->Name = L"Nome";
			this->Nome->ReadOnly = true;
			// 
			// Atual
			// 
			this->Atual->HeaderText = L"Estoque";
			this->Atual->Name = L"Atual";
			this->Atual->ReadOnly = true;
			this->Atual->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Atual->Width = 50;
			// 
			// EstoqueMinimo
			// 
			this->EstoqueMinimo->HeaderText = L"Minimo";
			this->EstoqueMinimo->Name = L"EstoqueMinimo";
			this->EstoqueMinimo->ReadOnly = true;
			this->EstoqueMinimo->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->EstoqueMinimo->Width = 50;
			// 
			// MostraEstoque
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Name = L"MostraEstoque";
			this->Text = L"MostraEstoque";
			this->Load += gcnew System::EventHandler(this, &MostraEstoque::MostraEstoque_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MostraEstoque_Load(System::Object^ sender, System::EventArgs^ e) {
		PreencherDataGridView(dataGridView1);
	}

	void PreencherDataGridView(DataGridView^ dataGridView) {
	   // Lista para armazenar as linhas do arquivo CSV
	   List<List<String^>^>^ rows = gcnew List<List<String^>^>();

	   // Leitura do arquivo CSV
	   std::ifstream file("stockManager.csv");
	   std::string line;

	   while (std::getline(file, line))
	   {
		   std::stringstream ss(line);
		   std::string field;
		   List<String^>^ row = gcnew List<String^>();

		   while (std::getline(ss, field, ','))
		   {
			   row->Add(gcnew String(field.c_str()));
		   }

		   rows->Add(row);
	   }

	   file.close();

	   // Adiciona os campos a dataGridView
	   for each (auto row in rows)
	   {
		   array<String^>^ rowData = row->ToArray();
		   dataGridView->Rows->Add(rowData);
	   }
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Close();
	}
	private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
};
}
