
// 第四周实验题一View.cpp : C第四周实验题一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周实验题一.h"
#endif

#include "第四周实验题一Doc.h"
#include "第四周实验题一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周实验题一View

IMPLEMENT_DYNCREATE(C第四周实验题一View, CView)

BEGIN_MESSAGE_MAP(C第四周实验题一View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C第四周实验题一View 构造/析构

C第四周实验题一View::C第四周实验题一View()
{
	// TODO: 在此处添加构造代码

}

C第四周实验题一View::~C第四周实验题一View()
{
}

BOOL C第四周实验题一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周实验题一View 绘制

void C第四周实验题一View::OnDraw(CDC* /*pDC*/)
{
	C第四周实验题一Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第四周实验题一View 诊断

#ifdef _DEBUG
void C第四周实验题一View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周实验题一View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周实验题一Doc* C第四周实验题一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周实验题一Doc)));
	return (C第四周实验题一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周实验题一View 消息处理程序


void C第四周实验题一View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周实验题一Doc* pDoc = GetDocument();
	pDoc->x = point;
	CView::OnLButtonDown(nFlags, point);
}


void C第四周实验题一View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周实验题一Doc* pDoc = GetDocument();
	CString s;
	int one = pDoc->count / pDoc->ex;
	CClientDC dc(this);
	if(point.x>pDoc->x.x)
	pDoc->ex = point.x - pDoc->x.x;
	else
	{
		pDoc->ex = pDoc->x.x - point.x;
	}
	s.Format(_T("一共移动了%d次，每%d个像素移动一次"),pDoc->count,one);
	dc.TextOutW(200,200,s);
	CView::OnLButtonUp(nFlags, point);
}


void C第四周实验题一View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周实验题一Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnMouseMove(nFlags, point);
}
