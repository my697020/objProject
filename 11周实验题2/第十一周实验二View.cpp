
// 第十一周实验二View.cpp : C第十一周实验二View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "第十一周实验二.h"
#endif

#include "第十一周实验二Set.h"
#include "第十一周实验二Doc.h"
#include "第十一周实验二View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C第十一周实验二View

IMPLEMENT_DYNCREATE(C第十一周实验二View, CRecordView)

BEGIN_MESSAGE_MAP(C第十一周实验二View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C第十一周实验二View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C第十一周实验二View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C第十一周实验二View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C第十一周实验二View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C第十一周实验二View 构造/析构

C第十一周实验二View::C第十一周实验二View()
	: CRecordView(IDD_MY_FORM)
	, name(_T(""))
	, age(_T(""))
	, num(_T(""))
	, phone(_T(""))
	
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码

}

C第十一周实验二View::~C第十一周实验二View()
{
}

void C第十一周实验二View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column4);
	
}

BOOL C第十一周实验二View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C第十一周实验二View::OnInitialUpdate()
{
	
	m_pSet = &GetDocument()->m_第十一周实验二Set;
	CRecordView::OnInitialUpdate();

}


// C第十一周实验二View 诊断

#ifdef _DEBUG
void C第十一周实验二View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C第十一周实验二View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C第十一周实验二Doc* C第十一周实验二View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C第十一周实验二Doc)));
	return (C第十一周实验二Doc*)m_pDocument;
}
#endif //_DEBUG


// C第十一周实验二View 数据库支持
CRecordset* C第十一周实验二View::OnGetRecordset()
{
	return m_pSet;
}



// C第十一周实验二View 消息处理程序



void C第十一周实验二View::foo(CImage& image, int& x, int& y, int& wh, int& hh)
{
	CRect rc;
	GetDlgItem(IDC_STATICp)->GetClientRect(&rc);

	float img_rit = 1.0*image.GetWidth() / image.GetHeight();
	float clientrect_rit = 1.0*rc.Width() / rc.Height();
	if (clientrect_rit > img_rit)
	{
		hh = rc.Height();
		wh = hh*img_rit;
		x = (rc.Width() - wh) / 2;
		y = 0;

	}
	else
	{
		wh = rc.Width();
		hh = wh;
		x = 0;
		y = (rc.Height() - hh) / 2;


	}
}


void C第十一周实验二View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(false);

	
}


void C第十一周实验二View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(false);
}


void C第十一周实验二View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(false);
}


void C第十一周实验二View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(false);
}


void C第十一周实验二View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CImage im;
	CString s;
	m_pSet->GetFieldValue(short(5), s);
	im.Load(s);
	if (!im.IsNull())
	{
		int x, y, wh, hh;
		foo(im, x, y, wh, hh);
		CDC *pDC = GetDlgItem(IDC_STATICp)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		im.Draw(pDC->m_hDC, x, y, wh, hh);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}
}
