
// �ھ���ʵ������.h : �ھ���ʵ������ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ھ���ʵ������App:
// �йش����ʵ�֣������ �ھ���ʵ������.cpp
//

class C�ھ���ʵ������App : public CWinApp
{
public:
	C�ھ���ʵ������App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ھ���ʵ������App theApp;
