
// �ڰ��ܿ���ʵ������Doc.cpp : C�ڰ��ܿ���ʵ������Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ��ܿ���ʵ������.h"
#endif

#include "�ڰ��ܿ���ʵ������Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ڰ��ܿ���ʵ������Doc

IMPLEMENT_DYNCREATE(C�ڰ��ܿ���ʵ������Doc, CDocument)

BEGIN_MESSAGE_MAP(C�ڰ��ܿ���ʵ������Doc, CDocument)
END_MESSAGE_MAP()


// C�ڰ��ܿ���ʵ������Doc ����/����

C�ڰ��ܿ���ʵ������Doc::C�ڰ��ܿ���ʵ������Doc()
{
	// TODO: �ڴ����һ���Թ������

}

C�ڰ��ܿ���ʵ������Doc::~C�ڰ��ܿ���ʵ������Doc()
{
}

BOOL C�ڰ��ܿ���ʵ������Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�ڰ��ܿ���ʵ������Doc ���л�

void C�ڰ��ܿ���ʵ������Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C�ڰ��ܿ���ʵ������Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void C�ڰ��ܿ���ʵ������Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�ڰ��ܿ���ʵ������Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// C�ڰ��ܿ���ʵ������Doc ���

#ifdef _DEBUG
void C�ڰ��ܿ���ʵ������Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ڰ��ܿ���ʵ������Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ڰ��ܿ���ʵ������Doc ����
