
// �ڶ���������һView.h : C�ڶ���������һView ��Ľӿ�
//

#pragma once


class C�ڶ���������һView : public CView
{
protected: // �������л�����
	C�ڶ���������һView();
	DECLARE_DYNCREATE(C�ڶ���������һView)

// ����
public:
	C�ڶ���������һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�ڶ���������һView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �ڶ���������һView.cpp �еĵ��԰汾
inline C�ڶ���������һDoc* C�ڶ���������һView::GetDocument() const
   { return reinterpret_cast<C�ڶ���������һDoc*>(m_pDocument); }
#endif

