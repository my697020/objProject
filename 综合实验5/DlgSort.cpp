// DlgSort.cpp : 实现文件
//

#include "stdafx.h"
#include "综合总实验.h"
#include "DlgSort.h"
#include "afxdialogex.h"


// DlgSort 对话框

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


// DlgSort 消息处理程序
