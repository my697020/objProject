// Dialog3.cpp : 实现文件
//

#include "stdafx.h"
#include "第八周实验题一.h"
#include "Dialog3.h"
#include "afxdialogex.h"


// Dialog3 对话框

IMPLEMENT_DYNAMIC(Dialog3, CDialogEx)

Dialog3::Dialog3(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

Dialog3::~Dialog3()
{
}

void Dialog3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog3, CDialogEx)
END_MESSAGE_MAP()


// Dialog3 消息处理程序
