
// ������ʵ���һ��View.h : C������ʵ���һ��View ��Ľӿ�
//

#pragma once


class C������ʵ���һ��View : public CView
{
protected: // �������л�����
	C������ʵ���һ��View();
	DECLARE_DYNCREATE(C������ʵ���һ��View)

// ����
public:
	C������ʵ���һ��Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C������ʵ���һ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void Onone();
};

#ifndef _DEBUG  // ������ʵ���һ��View.cpp �еĵ��԰汾
inline C������ʵ���һ��Doc* C������ʵ���һ��View::GetDocument() const
   { return reinterpret_cast<C������ʵ���һ��Doc*>(m_pDocument); }
#endif

