
// ��һ��ʵ����һView.h : C��һ��ʵ����һView ��Ľӿ�
//

#pragma once


class C��һ��ʵ����һView : public CView
{
protected: // �������л�����
	C��һ��ʵ����һView();
	DECLARE_DYNCREATE(C��һ��ʵ����һView)

// ����
public:
	C��һ��ʵ����һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��һ��ʵ����һView();
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
};

#ifndef _DEBUG  // ��һ��ʵ����һView.cpp �еĵ��԰汾
inline C��һ��ʵ����һDoc* C��һ��ʵ����һView::GetDocument() const
   { return reinterpret_cast<C��һ��ʵ����һDoc*>(m_pDocument); }
#endif

