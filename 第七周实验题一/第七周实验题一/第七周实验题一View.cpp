
// 第七周实验题一View.cpp : C第七周实验题一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第七周实验题一.h"
#endif

#include "第七周实验题一Doc.h"
#include "第七周实验题一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第七周实验题一View

IMPLEMENT_DYNCREATE(C第七周实验题一View, CView)

BEGIN_MESSAGE_MAP(C第七周实验题一View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第七周实验题一View 构造/析构

C第七周实验题一View::C第七周实验题一View()
{
	// TODO: 在此处添加构造代码
	flag = 0;
	r = 50;
	rc.SetRect(200 - r, 200 - r,200+r,200+r);

}

C第七周实验题一View::~C第七周实验题一View()
{
}

BOOL C第七周实验题一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第七周实验题一View 绘制

void C第七周实验题一View::OnDraw(CDC* pDC)
{
	C第七周实验题一Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(rc);
	// TODO: 在此处为本机数据添加绘制代码
}


// C第七周实验题一View 诊断

#ifdef _DEBUG
void C第七周实验题一View::AssertValid() const
{
	CView::AssertValid();
}

void C第七周实验题一View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第七周实验题一Doc* C第七周实验题一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第七周实验题一Doc)));
	return (C第七周实验题一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第七周实验题一View 消息处理程序


void C第七周实验题一View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;

	CView::OnLButtonDown(nFlags, point);
}


void C第七周实验题一View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (flag == 1) { rc.SetRect(point.x - r, point.y - r, point.x + r, point.y + r); Invalidate(); }

	CView::OnMouseMove(nFlags, point);
}


void C第七周实验题一View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 0;

	CView::OnLButtonUp(nFlags, point);
}
