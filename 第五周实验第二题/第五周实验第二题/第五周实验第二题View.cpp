
// ������ʵ��ڶ���View.cpp : C������ʵ��ڶ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ��ڶ���.h"
#endif

#include "������ʵ��ڶ���Doc.h"
#include "������ʵ��ڶ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ��ڶ���View

IMPLEMENT_DYNCREATE(C������ʵ��ڶ���View, CView)

BEGIN_MESSAGE_MAP(C������ʵ��ڶ���View, CView)
END_MESSAGE_MAP()

// C������ʵ��ڶ���View ����/����

C������ʵ��ڶ���View::C������ʵ��ڶ���View()
{
	// TODO: �ڴ˴���ӹ������
	BITMAP BM;

	m_Bitmap.LoadBitmap(IDB_BITMAP1);

	m_Bitmap.GetBitmap(&BM);

	m_nWidth = BM.bmWidth;

	m_nHeight = BM.bmHeight;


}

C������ʵ��ڶ���View::~C������ʵ��ڶ���View()
{
}

BOOL C������ʵ��ڶ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ��ڶ���View ����

void C������ʵ��ڶ���View::OnDraw(CDC* pDC)
{
	C������ʵ��ڶ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CDC MemDC;
	MemDC.CreateCompatibleDC(NULL);
	MemDC.SelectObject(m_Bitmap);
	pDC->BitBlt(0, 0, m_nWidth, m_nHeight, &MemDC, 0, 0, SRCCOPY);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ��ڶ���View ���

#ifdef _DEBUG
void C������ʵ��ڶ���View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ��ڶ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ��ڶ���Doc* C������ʵ��ڶ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ��ڶ���Doc)));
	return (C������ʵ��ڶ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ��ڶ���View ��Ϣ�������
