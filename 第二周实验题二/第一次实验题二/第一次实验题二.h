
// ��һ��ʵ�����.h : ��һ��ʵ����� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��һ��ʵ�����App:
// �йش����ʵ�֣������ ��һ��ʵ�����.cpp
//

class C��һ��ʵ�����App : public CWinApp
{
public:
	C��һ��ʵ�����App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��һ��ʵ�����App theApp;
