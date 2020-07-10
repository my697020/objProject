#pragma once


// DlgAdd 对话框

class DlgAdd : public CDialogEx
{
	DECLARE_DYNAMIC(DlgAdd)

public:
	DlgAdd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DlgAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString stunum;
	CString phone;
	CString major;
	CString sex;
	long birth;
	CString home;
	CString photo;
};
