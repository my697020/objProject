
// ��һ��ʵ�����View.h : C��һ��ʵ�����View ��Ľӿ�
//

#pragma once


class C��һ��ʵ�����View : public CView
{
protected: // �������л�����
	C��һ��ʵ�����View();
	DECLARE_DYNCREATE(C��һ��ʵ�����View)

// ����
public:
	C��һ��ʵ�����Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C��һ��ʵ�����View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��һ��ʵ�����View.cpp �еĵ��԰汾
inline C��һ��ʵ�����Doc* C��һ��ʵ�����View::GetDocument() const
   { return reinterpret_cast<C��һ��ʵ�����Doc*>(m_pDocument); }
#endif

