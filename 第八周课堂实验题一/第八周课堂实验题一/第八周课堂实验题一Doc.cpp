
// �ڰ��ܿ���ʵ����һDoc.cpp : C�ڰ��ܿ���ʵ����һDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ڰ��ܿ���ʵ����һ.h"
#endif

#include "�ڰ��ܿ���ʵ����һDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ڰ��ܿ���ʵ����һDoc

IMPLEMENT_DYNCREATE(C�ڰ��ܿ���ʵ����һDoc, CDocument)

BEGIN_MESSAGE_MAP(C�ڰ��ܿ���ʵ����һDoc, CDocument)
END_MESSAGE_MAP()


// C�ڰ��ܿ���ʵ����һDoc ����/����

C�ڰ��ܿ���ʵ����һDoc::C�ڰ��ܿ���ʵ����һDoc()
{
	// TODO: �ڴ����һ���Թ������

}

C�ڰ��ܿ���ʵ����һDoc::~C�ڰ��ܿ���ʵ����һDoc()
{
}

BOOL C�ڰ��ܿ���ʵ����һDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�ڰ��ܿ���ʵ����һDoc ���л�

void C�ڰ��ܿ���ʵ����һDoc::Serialize(CArchive& ar)
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
void C�ڰ��ܿ���ʵ����һDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C�ڰ��ܿ���ʵ����һDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�ڰ��ܿ���ʵ����һDoc::SetSearchContent(const CString& value)
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

// C�ڰ��ܿ���ʵ����һDoc ���

#ifdef _DEBUG
void C�ڰ��ܿ���ʵ����һDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ڰ��ܿ���ʵ����һDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ڰ��ܿ���ʵ����һDoc ����
