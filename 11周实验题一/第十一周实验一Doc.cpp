
// ��ʮһ��ʵ��һDoc.cpp : C��ʮһ��ʵ��һDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʮһ��ʵ��һ.h"
#endif

#include "��ʮһ��ʵ��һSet.h"
#include "��ʮһ��ʵ��һDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ʮһ��ʵ��һDoc

IMPLEMENT_DYNCREATE(C��ʮһ��ʵ��һDoc, CDocument)

BEGIN_MESSAGE_MAP(C��ʮһ��ʵ��һDoc, CDocument)
END_MESSAGE_MAP()


// C��ʮһ��ʵ��һDoc ����/����

C��ʮһ��ʵ��һDoc::C��ʮһ��ʵ��һDoc()
{
	// TODO: �ڴ����һ���Թ������

}

C��ʮһ��ʵ��һDoc::~C��ʮһ��ʵ��һDoc()
{
}

BOOL C��ʮһ��ʵ��һDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}



#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void C��ʮһ��ʵ��һDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C��ʮһ��ʵ��һDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void C��ʮһ��ʵ��һDoc::SetSearchContent(const CString& value)
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

// C��ʮһ��ʵ��һDoc ���

#ifdef _DEBUG
void C��ʮһ��ʵ��һDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void C��ʮһ��ʵ��һDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C��ʮһ��ʵ��һDoc ����
