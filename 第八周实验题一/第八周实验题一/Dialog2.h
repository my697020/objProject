#pragma once


// Dialog2 �Ի���

class Dialog2 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog2)

public:
	Dialog2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialog2();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
