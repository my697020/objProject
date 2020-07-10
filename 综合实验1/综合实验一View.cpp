
// 综合实验一View.cpp : C综合实验一View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合实验一.h"
#endif

#include "综合实验一Set.h"
#include "综合实验一Doc.h"
#include "综合实验一View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合实验一View

IMPLEMENT_DYNCREATE(C综合实验一View, CRecordView)

BEGIN_MESSAGE_MAP(C综合实验一View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C综合实验一View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合实验一View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合实验一View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合实验一View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C综合实验一View 构造/析构

C综合实验一View::C综合实验一View()
	: CRecordView(IDD_MY_FORM)
	, path(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	path = _T("C:\\综合实验\\");

}

C综合实验一View::~C综合实验一View()
{
}

void C综合实验一View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	
}

BOOL C综合实验一View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合实验一View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合实验一Set;
	CRecordView::OnInitialUpdate();

}


// C综合实验一View 诊断

#ifdef _DEBUG
void C综合实验一View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合实验一View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合实验一Doc* C综合实验一View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合实验一Doc)));
	return (C综合实验一Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合实验一View 数据库支持
CRecordset* C综合实验一View::OnGetRecordset()
{
	return m_pSet;
}



// C综合实验一View 消息处理程序


void C综合实验一View::foo(CImage& image, int& x, int& y, int& wh, int& hh)
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


void C综合实验一View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void C综合实验一View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
	
	/*CImage im;
	CString s;
	GetDlgItemText(IDC_EDIT1, s);
	CString file;
	file = path + s;
	im.Load(file);
	if (!im.IsNull())
	{
		int x, y, wh, hh;
		foo(im, x, y, wh, hh);
		CDC *pDC = GetDlgItem(IDC_STATICp)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		GetDlgItem(IDC_EDIT1)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		im.Draw(pDC->m_hDC, x, y, wh, hh);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}*/
}


void C综合实验一View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);
	/*CImage im;
	CString s;
	GetDlgItemText(IDC_EDIT1,s);
	CString file;
	file = path + s;
	im.Load(file);
	if (!im.IsNull())
	{
		int x, y, wh, hh;
		foo(im, x, y, wh, hh);
		CDC *pDC = GetDlgItem(IDC_STATICp)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		GetDlgItem(IDC_EDIT1)->ShowWindow(FALSE);
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		im.Draw(pDC->m_hDC, x, y, wh, hh);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}*/
}


void C综合实验一View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);

	/*CImage im;
	CString s;
	GetDlgItemText(IDC_EDIT1, s);
	CString file;
	file = path + s;
	im.Load(file);
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
	}*///实验要求二
}


void C综合实验一View::OnPaint()
{
	 // device context for painting
					   // TODO: 在此处添加消息处理程序代码
	CPaintDC dc(this);		   // 不为绘图消息调用 CRecordView::OnPaint()
	CImage im;
	CString s;
	GetDlgItemText(IDC_EDIT1, s);
	CString file;
	file = path + s;
	im.Load(file);
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
