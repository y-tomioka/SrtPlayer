#pragma once

#include "FrmSetting.h"
#include "inc/STDataControl.h"

namespace STPlayer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace RamGecTools;

	/// <summary>
	/// FrmSTPlayer の概要
	/// </summary>
	public ref class FrmSTPlayer : public System::Windows::Forms::Form
	{
	public:
		FrmSTPlayer(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			m_stDataCtrl = gcnew STDataControl();
			frmSetting = gcnew FrmSetting(m_stDataCtrl, label5);

			// XMLのデータが存在する場合
			String ^filePath = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location) + "\\" + "settings.xml";
			if (File::Exists(filePath))
			{
				// XMLからデータ取得
				m_stDataCtrl->load();

				// フォントダイアログに初期値設定
				STData ^stdata;
				m_stDataCtrl->getSTData(stdata);
				label5->ForeColor = System::Drawing::Color::FromName(stdata->fontColor);
				label5->Font = gcnew System::Drawing::Font(gcnew System::Drawing::FontFamily(stdata->fontName), stdata->fontSize, (System::Drawing::FontStyle)stdata->fontStyle);

				// 字幕ファイルのロード
				if(stdata->srtPath != nullptr && stdata->srtPath->Length > 0)
				{
					// 字幕データを読み出し
					m_stDataCtrl->loadSubtitle();

					if(m_stDataCtrl->getSubtitleSize() > 0)
					{
						button1->Enabled = true;
						//button2->Enabled = true;
						button3->Enabled = true;
						PlayToolStripMenuItem->Enabled = true;
						PauseToolStripMenuItem->Enabled = true;
						StopToolStripMenuItem->Enabled = true;
						SyncToolStripMenuItem->Enabled = true;
						DragToolStripMenuItem->Enabled = true;
						trackBar1->Enabled = true;

						trackBar1->Maximum = m_stDataCtrl->getSubtitleSize();
					}
				}
				m_dragErea = false;
			}

			//Timer
			m_swatch = gcnew System::Diagnostics::Stopwatch();
			this->timer1->Tick += gcnew System::EventHandler(this, &FrmSTPlayer::timer1_Tick);
			m_stIndex = 1;
			m_timerOffset = 0;

			//MouseHook
			m_mouseHook = gcnew MouseHook();
			m_mouseHook->LeftButtonUp += gcnew MouseHook::MouseHookCallback(&FrmSTPlayer::mouseHook_MouseUp);

			trackBar1->Value = 0;

			//Image
			m_resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmSTPlayer::typeid));
			m_playImg = (cli::safe_cast<System::Drawing::Image^  >(m_resources->GetObject(L"button1.BackgroundImage")));
			m_pauseImg = (cli::safe_cast<System::Drawing::Image^  >(m_resources->GetObject(L"pause.BackgroundImage")));
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~FrmSTPlayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private:
		FrmSetting ^frmSetting;
		STDataControl ^m_stDataCtrl;
		static System::Diagnostics::Stopwatch ^m_swatch;
		int m_stIndex;
		static bool m_dragErea;
		static MouseHook ^m_mouseHook;
		unsigned int m_timerOffset;
		Image ^m_playImg;
		Image ^m_pauseImg;
		System::ComponentModel::ComponentResourceManager^  m_resources;

	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  button1;
	private: static System::Windows::Forms::Label^  label5;















	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ファイルToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  SettingToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  FinishToolStripMenuItem;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  MinToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  OriToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  PlayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  PauseToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  StopToolStripMenuItem;
private: static System::Windows::Forms::ToolStripMenuItem^  SyncToolStripMenuItem;
private: static System::Windows::Forms::Timer^  timer1;




































	private: System::Windows::Forms::NotifyIcon^  notifyIcon1;
	private: System::Windows::Forms::ToolStripMenuItem^  DragToolStripMenuItem;
