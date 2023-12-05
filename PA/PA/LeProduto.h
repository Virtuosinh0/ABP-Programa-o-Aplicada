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
			this->SuspendLayout();
			// 
			// LeProduto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"LeProduto";
			this->Text = L"LeProduto";
			this->Load += gcnew System::EventHandler(this, &LeProduto::LeProduto_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void LeProduto_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
