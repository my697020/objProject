
// 第二次试验题一View.cpp : C第二次试验题一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二次试验题一.h"
#endif

#include "第二次试验题一Doc.h"
#include "第二次试验题一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二次试验题一View

IMPLEMENT_DYNCREATE(C第二次试验题一View, CView)

BEGIN_MESSAGE_MAP(C第二次试验题一View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第二次试验题一View 构造/析构

C第二次试验题一View::C第二次试验题一View()
{
	// TODO: 在此处添加构造代码

}

C第二次试验题一View::~C第二次试验题一View()
{
}

BOOL C第二次试验题一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第二次试验题一View 绘制

void C第二次试验题一View::OnDraw(CDC* /*pDC*/)
{
	C第二次试验题一Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第二次试验题一View 诊断

#ifdef _DEBUG
void C第二次试验题一View::AssertValid() const
{
	CView::AssertValid();
}

void C第二次试验题一View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二次试验题一Doc* C第二次试验题一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二次试验题一Doc)));
	return (C第二次试验题一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二次试验题一View 消息处理程序


void C第二次试验题一View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s = _T("左键正被按下");
	dc.TextOutW(200, 100, s);
	CView::OnLButtonDown(nFlags, point);
}


void C第二次试验题一View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CString s = _T("左键正被松开");
	dc.TextOutW(200, 200, s);
	CView::OnLButtonUp(nFlags, point);
}
