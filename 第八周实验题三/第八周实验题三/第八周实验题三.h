
// �ڰ���ʵ������.h : �ڰ���ʵ������ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ڰ���ʵ������App:
// �йش����ʵ�֣������ �ڰ���ʵ������.cpp
//

class C�ڰ���ʵ������App : public CWinApp
{
public:
	C�ڰ���ʵ������App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ڰ���ʵ������App theApp;
