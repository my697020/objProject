
// �ۺ�ʵ�������2��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ۺ�ʵ�������2��App: 
// �йش����ʵ�֣������ �ۺ�ʵ�������2��.cpp
//

class C�ۺ�ʵ�������2��App : public CWinApp
{
public:
	C�ۺ�ʵ�������2��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ۺ�ʵ�������2��App theApp;