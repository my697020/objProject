
// �ڰ��ܿ���ʵ�����View.cpp : C�ڰ��ܿ���ʵ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ��ܿ���ʵ�����.h"
#endif

#include "�ڰ��ܿ���ʵ�����Doc.h"
#include "�ڰ��ܿ���ʵ�����View.h"
#include "MyDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ڰ��ܿ���ʵ�����View

IMPLEMENT_DYNCREATE(C�ڰ��ܿ���ʵ�����View, CView)

BEGIN_MESSAGE_MAP(C�ڰ��ܿ���ʵ�����View, CView)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_32771, &C�ڰ��ܿ���ʵ�����View::On32771)
END_MESSAGE_MAP()

// C�ڰ��ܿ���ʵ�����View ����/����

C�ڰ��ܿ���ʵ�����View::C�ڰ��ܿ���ʵ�����View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ڰ��ܿ���ʵ�����View::~C�ڰ��ܿ���ʵ�����View()
{
}

BOOL C�ڰ��ܿ���ʵ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ڰ��ܿ���ʵ�����View ����

void C�ڰ��ܿ���ʵ�����View::OnDraw(CDC* /*pDC*/)
{
	C�ڰ��ܿ���ʵ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ڰ��ܿ���ʵ�����View ���

#ifdef _DEBUG
void C�ڰ��ܿ���ʵ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C�ڰ��ܿ���ʵ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ڰ��ܿ���ʵ�����Doc* C�ڰ��ܿ���ʵ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ڰ��ܿ���ʵ�����Doc)));
	return (C�ڰ��ܿ���ʵ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ڰ��ܿ���ʵ�����View ��Ϣ�������


void C�ڰ��ܿ���ʵ�����View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	C�ڰ��ܿ���ʵ�����Doc* pDoc = GetDocument();
	CFileDialog cg(true);
	int r = cg.DoModal();
	if (r == IDOK) { pDoc->name = cg.GetPathName(); GetDC()->TextOutW(200, 200, pDoc->name); }
	CView::OnLButtonDblClk(nFlags, point);
}


void C�ڰ��ܿ���ʵ�����View::On32771()
{
	// TODO: �ڴ���������������
	C�ڰ��ܿ���ʵ�����Doc* pDoc = GetDocument();
	MyDialog *dlg=new MyDialog;
	dlg->Create(IDD_DIALOG1,this);
	dlg->cname = pDoc->name;
	dlg->UpdateData(false);
	dlg->ShowWindow(1);

}
