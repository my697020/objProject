
// �ھ���ʵ�����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ھ���ʵ�����App: 
// �йش����ʵ�֣������ �ھ���ʵ�����.cpp
//

class C�ھ���ʵ�����App : public CWinApp
{
public:
	C�ھ���ʵ�����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ھ���ʵ�����App theApp;