
// �ۺ�ʵ��һDoc.h : C�ۺ�ʵ��һDoc ��Ľӿ�
//


#pragma once
#include "�ۺ�ʵ��һSet.h"


class C�ۺ�ʵ��һDoc : public CDocument
{
protected: // �������л�����
	C�ۺ�ʵ��һDoc();
	DECLARE_DYNCREATE(C�ۺ�ʵ��һDoc)

// ����
public:
	C�ۺ�ʵ��һSet m_�ۺ�ʵ��һSet;

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
	virtual ~C�ۺ�ʵ��һDoc();
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
