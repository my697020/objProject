
// usinglibdllView.h : CusinglibdllView ��Ľӿ�
//

#pragma once


class CusinglibdllView : public CView
{
protected: // �������л�����
	CusinglibdllView();
	DECLARE_DYNCREATE(CusinglibdllView)

// ����
public:
	CusinglibdllDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CusinglibdllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // usinglibdllView.cpp �еĵ��԰汾
inline CusinglibdllDoc* CusinglibdllView::GetDocument() const
   { return reinterpret_cast<CusinglibdllDoc*>(m_pDocument); }
#endif

