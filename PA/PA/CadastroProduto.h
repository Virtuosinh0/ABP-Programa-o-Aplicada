#pragma once
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <vcclr.h>
#include "Telas.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

namespace PA {

	struct stockManager {
		int code;
		char description[50];
		int quantity;
		int minStock;
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
	/// Sumário para CadastroProduto
	/// </summary>
	public ref class CadastroProduto : public System::Windows::Forms::Form
	{
	public:
		CadastroProduto(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~CadastroProduto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(27, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Cadastro de produtos no estoque ";
			this->label1->Click += gcnew System::EventHandler(this, &CadastroProduto::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(27, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(166, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Insira as informações do produto: ";
			this->label2->Click += gcnew System::EventHandler(this, &CadastroProduto::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(27, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Código do produto: ";
			this->label3->Click += gcnew System::EventHandler(this, &CadastroProduto::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(27, 128);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Descrição do produto: ";
			this->label4->Click += gcnew System::EventHandler(this, &CadastroProduto::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(27, 166);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(144, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Estoque Mínimo de produto: ";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(148, 88);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(126, 20);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(148, 125);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(126, 20);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(174, 163);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(98, 20);
			this->textBox3->TabIndex = 7;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(174, 208);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Confirmar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CadastroProduto::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(30, 208);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CadastroProduto::button2_Click);
			// 
			// CadastroProduto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"CadastroProduto";
			this->Text = L"CadastroProduto";
			this->Load += gcnew System::EventHandler(this, &CadastroProduto::CadastroProduto_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CadastroProduto_Load(System::Object^ sender, System::EventArgs^ e) {}
	private:
	void inserirNoArquivoCSV(const stockManager& item) {
		if (codigoExistente(item.code)) {
			MessageBox::Show("O código do produto já existe.");
			return;
		}

		std::ofstream arquivo("stockManager.csv", std::ios::app); // Abre o arquivo em modo de append (adicionar ao final)

		if (arquivo.is_open()) {
			arquivo << item.code << "," << item.description << "," << item.quantity << "," << item.minStock << "\n";
			arquivo.close();
			MessageBox::Show("Produto inserido no arquivo CSV com sucesso!");
		}
		else {
			MessageBox::Show("Não foi possível abrir o arquivo para inserção do produto.");
		}
	}
	bool codigoExistente(int codigo) {
		std::ifstream arquivo("stockManager.csv");
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
					return true; // Código já existe
				}
			}
			arquivo.close();
		}
		return false;
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ codigoStr = textBox1->Text;
		String^ descricaoStr = textBox2->Text;
		String^ estoqueMinimoStr = textBox3->Text;

		// Verificar se os campos não estão vazios
		if (String::IsNullOrEmpty(codigoStr) || String::IsNullOrEmpty(descricaoStr) || String::IsNullOrEmpty(estoqueMinimoStr)) {
			MessageBox::Show("Por favor, preencha todos os campos.");
			return;
		}

		// Converter os valores para inteiros (outras verificações de validação podem ser necessárias)
		int codigo = System::Convert::ToInt32(codigoStr);
		int estoqueMinimo = System::Convert::ToInt32(estoqueMinimoStr);

		// Verificar se os campos não estão vazios
		if (codigo <= 0 || descricaoStr->Length == 0 || estoqueMinimo <= 0) {
			MessageBox::Show("Por favor, preencha todos os campos corretamente.");
			return;
		}

		// Criar uma instância de stockManager e preenchê-la com os valores obtidos
		stockManager novoProduto;
		novoProduto.code = codigo;

		// Copiar a string para o campo de descrição da estrutura (até 50 caracteres)
		strncpy_s(novoProduto.description, msclr::interop::marshal_as<std::string>(descricaoStr).c_str(), sizeof(novoProduto.description));
		novoProduto.quantity = 0; // Quantidade inicialmente zero
		novoProduto.minStock = estoqueMinimo;

		// Verificar se o código já existe
		if (codigoExistente(codigo)) {
			MessageBox::Show("O código do produto já existe.");
			return;
		}

		// Adicionar o novo produto ao arquivo CSV
		inserirNoArquivoCSV(novoProduto);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Close();
	}
};
}
