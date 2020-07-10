
// ��ʮһ��ʵ���View.cpp : C��ʮһ��ʵ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮһ��ʵ���.h"
#endif

#include "��ʮһ��ʵ���Set.h"
#include "��ʮһ��ʵ���Doc.h"
#include "��ʮһ��ʵ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ��ʵ���View

IMPLEMENT_DYNCREATE(C��ʮһ��ʵ���View, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮһ��ʵ���View, CRecordView)
	ON_COMMAND(ID_RECORD_FIRST, &C��ʮһ��ʵ���View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C��ʮһ��ʵ���View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C��ʮһ��ʵ���View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C��ʮһ��ʵ���View::OnRecordLast)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C��ʮһ��ʵ���View ����/����

C��ʮһ��ʵ���View::C��ʮһ��ʵ���View()
	: CRecordView(IDD_MY_FORM)
	, name(_T(""))
	, age(_T(""))
	, num(_T(""))
	, phone(_T(""))
	
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ʮһ��ʵ���View::~C��ʮһ��ʵ���View()
{
}

void C��ʮһ��ʵ���View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT5, m_pSet->column1);
	DDX_Text(pDX, IDC_EDIT6, m_pSet->column2);
	DDX_Text(pDX, IDC_EDIT7, m_pSet->column3);
	DDX_Text(pDX, IDC_EDIT8, m_pSet->column4);
	
}

BOOL C��ʮһ��ʵ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ʮһ��ʵ���View::OnInitialUpdate()
{
	
	m_pSet = &GetDocument()->m_��ʮһ��ʵ���Set;
	CRecordView::OnInitialUpdate();

}


// C��ʮһ��ʵ���View ���

#ifdef _DEBUG
void C��ʮһ��ʵ���View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ʮһ��ʵ���View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ʮһ��ʵ���Doc* C��ʮһ��ʵ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮһ��ʵ���Doc)));
	return (C��ʮһ��ʵ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮһ��ʵ���View ���ݿ�֧��
CRecordset* C��ʮһ��ʵ���View::OnGetRecordset()
{
	return m_pSet;
}



// C��ʮһ��ʵ���View ��Ϣ�������



void C��ʮһ��ʵ���View::foo(CImage& image, int& x, int& y, int& wh, int& hh)
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


void C��ʮһ��ʵ���View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(false);

	
}


void C��ʮһ��ʵ���View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())m_pSet->MoveFirst();
	UpdateData(false);
	InvalidateRect(false);
}


void C��ʮһ��ʵ���View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(false);
}


void C��ʮһ��ʵ���View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	InvalidateRect(false);
}


void C��ʮһ��ʵ���View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
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
