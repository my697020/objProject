
// 第五周实验第二题View.cpp : C第五周实验第二题View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第五周实验第二题.h"
#endif

#include "第五周实验第二题Doc.h"
#include "第五周实验第二题View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第五周实验第二题View

IMPLEMENT_DYNCREATE(C第五周实验第二题View, CView)

BEGIN_MESSAGE_MAP(C第五周实验第二题View, CView)
END_MESSAGE_MAP()

// C第五周实验第二题View 构造/析构

C第五周实验第二题View::C第五周实验第二题View()
{
	// TODO: 在此处添加构造代码
	BITMAP BM;

	m_Bitmap.LoadBitmap(IDB_BITMAP1);

	m_Bitmap.GetBitmap(&BM);

	m_nWidth = BM.bmWidth;

	m_nHeight = BM.bmHeight;


}

C第五周实验第二题View::~C第五周实验第二题View()
{
}

BOOL C第五周实验第二题View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第五周实验第二题View 绘制

void C第五周实验第二题View::OnDraw(CDC* pDC)
{
	C第五周实验第二题Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: 在此处为本机数据添加绘制代码
}


// C第五周实验第二题View 诊断

#ifdef _DEBUG
void C第五周实验第二题View::AssertValid() const
{
	CView::AssertValid();
}

void C第五周实验第二题View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第五周实验第二题Doc* C第五周实验第二题View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第五周实验第二题Doc)));
	return (C第五周实验第二题Doc*)m_pDocument;
}
#endif //_DEBUG


// C第五周实验第二题View 消息处理程序
