
// ��һ��ʵ�����View.cpp : C��һ��ʵ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��һ��ʵ�����.h"
#endif

#include "��һ��ʵ�����Doc.h"
#include "��һ��ʵ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��һ��ʵ�����View

IMPLEMENT_DYNCREATE(C��һ��ʵ�����View, CView)

BEGIN_MESSAGE_MAP(C��һ��ʵ�����View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C��һ��ʵ�����View ����/����

C��һ��ʵ�����View::C��һ��ʵ�����View()
{
	// TODO: �ڴ˴���ӹ������

}

C��һ��ʵ�����View::~C��һ��ʵ�����View()
{
}

BOOL C��һ��ʵ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��һ��ʵ�����View ����

void C��һ��ʵ�����View::OnDraw(CDC* /*pDC*/)
{
	C��һ��ʵ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��һ��ʵ�����View ���

#ifdef _DEBUG
void C��һ��ʵ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C��һ��ʵ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��һ��ʵ�����Doc* C��һ��ʵ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��һ��ʵ�����Doc)));
	return (C��һ��ʵ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C��һ��ʵ�����View ��Ϣ�������


void C��һ��ʵ�����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��һ��ʵ�����Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void C��һ��ʵ�����View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C��һ��ʵ�����Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString c;
	c.Format(_T("%d"), pDoc->count);
	dc.TextOutW(200,200,c);

	CView::OnRButtonDown(nFlags, point);
}
