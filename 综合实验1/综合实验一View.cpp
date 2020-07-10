
// �ۺ�ʵ��һView.cpp : C�ۺ�ʵ��һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ��һ.h"
#endif

#include "�ۺ�ʵ��һSet.h"
#include "�ۺ�ʵ��һDoc.h"
#include "�ۺ�ʵ��һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��һView

IMPLEMENT_DYNCREATE(C�ۺ�ʵ��һView, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ��һView, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ��һView::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C�ۺ�ʵ��һView::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C�ۺ�ʵ��һView::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C�ۺ�ʵ��һView::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C�ۺ�ʵ��һView ����/����

C�ۺ�ʵ��һView::C�ۺ�ʵ��һView()
	: CRecordView(IDD_MY_FORM)
	, path(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\�ۺ�ʵ��\\");

}

C�ۺ�ʵ��һView::~C�ۺ�ʵ��һView()
{
}

void C�ۺ�ʵ��һView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
	
}

BOOL C�ۺ�ʵ��һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ��һView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ��һSet;
	CRecordView::OnInitialUpdate();

}


// C�ۺ�ʵ��һView ���

#ifdef _DEBUG
void C�ۺ�ʵ��һView::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ��һView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ��һDoc* C�ۺ�ʵ��һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ��һDoc)));
	return (C�ۺ�ʵ��һDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ��һView ���ݿ�֧��
CRecordset* C�ۺ�ʵ��һView::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ��һView ��Ϣ�������


void C�ۺ�ʵ��һView::foo(CImage& image, int& x, int& y, int& wh, int& hh)
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


void C�ۺ�ʵ��һView::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void C�ۺ�ʵ��һView::OnRecordPrev()
{
	// TODO: �ڴ���������������
	
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


void C�ۺ�ʵ��һView::OnRecordNext()
{
	// TODO: �ڴ���������������
	
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


void C�ۺ�ʵ��һView::OnRecordLast()
{
	// TODO: �ڴ���������������
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
	}*///ʵ��Ҫ���
}


void C�ۺ�ʵ��һView::OnPaint()
{
	 // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
	CPaintDC dc(this);		   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
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
