
// �ڶ���������һView.cpp : C�ڶ���������һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ���������һ.h"
#endif

#include "�ڶ���������һDoc.h"
#include "�ڶ���������һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڶ���������һView

IMPLEMENT_DYNCREATE(C�ڶ���������һView, CView)

BEGIN_MESSAGE_MAP(C�ڶ���������һView, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C�ڶ���������һView ����/����

C�ڶ���������һView::C�ڶ���������һView()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڶ���������һView::~C�ڶ���������һView()
{
}

BOOL C�ڶ���������һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڶ���������һView ����

void C�ڶ���������һView::OnDraw(CDC* /*pDC*/)
{
	C�ڶ���������һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڶ���������һView ���

#ifdef _DEBUG
void C�ڶ���������һView::AssertValid() const
{
	CView::AssertValid();
}

void C�ڶ���������һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڶ���������һDoc* C�ڶ���������һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڶ���������һDoc)));
	return (C�ڶ���������һDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ڶ���������һView ��Ϣ�������


void C�ڶ���������һView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s = _T("�����������");
	dc.TextOutW(200, 100, s);
	CView::OnLButtonDown(nFlags, point);
}


void C�ڶ���������һView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	CString s = _T("��������ɿ�");
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
