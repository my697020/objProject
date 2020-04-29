
// 第六周实验题一View.cpp : C第六周实验题一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第六周实验题一.h"
#endif

#include "第六周实验题一Doc.h"
#include "第六周实验题一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第六周实验题一View

IMPLEMENT_DYNCREATE(C第六周实验题一View, CView)

BEGIN_MESSAGE_MAP(C第六周实验题一View, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C第六周实验题一View 构造/析构

C第六周实验题一View::C第六周实验题一View()
{
	// TODO: 在此处添加构造代码
	line = "";

	rc.left = 200;
	rc.top = 200;
	rc.bottom = 250;
	rc.right = 800;
}

C第六周实验题一View::~C第六周实验题一View()
{
}

BOOL C第六周实验题一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第六周实验题一View 绘制

void C第六周实验题一View::OnDraw(CDC* pDC)
{
	C第六周实验题一Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(rc);

	// TODO: 在此处为本机数据添加绘制代码
}


// C第六周实验题一View 诊断

#ifdef _DEBUG
void C第六周实验题一View::AssertValid() const
{
	CView::AssertValid();
}

void C第六周实验题一View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第六周实验题一Doc* C第六周实验题一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第六周实验题一Doc)));
	return (C第六周实验题一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第六周实验题一View 消息处理程序


void C第六周实验题一View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	line.AppendChar(nChar);
	 c= dc.GetTextExtent(line);
	if (c.cx<(rc.right-rc.left))
	dc.TextOutW(201,225,line);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
