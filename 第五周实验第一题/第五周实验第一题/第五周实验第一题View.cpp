
// ������ʵ���һ��View.cpp : C������ʵ���һ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ���һ��.h"
#endif

#include "������ʵ���һ��Doc.h"
#include "������ʵ���һ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ���һ��View

IMPLEMENT_DYNCREATE(C������ʵ���һ��View, CView)

BEGIN_MESSAGE_MAP(C������ʵ���һ��View, CView)
	ON_COMMAND(ID_one, &C������ʵ���һ��View::Onone)
END_MESSAGE_MAP()

// C������ʵ���һ��View ����/����

C������ʵ���һ��View::C������ʵ���һ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʵ���һ��View::~C������ʵ���һ��View()
{
}

BOOL C������ʵ���һ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ���һ��View ����

void C������ʵ���һ��View::OnDraw(CDC* /*pDC*/)
{
	C������ʵ���һ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ���һ��View ���

#ifdef _DEBUG
void C������ʵ���һ��View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ���һ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ���һ��Doc* C������ʵ���һ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ���һ��Doc)));
	return (C������ʵ���һ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ���һ��View ��Ϣ�������


void C������ʵ���һ��View::Onone()
{
	// TODO: �ڴ���������������
	CClientDC dc(this);
	CString s =_T("�ҵ�������κ�t��");
	dc.TextOutW(200, 200, s);
}
