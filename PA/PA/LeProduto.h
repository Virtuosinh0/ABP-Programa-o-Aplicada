#pragma once
#include "FinalizaCompras.h"
#include "CadastroProduto.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <vcclr.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace PA {

	struct shopManager {
		int code;
		int quantity;
	};

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Sumário para LeProduto
	/// </summary>
	public ref class LeProduto : public System::Windows::Forms::Form
	{
	public:
		LeProduto(void)
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
		~LeProduto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(18, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Digite o código do produto";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(154, 61);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(47, 114);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Remove";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &LeProduto::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(167, 114);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Adiciona";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &LeProduto::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(47, 187);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Cancela";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &LeProduto::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(167, 187);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Finaliza";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &LeProduto::button4_Click);
			// 
			// LeProduto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"LeProduto";
			this->Text = L"LeProduto";
			this->Load += gcnew System::EventHandler(this, &LeProduto::LeProduto_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	bool confirma(String^ ID) {
			// Verifica se a string está vazia ou é nula
			if (String::IsNullOrEmpty(ID)) {
				MessageBox::Show("Por favor, preencha todos os campos.");
				return false;
			}

			// Converte as strings para inteiros
			int productId;
			if (!Int32::TryParse(ID, productId)) {
				MessageBox::Show("ID do produto inválido.");
				return false;
			}
			return true; // Todos os campos estão preenchidos corretamente e o produto pode ser adicionado
		}
	bool codigoExistente(int codigo) {
		std::ifstream arquivo("shopManager.csv");
		if (arquivo.is_open()) {
			std::string linha;
			while (std::getline(arquivo, linha)) {
				std::istringstream iss(linha);
				std::string field;
				std::getline(iss, field, ','); // Assuming the code is the first field in the CSV

				// Convertendo a string do campo para um inteiro
				int code = std::stoi(field);

				if (code == codigo) {
					arquivo.close();
					return false; // Código já existe
				}
			}
			arquivo.close();
		}
		return true;
	}
	void inserirNoArquivoCSV(const shopManager& item, int vl) {
		if (!codigoExistente(item.code)) {
			atualizaEstoque(item.code, vl);
			return;
		}

		std::ofstream arquivo("shopManager.csv", std::ios::app);

		if (arquivo.is_open()) {
			arquivo << item.code << "," << item.quantity << "\n";
			arquivo.close();
			String^ rascunho = gcnew String(std::to_string(item.code).c_str());
			MessageBox::Show("Comprado o produto " + rascunho);
			MessageBox::Show("Produto inserido no arquivo CSV com sucesso!");
			textBox1->Text = String::Empty;
		}
		else {
			MessageBox::Show("Não foi possível abrir o arquivo para inserção do produto.");
		}
	}
	void atualizaEstoque(int ID, int V) {
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
			if (std::stoi(row[0]) == ID) {
				int qt = std::stoi(row[1]);
				if (qt > 0 && V > 0) {
					row[1] = std::to_string(V + qt);
					MessageBox::Show("Produto lido com sucesso.");
					textBox1->Text = String::Empty;
					break;
				}
				else {
					MessageBox::Show("O produto não está no carrinho de comprar.");
				}
			}
		}

		std::ofstream outfile("shopManager.csv");
		for (auto& row : data) {
			for (size_t i = 0; i < row.size(); ++i) {
				outfile << row[i];
				if (i != row.size() - 1) {
					outfile << ",";
				}
			}
			outfile << "\n";
		}
	}
	void deletaCarrinhoCompras() {
		if (File::Exists("shopManager.csv")) {
			File::Delete("shopManager.csv");
			MessageBox::Show("Compra cancelada!");
		}
		else {
			MessageBox::Show("Nenhum item no carrinho para cancelar.");
		}
	}
	private: System::Void LeProduto_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		shopManager ProdutoRemove;
		if (confirma(textBox1->Text)) {
			inserirNoArquivoCSV(ProdutoRemove, -1);
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		shopManager novoProduto;
		if (confirma(textBox1->Text)) {
			inserirNoArquivoCSV(novoProduto, 1);
		}
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		deletaCarrinhoCompras();
		MessageBox::Show("Compra cancelada!");
		this->Hide();
		this->Close();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		FinalizaCompras^ tela = gcnew FinalizaCompras();
		this->Hide();
		tela->ShowDialog();
		this->Close();
	}
};
}
