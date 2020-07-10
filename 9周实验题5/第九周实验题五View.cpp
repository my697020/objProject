
// 第九周实验题五View.cpp : C第九周实验题五View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第九周实验题五.h"
#endif

#include "第九周实验题五Doc.h"
#include "第九周实验题五View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第九周实验题五View

IMPLEMENT_DYNCREATE(C第九周实验题五View, CView)

BEGIN_MESSAGE_MAP(C第九周实验题五View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C第九周实验题五View 构造/析构

C第九周实验题五View::C第九周实验题五View()
{
	// TODO: 在此处添加构造代码
	flag = 0;

}

C第九周实验题五View::~C第九周实验题五View()
{
}

BOOL C第九周实验题五View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第九周实验题五View 绘制

void C第九周实验题五View::OnDraw(CDC* pDC)
{
	C第九周实验题五Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->arr.GetCount(); i++)
		pDC->Ellipse(pDoc->arr.GetAt(i));
	// TODO: 在此处为本机数据添加绘制代码
}


// C第九周实验题五View 诊断

#ifdef _DEBUG
void C第九周实验题五View::AssertValid() const
{
	CView::AssertValid();
}

void C第九周实验题五View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第九周实验题五Doc* C第九周实验题五View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第九周实验题五Doc)));
	return (C第九周实验题五Doc*)m_pDocument;
}
#endif //_DEBUG


// C第九周实验题五View 消息处理程序


void C第九周实验题五View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	flag = 1;
	x = point;
	y = point;

	CView::OnLButtonDown(nFlags, point);
}


void C第九周实验题五View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	dc.SetROP2(R2_NOT);
	dc.SelectStockObject(NULL_BRUSH);
	if (flag)   //根据是否有单击判断是否可以画矩形
	{
		dc.Ellipse(CRect(x, y));
		dc.Ellipse(CRect(x, point));
		y = point;
	}

	CView::OnMouseMove(nFlags, point);
}


void C第九周实验题五View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第九周实验题五Doc* pDoc = GetDocument();
	flag = 0;
	CClientDC dc(this);
	dc.SelectStockObject(NULL_BRUSH);
	rc.SetRect(x, y);
	pDoc->arr.Add(rc);
	dc.Ellipse(CRect(x, y));


	CView::OnLButtonUp(nFlags, point);
}
