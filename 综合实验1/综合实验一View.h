
// �ۺ�ʵ��һView.h : C�ۺ�ʵ��һView ��Ľӿ�
//

#pragma once

class C�ۺ�ʵ��һSet;

class C�ۺ�ʵ��һView : public CRecordView
{
protected: // �������л�����
	C�ۺ�ʵ��һView();
	DECLARE_DYNCREATE(C�ۺ�ʵ��һView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MY_FORM };
#endif
	C�ۺ�ʵ��һSet* m_pSet;

// ����
public:
	C�ۺ�ʵ��һDoc* GetDocument() const;
	CString path;

// ����
public:

// ��д
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C�ۺ�ʵ��һView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	void foo(CImage& image, int& x, int& y, int& wh, int& hh);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordLast();
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // �ۺ�ʵ��һView.cpp �еĵ��԰汾
inline C�ۺ�ʵ��һDoc* C�ۺ�ʵ��һView::GetDocument() const
   { return reinterpret_cast<C�ۺ�ʵ��һDoc*>(m_pDocument); }
#endif

