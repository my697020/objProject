
// 综合总实验View.cpp : C综合总实验View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "综合总实验.h"
#endif

#include "综合总实验Set.h"
#include "综合总实验Doc.h"
#include "综合总实验View.h"
#include"Dialog1.h"
#include"Dlgseek.h"
#include"DlgAdd.h"
#include"DlgSort.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C综合总实验View

IMPLEMENT_DYNCREATE(C综合总实验View, CRecordView)

BEGIN_MESSAGE_MAP(C综合总实验View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &C综合总实验View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C综合总实验View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C综合总实验View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C综合总实验View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &C综合总实验View::OnBnClickedButton1)
	ON_COMMAND(ID_32771, &C综合总实验View::OnSeek)
	ON_COMMAND(ID_32772, &C综合总实验View::Ondelete)
	ON_COMMAND(ID_32773, &C综合总实验View::On32773)
	ON_COMMAND(ID_32774, &C综合总实验View::On32774)
	ON_COMMAND(ID_32775, &C综合总实验View::On32775)
END_MESSAGE_MAP()

// C综合总实验View 构造/析构

C综合总实验View::C综合总实验View()
	: CRecordView(IDD_MY_FORM)
	, name(_T(""))
	, stunum(_T(""))
	, phone(_T(""))
	, major(_T(""))
	, sex(_T(""))
	, birth(_T(""))
	, photo(_T(""))
	, jar(_T(""))
{
	m_pSet = NULL;
	// TODO: 在此处添加构造代码
	jar = "新建文件夹";
	path = _T("C:\\Users\\16932\\Desktop\\新建文件夹\\");

}

C综合总实验View::~C综合总实验View()
{
}

void C综合总实验View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// 可以在此处插入 DDX_Field* 函数以将控件“连接”到数据库字段，例如
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// 有关详细信息，请参阅 MSDN 和 ODBC 示例
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->column4);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column5);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column6);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column7);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column8);
	DDX_Text(pDX, IDC_EDIT9, jar);
}

BOOL C综合总实验View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CRecordView::PreCreateWindow(cs);
}

void C综合总实验View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_综合总实验Set;
	CRecordView::OnInitialUpdate();

}


// C综合总实验View 诊断

#ifdef _DEBUG
void C综合总实验View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C综合总实验View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C综合总实验Doc* C综合总实验View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C综合总实验Doc)));
	return (C综合总实验Doc*)m_pDocument;
}
#endif //_DEBUG


// C综合总实验View 数据库支持
CRecordset* C综合总实验View::OnGetRecordset()
{
	return m_pSet;
}



// C综合总实验View 消息处理程序


void C综合总实验View::foo(CImage& image, int& x, int& y, int& wh, int& hh)
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


void C综合总实验View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CRecordView::OnPaint()
	CImage im;
	CString s;
	GetDlgItemText(IDC_EDIT8, s);
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


void C综合总实验View::OnRecordFirst()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void C综合总实验View::OnRecordPrev()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void C综合总实验View::OnRecordNext()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);
}


void C综合总实验View::OnRecordLast()
{
	// TODO: 在此添加命令处理程序代码
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);
}


void C综合总实验View::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Dialog1 *dlg = new Dialog1;

	dlg->Create(IDD_DIALOG1, this);

	CRect rc;
	GetDlgItem(IDC_STATICp)->GetClientRect(&rc);
	InvalidateRect(rc, false);
	dlg->ShowWindow(1);

}






void C综合总实验View::OnSeek()
{
	// TODO: 在此添加命令处理程序代码
	Dlgseek dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		UpdateData(true);
		m_pSet->m_strFilter = dlg.seek;
		m_pSet->Requery();
	}
}


void C综合总实验View::Ondelete()
{
	// TODO: 在此添加命令处理程序代码
	CRecordsetStatus status;
	m_pSet->GetStatus(status);
	m_pSet->Delete();
	if (status.m_lCurrentRecord == 0)
		m_pSet->MoveNext();
	else
	{
		m_pSet->MoveFirst();
	}
	UpdateData(false);
	MessageBox(_T("该记录已删除！"));
}


void C综合总实验View::On32773()
{
	// TODO: 在此添加命令处理程序代码
	DlgAdd dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		m_pSet->AddNew();
		m_pSet->SetFieldNull(&(m_pSet->column1), false);
		UpdateData(true);
		m_pSet->column1 = dlg.name;
		m_pSet->column2 = dlg.stunum;
		m_pSet->column3 = dlg.phone;
		m_pSet->column4 = dlg.major;
	       m_pSet->column5 = dlg.sex;
			m_pSet->column6 = dlg.birth;
			m_pSet->column7 = dlg.home;
			m_pSet->column8 = dlg.photo;
	     m_pSet->Update();
		m_pSet->Requery();
	}
}


void C综合总实验View::On32774()
{
	// TODO: 在此添加命令处理程序代码
	DlgAdd dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		m_pSet->Edit();
		UpdateData(true);
		if(*dlg.name!=NULL)m_pSet->column1 = dlg.name;
		if (*dlg.stunum != NULL)m_pSet->column2 = dlg.stunum;
		if (*dlg.phone != NULL)m_pSet->column3 = dlg.phone;
		if (*dlg.major!= NULL)m_pSet->column4 = dlg.major;
		if (*dlg.sex != NULL)m_pSet->column5 = dlg.sex;
		if (dlg.birth != NULL)m_pSet->column6 = dlg.birth;
		if (*dlg.home != NULL)m_pSet->column7 = dlg.home;
		if (*dlg.phone!= NULL)m_pSet->column8 = dlg.photo;
		
		m_pSet->Update();
		m_pSet->Requery();
	}
}


void C综合总实验View::On32775()
{
	// TODO: 在此添加命令处理程序代码
	DlgSort dlg;
	int r = dlg.DoModal();
	if (r == IDOK) {
		UpdateData(true);
		m_pSet->m_strSort = dlg.one;
		m_pSet->Requery();
	}
}
