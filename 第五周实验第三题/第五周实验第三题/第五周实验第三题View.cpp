
// 第五周实验第三题View.cpp : C第五周实验第三题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验第三题.h"
#endif

#include "第五周实验第三题Doc.h"
#include "第五周实验第三题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验第三题View

IMPLEMENT_DYNCREATE(C第五周实验第三题View, CView)

BEGIN_MESSAGE_MAP(C第五周实验第三题View, CView)
	ON_COMMAND(ID_32771, &C第五周实验第三题View::On32771)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	
	ON_COMMAND(ID_32774, &C第五周实验第三题View::On32774)
	ON_COMMAND(ID_32775, &C第五周实验第三题View::On32775)
END_MESSAGE_MAP()

// C第五周实验第三题View 构造/析构

C第五周实验第三题View::C第五周实验第三题View()
{
	// TODO: 在此处添加构造代码

}

C第五周实验第三题View::~C第五周实验第三题View()
{
}

BOOL C第五周实验第三题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验第三题View 绘制

void C第五周实验第三题View::OnDraw(CDC* pDC)
{
	C第五周实验第三题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// C第五周实验第三题View 诊断

#ifdef _DEBUG
void C第五周实验第三题View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验第三题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验第三题Doc* C第五周实验第三题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验第三题Doc)));
	return (C第五周实验第三题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验第三题View 消息处理程序


void C第五周实验第三题View::On32771()
{
	// TODO: 在此添加命令处理程序代码
	C第五周实验第三题Doc* pDoc = GetDocument();
	pDoc->flag = 1;
	
}


void C第五周实验第三题View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第五周实验第三题Doc* pDoc = GetDocument();
	pDoc->x = point;
	CView::OnLButtonDown(nFlags, point);
}


void C第五周实验第三题View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第五周实验第三题Doc* pDoc = GetDocument();
	pDoc->y = point;
	CClientDC dc(this);
	int red = 10;
	int green = 10;
	int blue = 200;
	int width = 2;
	int color = RGB(red, green, blue);
	CPen newpen(PS_SOLID, width, color);
	CPen *oldpen = dc.SelectObject(&newpen);
	if (pDoc->flag == 1)
	{
		dc.MoveTo(pDoc->x.x, pDoc->x.y);
		dc.LineTo(pDoc->y.x, pDoc->y.y);
	} 
	if (pDoc->flag == 2) {
		a.SetRect(pDoc->x, pDoc->y);
		dc.Rectangle(&a);
		
	}
	if (pDoc->flag == 3) {

		a.SetRect(pDoc->x, pDoc->y);
		dc.Ellipse(a);
	}
	CView::OnLButtonUp(nFlags, point);
}





void C第五周实验第三题View::On32774()
{
	// TODO: 在此添加命令处理程序代码
	C第五周实验第三题Doc* pDoc = GetDocument();
	pDoc->flag = 2;
}


void C第五周实验第三题View::On32775()
{
	// TODO: 在此添加命令处理程序代码
	C第五周实验第三题Doc* pDoc = GetDocument();
	pDoc->flag =3;
}
