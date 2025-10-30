/*
 *    *********************************************************
 *    **            Copyright (c) 2014 Y.Tomioka             **
 *    **                                                     **
 *    **   This software is released under the MIT License.  **
 *    *********************************************************
 *
 */

/**
 * @file	STData.h
 * @brief	Header file for STData class.
 *
 * @author	Y.Tomioka
 * @date	2014/01/02
**/

#ifndef STData_H
#define STData_H

#if		_MSC_VER > 1000
#pragma once
#endif	// _MSC_VER > 1000


namespace STPlayer
{
/**
 * @class STData
 * 
 */
public ref class STData
{
public:

	/** @brief 字幕ファイルパス */
	property System::String ^srtPath; 
	/** @brief フォント */
	property System::String ^fontName; 
	/** @brief フォントスタイル */
	property int fontStyle; 
	/** @brief フォントサイズ */
	property float fontSize; 
	/** @brief フォントカラー */
	property System::String ^fontColor; 
};

}

#endif
