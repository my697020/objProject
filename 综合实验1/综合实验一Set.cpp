
// �ۺ�ʵ��һSet.cpp : C�ۺ�ʵ��һSet ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ��һ.h"
#include "�ۺ�ʵ��һSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ��һSet ʵ��

// ���������� 2020��6��9��, 22:52

IMPLEMENT_DYNAMIC(C�ۺ�ʵ��һSet, CRecordset)

C�ۺ�ʵ��һSet::C�ۺ�ʵ��һSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	m_nFields = 2;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ��һSet::GetDefaultConnect()
{
	return _T("DSN=\x7efc\x5408\x5b9e\x9a8c;DBQ=C:\\\x7efc\x5408\x5b9e\x9a8c\\Database31.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C�ۺ�ʵ��һSet::GetDefaultSQL()
{
	return _T("[��Ƭ]");
}

void C�ۺ�ʵ��һSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[ͼƬ�ļ���]"), column1);
}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ��һSet ���

#ifdef _DEBUG
void C�ۺ�ʵ��һSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ��һSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

