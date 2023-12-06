#pragma once
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
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para EntradaProduto
	/// </summary>
	public ref class EntradaProduto : public System::Windows::Forms::Form
	{
	public:
		EntradaProduto(void)
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
		~EntradaProduto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(217, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Insira o ID do produto para realizar o entrada";
			this->label1->Click += gcnew System::EventHandler(this, &EntradaProduto::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 84);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"ID do produto: ";
			this->label2->Click += gcnew System::EventHandler(this, &EntradaProduto::label2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(43, 159);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Fechar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &EntradaProduto::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(165, 159);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Confirmar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EntradaProduto::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(140, 81);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(140, 115);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(40, 118);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(68, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Quantidade: ";
			this->label3->Click += gcnew System::EventHandler(this, &EntradaProduto::label3_Click);
			// 
			// EntradaProduto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"EntradaProduto";
			this->Text = L"EntradaProduto";
			this->Load += gcnew System::EventHandler(this, &EntradaProduto::EntradaProduto_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	bool confirma() {
		// Obtenha os valores dos campos de texto e verifique se estão vazios
		String^ ID = textBox1->Text;
		String^ Quantity = textBox2->Text;

		if (String::IsNullOrEmpty(ID) || String::IsNullOrEmpty(Quantity)) {
			MessageBox::Show("Por favor, preencha todos os campos.");
			return false;
		}

		// Converte as strings para inteiros
		int productId, quantity;
		if (!Int32::TryParse(ID, productId)) {
			MessageBox::Show("ID do produto inválido.");
			return false;
		}
		if (!Int32::TryParse(Quantity, quantity)) {
			MessageBox::Show("Quantidade inválida.");
			return false;
		}

		// Verifica se o código existe (exemplo de implementação)
		if (codigoExistente(productId)) {
			MessageBox::Show("Produto não encontrado.");
			return false;
		}

		return true; // Todos os campos estão preenchidos corretamente e o produto pode ser adicionado
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
					return false; // Código já existe
				}
			}
			arquivo.close();
		}
		return true;
	}
	void atualizaEstoque(int ID, int Quantidade) {
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
			if (std::stoi(row[0]) == ID) {
				int qt = std::stoi(row[2]);
				row[2] = std::to_string(Quantidade + qt);
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
		MessageBox::Show("Produto recebido com sucesso.");
		textBox1->Text = String::Empty;
		textBox2->Text = String::Empty;
	}
	private: System::Void EntradaProduto_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		this->Close();
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (confirma()) {
			int ID_P = System::Convert::ToInt32(textBox1->Text);
			int Quant_P = System::Convert::ToInt32(textBox2->Text);
			atualizaEstoque(ID_P, Quant_P);
		}
	}
};
}
