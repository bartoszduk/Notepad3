﻿/******************************************************************************
*                                                                             *
*                                                                             *
* Notepad3                                                                    *
*                                                                             *
* MuiLanguage.h                                                               *
*   Definitions for MUI Language support                                      *
*   Based on code from Notepad2, (c) Florian Balmer 1996-2011                 *
*                                                                             *
*                                                  (c) Rizonesoft 2008-2019   *
*                                                    https://rizonesoft.com   *
*                                                                             *
*                                                                             *
*******************************************************************************/
#pragma once
#ifndef _NP3_MUI_LANGUAGE_H_
#define _NP3_MUI_LANGUAGE_H_


typedef struct _muilanguage
{
  UINT    rid;
  WCHAR   szLocaleName[LOCALE_NAME_MAX_LENGTH];
  // !!! WARNING:  LCID is DEPRECATED 
  LANGID  LangId;
  bool    bHasDLL;
  bool    bIsActive;

} MUILANGUAGE, *PMUILANGUAGE;

extern MUILANGUAGE MUI_LanguageDLLs[];
int MuiLanguages_CountOf();


LANGID LoadLanguageResources();
void   FreeLanguageResources();

int LoadLngStringW(UINT uID, LPWSTR lpBuffer, int nBufferMax);
int LoadLngStringA(UINT uID, LPSTR lpBuffer, int nBufferMax);
int FormatLngStringW(LPWSTR lpOutput, int nOutput, UINT uIdFormat, ...);
int FormatLngStringA(LPSTR lpOutput, int nOutput, UINT uIdFormat, ...);
int LoadLngStringW2MB(UINT uID, LPSTR lpBuffer, int nBufferMax);

#define GetLngString(id,pb,cb) LoadLngStringW((id),(pb),(cb))
#define GetLngStringA(id,pb,cb) LoadLngStringA((id),(pb),(cb))
#define GetLngStringW2MB(id,pb,cb) LoadLngStringW2MB((id),(pb),(cb))



#endif //_NP3_MUI_LANGUAGE_H_

///   End of MuiLanguage.h   ///
