
// 第二周实验第三题View.cpp : C第二周实验第三题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第二周实验第三题.h"
#endif

#include "第二周实验第三题Doc.h"
#include "第二周实验第三题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第二周实验第三题View

IMPLEMENT_DYNCREATE(C第二周实验第三题View, CView)

BEGIN_MESSAGE_MAP(C第二周实验第三题View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第二周实验第三题View 构造/析构

C第二周实验第三题View::C第二周实验第三题View()
{
	// TODO: 在此处添加构造代码

}

C第二周实验第三题View::~C第二周实验第三题View()
{
}

BOOL C第二周实验第三题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第二周实验第三题View 绘制

void C第二周实验第三题View::OnDraw(CDC* pDC)
{
	C第二周实验第三题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->A);
	pDC->Rectangle(pDoc->B);
	pDC->Rectangle(pDoc->C);


	// TODO: 在此处为本机数据添加绘制代码
}


// C第二周实验第三题View 诊断

#ifdef _DEBUG
void C第二周实验第三题View::AssertValid() const
{
	CView::AssertValid();
}

void C第二周实验第三题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第二周实验第三题Doc* C第二周实验第三题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第二周实验第三题Doc)));
	return (C第二周实验第三题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第二周实验第三题View 消息处理程序


void C第二周实验第三题View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第二周实验第三题Doc* pDoc = GetDocument();
	CClientDC dc(this);
	
	CString s;

	if (pDoc->A.PtInRect(point))
	{   pDoc->a= rand()+1;
	 pDoc->c = 1;
		s.Format(_T("%d"), pDoc->a);
		dc.TextOutW(100, 100,s );
	}
	if (pDoc->B.PtInRect(point))
	{
		pDoc->b= rand()+1;
		pDoc->d = 1;
		s.Format(_T("%d"), pDoc->b);
		dc.TextOutW(300, 100, s);
	}
	if (pDoc->c==1&& pDoc->d==1)
	{
		pDoc->sum = pDoc->a + pDoc->b;
		s.Format(_T("%d"), pDoc->sum);
		dc.TextOutW(500,100,s);
		
	}
	if ((!pDoc->c||!pDoc->d)&&(!pDoc->A.PtInRect(point)||! pDoc->B.PtInRect(point)))
		{
			s = "点击无效";
			dc.TextOutW(300, 300,s);
		}
	CView::OnLButtonDown(nFlags, point);
}
