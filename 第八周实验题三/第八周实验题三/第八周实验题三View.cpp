
// �ڰ���ʵ������View.cpp : C�ڰ���ʵ������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ���ʵ������.h"
#endif

#include "�ڰ���ʵ������Doc.h"
#include "�ڰ���ʵ������View.h"
#include"MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ���ʵ������View

IMPLEMENT_DYNCREATE(C�ڰ���ʵ������View, CView)

BEGIN_MESSAGE_MAP(C�ڰ���ʵ������View, CView)
	ON_COMMAND(ID_32771, &C�ڰ���ʵ������View::On32771)
END_MESSAGE_MAP()

// C�ڰ���ʵ������View ����/����

C�ڰ���ʵ������View::C�ڰ���ʵ������View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڰ���ʵ������View::~C�ڰ���ʵ������View()
{
}

BOOL C�ڰ���ʵ������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ���ʵ������View ����

void C�ڰ���ʵ������View::OnDraw(CDC* /*pDC*/)
{
	C�ڰ���ʵ������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڰ���ʵ������View ���

#ifdef _DEBUG
void C�ڰ���ʵ������View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ���ʵ������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ���ʵ������Doc* C�ڰ���ʵ������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ���ʵ������Doc)));
	return (C�ڰ���ʵ������Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ���ʵ������View ��Ϣ�������


void C�ڰ���ʵ������View::On32771()
{
	// TODO: �ڴ���������������
	MyDialog dlg;
	dlg.DoModal();
    x.x = dlg.x1; x.y = dlg.y1;
	y.x = dlg.x2; y.y = dlg.y2;
	GetDC()->Ellipse(x.x,x.y,y.x,y.y);
}
