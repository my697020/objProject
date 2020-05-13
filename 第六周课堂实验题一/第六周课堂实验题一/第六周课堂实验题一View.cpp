
// 第六周课堂实验题一View.cpp : C第六周课堂实验题一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第六周课堂实验题一.h"
#endif

#include "第六周课堂实验题一Doc.h"
#include "第六周课堂实验题一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第六周课堂实验题一View

IMPLEMENT_DYNCREATE(C第六周课堂实验题一View, CView)

BEGIN_MESSAGE_MAP(C第六周课堂实验题一View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C第六周课堂实验题一View::OnFileOpen)
END_MESSAGE_MAP()

// C第六周课堂实验题一View 构造/析构

C第六周课堂实验题一View::C第六周课堂实验题一View()
{
	// TODO: 在此处添加构造代码

}

C第六周课堂实验题一View::~C第六周课堂实验题一View()
{
}

BOOL C第六周课堂实验题一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第六周课堂实验题一View 绘制

void C第六周课堂实验题一View::OnDraw(CDC* /*pDC*/)
{
	C第六周课堂实验题一Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C第六周课堂实验题一View 诊断

#ifdef _DEBUG
void C第六周课堂实验题一View::AssertValid() const
{
	CView::AssertValid();
}

void C第六周课堂实验题一View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第六周课堂实验题一Doc* C第六周课堂实验题一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第六周课堂实验题一Doc)));
	return (C第六周课堂实验题一Doc*)m_pDocument;
}
#endif //_DEBUG


// C第六周课堂实验题一View 消息处理程序


void C第六周课堂实验题一View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CRect rc;
	GetClientRect(&rc);
	CFileDialog cfd(true);
	int r = cfd.DoModal();
	
	
	CClientDC dc(this);int sx, sy;
	CImage image;
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		
		image.Load(filename);
		
		sx = (rc.Width() - image.GetWidth()) / 2;
		sy = (rc.Height() - image.GetHeight()) / 2;
		



	}
	image.Draw(dc.m_hDC, sx, sy, image.GetWidth(), image.GetHeight());
}
