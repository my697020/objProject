
// ��ʮһ�ܿ���ʵ��View.cpp : C��ʮһ�ܿ���ʵ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮһ�ܿ���ʵ��.h"
#endif

#include "��ʮһ�ܿ���ʵ��Set.h"
#include "��ʮһ�ܿ���ʵ��Doc.h"
#include "��ʮһ�ܿ���ʵ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ�ܿ���ʵ��View

IMPLEMENT_DYNCREATE(C��ʮһ�ܿ���ʵ��View, CRecordView)

BEGIN_MESSAGE_MAP(C��ʮһ�ܿ���ʵ��View, CRecordView)
END_MESSAGE_MAP()

// C��ʮһ�ܿ���ʵ��View ����/����

C��ʮһ�ܿ���ʵ��View::C��ʮһ�ܿ���ʵ��View()
	: CRecordView(IDD_MY_FORM)
	, ID(0)
	, name(_T(""))
	, num(_T(""))
	, age(_T(""))
	, phone(_T(""))
{
	m_pSet = NULL;
	// TODO: �ڴ˴���ӹ������

}

C��ʮһ�ܿ���ʵ��View::~C��ʮһ�ܿ���ʵ��View()
{
}

void C��ʮһ�ܿ���ʵ��View::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	// �����ڴ˴����� DDX_Field* �����Խ��ؼ������ӡ������ݿ��ֶΣ�����
	// DDX_FieldText(pDX, IDC_MYEDITBOX, m_pSet->m_szColumn1, m_pSet);
	// DDX_FieldCheck(pDX, IDC_MYCHECKBOX, m_pSet->m_bColumn2, m_pSet);
	// �й���ϸ��Ϣ������� MSDN �� ODBC ʾ��
	DDX_Text(pDX, IDC_EDIT1,m_pSet->m_ID);
	DDX_Text(pDX, IDC_EDIT2, m_pSet->m_1);
	DDX_Text(pDX, IDC_EDIT3, m_pSet->m_2);
	DDX_Text(pDX, IDC_EDIT4, m_pSet->m_3);
	DDX_Text(pDX, IDC_EDIT5, m_pSet->m_4);
}

BOOL C��ʮһ�ܿ���ʵ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CRecordView::PreCreateWindow(cs);
}

void C��ʮһ�ܿ���ʵ��View::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_��ʮһ�ܿ���ʵ��Set;
	CRecordView::OnInitialUpdate();

}


// C��ʮһ�ܿ���ʵ��View ���

#ifdef _DEBUG
void C��ʮһ�ܿ���ʵ��View::AssertValid() const
{
	CRecordView::AssertValid();
}

void C��ʮһ�ܿ���ʵ��View::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

C��ʮһ�ܿ���ʵ��Doc* C��ʮһ�ܿ���ʵ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʮһ�ܿ���ʵ��Doc)));
	return (C��ʮһ�ܿ���ʵ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ʮһ�ܿ���ʵ��View ���ݿ�֧��
CRecordset* C��ʮһ�ܿ���ʵ��View::OnGetRecordset()
{
	return m_pSet;
}



// C��ʮһ�ܿ���ʵ��View ��Ϣ�������
