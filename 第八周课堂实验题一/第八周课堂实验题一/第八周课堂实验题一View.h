
// �ڰ��ܿ���ʵ����һView.h : C�ڰ��ܿ���ʵ����һView ��Ľӿ�
//

#pragma once


class C�ڰ��ܿ���ʵ����һView : public CView
{
protected: // �������л�����
	C�ڰ��ܿ���ʵ����һView();
	DECLARE_DYNCREATE(C�ڰ��ܿ���ʵ����һView)

// ����
public:
	C�ڰ��ܿ���ʵ����һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�ڰ��ܿ���ʵ����һView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �ڰ��ܿ���ʵ����һView.cpp �еĵ��԰汾
inline C�ڰ��ܿ���ʵ����һDoc* C�ڰ��ܿ���ʵ����һView::GetDocument() const
   { return reinterpret_cast<C�ڰ��ܿ���ʵ����һDoc*>(m_pDocument); }
#endif

