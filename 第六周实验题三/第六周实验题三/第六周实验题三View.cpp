
// 第六周实验题三View.cpp : C第六周实验题三View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第六周实验题三.h"
#endif

#include "第六周实验题三Doc.h"
#include "第六周实验题三View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第六周实验题三View

IMPLEMENT_DYNCREATE(C第六周实验题三View, CView)

BEGIN_MESSAGE_MAP(C第六周实验题三View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C第六周实验题三View 构造/析构

C第六周实验题三View::C第六周实验题三View()
{
	// TODO: 在此处添加构造代码
	line = "";

	rc.left = 200;
	rc.top = 200;
	rc.bottom = 600;
	rc.right = 800;
	x = 215;
	y = 201;
}

C第六周实验题三View::~C第六周实验题三View()
{
}

BOOL C第六周实验题三View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C第六周实验题三View 绘制

void C第六周实验题三View::OnDraw(CDC* pDC)
{
	C第六周实验题三Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(rc);
	// TODO: 在此处为本机数据添加绘制代码
}


// C第六周实验题三View 打印

BOOL C第六周实验题三View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C第六周实验题三View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C第六周实验题三View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C第六周实验题三View 诊断

#ifdef _DEBUG
void C第六周实验题三View::AssertValid() const
{
	CView::AssertValid();
}

void C第六周实验题三View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C第六周实验题三Doc* C第六周实验题三View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第六周实验题三Doc)));
	return (C第六周实验题三Doc*)m_pDocument;
}
#endif //_DEBUG


// C第六周实验题三View 消息处理程序


void C第六周实验题三View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	line.AppendChar(nChar);
	c = dc.GetTextExtent(line);
	
	if (c.cx>=(rc.right - rc.left)&&(c.cy<rc.Height()))
	{
		
		x = x + tm.tmHeight;
		line.Empty();
	}
	if (c.cx<(rc.right - rc.left))
		dc.TextOutW(y,x, line);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
