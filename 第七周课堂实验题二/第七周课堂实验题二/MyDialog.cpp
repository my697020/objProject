// MyDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "第七周课堂实验题二.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// MyDialog 对话框

IMPLEMENT_DYNAMIC(MyDialog, CDialogEx)

MyDialog::MyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, one(_T(""))
	, two(_T(""))
{

}

MyDialog::~MyDialog()
{
}

void MyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, one);
	DDX_Text(pDX, IDC_EDIT2, two);
}


BEGIN_MESSAGE_MAP(MyDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MyDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// MyDialog 消息处理程序


void MyDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	this->UpdateData(true);
	CString temp;
	temp = one;
	one = two;
	two =temp;
	this->UpdateData(false);
}
