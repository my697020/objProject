
// timerView.cpp : CtimerView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "timer.h"
#endif

#include "timerDoc.h"
#include "timerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtimerView

IMPLEMENT_DYNCREATE(CtimerView, CView)

BEGIN_MESSAGE_MAP(CtimerView, CView)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CtimerView ����/����

CtimerView::CtimerView()
{
	// TODO: �ڴ˴���ӹ������
	rc.left = 200; rc.top = 0;
	rc.bottom = 200; rc.right = 400;
	flag = 0;
}

CtimerView::~CtimerView()
{
}

BOOL CtimerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CtimerView ����

void CtimerView::OnDraw(CDC* pDC)
{
	CtimerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Ellipse(&rc);
	if (pDoc->set) 
	{   
		SetTimer(1,100,NULL);
		pDoc->set = false;
	}
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CtimerView ���

#ifdef _DEBUG
void CtimerView::AssertValid() const
{
	CView::AssertValid();
}

void CtimerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtimerDoc* CtimerView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtimerDoc)));
	return (CtimerDoc*)m_pDocument;
}
#endif //_DEBUG


// CtimerView ��Ϣ�������


void CtimerView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect r;
	GetClientRect(&r);
	if (rc.bottom < r.bottom && !flag) {
		rc.bottom += 5;
		rc.top += 5;
		Invalidate();
	}
	else if (rc.bottom >= r.bottom) {
		flag = 1;
	}
	if (flag&&rc.top > r.top) {
		rc.bottom -= 5;
		rc.top -= 5;
		Invalidate();
	}
	
	CView::OnTimer(nIDEvent);
}
