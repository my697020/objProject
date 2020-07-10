
// �ۺ�ʵ���View.cpp : C�ۺ�ʵ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ۺ�ʵ���.h"
#endif

#include "�ۺ�ʵ���Set.h"
#include "�ۺ�ʵ���Doc.h"
#include "�ۺ�ʵ���View.h"
#include"Dialog1.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ���View

IMPLEMENT_DYNCREATE(C�ۺ�ʵ���View, CRecordView)

BEGIN_MESSAGE_MAP(C�ۺ�ʵ���View, CRecordView)
	ON_WM_PAINT()
	ON_COMMAND(ID_RECORD_FIRST, &C�ۺ�ʵ���View::OnRecordFirst)
	ON_COMMAND(ID_RECORD_PREV, &C�ۺ�ʵ���View::OnRecordPrev)
	ON_COMMAND(ID_RECORD_NEXT, &C�ۺ�ʵ���View::OnRecordNext)
	ON_COMMAND(ID_RECORD_LAST, &C�ۺ�ʵ���View::OnRecordLast)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ۺ�ʵ���View::OnBnClickedButton1)
END_MESSAGE_MAP()

// C�ۺ�ʵ���View ����/����

C�ۺ�ʵ���View::C�ۺ�ʵ���View()
	: CRecordView(IDD_MY_FORM)
	
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������
	path = _T("C:\\�ۺ�ʵ��\\");
	

}

C�ۺ�ʵ���View::~C�ۺ�ʵ���View()
{
}

void C�ۺ�ʵ���View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1, m_pSet->column1);
}

BOOL C�ۺ�ʵ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C�ۺ�ʵ���View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_�ۺ�ʵ���Set;
	CRecordView::OnInitialUpdate();
	

}


// C�ۺ�ʵ���View ���

#ifdef _DEBUG
void C�ۺ�ʵ���View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C�ۺ�ʵ���View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C�ۺ�ʵ���Doc* C�ۺ�ʵ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ۺ�ʵ���Doc)));
	return (C�ۺ�ʵ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ۺ�ʵ���View ���ݿ�֧��
CRecordset* C�ۺ�ʵ���View::OnGetRecordset()
{
	return m_pSet;
}



// C�ۺ�ʵ���View ��Ϣ�������


void C�ۺ�ʵ���View::foo(CImage& image, int& x, int& y, int& wh, int& hh)
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


void C�ۺ�ʵ���View::OnPaint()
{
	CPaintDC dc(this);
	// device context for painting
					   // TODO: �ڴ˴������Ϣ����������
					   // ��Ϊ��ͼ��Ϣ���� CRecordView::OnPaint()
		   
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


void C�ۺ�ʵ���View::OnRecordFirst()
{
	// TODO: �ڴ���������������
	m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void C�ۺ�ʵ���View::OnRecordPrev()
{
	// TODO: �ڴ���������������
	m_pSet->MovePrev();
	if (m_pSet->IsBOF())m_pSet->MoveFirst();
	UpdateData(false);
	Invalidate(true);
}


void C�ۺ�ʵ���View::OnRecordNext()
{
	// TODO: �ڴ���������������
	m_pSet->MoveNext();
	if (m_pSet->IsEOF())m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);
}


void C�ۺ�ʵ���View::OnRecordLast()
{
	// TODO: �ڴ���������������
	m_pSet->MoveLast();
	UpdateData(false);
	Invalidate(true);

}


void C�ۺ�ʵ���View::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ��������
	Dialog1 *dlg=new Dialog1;
	
	dlg->Create(IDD_DIALOG1,this);
	
	CRect rc;
	GetDlgItem(IDC_STATICp)->GetClientRect(&rc);
	InvalidateRect(rc,false);
	dlg->ShowWindow(1);
	
}
