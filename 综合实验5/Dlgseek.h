#pragma once


// Dlgseek �Ի���

class Dlgseek : public CDialogEx
{
	DECLARE_DYNAMIC(Dlgseek)

public:
	Dlgseek(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~Dlgseek();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString seek;
};
