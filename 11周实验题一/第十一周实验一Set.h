
// ��ʮһ��ʵ��һSet.h: C��ʮһ��ʵ��һSet ��Ľӿ�
//


#pragma once

// ���������� 2020��6��9��, 10:57

class C��ʮһ��ʵ��һSet : public CRecordset
{
public:
	C��ʮһ��ʵ��һSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(C��ʮһ��ʵ��һSet)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_ID;
	CStringW	m_1;
	CStringW	m_2;
	CStringW	m_3;
	CStringW	m_4;
	CStringW	m_5;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

