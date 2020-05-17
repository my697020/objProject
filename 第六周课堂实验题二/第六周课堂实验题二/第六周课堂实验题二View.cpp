
// 第六周课堂实验题二View.cpp : C第六周课堂实验题二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第六周课堂实验题二.h"
#endif

#include "第六周课堂实验题二Doc.h"
#include "第六周课堂实验题二View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第六周课堂实验题二View

IMPLEMENT_DYNCREATE(C第六周课堂实验题二View, CView)

BEGIN_MESSAGE_MAP(C第六周课堂实验题二View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C第六周课堂实验题二View::OnFileOpen)
END_MESSAGE_MAP()

// C第六周课堂实验题二View 构造/析构

C第六周课堂实验题二View::C第六周课堂实验题二View()
{
	// TODO: 在此处添加构造代码

}

C第六周课堂实验题二View::~C第六周课堂实验题二View()
{
}

BOOL C第六周课堂实验题二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第六周课堂实验题二View 绘制

void C第六周课堂实验题二View::OnDraw(CDC* pDC)
{
	C第六周课堂实验题二Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	GetClientRect(&pDoc->rc);
	if (pDoc->flag == 1)
	{
		float img_rit = 1.0*pDoc->image.GetWidth() / pDoc->image.GetHeight();
		float clientrect_rit = 1.0*pDoc->rc.Width() / pDoc->rc.Height();
		if (clientrect_rit > img_rit)
		{
			pDoc->h = pDoc->rc.Height();
			pDoc->w = pDoc->h*img_rit;
			pDoc->sx = (pDoc->rc.Width() - pDoc->w) / 2;
			pDoc->sy = 0;

		}
		else
		{
			pDoc->w = pDoc->rc.Width();
			pDoc->h = pDoc->w;
			pDoc->sx = 0;
			pDoc->sy = (pDoc->rc.Height() - pDoc->h) / 2;


		}
		pDoc->image.Draw(dc.m_hDC, pDoc->sx, pDoc->sy, pDoc->w, pDoc->h);
	}

	
}


// C第六周课堂实验题二View 诊断

#ifdef _DEBUG
void C第六周课堂实验题二View::AssertValid() const
{
	CView::AssertValid();
}

void C第六周课堂实验题二View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第六周课堂实验题二Doc* C第六周课堂实验题二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第六周课堂实验题二Doc)));
	return (C第六周课堂实验题二Doc*)m_pDocument;
}
#endif //_DEBUG


// C第六周课堂实验题二View 消息处理程序


void C第六周课堂实验题二View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码

	C第六周课堂实验题二Doc* pDoc = GetDocument();
    GetClientRect(&pDoc->rc);
	CFileDialog cfd(true);
	
	int r = cfd.DoModal();
	CClientDC dc(this);
	
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		pDoc->image.Load(filename);
		pDoc->flag = 1;
   float img_rit=1.0*pDoc->image.GetWidth()/ pDoc->image.GetHeight();
	float clientrect_rit=1.0*pDoc->rc.Width()/pDoc-> rc.Height();
	if (clientrect_rit > img_rit)
	{
		pDoc->h = pDoc->rc.Height();
		pDoc->w =pDoc->h*img_rit;
		pDoc->sx = (pDoc->rc.Width() - pDoc->w) / 2;
		pDoc->sy = 0;
	
	}
	else
	{
		pDoc->w = pDoc->rc.Width();
		pDoc->h = pDoc->w;
		pDoc->sx = 0;
		pDoc->sy = (pDoc->rc.Height() - pDoc->h)/2;
		
		
	}
		

	pDoc->image.Draw(dc.m_hDC, pDoc->sx, pDoc->sy, pDoc->w, pDoc->h);


	}
	
}
