
// ������ʵ��ڶ���View.h : C������ʵ��ڶ���View ��Ľӿ�
//

#pragma once


class C������ʵ��ڶ���View : public CView
{
protected: // �������л�����
	C������ʵ��ڶ���View();
	DECLARE_DYNCREATE(C������ʵ��ڶ���View)

// ����
public:
	C������ʵ��ڶ���Doc* GetDocument() const;

// ����
public:
	CBitmap m_Bitmap;

	int m_nWidth;

	int m_nHeight;

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~C������ʵ��ڶ���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ������ʵ��ڶ���View.cpp �еĵ��԰汾
inline C������ʵ��ڶ���Doc* C������ʵ��ڶ���View::GetDocument() const
   { return reinterpret_cast<C������ʵ��ڶ���Doc*>(m_pDocument); }
#endif

