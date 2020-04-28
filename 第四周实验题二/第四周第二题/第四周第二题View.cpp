
// �����ܵڶ���View.cpp : C�����ܵڶ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܵڶ���.h"
#endif

#include "�����ܵڶ���Doc.h"
#include "�����ܵڶ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܵڶ���View

IMPLEMENT_DYNCREATE(C�����ܵڶ���View, CView)

BEGIN_MESSAGE_MAP(C�����ܵڶ���View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C�����ܵڶ���View ����/����

C�����ܵڶ���View::C�����ܵڶ���View()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ܵڶ���View::~C�����ܵڶ���View()
{
}

BOOL C�����ܵڶ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܵڶ���View ����

void C�����ܵڶ���View::OnDraw(CDC* pDC)
{
	C�����ܵڶ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rc);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�����ܵڶ���View ���

#ifdef _DEBUG
void C�����ܵڶ���View::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܵڶ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܵڶ���Doc* C�����ܵڶ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܵڶ���Doc)));
	return (C�����ܵڶ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܵڶ���View ��Ϣ�������


void C�����ܵڶ���View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�����ܵڶ���Doc* pDoc = GetDocument();
	CRect client;
	GetClientRect(&client);
	switch (nChar)
	{ 
	case VK_LEFT:
		if (pDoc->rc.left>client.left)
		{
			pDoc->rc.left -= 5;
			pDoc->rc.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->rc.right<(client.right-client.left))
		{
			pDoc->rc.right += 5;
			pDoc->rc.left += 5;
		}
		break;
	case VK_UP:
		if (pDoc->rc.top>client.top)
		{
			pDoc->rc.top -= 5;
			pDoc->rc.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->rc.bottom<client.bottom)
		{
			pDoc->rc.bottom += 5;
			pDoc->rc.top += 5;
		}
		break;
	case VK_HOME:
		if ((pDoc->rc.left>client.left)&&(pDoc->rc.top>client.top))
		{
			pDoc->rc.top -= 5;
			pDoc->rc.left -= 5;
		}break;
	case VK_END:
		if ((pDoc->rc.right>pDoc->rc.left) && (pDoc->rc.top<pDoc->rc.bottom))
		{
			pDoc->rc.right -= 5;
			pDoc->rc.bottom -= 5;
		}break;

	}
	
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void C�����ܵڶ���View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�����ܵڶ���Doc* pDoc = GetDocument();
	pDoc->rc.left = 200; pDoc->rc.top = 200;
	pDoc->rc.right = 400; pDoc->rc.bottom = 400;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
