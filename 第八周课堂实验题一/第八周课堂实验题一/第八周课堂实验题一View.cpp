
// �ڰ��ܿ���ʵ����һView.cpp : C�ڰ��ܿ���ʵ����һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ��ܿ���ʵ����һ.h"
#endif

#include "�ڰ��ܿ���ʵ����һDoc.h"
#include "�ڰ��ܿ���ʵ����һView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ��ܿ���ʵ����һView

IMPLEMENT_DYNCREATE(C�ڰ��ܿ���ʵ����һView, CView)

BEGIN_MESSAGE_MAP(C�ڰ��ܿ���ʵ����һView, CView)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C�ڰ��ܿ���ʵ����һView ����/����

C�ڰ��ܿ���ʵ����һView::C�ڰ��ܿ���ʵ����һView()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڰ��ܿ���ʵ����һView::~C�ڰ��ܿ���ʵ����һView()
{
}

BOOL C�ڰ��ܿ���ʵ����һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ��ܿ���ʵ����һView ����

void C�ڰ��ܿ���ʵ����һView::OnDraw(CDC* /*pDC*/)
{
	C�ڰ��ܿ���ʵ����һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڰ��ܿ���ʵ����һView ���

#ifdef _DEBUG
void C�ڰ��ܿ���ʵ����һView::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ��ܿ���ʵ����һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ��ܿ���ʵ����һDoc* C�ڰ��ܿ���ʵ����һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ��ܿ���ʵ����һDoc)));
	return (C�ڰ��ܿ���ʵ����һDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ��ܿ���ʵ����һView ��Ϣ�������


void C�ڰ��ܿ���ʵ����һView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFileDialog clg(true);
	int r = clg.DoModal();
	if (r == IDOK) 
	{
		CString s = clg.GetPathName();
		GetDC()->TextOutW(200,200,s);

	
	}
	CView::OnLButtonDblClk(nFlags, point);
}
