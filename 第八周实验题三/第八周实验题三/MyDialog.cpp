// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "第八周实验题三.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, x1(0)
	, y2(0)
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, x1);
	DDX_Text(pDX, IDC_EDIT2, y1);
	DDX_Text(pDX, IDC_EDIT3, x2);
	DDX_Text(pDX, IDC_EDIT4, y2);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(true);
	UpdateData(false);
	int r = DoModal();
	ShowWindow(0);
	
	
}
