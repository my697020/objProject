// Dial.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "Dial.h"
#include "afxdialogex.h"


// Dial �Ի���

IMPLEMENT_DYNAMIC(Dial, CDialogEx)

Dial::Dial(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, s(_T(""))
{

}

Dial::~Dial()
{
}

void Dial::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, s);
}


BEGIN_MESSAGE_MAP(Dial, CDialogEx)
END_MESSAGE_MAP()


// Dial ��Ϣ�������
