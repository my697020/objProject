
// �ھ��ܿ���ʵ����һDoc.cpp : C�ھ��ܿ���ʵ����һDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ھ��ܿ���ʵ����һ.h"
#endif

#include "�ھ��ܿ���ʵ����һDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C�ھ��ܿ���ʵ����һDoc

IMPLEMENT_DYNCREATE(C�ھ��ܿ���ʵ����һDoc, CDocument)

BEGIN_MESSAGE_MAP(C�ھ��ܿ���ʵ����һDoc, CDocument)
END_MESSAGE_MAP()


// C�ھ��ܿ���ʵ����һDoc ����/����

C�ھ��ܿ���ʵ����һDoc::C�ھ��ܿ���ʵ����һDoc()
{
	// TODO: �ڴ����һ���Թ������
	name = _T("");

}

C�ھ��ܿ���ʵ����һDoc::~C�ھ��ܿ���ʵ����һDoc()
{
}

BOOL C�ھ��ܿ���ʵ����һDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// C�ھ��ܿ���ʵ����һDoc ���л�

void C�ھ��ܿ���ʵ����һDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		ar << name;
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		ar >> name;
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C�ھ��ܿ���ʵ����һDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C�ھ��ܿ���ʵ����һDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C�ھ��ܿ���ʵ����һDoc::SetSearchContent(const CString& value)
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

// C�ھ��ܿ���ʵ����һDoc ���

#ifdef _DEBUG
void C�ھ��ܿ���ʵ����һDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C�ھ��ܿ���ʵ����һDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C�ھ��ܿ���ʵ����һDoc ����
