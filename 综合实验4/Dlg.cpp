// Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "Dlg.h"
#include "afxdialogex.h"


// Dlg �Ի���

IMPLEMENT_DYNAMIC(Dlg, CDialogEx)

Dlg::Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Dlg::~Dlg()
{
}

void Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a);

}


BEGIN_MESSAGE_MAP(Dlg, CDialogEx)
END_MESSAGE_MAP()


// Dlg ��Ϣ�������
