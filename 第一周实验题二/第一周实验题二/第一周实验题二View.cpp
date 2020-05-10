
// 第一周实验题二View.cpp : C第一周实验题二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第一周实验题二.h"
#endif

#include "第一周实验题二Doc.h"
#include "第一周实验题二View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第一周实验题二View

IMPLEMENT_DYNCREATE(C第一周实验题二View, CView)

BEGIN_MESSAGE_MAP(C第一周实验题二View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// C第一周实验题二View 构造/析构

C第一周实验题二View::C第一周实验题二View()
{
	// TODO: 在此处添加构造代码

}

C第一周实验题二View::~C第一周实验题二View()
{
}

BOOL C第一周实验题二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第一周实验题二View 绘制

void C第一周实验题二View::OnDraw(CDC* /*pDC*/)
{
	C第一周实验题二Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第一周实验题二View 诊断

#ifdef _DEBUG
void C第一周实验题二View::AssertValid() const
{
	CView::AssertValid();
}

void C第一周实验题二View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第一周实验题二Doc* C第一周实验题二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第一周实验题二Doc)));
	return (C第一周实验题二Doc*)m_pDocument;
}
#endif //_DEBUG


// C第一周实验题二View 消息处理程序


void C第一周实验题二View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第一周实验题二Doc* pDoc = GetDocument();
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void C第一周实验题二View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第一周实验题二Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CString c;
	c.Format(_T("%d"), pDoc->count);
	dc.TextOutW(200,200,c);

	CView::OnRButtonDown(nFlags, point);
}
