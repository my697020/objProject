
// �����ܵڶ���View.h : C�����ܵڶ���View ��Ľӿ�
//

#pragma once


class C�����ܵڶ���View : public CView
{
protected: // �������л�����
	C�����ܵڶ���View();
	DECLARE_DYNCREATE(C�����ܵڶ���View)

// ����
public:
	C�����ܵڶ���Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�����ܵڶ���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // �����ܵڶ���View.cpp �еĵ��԰汾
inline C�����ܵڶ���Doc* C�����ܵڶ���View::GetDocument() const
   { return reinterpret_cast<C�����ܵڶ���Doc*>(m_pDocument); }
#endif

