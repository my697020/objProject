
// �ھ��ܿ���ʵ����һView.cpp : C�ھ��ܿ���ʵ����һView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ��ܿ���ʵ����һ.h"
#endif

#include "�ھ��ܿ���ʵ����һDoc.h"
#include "�ھ��ܿ���ʵ����һView.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ھ��ܿ���ʵ����һView

IMPLEMENT_DYNCREATE(C�ھ��ܿ���ʵ����һView, CView)

BEGIN_MESSAGE_MAP(C�ھ��ܿ���ʵ����һView, CView)
	ON_COMMAND(ID_32771, &C�ھ��ܿ���ʵ����һView::On32771)
END_MESSAGE_MAP()

// C�ھ��ܿ���ʵ����һView ����/����

C�ھ��ܿ���ʵ����һView::C�ھ��ܿ���ʵ����һView()
{
	// TODO: �ڴ˴���ӹ������

}

C�ھ��ܿ���ʵ����һView::~C�ھ��ܿ���ʵ����һView()
{
}

BOOL C�ھ��ܿ���ʵ����һView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ھ��ܿ���ʵ����һView ����

void C�ھ��ܿ���ʵ����һView::OnDraw(CDC* pDC)
{
	C�ھ��ܿ���ʵ����һDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOutW(200,200,pDoc->name);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ھ��ܿ���ʵ����һView ���

#ifdef _DEBUG
void C�ھ��ܿ���ʵ����һView::AssertValid() const
{
	CView::AssertValid();
}

void C�ھ��ܿ���ʵ����һView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ھ��ܿ���ʵ����һDoc* C�ھ��ܿ���ʵ����һView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ھ��ܿ���ʵ����һDoc)));
	return (C�ھ��ܿ���ʵ����һDoc*)m_pDocument;
}
#endif //_DEBUG


// C�ھ��ܿ���ʵ����һView ��Ϣ�������


void C�ھ��ܿ���ʵ����һView::On32771()
{
	// TODO: �ڴ���������������
	C�ھ��ܿ���ʵ����һDoc* pDoc = GetDocument();
	CFileDialog dlg(true);
	int r = dlg.DoModal();
	if (r == IDOK) {
		pDoc->name = dlg.GetPathName(); 
		
		Invalidate();
	}
}