private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
private: System::Windows::Forms::TrackBar^  trackBar1;

	private: System::ComponentModel::IContainer^  components;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmSTPlayer::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ファイルToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SettingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->FinishToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->MinToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->OriToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PlayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->PauseToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->StopToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->SyncToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DragToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->contextMenuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel1->Controls->Add(this->trackBar1);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(13, 175);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(252, 79);
			this->panel1->TabIndex = 0;
			// 
			// trackBar1
			// 
			this->trackBar1->AutoSize = false;
			this->trackBar1->Enabled = false;
			this->trackBar1->LargeChange = 10;
			this->trackBar1->Location = System::Drawing::Point(12, 13);
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(230, 30);
			this->trackBar1->TabIndex = 8;
			this->trackBar1->TickStyle = System::Windows::Forms::TickStyle::None;
			this->trackBar1->Value = 1;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &FrmSTPlayer::trackBar1_Scroll);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(225, 55);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(17, 12);
			this->label6->TabIndex = 7;
			this->label6->Text = L"00";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(217, 55);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(7, 12);
			this->label3->TabIndex = 6;
			this->label3->Text = L":";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(194, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(7, 12);
			this->label2->TabIndex = 4;
			this->label2->Text = L":";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(202, 55);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(17, 12);
			this->label4->TabIndex = 5;
			this->label4->Text = L"00";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(179, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(17, 12);
			this->label1->TabIndex = 3;
			this->label1->Text = L"00";
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(55, 49);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(37, 23);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &FrmSTPlayer::button3_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(12, 49);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(37, 23);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FrmSTPlayer::button1_Click);
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(128)));
			this->label5->Location = System::Drawing::Point(7, 33);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(248, 72);
			this->label5->TabIndex = 1;
			this->label5->Text = L"ここに字幕が表示されます。\r\n\r\n使い方\r\n(1) 設定画面で字幕ファイルを読み込みます。\r\n(2) 再生ボタンをクリックして字幕表示を開始します。\r\n(3) 右" 
				L"クリック→最小化で画面を最小化します。";
			this->label5->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmSTPlayer::FrmSTPlayer_MouseDown);
			this->label5->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &FrmSTPlayer::FrmSTPlayer_MouseMove);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ファイルToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(292, 24);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ファイルToolStripMenuItem
			// 
			this->ファイルToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->SettingToolStripMenuItem, 
				this->FinishToolStripMenuItem});
			this->ファイルToolStripMenuItem->Name = L"ファイルToolStripMenuItem";
			this->ファイルToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->ファイルToolStripMenuItem->Text = L"ファイル";
			// 
			// SettingToolStripMenuItem
			// 
			this->SettingToolStripMenuItem->Name = L"SettingToolStripMenuItem";
			this->SettingToolStripMenuItem->Size = System::Drawing::Size(94, 22);
			this->SettingToolStripMenuItem->Text = L"設定";
			this->SettingToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::SettingToolStripMenuItem_Click);
			// 
			// FinishToolStripMenuItem
			// 
			this->FinishToolStripMenuItem->Name = L"FinishToolStripMenuItem";
			this->FinishToolStripMenuItem->Size = System::Drawing::Size(94, 22);
			this->FinishToolStripMenuItem->Text = L"終了";
			this->FinishToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::FinishToolStripMenuItem_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->MinToolStripMenuItem, 
				this->OriToolStripMenuItem, this->PlayToolStripMenuItem, this->PauseToolStripMenuItem, this->StopToolStripMenuItem, this->SyncToolStripMenuItem, 
				this->DragToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(153, 158);
			// 
			// MinToolStripMenuItem
			// 
			this->MinToolStripMenuItem->Name = L"MinToolStripMenuItem";
			this->MinToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->MinToolStripMenuItem->Text = L"最小化";
			this->MinToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::MinToolStripMenuItem_Click);
			// 
			// OriToolStripMenuItem
			// 
			this->OriToolStripMenuItem->Enabled = false;
			this->OriToolStripMenuItem->Name = L"OriToolStripMenuItem";
			this->OriToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->OriToolStripMenuItem->Text = L"元に戻す";
			this->OriToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::OriToolStripMenuItem_Click);
			// 
			// PlayToolStripMenuItem
			// 
			this->PlayToolStripMenuItem->Enabled = false;
			this->PlayToolStripMenuItem->Name = L"PlayToolStripMenuItem";
			this->PlayToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->PlayToolStripMenuItem->Text = L"再生";
			this->PlayToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::PlayToolStripMenuItem_Click);
			// 
			// PauseToolStripMenuItem
			// 
			this->PauseToolStripMenuItem->Enabled = false;
			this->PauseToolStripMenuItem->Name = L"PauseToolStripMenuItem";
			this->PauseToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->PauseToolStripMenuItem->Text = L"一時停止";
			this->PauseToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::PauseToolStripMenuItem_Click);
			// 
			// StopToolStripMenuItem
			// 
			this->StopToolStripMenuItem->Enabled = false;
			this->StopToolStripMenuItem->Name = L"StopToolStripMenuItem";
			this->StopToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->StopToolStripMenuItem->Text = L"停止";
			this->StopToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::StopToolStripMenuItem_Click);
			// 
			// SyncToolStripMenuItem
			// 
			this->SyncToolStripMenuItem->Enabled = false;
			this->SyncToolStripMenuItem->Name = L"SyncToolStripMenuItem";
			this->SyncToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->SyncToolStripMenuItem->Text = L"同期再生";
			this->SyncToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::SyncToolStripMenuItem_Click);
			// 
			// DragToolStripMenuItem
			// 
			this->DragToolStripMenuItem->Enabled = false;
			this->DragToolStripMenuItem->Name = L"DragToolStripMenuItem";
			this->DragToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->DragToolStripMenuItem->Text = L"ドラッグエリア表示";
			this->DragToolStripMenuItem->Click += gcnew System::EventHandler(this, &FrmSTPlayer::DragToolStripMenuItem_Click);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->ContextMenuStrip = this->contextMenuStrip1;
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"notifyIcon1";
			this->notifyIcon1->Visible = true;
			// 
			// FrmSTPlayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->ContextMenuStrip = this->contextMenuStrip1;
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"FrmSTPlayer";
			this->Text = L"字幕プレーヤー";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->contextMenuStrip1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


	private:
		System::Drawing::Point^ mousePoint;
		System::Drawing::Size m_frmSize;

	private:
		//FrmSTPlayerのMouseDownイベントハンドラ（マウスのボタンが押されたとき）
		void FrmSTPlayer_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			//位置を記憶する
			if ((e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left)
			{
				mousePoint = gcnew System::Drawing::Point(e->X, e->Y);
			}
		}

		//FrmSTPlayerのMouseMoveイベントハンドラ（マウスが動いたとき）
		void FrmSTPlayer_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if ((e->Button & System::Windows::Forms::MouseButtons::Left) == System::Windows::Forms::MouseButtons::Left)
			{
				this->Left += e->X - mousePoint->X;
				this->Top += e->Y - mousePoint->Y;
			}
		}

#pragma endregion
	private: System::Void MinToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				//背景を透明にする
				menuStrip1->Hide();
				panel1->Hide();
				//this->ControlBox = false;
				//this->Text = "";
				//this->Opacity = 0.5;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				this->BackColor = System::Drawing::Color::FromArgb(255,0,255); 
				label5->BackColor = System::Drawing::Color::FromArgb(255,0,255);
				this->TransparencyKey = System::Drawing::Color::FromArgb(255,0,255);

				m_frmSize = this->ClientSize;
				this->ClientSize = System::Drawing::Size(800, 800);
				this->TopMost = true;
				MinToolStripMenuItem->Enabled = false;
				OriToolStripMenuItem->Enabled = true;
			 }
private: System::Void OriToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				this->ClientSize = m_frmSize;

				menuStrip1->Show();
				panel1->Show();
				this->TransparencyKey = System::Drawing::Color::Empty;
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
				this->BackColor = SystemColors::Control; 
				label5->BackColor = SystemColors::Control;
				this->TopMost = false;
				MinToolStripMenuItem->Enabled = true;
				OriToolStripMenuItem->Enabled = false;
		 }
private: System::Void FinishToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
		 }
private: System::Void SettingToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			STData ^stdata;
			String ^filePath = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location) + "\\" + "settings.xml";
			String ^strpath;
			if (File::Exists(filePath))
			{
 				// XMLからデータ取得
				m_stDataCtrl->load();

				m_stDataCtrl->getSTData(stdata);
				if(stdata->srtPath != nullptr && stdata->srtPath->Length > 0)
				{
					frmSetting->setText(stdata->srtPath);
					strpath = String::Copy(stdata->srtPath);
				}
			}

			System::Windows::Forms::DialogResult result = frmSetting->ShowDialog();

			if(result == System::Windows::Forms::DialogResult::OK && 
			   frmSetting->getText() != strpath)
			{
				if(m_stDataCtrl->getSubtitleSize() > 0)
				{
					button1->Enabled = true;
					//button2->Enabled = true;
					button3->Enabled = true;
					PlayToolStripMenuItem->Enabled = true;
					PauseToolStripMenuItem->Enabled = true;
					StopToolStripMenuItem->Enabled = true;
					SyncToolStripMenuItem->Enabled = true;
					DragToolStripMenuItem->Enabled = true;
					trackBar1->Enabled = true;
					trackBar1->Maximum = m_stDataCtrl->getSubtitleSize();
				}
				else
				{
					button1->Enabled = false;
					//button2->Enabled = false;
					button3->Enabled = false;
					PlayToolStripMenuItem->Enabled = false;
					PauseToolStripMenuItem->Enabled = false;
					StopToolStripMenuItem->Enabled = false;
					SyncToolStripMenuItem->Enabled = false;
					DragToolStripMenuItem->Enabled = false;
					trackBar1->Enabled = false;
				}
				button3_Click(sender, e);
			}
		 }
