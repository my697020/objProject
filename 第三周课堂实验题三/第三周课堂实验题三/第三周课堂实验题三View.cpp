
// 第三周课堂实验题三View.cpp : C第三周课堂实验题三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第三周课堂实验题三.h"
#endif

#include "第三周课堂实验题三Doc.h"
#include "第三周课堂实验题三View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第三周课堂实验题三View

IMPLEMENT_DYNCREATE(C第三周课堂实验题三View, CView)

BEGIN_MESSAGE_MAP(C第三周课堂实验题三View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第三周课堂实验题三View 构造/析构

C第三周课堂实验题三View::C第三周课堂实验题三View()
{
	// TODO: 在此处添加构造代码

}

C第三周课堂实验题三View::~C第三周课堂实验题三View()
{
}

BOOL C第三周课堂实验题三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第三周课堂实验题三View 绘制

void C第三周课堂实验题三View::OnDraw(CDC* pDC)
{
	C第三周课堂实验题三Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	for (int i = 0; i < pDoc->array.GetSize(); i++)
		pDC->Ellipse(pDoc->array.GetAt(i));

	// TODO: 在此处为本机数据添加绘制代码
}


// C第三周课堂实验题三View 诊断

#ifdef _DEBUG
void C第三周课堂实验题三View::AssertValid() const
{
	CView::AssertValid();
}

void C第三周课堂实验题三View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第三周课堂实验题三Doc* C第三周课堂实验题三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第三周课堂实验题三Doc)));
	return (C第三周课堂实验题三Doc*)m_pDocument;
}
#endif //_DEBUG


// C第三周课堂实验题三View 消息处理程序


void C第三周课堂实验题三View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第三周课堂实验题三Doc* pDoc = GetDocument();
	int r1 = rand() % 100 + 1;
	int r2 = rand() % 100 + 1;
	CRect cr(point.x - r1, point.y - r2, point.x + r1, point.y + r2);
	pDoc->array.Add(cr);
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
