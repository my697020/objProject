
// 第九周实验题二Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C第九周实验题二Dlg 对话框
class C第九周实验题二Dlg : public CDialogEx
{
// 构造
public:
	C第九周实验题二Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox md;
	CString txt;
	CEdit m_edit;
	afx_msg void OnLbnSelchangeList1();
};
