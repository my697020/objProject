#pragma once


// DlgSort �Ի���

class DlgSort : public CDialogEx
{
	DECLARE_DYNAMIC(DlgSort)

public:
	DlgSort(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DlgSort();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString one;
};
