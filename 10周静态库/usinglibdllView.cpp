
// usinglibdllView.cpp : CusinglibdllView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "usinglibdll.h"
#endif

#include "usinglibdllDoc.h"
#include "usinglibdllView.h"
#include"one.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CusinglibdllView

IMPLEMENT_DYNCREATE(CusinglibdllView, CView)

BEGIN_MESSAGE_MAP(CusinglibdllView, CView)
END_MESSAGE_MAP()

// CusinglibdllView ����/����

CusinglibdllView::CusinglibdllView()
{
	// TODO: �ڴ˴���ӹ������

}

CusinglibdllView::~CusinglibdllView()
{
}

BOOL CusinglibdllView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CusinglibdllView ����

void CusinglibdllView::OnDraw(CDC* pDC)
{
	CusinglibdllDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CString s;
	s.Format(_T("%d"),factorial(5));
	pDC->TextOutW(200,200,s);

	FAC fac;
	CString ss;
	
	ss.Format(_T("%.2f"),fac.convert(30));
	pDC->TextOutW(100, 200, ss);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CusinglibdllView ���

#ifdef _DEBUG
void CusinglibdllView::AssertValid() const
{
	CView::AssertValid();
}

void CusinglibdllView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CusinglibdllDoc* CusinglibdllView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CusinglibdllDoc)));
	return (CusinglibdllDoc*)m_pDocument;
}
#endif //_DEBUG


// CusinglibdllView ��Ϣ�������
