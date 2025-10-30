/*
 *    *********************************************************
 *    **            Copyright (c) 2014 Y.Tomioka             **
 *    **                                                     **
 *    **   This software is released under the MIT License.  **
 *    *********************************************************
 *
 */

/**
 * @file	STDataControl.cpp
 * @brief	Implementation for STDataControl.
 * @date	
 * @author	
 */

#include "../inc/STDataControl.h"


using namespace STPlayer;
using namespace System::IO;
using namespace System::Xml::Serialization;

/**
 * @brief コンストラクタ
 * 
 */
STDataControl::STDataControl()
{
	m_stIndex = 0;
	m_stdata = gcnew STData();
}

/**
 * @brief デストラクタ
 * 
 */
STDataControl::~STDataControl()
{
	delete m_stdata;
	clearSubtitle();
}

/**
 * @brief 設定データを保存する
 *
 * @return
 *		true	:正常に実行できた場合
 *		false	:正常に実行でできなかった場合
 */
bool
STDataControl::save()
{
	System::String ^path = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location);
	System::IO::File::Delete(path + "\\" + "settings.xml");
	try {
		XmlSerializer^ serializer = gcnew XmlSerializer(STData::typeid);
		FileStream^ fs = gcnew FileStream(path + "\\" + "settings.xml", FileMode::OpenOrCreate);
		serializer->Serialize(fs, m_stdata);
		fs->Close();
	}
	catch(System::Exception^ /*e*/) {
		/* 設定データの保存に失敗 */
		System::Windows::Forms::MessageBox::Show("設定データの保存に失敗しました。");
		return false;
	}

	return true;
}

/**
 * @brief 設定データをロードする
 *
 * @return
 *		true	:正常に実行できた場合
 *		false	:正常に実行でできなかった場合
 */
bool
STDataControl::load()
{
	System::String ^path = System::IO::Path::GetDirectoryName(System::Reflection::Assembly::GetExecutingAssembly()->Location);
	try {
		XmlSerializer^ serializer = gcnew XmlSerializer(STData::typeid);
		FileStream^ fs = gcnew FileStream(path + "\\" + "settings.xml", FileMode::Open);
		m_stdata = (STData^)serializer->Deserialize(fs);
		fs->Close();
	}
	catch(System::Exception^ /*e*/) {
		/* 設定データをロードに失敗 */
		System::Windows::Forms::MessageBox::Show("設定データをロードに失敗しました。");
		return false;
	}

	return true;
}

/**
 * @brief 字幕データをロードする
 *
 * @return
 *		true	:正常に実行できた場合
 *		false	:正常に実行でできなかった場合
 */
bool
STDataControl::loadSubtitle()
{
	/* 既に字幕データをロード済みの場合は、一旦解放 */
	clearSubtitle();

	try {
		/* ファイルから字幕データを読み出し */
		StreamReader^ din = File::OpenText(m_stdata->srtPath);

		/* 行データの読み出し */
		m_stIndex = 0;
		System::String^ line;
		while ((line = din->ReadLine()) != nullptr)
		{
			if(line->Length > 0)
			{
				/* 番号取得 */
				int number;
				if(System::Int32::TryParse(line, number) == false)
				{
					throw gcnew System::Exception("error");
				}

				/* 時間取得 */
				System::String ^stTime;
				System::String ^edTime;
				array<System::String^>^ splitStr ={"-->"};
				if((line = din->ReadLine()) == nullptr)
				{
					throw gcnew System::Exception("error");
				}
				array<System::String^>^ timeArray = line->Split(splitStr, System::StringSplitOptions::RemoveEmptyEntries);
				if(timeArray->Length != 2)
				{
					throw gcnew System::Exception("error");
				}
				stTime = timeArray[0]->Trim()->Replace(',', '.');
				edTime = timeArray[1]->Trim()->Replace(',', '.');

				/* 字幕取得 */
				System::String ^subtitle = nullptr;
				while ((line = din->ReadLine()) != nullptr)
				{
					if(line->Length == 0)
					{
						break;
					}
					if(subtitle != nullptr && subtitle->Length > 0)
					{
						subtitle += "\n";
					}
					subtitle += line;
				}
				if(subtitle->Length == 0)
				{
					throw gcnew System::Exception("error");
				}

				Subtitle_t ^curData = gcnew Subtitle_t();
				curData->starttime = System::DateTime::Parse(stTime);
				curData->endtime = System::DateTime::Parse(edTime);
				curData->subtitle = subtitle;
				m_subtitle[number] = curData;
				m_stIndex++;
			}
		}
	}
	catch(System::Exception^ /*e*/) {
		/* ファイルの読み込みに失敗 */
		System::Windows::Forms::MessageBox::Show("字幕ファイルの読み込みに失敗しました。");
		return false;
	}

	return true;
}

/**
 * @brief 設定データを取得する
 *
 * @param[out]	stdata	設定データ
 *
 */
void
STDataControl::getSTData(STData ^%stdata)
{
	stdata = m_stdata;
}

/**
 * @brief 字幕データを解放する
 *
 */
void
STDataControl::clearSubtitle()
{
	cliext::map<unsigned int, Subtitle_t^>::iterator itr;
	for(itr = m_subtitle.begin(); itr != m_subtitle.end(); itr++)
	{
		delete itr->second->starttime;
		delete itr->second->endtime;
		delete itr->second->subtitle;
		delete itr->second;
	}
	m_subtitle.clear();
	m_stIndex = 0;
}

/**
 * @brief 字幕データを取得する
 *
 * @param[in]	index		インデックス
 * @param[out]	subtitle	字幕データ
 *
 */
void
STDataControl::getSubtitle(int index, Subtitle_t ^%subtitle)
{
	subtitle = m_subtitle[index];
}

/**
 * @brief 字幕数を取得する
 *
 * @return
 *		m_stIndex	:字幕の数
 */
int
STDataControl::getSubtitleSize()
{
	return m_stIndex;
}
