
// ������ʵ����һView.cpp : C������ʵ����һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ����һ.h"
#endif

#include "������ʵ����һDoc.h"
#include "������ʵ����һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ����һView

IMPLEMENT_DYNCREATE(C������ʵ����һView, CView)

BEGIN_MESSAGE_MAP(C������ʵ����һView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C������ʵ����һView ����/����

C������ʵ����һView::C������ʵ����һView()
{
	// TODO: �ڴ˴���ӹ������
	flag = 0;
	r = 50;
	rc.SetRect(200 - r, 200 - r,200+r,200+r);

}

C������ʵ����һView::~C������ʵ����һView()
{
}

BOOL C������ʵ����һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ����һView ����

void C������ʵ����һView::OnDraw(CDC* pDC)
{
	C������ʵ����һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(rc);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ����һView ���

#ifdef _DEBUG
void C������ʵ����һView::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ����һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ����һDoc* C������ʵ����һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ����һDoc)));
	return (C������ʵ����һDoc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ����һView ��Ϣ�������


void C������ʵ����һView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;

	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ����һView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (flag == 1) { rc.SetRect(point.x - r, point.y - r, point.x + r, point.y + r); Invalidate(); }

	CView::OnMouseMove(nFlags, point);
}


void C������ʵ����һView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 0;

	CView::OnLButtonUp(nFlags, point);
}
