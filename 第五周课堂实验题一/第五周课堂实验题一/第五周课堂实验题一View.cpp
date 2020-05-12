
// 第五周课堂实验题一View.cpp : C第五周课堂实验题一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周课堂实验题一.h"
#endif

#include "第五周课堂实验题一Doc.h"
#include "第五周课堂实验题一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周课堂实验题一View

IMPLEMENT_DYNCREATE(C第五周课堂实验题一View, CView)

BEGIN_MESSAGE_MAP(C第五周课堂实验题一View, CView)
	ON_COMMAND(ID_32771, &C第五周课堂实验题一View::On32771)
END_MESSAGE_MAP()

// C第五周课堂实验题一View 构造/析构

C第五周课堂实验题一View::C第五周课堂实验题一View()
{
	// TODO: 在此处添加构造代码

}

C第五周课堂实验题一View::~C第五周课堂实验题一View()
{
}

BOOL C第五周课堂实验题一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周课堂实验题一View 绘制

void C第五周课堂实验题一View::OnDraw(CDC* pDC)
{
	C第五周课堂实验题一Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// C第五周课堂实验题一View 诊断

#ifdef _DEBUG
void C第五周课堂实验题一View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周课堂实验题一View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周课堂实验题一Doc* C第五周课堂实验题一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周课堂实验题一Doc)));
	return (C第五周课堂实验题一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周课堂实验题一View 消息处理程序


void C第五周课堂实验题一View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	CRect tm;
	CClientDC dc(this);
	CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *pOldBrush =dc.SelectObject(pBrush);
	
	GetClientRect(&tm);
	CPoint c;
	c.x = (tm.right+tm.left) / 2;
	c.y = (tm.bottom+tm.top) / 2;
	int r = 50;
	for (int i = 0; i < 30 ; i++) {
		r += 10;
		CRect cr(c.x-r,c.y-r,c.x+r,c.y+r);
		dc.Ellipse(cr);
	
	}
	dc.SelectObject(pOldBrush);
}
