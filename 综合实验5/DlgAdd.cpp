// DlgAdd.cpp : 实现文件
//

#include "stdafx.h"
#include "综合总实验.h"
#include "DlgAdd.h"
#include "afxdialogex.h"


// DlgAdd 对话框

IMPLEMENT_DYNAMIC(DlgAdd, CDialogEx)

DlgAdd::DlgAdd(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, name(_T(""))
	, stunum(_T(""))
	, phone(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birth(0)
	, home(_T(""))
	, photo(_T(""))
{

}

DlgAdd::~DlgAdd()
{
}

void DlgAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, name);
	DDX_Text(pDX, IDC_EDIT7, stunum);
	DDX_Text(pDX, IDC_EDIT8, phone);
	DDX_Text(pDX, IDC_EDIT3, major);
	DDX_Text(pDX, IDC_EDIT4, sex);
	DDX_Text(pDX, IDC_EDIT5, birth);
	DDX_Text(pDX, IDC_EDIT1, home);
	DDX_Text(pDX, IDC_EDIT6, photo);
}


BEGIN_MESSAGE_MAP(DlgAdd, CDialogEx)
END_MESSAGE_MAP()


// DlgAdd 消息处理程序