private:
	/* タイマー(100ms) */
	void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		/* 時間表示 */
		__int64 curTime = m_swatch->ElapsedMilliseconds + m_timerOffset*1000;
		unsigned int sec = (unsigned int)(curTime / 1000);
		unsigned int hour = 0;
		unsigned int min = 0;
		if(sec >= 3600)
		{
			hour = sec / 3600;
			sec -= hour * 3600;
		}
		if(sec >= 60)
		{
			min = sec / 60;
			sec -= min * 60;
		}

		label1->Text = (hour<10) ? "0"+hour.ToString() : hour.ToString();
		label4->Text = (min<10) ? "0"+min.ToString() : min.ToString();
		label6->Text = (sec<10) ? "0"+sec.ToString() : sec.ToString();

		/* 字幕表示 */
		if(m_stDataCtrl->getSubtitleSize() >= m_stIndex)
		{
			Subtitle_t ^subtitleData;
			m_stDataCtrl->getSubtitle(m_stIndex, subtitleData);
			unsigned int startTime = (subtitleData->starttime->Hour*3600 + subtitleData->starttime->Minute*60 + subtitleData->starttime->Second) * 1000 + subtitleData->starttime->Millisecond;
			unsigned int endTime   = (subtitleData->endtime->Hour*3600 + subtitleData->endtime->Minute*60 + subtitleData->endtime->Second) * 1000 + subtitleData->endtime->Millisecond;
			if(startTime <= curTime && endTime >= curTime)
			{
				label5->Text = (m_dragErea)? "●"+subtitleData->subtitle : subtitleData->subtitle;
			}
			else if(endTime < curTime)
			{
				label5->Text = (m_dragErea)? "●" : "";
				m_stIndex++;
			}

			if(trackBar1->Maximum < m_stIndex)
			{
				button3_Click(sender, e);
				return;
			}
			trackBar1->Value = m_stIndex;
		}
	}

