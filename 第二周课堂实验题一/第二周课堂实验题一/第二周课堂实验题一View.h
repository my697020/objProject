
// �ڶ��ܿ���ʵ����һView.h : C�ڶ��ܿ���ʵ����һView ��Ľӿ�
//

#pragma once


class C�ڶ��ܿ���ʵ����һView : public CView
{
protected: // �������л�����
	C�ڶ��ܿ���ʵ����һView();
	DECLARE_DYNCREATE(C�ڶ��ܿ���ʵ����һView)

// ����
public:
	C�ڶ��ܿ���ʵ����һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�ڶ��ܿ���ʵ����һView();
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

#ifndef _DEBUG  // �ڶ��ܿ���ʵ����һView.cpp �еĵ��԰汾
inline C�ڶ��ܿ���ʵ����һDoc* C�ڶ��ܿ���ʵ����һView::GetDocument() const
   { return reinterpret_cast<C�ڶ��ܿ���ʵ����һDoc*>(m_pDocument); }
#endif

