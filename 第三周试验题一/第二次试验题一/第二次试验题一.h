
// �ڶ���������һ.h : �ڶ���������һ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڶ���������һApp:
// �йش����ʵ�֣������ �ڶ���������һ.cpp
//

class C�ڶ���������һApp : public CWinApp
{
public:
	C�ڶ���������һApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڶ���������һApp theApp;
