#pragma once


// Dialog3 �Ի���

class Dialog3 : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog3)

public:
	Dialog3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dialog3();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
