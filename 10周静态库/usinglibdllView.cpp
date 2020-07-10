
// usinglibdllView.cpp : CusinglibdllView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "usinglibdll.h"
#endif

#include "usinglibdllDoc.h"
#include "usinglibdllView.h"
#include"one.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CusinglibdllView

IMPLEMENT_DYNCREATE(CusinglibdllView, CView)

BEGIN_MESSAGE_MAP(CusinglibdllView, CView)
END_MESSAGE_MAP()

// CusinglibdllView 构造/析构

CusinglibdllView::CusinglibdllView()
{
	// TODO: 在此处添加构造代码

}

CusinglibdllView::~CusinglibdllView()
{
}

BOOL CusinglibdllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CusinglibdllView 绘制

void CusinglibdllView::OnDraw(CDC* pDC)
{
	CusinglibdllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("%d"),factorial(5));
	pDC->TextOutW(200,200,s);

	FAC fac;
	CString ss;
	
	ss.Format(_T("%.2f"),fac.convert(30));
	pDC->TextOutW(100, 200, ss);

	// TODO: 在此处为本机数据添加绘制代码
}


// CusinglibdllView 诊断

#ifdef _DEBUG
void CusinglibdllView::AssertValid() const
{
	CView::AssertValid();
}

void CusinglibdllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusinglibdllDoc* CusinglibdllView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusinglibdllDoc)));
	return (CusinglibdllDoc*)m_pDocument;
}
#endif //_DEBUG


// CusinglibdllView 消息处理程序
