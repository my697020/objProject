
// ��ʮһ��ʵ��һDoc.h : C��ʮһ��ʵ��һDoc ��Ľӿ�
//


#pragma once
#include "��ʮһ��ʵ��һSet.h"


class C��ʮһ��ʵ��һDoc : public CDocument
{
protected: // �������л�����
	C��ʮһ��ʵ��һDoc();
	DECLARE_DYNCREATE(C��ʮһ��ʵ��һDoc)

// ����
public:
	C��ʮһ��ʵ��һSet m_��ʮһ��ʵ��һSet;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��ʮһ��ʵ��һDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
