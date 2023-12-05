#pragma once
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <vcclr.h>
#include "Telas.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace System;
using namespace System::IO;

const std::string kUsersFile = "Users.csv";

namespace PA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Sumário para MyForm
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
		}

	protected:
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(147, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Log In";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 72);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nome: ";
			this->label1->Click += gcnew System::EventHandler(this, &Login::label1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(66, 175);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Cadastro";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Login::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(36, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Senha: ";
			this->label2->Click += gcnew System::EventHandler(this, &Login::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(97, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(125, 20);
			this->textBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(97, 101);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(125, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Login::textBox2_TextChanged);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// Código para realizar o login
		std::string username = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string password = msclr::interop::marshal_as<std::string>(textBox2->Text);

		if (LoginUser(username, password)) {
			MessageBox::Show("Login bem-sucedido!");
			OpenMenu();
		}
		else {
			MessageBox::Show("Credenciais inválidas. Tente novamente.");
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		// Código para criar um novo usuário
		std::string username = msclr::interop::marshal_as<std::string>(textBox1->Text);
		std::string password = msclr::interop::marshal_as<std::string>(textBox2->Text);

		if (UserExists(username)) {
			MessageBox::Show("Usuário já cadastrado. Use um nome de usuário diferente.");
			return;
		}

		std::ofstream file(kUsersFile, std::ios_base::app);
		file << username << "," << password << std::endl;
		file.close();

		MessageBox::Show("Cadastro realizado com sucesso!");
	}
	
	bool isLoggedIn() {
	   String^ username = textBox1->Text;
	   String^ password = textBox2->Text;

	   // Verifica se os campos de entrada não estão vazios
	   if (String::IsNullOrEmpty(username) || String::IsNullOrEmpty(password)) {
		   MessageBox::Show("Por favor, preencha todos os campos.");
		   return false;
	   }

	   try {
		   StreamReader^ sr = gcnew StreamReader(username + ".txt");
		   String^ fileUsername = sr->ReadLine();
		   String^ filePassword = sr->ReadLine();
		   sr->Close();

		   if (fileUsername == username && filePassword == password) {
			   return true;
		   }
		   else {
			   MessageBox::Show("Credenciais inválidas. Tente novamente.");
			   return false;
		   }
	   }
	   catch (FileNotFoundException^) {
		   MessageBox::Show("Arquivo de credenciais não encontrado.");
		   return false;
	   }
	   catch (IOException^ e) {
		   MessageBox::Show("Erro ao acessar o arquivo de credenciais: " + e->Message);
		   return false;
	   }
	}
	bool UserExists(const std::string& username) {
		std::ifstream file(kUsersFile);
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string user;
			std::getline(iss, user, ',');
			if (user == username) {
				return true;
			}
		}
		return false;
	}
	bool LoginUser(const std::string& username, const std::string& password) {
		std::ifstream file(kUsersFile);
		std::string line;
		while (std::getline(file, line)) {
			std::istringstream iss(line);
			std::string user, pass;
			std::getline(iss, user, ',');
			std::getline(iss, pass, ',');
			if (user == username && pass == password) {
				return true;
			}
		}
		return false;
	}
	void OpenMenu() {
		Telas^ tela = gcnew Telas();
		this->Hide();
		tela->ShowDialog();
		this->Close();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		this->textBox2->PasswordChar = '*';
		this->textBox2->UseSystemPasswordChar = true;
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
};
}
