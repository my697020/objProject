
// �ھ���ʵ������View.cpp : C�ھ���ʵ������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ���ʵ������.h"
#endif

#include "�ھ���ʵ������Doc.h"
#include "�ھ���ʵ������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ھ���ʵ������View

IMPLEMENT_DYNCREATE(C�ھ���ʵ������View, CView)

BEGIN_MESSAGE_MAP(C�ھ���ʵ������View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C�ھ���ʵ������View ����/����

C�ھ���ʵ������View::C�ھ���ʵ������View()
{
	// TODO: �ڴ˴���ӹ������
	flag = 0;

}

C�ھ���ʵ������View::~C�ھ���ʵ������View()
{
}

BOOL C�ھ���ʵ������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ���ʵ������View ����

void C�ھ���ʵ������View::OnDraw(CDC* pDC)
{
	C�ھ���ʵ������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->arr.GetCount(); i++)
		pDC->Ellipse(pDoc->arr.GetAt(i));
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ھ���ʵ������View ���

#ifdef _DEBUG
void C�ھ���ʵ������View::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ���ʵ������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ���ʵ������Doc* C�ھ���ʵ������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ���ʵ������Doc)));
	return (C�ھ���ʵ������Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ���ʵ������View ��Ϣ�������


void C�ھ���ʵ������View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	flag = 1;
	x = point;
	y = point;

	CView::OnLButtonDown(nFlags, point);
}


void C�ھ���ʵ������View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);

	dc.SetROP2(R2_NOT);
	dc.SelectStockObject(NULL_BRUSH);
	if (flag)   //�����Ƿ��е����ж��Ƿ���Ի�����
	{
		dc.Ellipse(CRect(x, y));
		dc.Ellipse(CRect(x, point));
		y = point;
	}

	CView::OnMouseMove(nFlags, point);
}


void C�ھ���ʵ������View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�ھ���ʵ������Doc* pDoc = GetDocument();
	flag = 0;
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	rc.SetRect(x, y);
	pDoc->arr.Add(rc);
	dc.Ellipse(CRect(x, y));


	CView::OnLButtonUp(nFlags, point);
}
