
// �ڶ���ʵ�������View.cpp : C�ڶ���ʵ�������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���ʵ�������.h"
#endif

#include "�ڶ���ʵ�������Doc.h"
#include "�ڶ���ʵ�������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���ʵ�������View

IMPLEMENT_DYNCREATE(C�ڶ���ʵ�������View, CView)

BEGIN_MESSAGE_MAP(C�ڶ���ʵ�������View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C�ڶ���ʵ�������View ����/����

C�ڶ���ʵ�������View::C�ڶ���ʵ�������View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڶ���ʵ�������View::~C�ڶ���ʵ�������View()
{
}

BOOL C�ڶ���ʵ�������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ���ʵ�������View ����

void C�ڶ���ʵ�������View::OnDraw(CDC* pDC)
{
	C�ڶ���ʵ�������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);


	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڶ���ʵ�������View ���

#ifdef _DEBUG
void C�ڶ���ʵ�������View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���ʵ�������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���ʵ�������Doc* C�ڶ���ʵ�������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���ʵ�������Doc)));
	return (C�ڶ���ʵ�������Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���ʵ�������View ��Ϣ�������


void C�ڶ���ʵ�������View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�ڶ���ʵ�������Doc* pDoc = GetDocument();
	CClientDC dc(this);
	
	CString s;

	if (pDoc->A.PtInRect(point))
	{   pDoc->a= rand()+1;
	 pDoc->c = 1;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(100, 100,s );
	}
	if (pDoc->B.PtInRect(point))
	{
		pDoc->b= rand()+1;
		pDoc->d = 1;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(300, 100, s);
	}
	if (pDoc->c==1&& pDoc->d==1)
	{
		pDoc->sum = pDoc->a + pDoc->b;
		s.Format(_T("%d"), pDoc->sum);
		dc.TextOutW(500,100,s);
		
	}
	if ((!pDoc->c||!pDoc->d)&&(!pDoc->A.PtInRect(point)||! pDoc->B.PtInRect(point)))
		{
			s = "�����Ч";
			dc.TextOutW(300, 300,s);
		}
	CView::OnLButtonDown(nFlags, point);
}
