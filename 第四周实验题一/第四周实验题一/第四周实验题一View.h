
// ������ʵ����һView.h : C������ʵ����һView ��Ľӿ�
//

#pragma once


class C������ʵ����һView : public CView
{
protected: // �������л�����
	C������ʵ����һView();
	DECLARE_DYNCREATE(C������ʵ����һView)

// ����
public:
	C������ʵ����һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C������ʵ����һView();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ������ʵ����һView.cpp �еĵ��԰汾
inline C������ʵ����һDoc* C������ʵ����һView::GetDocument() const
   { return reinterpret_cast<C������ʵ����һDoc*>(m_pDocument); }
#endif

