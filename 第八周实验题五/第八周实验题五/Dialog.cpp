// Dialog.cpp : 实现文件
//

#include "stdafx.h"
#include "第八周实验题五.h"
#include "Dialog.h"
#include "afxdialogex.h"


// Dialog 对话框

IMPLEMENT_DYNAMIC(Dialog, CDialogEx)

Dialog::Dialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, red(0)
	, blue(0)
	, green(0)
{

}

Dialog::~Dialog()
{
}

void Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, red);
	DDX_Text(pDX, IDC_EDIT2, blue);
	DDX_Text(pDX, IDC_EDIT3, green);
}


BEGIN_MESSAGE_MAP(Dialog, CDialogEx)
END_MESSAGE_MAP()


// Dialog 消息处理程序
