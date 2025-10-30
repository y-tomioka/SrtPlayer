#pragma once

#include "inc/STDataControl.h"

namespace STPlayer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// FrmSetting の概要
	/// </summary>
	public ref class FrmSetting : public System::Windows::Forms::Form
	{
	public:
		FrmSetting(STDataControl ^stDataCtrl, System::Windows::Forms::Label ^label)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			m_stDataCtrl = stDataCtrl;
			m_label = label;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FrmSetting()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		System::Windows::Forms::Label ^m_label;
		STDataControl ^m_stDataCtrl;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;






	private: System::Windows::Forms::FontDialog^  fontDialog1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::BindingSource^  bindingSource1;
	private: System::Windows::Forms::Button^  button5;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->fontDialog1 = (gcnew System::Windows::Forms::FontDialog());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->bindingSource1 = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingSource1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 12);
			this->label1->TabIndex = 0;
			this->label1->Text = L"字幕ファイル";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(94, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(142, 19);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(242, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(43, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"参照";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FrmSetting::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 12);
			this->label2->TabIndex = 3;
			this->label2->Text = L"フォント";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(94, 39);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(43, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"設定";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &FrmSetting::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(93, 78);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"OK";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FrmSetting::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(174, 78);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"キャンセル";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &FrmSetting::button4_Click);
			// 
			// fontDialog1
			// 
			this->fontDialog1->ShowColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"字幕ファイル(*.srt)|*.srt";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(291, 11);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(41, 23);
			this->button5->TabIndex = 9;
			this->button5->Text = L"クリア";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &FrmSetting::button5_Click);
			// 
			// FrmSetting
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(344, 129);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"FrmSetting";
			this->ShowIcon = false;
			this->Text = L"設定画面";
			this->Shown += gcnew System::EventHandler(this, &FrmSetting::FrmSetting_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bindingSource1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/* 字幕ファイル参照ボタン */
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 openFileDialog1->FileName = "";
				 System::Windows::Forms::DialogResult result = openFileDialog1->ShowDialog();
				 if(result == System::Windows::Forms::DialogResult::OK)
				 {
					textBox1->Text = openFileDialog1->FileName;
				 }
			 }
	/* フォント設定ボタン */
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {	
				// XMLのデータが存在する場合
				String ^filePath = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location) + "\\" + "settings.xml";
				if (File::Exists(filePath))
				{
 					// XMLからデータ取得
					m_stDataCtrl->load();

					// フォントダイアログに初期値設定
					STData ^stdata;
					m_stDataCtrl->getSTData(stdata);
					fontDialog1->Color = System::Drawing::Color::FromName(stdata->fontColor);
					fontDialog1->Font = gcnew System::Drawing::Font(gcnew System::Drawing::FontFamily(stdata->fontName), stdata->fontSize, (System::Drawing::FontStyle)stdata->fontStyle);
				}

				// 画面表示
				fontDialog1->ShowColor = true;
				System::Windows::Forms::DialogResult result = fontDialog1->ShowDialog();
			 }
	/* OKボタン */
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				STData ^stdata;
				m_stDataCtrl->getSTData(stdata);

				if(textBox1->Text != stdata->srtPath)
				{
					// 字幕ファイルが設定されている場合
					if(textBox1->Text->Length > 0)
					{
						if (File::Exists(textBox1->Text))
						{
							// 字幕データを読み出し
							stdata->srtPath = textBox1->Text;
							m_stDataCtrl->loadSubtitle();
						}
					}
					else
					{
						m_stDataCtrl->clearSubtitle();
					}
				}

				// XMLにデータを保存
				stdata->srtPath = textBox1->Text;
				stdata->fontName = fontDialog1->Font->Name;
				stdata->fontStyle = (int)fontDialog1->Font->Style;
				stdata->fontSize = fontDialog1->Font->Size;
				stdata->fontColor = fontDialog1->Color.Name;
				m_stDataCtrl->save();

				// フォントダイアログの情報をラベルに反映
				m_label->ForeColor = System::Drawing::Color::FromName(fontDialog1->Color.Name);
				m_label->Font = gcnew System::Drawing::Font(fontDialog1->Font->Name, fontDialog1->Font->Size, fontDialog1->Font->Style);
				this->DialogResult = System::Windows::Forms::DialogResult::OK;
				this->Close();
			 }
	/* キャンセルボタン */
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
				this->Close();
			 }
/* クリアボタン */
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox1->Text = "";
		 }
public:
	void setText(String ^srtPath)
	{
		textBox1->Text = srtPath;
	}
	String^ getText()
	{
		return textBox1->Text;
	}
private:
	void FrmSetting_Shown(System::Object^  sender, System::EventArgs^  e) {
		button1->Focus();
	}
};
}
