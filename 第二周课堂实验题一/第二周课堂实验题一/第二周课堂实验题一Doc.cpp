
// �ڶ��ܿ���ʵ����һDoc.cpp : C�ڶ��ܿ���ʵ����һDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڶ��ܿ���ʵ����һ.h"
#endif

#include "�ڶ��ܿ���ʵ����һDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ڶ��ܿ���ʵ����һDoc

IMPLEMENT_DYNCREATE(C�ڶ��ܿ���ʵ����һDoc, CDocument)

BEGIN_MESSAGE_MAP(C�ڶ��ܿ���ʵ����һDoc, CDocument)
END_MESSAGE_MAP()


// C�ڶ��ܿ���ʵ����һDoc ����/����

C�ڶ��ܿ���ʵ����һDoc::C�ڶ��ܿ���ʵ����һDoc()
{
	// TODO: �ڴ����һ���Թ������

}

C�ڶ��ܿ���ʵ����һDoc::~C�ڶ��ܿ���ʵ����һDoc()
{
}

BOOL C�ڶ��ܿ���ʵ����һDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�ڶ��ܿ���ʵ����һDoc ���л�

void C�ڶ��ܿ���ʵ����һDoc::Serialize(CArchive& ar)
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
void C�ڶ��ܿ���ʵ����һDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C�ڶ��ܿ���ʵ����һDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�ڶ��ܿ���ʵ����һDoc::SetSearchContent(const CString& value)
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

// C�ڶ��ܿ���ʵ����һDoc ���

#ifdef _DEBUG
void C�ڶ��ܿ���ʵ����һDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ڶ��ܿ���ʵ����һDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ڶ��ܿ���ʵ����һDoc ����
