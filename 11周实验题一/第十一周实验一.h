
// ��ʮһ��ʵ��һ.h : ��ʮһ��ʵ��һ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ʮһ��ʵ��һApp:
// �йش����ʵ�֣������ ��ʮһ��ʵ��һ.cpp
//

class C��ʮһ��ʵ��һApp : public CWinApp
{
public:
	C��ʮһ��ʵ��һApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ʮһ��ʵ��һApp theApp;
