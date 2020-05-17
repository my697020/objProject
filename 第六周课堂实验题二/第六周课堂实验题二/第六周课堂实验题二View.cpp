
// �����ܿ���ʵ�����View.cpp : C�����ܿ���ʵ�����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ܿ���ʵ�����.h"
#endif

#include "�����ܿ���ʵ�����Doc.h"
#include "�����ܿ���ʵ�����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ܿ���ʵ�����View

IMPLEMENT_DYNCREATE(C�����ܿ���ʵ�����View, CView)

BEGIN_MESSAGE_MAP(C�����ܿ���ʵ�����View, CView)
	ON_COMMAND(ID_FILE_OPEN, &C�����ܿ���ʵ�����View::OnFileOpen)
END_MESSAGE_MAP()

// C�����ܿ���ʵ�����View ����/����

C�����ܿ���ʵ�����View::C�����ܿ���ʵ�����View()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ܿ���ʵ�����View::~C�����ܿ���ʵ�����View()
{
}

BOOL C�����ܿ���ʵ�����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ܿ���ʵ�����View ����

void C�����ܿ���ʵ�����View::OnDraw(CDC* pDC)
{
	C�����ܿ���ʵ�����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CClientDC dc(this);
	GetClientRect(&pDoc->rc);
	if (pDoc->flag == 1)
	{
		float img_rit = 1.0*pDoc->image.GetWidth() / pDoc->image.GetHeight();
		float clientrect_rit = 1.0*pDoc->rc.Width() / pDoc->rc.Height();
		if (clientrect_rit > img_rit)
		{
			pDoc->h = pDoc->rc.Height();
			pDoc->w = pDoc->h*img_rit;
			pDoc->sx = (pDoc->rc.Width() - pDoc->w) / 2;
			pDoc->sy = 0;

		}
		else
		{
			pDoc->w = pDoc->rc.Width();
			pDoc->h = pDoc->w;
			pDoc->sx = 0;
			pDoc->sy = (pDoc->rc.Height() - pDoc->h) / 2;


		}
		pDoc->image.Draw(dc.m_hDC, pDoc->sx, pDoc->sy, pDoc->w, pDoc->h);
	}

	
}


// C�����ܿ���ʵ�����View ���

#ifdef _DEBUG
void C�����ܿ���ʵ�����View::AssertValid() const
{
	CView::AssertValid();
}

void C�����ܿ���ʵ�����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ܿ���ʵ�����Doc* C�����ܿ���ʵ�����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ܿ���ʵ�����Doc)));
	return (C�����ܿ���ʵ�����Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����ܿ���ʵ�����View ��Ϣ�������


void C�����ܿ���ʵ�����View::OnFileOpen()
{
	// TODO: �ڴ���������������

	C�����ܿ���ʵ�����Doc* pDoc = GetDocument();
    GetClientRect(&pDoc->rc);
	CFileDialog cfd(true);
	
	int r = cfd.DoModal();
	CClientDC dc(this);
	
	if (r == IDOK) {
		CString filename = cfd.GetPathName();
		pDoc->image.Load(filename);
		pDoc->flag = 1;
   float img_rit=1.0*pDoc->image.GetWidth()/ pDoc->image.GetHeight();
	float clientrect_rit=1.0*pDoc->rc.Width()/pDoc-> rc.Height();
	if (clientrect_rit > img_rit)
	{
		pDoc->h = pDoc->rc.Height();
		pDoc->w =pDoc->h*img_rit;
		pDoc->sx = (pDoc->rc.Width() - pDoc->w) / 2;
		pDoc->sy = 0;
	
	}
	else
	{
		pDoc->w = pDoc->rc.Width();
		pDoc->h = pDoc->w;
		pDoc->sx = 0;
		pDoc->sy = (pDoc->rc.Height() - pDoc->h)/2;
		
		
	}
		

	pDoc->image.Draw(dc.m_hDC, pDoc->sx, pDoc->sy, pDoc->w, pDoc->h);


	}
	
}
