
// �����ܿ���ʵ����һView.cpp : C�����ܿ���ʵ����һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ���ʵ����һ.h"
#endif

#include "�����ܿ���ʵ����һDoc.h"
#include "�����ܿ���ʵ����һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ���ʵ����һView

IMPLEMENT_DYNCREATE(C�����ܿ���ʵ����һView, CView)

BEGIN_MESSAGE_MAP(C�����ܿ���ʵ����һView, CView)
	ON_COMMAND(ID_32771, &C�����ܿ���ʵ����һView::On32771)
END_MESSAGE_MAP()

// C�����ܿ���ʵ����һView ����/����

C�����ܿ���ʵ����һView::C�����ܿ���ʵ����һView()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ܿ���ʵ����һView::~C�����ܿ���ʵ����һView()
{
}

BOOL C�����ܿ���ʵ����һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ���ʵ����һView ����

void C�����ܿ���ʵ����һView::OnDraw(CDC* pDC)
{
	C�����ܿ���ʵ����һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�����ܿ���ʵ����һView ���

#ifdef _DEBUG
void C�����ܿ���ʵ����һView::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ���ʵ����һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ���ʵ����һDoc* C�����ܿ���ʵ����һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ���ʵ����һDoc)));
	return (C�����ܿ���ʵ����һDoc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ���ʵ����һView ��Ϣ�������


void C�����ܿ���ʵ����һView::On32771()
{
	// TODO: �ڴ���������������
	CRect tm;
	CClientDC dc(this);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush =dc.SelectObject(pBrush);
	
	GetClientRect(&tm);
	CPoint c;
	c.x = (tm.right+tm.left) / 2;
	c.y = (tm.bottom+tm.top) / 2;
	int r = 50;
	for (int i = 0; i < 30 ; i++) {
		r += 10;
		CRect cr(c.x-r,c.y-r,c.x+r,c.y+r);
		dc.Ellipse(cr);
	
	}
	dc.SelectObject(pOldBrush);
}
