
// �ۺ���ʵ��View.h : C�ۺ���ʵ��View ��Ľӿ�
//

#pragma once
#include "afxwin.h"

class C�ۺ���ʵ��Set;

class C�ۺ���ʵ��View : public CRecordView
{
protected: // �������л�����
	C�ۺ���ʵ��View();
	DECLARE_DYNCREATE(C�ۺ���ʵ��View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C�ۺ���ʵ��Set* m_pSet;

// ����
public:
	C�ۺ���ʵ��Doc* GetDocument() const;

// ����
public:
	CString path;

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C�ۺ���ʵ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString stunum;
	CString phone;
	CString major;
	CString sex;
	CString birth;
	CString home;
	CString photo;
	CString jar;
	void foo(CImage& image, int& x, int& y, int& wh, int& hh);
	afx_msg void OnPaint();
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnSeek();
	afx_msg void Ondelete();
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
};

#ifndef _DEBUG  // �ۺ���ʵ��View.cpp �еĵ��԰汾
inline C�ۺ���ʵ��Doc* C�ۺ���ʵ��View::GetDocument() const
   { return reinterpret_cast<C�ۺ���ʵ��Doc*>(m_pDocument); }
#endif

