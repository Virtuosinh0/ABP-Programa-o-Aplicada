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
	/// Sumário para FinalizaCompras
	/// </summary>
	public ref class FinalizaCompras : public System::Windows::Forms::Form
	{
	public:
		FinalizaCompras(void)
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
		~FinalizaCompras()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:




	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Produto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Atual;
	private: System::Windows::Forms::Button^ button1;





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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Produto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Atual = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->Produto,
					this->Atual
			});
			this->dataGridView1->Location = System::Drawing::Point(3, 38);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(279, 173);
			this->dataGridView1->TabIndex = 15;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FinalizaCompras::dataGridView1_CellContentClick);
			// 
			// Produto
			// 
			this->Produto->HeaderText = L"Produto";
			this->Produto->Name = L"Produto";
			this->Produto->ReadOnly = true;
			this->Produto->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Produto->Width = 130;
			// 
			// Atual
			// 
			this->Atual->HeaderText = L"Estoque";
			this->Atual->Name = L"Atual";
			this->Atual->ReadOnly = true;
			this->Atual->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(16, 226);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FinalizaCompras::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Lista de Compras";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(176, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Finalizar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FinalizaCompras::button1_Click);
			// 
			// FinalizaCompras
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Name = L"FinalizaCompras";
			this->Text = L"FinalizaCompras";
			this->Load += gcnew System::EventHandler(this, &FinalizaCompras::FinalizaCompras_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void procuraIDs() {
		std::vector<std::vector<std::string>> data;
		std::ifstream file("shopManager.csv");
		std::string line;

		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string token;

			std::vector<std::string> row;
			while (std::getline(ss, token, ',')) {
				row.push_back(token);
			}

			data.push_back(row);
		}

		for (auto& row : data) {
			int cd = std::stoi(row[0]);
			int qt = std::stoi(row[1]);
			baixaEstoque(cd, qt); 
			System::String^ codigo = msclr::interop::marshal_as<System::String^>(row[0]);
			MessageBox::Show("Comprado o produto " + codigo);
		}
	}
	void baixaEstoque(int code, int qtd) {
		std::vector<std::vector<std::string>> data;
		std::ifstream file("stockManager.csv");
		std::string line;

		while (std::getline(file, line)) {
			std::stringstream ss(line);
			std::string token;

			std::vector<std::string> row;
			while (std::getline(ss, token, ',')) {
				row.push_back(token);
			}

			data.push_back(row);
		}

		for (auto& row : data) {
			if (std::stoi(row[0]) == code) {
				int qt = std::stoi(row[2]);
				row[2] = std::to_string(qt - qtd);
			}
		}

		std::ofstream outfile("stockManager.csv");
		for (auto& row : data) {
			for (size_t i = 0; i < row.size(); ++i) {
				outfile << row[i];
				if (i != row.size() - 1) {
					outfile << ",";
				}
			}
			outfile << "\n";
		}
		MessageBox::Show("Produto lido com sucesso.");
	}
	void deletaCarrinhoCompras() {
		if (File::Exists("shopManager.csv")) {
			File::Delete("shopManager.csv");
		}
	}
	private: System::Void FinalizaCompras_Load(System::Object^ sender, System::EventArgs^ e) {
		PreencherDataGridView(dataGridView1);
	}
	void PreencherDataGridView(DataGridView ^ dataGridView) {
			// Lista para armazenar as linhas do arquivo CSV
			List<List<String^>^>^ rows = gcnew List<List<String^>^>();

			// Leitura do arquivo CSV
			std::ifstream file("shopManager.csv");
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
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		deletaCarrinhoCompras();
		MessageBox::Show("Compra cancelada!");
		this->Hide();
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		procuraIDs();
		MessageBox::Show("Compra finalizada!");
		deletaCarrinhoCompras();
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
};
}
