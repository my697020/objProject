
// 第五周实验第一题View.cpp : C第五周实验第一题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验第一题.h"
#endif

#include "第五周实验第一题Doc.h"
#include "第五周实验第一题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验第一题View

IMPLEMENT_DYNCREATE(C第五周实验第一题View, CView)

BEGIN_MESSAGE_MAP(C第五周实验第一题View, CView)
	ON_COMMAND(ID_one, &C第五周实验第一题View::Onone)
END_MESSAGE_MAP()

// C第五周实验第一题View 构造/析构

C第五周实验第一题View::C第五周实验第一题View()
{
	// TODO: 在此处添加构造代码

}

C第五周实验第一题View::~C第五周实验第一题View()
{
}

BOOL C第五周实验第一题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验第一题View 绘制

void C第五周实验第一题View::OnDraw(CDC* /*pDC*/)
{
	C第五周实验第一题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第五周实验第一题View 诊断

#ifdef _DEBUG
void C第五周实验第一题View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验第一题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验第一题Doc* C第五周实验第一题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验第一题Doc)));
	return (C第五周实验第一题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验第一题View 消息处理程序


void C第五周实验第一题View::Onone()
{
	// TODO: 在此添加命令处理程序代码
	CClientDC dc(this);
	CString s =_T("我的名字是魏祎婷");
	dc.TextOutW(200, 200, s);
}
