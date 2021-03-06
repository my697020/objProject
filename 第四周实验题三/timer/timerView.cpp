
// timerView.cpp : CtimerView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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

// CtimerView 构造/析构

CtimerView::CtimerView()
{
	// TODO: 在此处添加构造代码
	rc.left = 200; rc.top = 0;
	rc.bottom = 200; rc.right = 400;
	flag = 0;
}

CtimerView::~CtimerView()
{
}

BOOL CtimerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CtimerView 绘制

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
	// TODO: 在此处为本机数据添加绘制代码
}


// CtimerView 诊断

#ifdef _DEBUG
void CtimerView::AssertValid() const
{
	CView::AssertValid();
}

void CtimerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CtimerDoc* CtimerView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CtimerDoc)));
	return (CtimerDoc*)m_pDocument;
}
#endif //_DEBUG


// CtimerView 消息处理程序


void CtimerView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
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
