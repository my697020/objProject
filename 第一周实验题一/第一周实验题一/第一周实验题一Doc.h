
// ��һ��ʵ����һDoc.h : C��һ��ʵ����һDoc ��Ľӿ�
//


#pragma once


class C��һ��ʵ����һDoc : public CDocument
{
protected: // �������л�����
	C��һ��ʵ����һDoc();
	DECLARE_DYNCREATE(C��һ��ʵ����һDoc)

// ����
public:
	CString name;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~C��һ��ʵ����һDoc();
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
