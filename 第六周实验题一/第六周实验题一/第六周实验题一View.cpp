
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
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C������ʵ����һView ����/����

C������ʵ����һView::C������ʵ����һView()
{
	// TODO: �ڴ˴���ӹ������
	line = "";

	rc.left = 200;
	rc.top = 200;
	rc.bottom = 250;
	rc.right = 800;
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


void C������ʵ����һView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	line.AppendChar(nChar);
	 c= dc.GetTextExtent(line);
	if (c.cx<(rc.right-rc.left))
	dc.TextOutW(201,225,line);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
