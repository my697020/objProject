
// �ڶ��ܿ���ʵ�����View.cpp : C�ڶ��ܿ���ʵ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ��ܿ���ʵ�����.h"
#endif

#include "�ڶ��ܿ���ʵ�����Doc.h"
#include "�ڶ��ܿ���ʵ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ��ܿ���ʵ�����View

IMPLEMENT_DYNCREATE(C�ڶ��ܿ���ʵ�����View, CView)

BEGIN_MESSAGE_MAP(C�ڶ��ܿ���ʵ�����View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C�ڶ��ܿ���ʵ�����View ����/����

C�ڶ��ܿ���ʵ�����View::C�ڶ��ܿ���ʵ�����View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڶ��ܿ���ʵ�����View::~C�ڶ��ܿ���ʵ�����View()
{
}

BOOL C�ڶ��ܿ���ʵ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ��ܿ���ʵ�����View ����

void C�ڶ��ܿ���ʵ�����View::OnDraw(CDC* pDC)
{
	C�ڶ��ܿ���ʵ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(pDoc->rc);
	

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڶ��ܿ���ʵ�����View ���

#ifdef _DEBUG
void C�ڶ��ܿ���ʵ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ��ܿ���ʵ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ��ܿ���ʵ�����Doc* C�ڶ��ܿ���ʵ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ��ܿ���ʵ�����Doc)));
	return (C�ڶ��ܿ���ʵ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ��ܿ���ʵ�����View ��Ϣ�������


void C�ڶ��ܿ���ʵ�����View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�ڶ��ܿ���ʵ�����Doc* pDoc = GetDocument();
	int r = rand() % 100 + 10;
	pDoc->rc.SetRect(point.x - r, point.y - r, point.x + r, point.y + r);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
