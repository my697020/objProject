// DlgSort.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ���ʵ��.h"
#include "DlgSort.h"
#include "afxdialogex.h"


// DlgSort �Ի���

IMPLEMENT_DYNAMIC(DlgSort, CDialogEx)

DlgSort::DlgSort(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, one(_T(""))
{

}

DlgSort::~DlgSort()
{
}

void DlgSort::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, one);
}


BEGIN_MESSAGE_MAP(DlgSort, CDialogEx)
END_MESSAGE_MAP()


// DlgSort ��Ϣ�������
