#pragma once


// Dialog3 对话框

class Dialog3 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog3)

public:
	Dialog3(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~Dialog3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
