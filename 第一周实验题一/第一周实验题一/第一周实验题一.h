
// ��һ��ʵ����һ.h : ��һ��ʵ����һ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��һ��ʵ����һApp:
// �йش����ʵ�֣������ ��һ��ʵ����һ.cpp
//

class C��һ��ʵ����һApp : public CWinApp
{
public:
	C��һ��ʵ����һApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��һ��ʵ����һApp theApp;
