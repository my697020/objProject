
// �ڰ���ʵ����һ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ڰ���ʵ����һApp: 
// �йش����ʵ�֣������ �ڰ���ʵ����һ.cpp
//

class C�ڰ���ʵ����һApp : public CWinApp
{
public:
	C�ڰ���ʵ����һApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ڰ���ʵ����һApp theApp;