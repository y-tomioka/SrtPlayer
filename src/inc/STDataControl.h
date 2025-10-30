/*
 *    *********************************************************
 *    **            Copyright (c) 2014 Y.Tomioka             **
 *    **                                                     **
 *    **   This software is released under the MIT License.  **
 *    *********************************************************
 *
 */

/**
 * @file	STDataControl.h
 * @brief	Header file for STDataControl class.
 *
 * @author	Y.Tomioka
 * @date	2014/01/02
**/

#ifndef STDataControl_H
#define STDataControl_H

#if		_MSC_VER > 1000
#pragma once
#endif	// _MSC_VER > 1000

#include <cliext/map>
#include "STData.h"

namespace STPlayer
{

/* 字幕データ */
public ref struct Subtitle_t
{
	System::DateTime ^starttime;
	System::DateTime ^endtime;
	System::String ^subtitle;
};

/**
 * @class STDataControl
 * 
 */
public ref class STDataControl
{
public:
	/** @brief コンストラクタ */
	STDataControl();

	/** @brief デストラクタ */
	~STDataControl();

	/** @brief 設定データを保存する */
	bool save();

	/** @brief 設定データをロードする */
	bool load();

	/** @brief 設定データを取得する */
	void getSTData(STData ^%stdata);

	/** @brief 字幕データをロードする */
	bool loadSubtitle();

	/** @brief 字幕データを取得する */
	void getSubtitle(int index, Subtitle_t ^%subtitle);

	/** @brief 字幕数を取得する */
	int getSubtitleSize();

	/** @brief 字幕データを解放する */
	void clearSubtitle();

private:
	/* 設定画面の情報 */
	STData ^m_stdata;

	/* 字幕データ */
	int m_stIndex;
	cliext::map<unsigned int, Subtitle_t^> m_subtitle;
};

}

#endif
