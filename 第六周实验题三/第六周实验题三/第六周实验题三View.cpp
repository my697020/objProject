
// ������ʵ������View.cpp : C������ʵ������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʵ������.h"
#endif

#include "������ʵ������Doc.h"
#include "������ʵ������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʵ������View

IMPLEMENT_DYNCREATE(C������ʵ������View, CView)

BEGIN_MESSAGE_MAP(C������ʵ������View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// C������ʵ������View ����/����

C������ʵ������View::C������ʵ������View()
{
	// TODO: �ڴ˴���ӹ������
	line = "";

	rc.left = 200;
	rc.top = 200;
	rc.bottom = 600;
	rc.right = 800;
	x = 215;
	y = 201;
}

C������ʵ������View::~C������ʵ������View()
{
}

BOOL C������ʵ������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʵ������View ����

void C������ʵ������View::OnDraw(CDC* pDC)
{
	C������ʵ������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->Rectangle(rc);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C������ʵ������View ��ӡ

BOOL C������ʵ������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʵ������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʵ������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʵ������View ���

#ifdef _DEBUG
void C������ʵ������View::AssertValid() const
{
	CView::AssertValid();
}

void C������ʵ������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʵ������Doc* C������ʵ������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʵ������Doc)));
	return (C������ʵ������Doc*)m_pDocument;
}
#endif //_DEBUG


// C������ʵ������View ��Ϣ�������


void C������ʵ������View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CClientDC dc(this);
	TEXTMETRIC tm;
	dc.GetTextMetrics(&tm);
	line.AppendChar(nChar);
	c = dc.GetTextExtent(line);
	
	if (c.cx>=(rc.right - rc.left)&&(c.cy<rc.Height()))
	{
		
		x = x + tm.tmHeight;
		line.Empty();
	}
	if (c.cx<(rc.right - rc.left))
		dc.TextOutW(y,x, line);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
