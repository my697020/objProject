
// �ھ���ʵ������View.h : C�ھ���ʵ������View ��Ľӿ�
//

#pragma once


class C�ھ���ʵ������View : public CView
{
protected: // �������л�����
	C�ھ���ʵ������View();
	DECLARE_DYNCREATE(C�ھ���ʵ������View)

// ����
public:
	C�ھ���ʵ������Doc* GetDocument() const;

// ����
public:
	CPoint x;
	int flag;
	CRect rc;
	CPoint y;


// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�ھ���ʵ������View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �ھ���ʵ������View.cpp �еĵ��԰汾
inline C�ھ���ʵ������Doc* C�ھ���ʵ������View::GetDocument() const
   { return reinterpret_cast<C�ھ���ʵ������Doc*>(m_pDocument); }
#endif

