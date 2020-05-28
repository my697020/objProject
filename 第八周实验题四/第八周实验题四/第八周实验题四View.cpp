
// 第八周实验题四View.cpp : C第八周实验题四View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第八周实验题四.h"
#endif

#include "第八周实验题四Doc.h"
#include "第八周实验题四View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第八周实验题四View

IMPLEMENT_DYNCREATE(C第八周实验题四View, CView)

BEGIN_MESSAGE_MAP(C第八周实验题四View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第八周实验题四View 构造/析构

C第八周实验题四View::C第八周实验题四View()
{
	// TODO: 在此处添加构造代码

}

C第八周实验题四View::~C第八周实验题四View()
{
}

BOOL C第八周实验题四View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第八周实验题四View 绘制

void C第八周实验题四View::OnDraw(CDC* pDC)
{
	C第八周实验题四Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
       
		pDC->Ellipse(200, 200, 300, 400);
		

}


// C第八周实验题四View 诊断

#ifdef _DEBUG
void C第八周实验题四View::AssertValid() const
{
	CView::AssertValid();
}

void C第八周实验题四View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第八周实验题四Doc* C第八周实验题四View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第八周实验题四Doc)));
	return (C第八周实验题四Doc*)m_pDocument;
}
#endif //_DEBUG


// C第八周实验题四View 消息处理程序


void C第八周实验题四View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第八周实验题四Doc* pDoc = GetDocument();
	CClientDC dc(this);
	CPen pen(PS_DASH,1,RGB(200,0,0));
	CPen *oldpen=dc.SelectObject(&pen);
	CBrush *p = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
	CBrush *old = dc.SelectObject(p);
	pDoc->x = point;
	CRgn r1;
	r1.CreateEllipticRgn(200, 200,300, 400);
	bool falg = r1.PtInRegion(pDoc->x);

	if (falg) { dc.Rectangle(200, 200, 300, 400);  }
	CView::OnLButtonDown(nFlags, point);
}
