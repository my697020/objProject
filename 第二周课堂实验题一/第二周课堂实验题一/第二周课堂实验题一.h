
// �ڶ��ܿ���ʵ����һ.h : �ڶ��ܿ���ʵ����һ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڶ��ܿ���ʵ����һApp:
// �йش����ʵ�֣������ �ڶ��ܿ���ʵ����һ.cpp
//

class C�ڶ��ܿ���ʵ����һApp : public CWinApp
{
public:
	C�ڶ��ܿ���ʵ����һApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڶ��ܿ���ʵ����һApp theApp;
