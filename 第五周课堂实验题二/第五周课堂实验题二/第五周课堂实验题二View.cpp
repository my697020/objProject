
// �����ܿ���ʵ�����View.cpp : C�����ܿ���ʵ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ���ʵ�����.h"
#endif

#include "�����ܿ���ʵ�����Doc.h"
#include "�����ܿ���ʵ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ���ʵ�����View

IMPLEMENT_DYNCREATE(C�����ܿ���ʵ�����View, CView)

BEGIN_MESSAGE_MAP(C�����ܿ���ʵ�����View, CView)
	ON_COMMAND(ID_32771, &C�����ܿ���ʵ�����View::On32771)
END_MESSAGE_MAP()

// C�����ܿ���ʵ�����View ����/����

C�����ܿ���ʵ�����View::C�����ܿ���ʵ�����View()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ܿ���ʵ�����View::~C�����ܿ���ʵ�����View()
{
}

BOOL C�����ܿ���ʵ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ���ʵ�����View ����

void C�����ܿ���ʵ�����View::OnDraw(CDC* /*pDC*/)
{
	C�����ܿ���ʵ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�����ܿ���ʵ�����View ���

#ifdef _DEBUG
void C�����ܿ���ʵ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ���ʵ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ���ʵ�����Doc* C�����ܿ���ʵ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ���ʵ�����Doc)));
	return (C�����ܿ���ʵ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ���ʵ�����View ��Ϣ�������


void C�����ܿ���ʵ�����View::On32771()
{
	// TODO: �ڴ���������������
	CRect tm;
	CClientDC dc(this);
	
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush = dc.SelectObject(pBrush);

	GetClientRect(&tm);
	CPoint c;
	c.x = (tm.right + tm.left) / 2;
	c.y = (tm.bottom + tm.top) / 2;
	int r = 50;
	for (int i = 0; i < 30; i++) {
		r += 10;
		CRect cr(c.x - r, c.y - r, c.x + r, c.y + r);
		int color = RGB(200,100+5*i,10+8*i);
		CPen newpen(PS_SOLID,2,color);
		CPen *oldpen = dc.SelectObject(&newpen);
		dc.Ellipse(cr);

	}
	dc.SelectObject(pOldBrush);
}