public:
	/* Mouse Hookイベント */
	static void mouseHook_MouseUp(MouseHook::MSLLHOOKSTRUCT data)
	{
		m_mouseHook->Uninstall();
		SyncToolStripMenuItem->Enabled = true;

		/* 再生 */
		if(m_swatch->IsRunning == false)
		{
			label5->Text = (m_dragErea)? "●" : "";
			m_swatch->Start();
			timer1->Enabled = true;
		}
		/* 一時停止 */
		else
		{
			timer1->Enabled = false;
			m_swatch->Stop();
			label5->Text = label5->Text->Replace("●", "");
			label5->Text = (m_dragErea)? "●"+label5->Text : label5->Text;
		}
	}

/* 再生 */
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			/* 再生 */
			if(m_swatch->IsRunning == false)
			{
				label5->Text = (m_dragErea)? "●" : "";
				m_swatch->Start();
				timer1->Enabled = true;
				button1->BackgroundImage = m_pauseImg;
			}
			/* 一時停止 */
			else
			{
				button2_Click(sender, e);
				button1->BackgroundImage = m_playImg;
			}
		 }
/* 一時停止 */
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			timer1->Enabled = false;
			m_swatch->Stop();
			label5->Text = label5->Text->Replace("●", "");
			label5->Text = (m_dragErea)? "●"+label5->Text : label5->Text;
		 }
/* 停止 */
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			label5->Text = "";
			timer1->Enabled = false;
			m_swatch->Reset();
			trackBar1->Value = 0;
			m_timerOffset = 0;
			m_stIndex = 1;

			label1->Text = "00";
			label4->Text = "00";
			label6->Text = "00";
			button1->BackgroundImage = m_playImg;
		 }
/* 再生（右クリックメニュー） */
private: System::Void PlayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 button1_Click(sender, e);
		 }
/* 一時停止（右クリックメニュー） */
private: System::Void PauseToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 button2_Click(sender, e);
		 }
/* 停止（右クリックメニュー） */
private: System::Void StopToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 button3_Click(sender, e);
		 }
/* 同期再生（右クリックメニュー） */
private: System::Void SyncToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {	
			 SyncToolStripMenuItem->Enabled = false;
			 m_mouseHook->Install();
		 }
/* ドラッグエリア（右クリックメニュー） */
private: System::Void DragToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(DragToolStripMenuItem->Text == "ドラッグエリア表示")
			 {
				 DragToolStripMenuItem->Text = "ドラッグエリア非表示";
				 m_dragErea = true;
				 label5->Text = "●" + label5->Text;
			 }
			 else
			 {
				 DragToolStripMenuItem->Text = "ドラッグエリア表示";
				 m_dragErea = false;
				 label5->Text = label5->Text->Replace("●", "");
			 }
		 }
/* スクロール */
private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) {
			 /* 一時停止 */
			 button2_Click(sender, e);
			 button1->BackgroundImage = m_playImg;
			 m_swatch->Stop();
			 m_swatch->Reset();

			 if(trackBar1->Value > 0)
			 {
				 /* 字幕を表示 */
				 Subtitle_t ^subtitleData;
				 m_stDataCtrl->getSubtitle(trackBar1->Value, subtitleData);
				 label5->Text = (m_dragErea)? "●"+subtitleData->subtitle : subtitleData->subtitle;

				 /* 時間を変更 */
				unsigned int hour = subtitleData->starttime->Hour;
				unsigned int min  = subtitleData->starttime->Minute;
				unsigned int sec  = subtitleData->starttime->Second;
				label1->Text = (hour<10) ? "0"+hour.ToString() : hour.ToString();
				label4->Text = (min<10) ? "0"+min.ToString() : min.ToString();
				label6->Text = (sec<10) ? "0"+sec.ToString() : sec.ToString();

				m_stIndex = trackBar1->Value;
				m_timerOffset = hour * 3600 + min * 60 + sec;
			 }
			 else
			 {
				label5->Text = (m_dragErea)? "●" : "";
				label1->Text = "00";
				label4->Text = "00";
				label6->Text = "00";
				m_stIndex = 1;
				m_timerOffset = 0;
			 }
		 }
};
}
