
// �ۺ�ʵ��һ.h : �ۺ�ʵ��һ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ۺ�ʵ��һApp:
// �йش����ʵ�֣������ �ۺ�ʵ��һ.cpp
//

class C�ۺ�ʵ��һApp : public CWinApp
{
public:
	C�ۺ�ʵ��һApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ۺ�ʵ��һApp theApp;
