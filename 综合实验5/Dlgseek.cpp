// Dlgseek.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ���ʵ��.h"
#include "Dlgseek.h"
#include "afxdialogex.h"


// Dlgseek �Ի���

IMPLEMENT_DYNAMIC(Dlgseek, CDialogEx)

Dlgseek::Dlgseek(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, seek(_T(""))
{

}

Dlgseek::~Dlgseek()
{
}

void Dlgseek::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, seek);
}


BEGIN_MESSAGE_MAP(Dlgseek, CDialogEx)
END_MESSAGE_MAP()


// Dlgseek ��Ϣ�������
