
// �����ܵڶ���.h : �����ܵڶ��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�����ܵڶ���App:
// �йش����ʵ�֣������ �����ܵڶ���.cpp
//

class C�����ܵڶ���App : public CWinApp
{
public:
	C�����ܵڶ���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�����ܵڶ���App theApp;
