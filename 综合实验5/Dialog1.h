#pragma once


// Dialog1 �Ի���

class Dialog1 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog1)

public:
	Dialog1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialog1();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void foo(CImage& image, int& x, int& y, int& wh, int& hh);
	afx_msg void OnPaint();
	
};
