
// ��һ��ʵ����һView.cpp : C��һ��ʵ����һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��һ��ʵ����һ.h"
#endif

#include "��һ��ʵ����һDoc.h"
#include "��һ��ʵ����һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��һ��ʵ����һView

IMPLEMENT_DYNCREATE(C��һ��ʵ����һView, CView)

BEGIN_MESSAGE_MAP(C��һ��ʵ����һView, CView)
END_MESSAGE_MAP()

// C��һ��ʵ����һView ����/����

C��һ��ʵ����һView::C��һ��ʵ����һView()
{
	// TODO: �ڴ˴���ӹ������

}

C��һ��ʵ����һView::~C��һ��ʵ����һView()
{
}

BOOL C��һ��ʵ����һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��һ��ʵ����һView ����

void C��һ��ʵ����һView::OnDraw(CDC* pDC)
{
	C��һ��ʵ����һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s =_T( "����***");
	int A = 100;
	pDC->TextOutW(200,200,s);
	CString a;
	a.Format(_T("%d"),A);
	pDC->TextOutW(100,100,a);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��һ��ʵ����һView ���

#ifdef _DEBUG
void C��һ��ʵ����һView::AssertValid() const
{
	CView::AssertValid();
}

void C��һ��ʵ����һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��һ��ʵ����һDoc* C��һ��ʵ����һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��һ��ʵ����һDoc)));
	return (C��һ��ʵ����һDoc*)m_pDocument;
}
#endif //_DEBUG


// C��һ��ʵ����һView ��Ϣ�������
