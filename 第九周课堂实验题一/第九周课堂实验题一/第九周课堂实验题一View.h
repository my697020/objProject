
// �ھ��ܿ���ʵ����һView.h : C�ھ��ܿ���ʵ����һView ��Ľӿ�
//

#pragma once


class C�ھ��ܿ���ʵ����һView : public CView
{
protected: // �������л�����
	C�ھ��ܿ���ʵ����һView();
	DECLARE_DYNCREATE(C�ھ��ܿ���ʵ����һView)

// ����
public:
	C�ھ��ܿ���ʵ����һDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�ھ��ܿ���ʵ����һView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void On32771();
};

#ifndef _DEBUG  // �ھ��ܿ���ʵ����һView.cpp �еĵ��԰汾
inline C�ھ��ܿ���ʵ����һDoc* C�ھ��ܿ���ʵ����һView::GetDocument() const
   { return reinterpret_cast<C�ھ��ܿ���ʵ����һDoc*>(m_pDocument); }
#endif

