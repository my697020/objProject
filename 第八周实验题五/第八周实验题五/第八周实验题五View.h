
// �ڰ���ʵ������View.h : C�ڰ���ʵ������View ��Ľӿ�
//

#pragma once


class C�ڰ���ʵ������View : public CView
{
protected: // �������л�����
	C�ڰ���ʵ������View();
	DECLARE_DYNCREATE(C�ڰ���ʵ������View)

// ����
public:
	C�ڰ���ʵ������Doc* GetDocument() const;

// ����
public:
	

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C�ڰ���ʵ������View();
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

#ifndef _DEBUG  // �ڰ���ʵ������View.cpp �еĵ��԰汾
inline C�ڰ���ʵ������Doc* C�ڰ���ʵ������View::GetDocument() const
   { return reinterpret_cast<C�ڰ���ʵ������Doc*>(m_pDocument); }
#endif

