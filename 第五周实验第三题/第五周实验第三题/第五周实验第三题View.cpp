
// ������ʵ�������View.cpp : C������ʵ�������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ�������.h"
#endif

#include "������ʵ�������Doc.h"
#include "������ʵ�������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ�������View

IMPLEMENT_DYNCREATE(C������ʵ�������View, CView)

BEGIN_MESSAGE_MAP(C������ʵ�������View, CView)
	ON_COMMAND(ID_32771, &C������ʵ�������View::On32771)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	
	ON_COMMAND(ID_32774, &C������ʵ�������View::On32774)
	ON_COMMAND(ID_32775, &C������ʵ�������View::On32775)
END_MESSAGE_MAP()

// C������ʵ�������View ����/����

C������ʵ�������View::C������ʵ�������View()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʵ�������View::~C������ʵ�������View()
{
}

BOOL C������ʵ�������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ�������View ����

void C������ʵ�������View::OnDraw(CDC* pDC)
{
	C������ʵ�������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ�������View ���

#ifdef _DEBUG
void C������ʵ�������View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ�������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ�������Doc* C������ʵ�������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ�������Doc)));
	return (C������ʵ�������Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ�������View ��Ϣ�������


void C������ʵ�������View::On32771()
{
	// TODO: �ڴ���������������
	C������ʵ�������Doc* pDoc = GetDocument();
	pDoc->flag = 1;
	
}


void C������ʵ�������View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ�������Doc* pDoc = GetDocument();
	pDoc->x = point;
	CView::OnLButtonDown(nFlags, point);
}


void C������ʵ�������View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C������ʵ�������Doc* pDoc = GetDocument();
	pDoc->y = point;
	CClientDC dc(this);
	int red = 10;
	int green = 10;
	int blue = 200;
	int width = 2;
	int color = RGB(red, green, blue);
	CPen newpen(PS_SOLID, width, color);
	CPen *oldpen = dc.SelectObject(&newpen);
	if (pDoc->flag == 1)
	{
		dc.MoveTo(pDoc->x.x, pDoc->x.y);
		dc.LineTo(pDoc->y.x, pDoc->y.y);
	} 
	if (pDoc->flag == 2) {
		a.SetRect(pDoc->x, pDoc->y);
		dc.Rectangle(&a);
		
	}
	if (pDoc->flag == 3) {

		a.SetRect(pDoc->x, pDoc->y);
		dc.Ellipse(a);
	}
	CView::OnLButtonUp(nFlags, point);
}





void C������ʵ�������View::On32774()
{
	// TODO: �ڴ���������������
	C������ʵ�������Doc* pDoc = GetDocument();
	pDoc->flag = 2;
}


void C������ʵ�������View::On32775()
{
	// TODO: �ڴ���������������
	C������ʵ�������Doc* pDoc = GetDocument();
	pDoc->flag =3;
}
