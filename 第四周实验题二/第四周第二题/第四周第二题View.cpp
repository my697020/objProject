
// 第四周第二题View.cpp : C第四周第二题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第四周第二题.h"
#endif

#include "第四周第二题Doc.h"
#include "第四周第二题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第四周第二题View

IMPLEMENT_DYNCREATE(C第四周第二题View, CView)

BEGIN_MESSAGE_MAP(C第四周第二题View, CView)
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C第四周第二题View 构造/析构

C第四周第二题View::C第四周第二题View()
{
	// TODO: 在此处添加构造代码

}

C第四周第二题View::~C第四周第二题View()
{
}

BOOL C第四周第二题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第四周第二题View 绘制

void C第四周第二题View::OnDraw(CDC* pDC)
{
	C第四周第二题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(pDoc->rc);
	// TODO: 在此处为本机数据添加绘制代码
}


// C第四周第二题View 诊断

#ifdef _DEBUG
void C第四周第二题View::AssertValid() const
{
	CView::AssertValid();
}

void C第四周第二题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第四周第二题Doc* C第四周第二题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第四周第二题Doc)));
	return (C第四周第二题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第四周第二题View 消息处理程序


void C第四周第二题View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周第二题Doc* pDoc = GetDocument();
	CRect client;
	GetClientRect(&client);
	switch (nChar)
	{ 
	case VK_LEFT:
		if (pDoc->rc.left>client.left)
		{
			pDoc->rc.left -= 5;
			pDoc->rc.right -= 5;
		}
		break;
	case VK_RIGHT:
		if (pDoc->rc.right<(client.right-client.left))
		{
			pDoc->rc.right += 5;
			pDoc->rc.left += 5;
		}
		break;
	case VK_UP:
		if (pDoc->rc.top>client.top)
		{
			pDoc->rc.top -= 5;
			pDoc->rc.bottom -= 5;
		}
		break;
	case VK_DOWN:
		if (pDoc->rc.bottom<client.bottom)
		{
			pDoc->rc.bottom += 5;
			pDoc->rc.top += 5;
		}
		break;
	case VK_HOME:
		if ((pDoc->rc.left>client.left)&&(pDoc->rc.top>client.top))
		{
			pDoc->rc.top -= 5;
			pDoc->rc.left -= 5;
		}break;
	case VK_END:
		if ((pDoc->rc.right>pDoc->rc.left) && (pDoc->rc.top<pDoc->rc.bottom))
		{
			pDoc->rc.right -= 5;
			pDoc->rc.bottom -= 5;
		}break;

	}
	
	InvalidateRect(NULL,TRUE);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void C第四周第二题View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	C第四周第二题Doc* pDoc = GetDocument();
	pDoc->rc.left = 200; pDoc->rc.top = 200;
	pDoc->rc.right = 400; pDoc->rc.bottom = 400;
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}
