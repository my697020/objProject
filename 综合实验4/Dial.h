#pragma once


// Dial �Ի���

class Dial : public CDialogEx
{
	DECLARE_DYNAMIC(Dial)

public:
	Dial(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dial();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString s;
};
