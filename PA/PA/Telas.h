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

	/// <summary>
	/// Sum�rio para Telas
	/// </summary>
	public ref class Telas : public System::Windows::Forms::Form
	{
	public:
		Telas(void)
		{
			InitializeComponent();
			//
			//TODO: Adicione o c�digo do construtor aqui
			//
		}

	protected:
		/// <summary>
		/// Limpar os recursos que est�o sendo usados.
		/// </summary>
		~Telas()
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






	protected:

	private:
		/// <summary>
		/// Vari�vel de designer necess�ria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necess�rio para suporte ao Designer - n�o modifique 
		/// o conte�do deste m�todo com o editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(88, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Entrada de produto";
			this->label1->Click += gcnew System::EventHandler(this, &Telas::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(88, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(106, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Cadastro de produto ";
			this->label2->Click += gcnew System::EventHandler(this, &Telas::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(91, 136);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Mostra Estoque";
			this->label3->Click += gcnew System::EventHandler(this, &Telas::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(91, 179);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Venda de produto";
			this->label4->Click += gcnew System::EventHandler(this, &Telas::label4_Click);
			// 
			// Telas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Menu";
			this->Text = L"Menu";
			this->Load += gcnew System::EventHandler(this, &Telas::Telas_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Telas_Load(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
		EntradaProduto^ tela = gcnew EntradaProduto();
		tela->Show();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
		CadastroProduto^ tela = gcnew CadastroProduto();
		tela->Show();

	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
		MostraEstoque^ tela = gcnew MostraEstoque();
		tela->Show();
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
		LeProduto^ tela = gcnew LeProduto();
		tela->Show(); 
	}
};
}
