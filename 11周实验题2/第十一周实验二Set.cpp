
// ��ʮһ��ʵ���Set.cpp : C��ʮһ��ʵ���Set ���ʵ��
//

#include "stdafx.h"
#include "��ʮһ��ʵ���.h"
#include "��ʮһ��ʵ���Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ��ʵ���Set ʵ��

// ���������� 2020��6��9��, 19:37

IMPLEMENT_DYNAMIC(C��ʮһ��ʵ���Set, CRecordset)

C��ʮһ��ʵ���Set::C��ʮһ��ʵ���Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ʮһ��ʵ���Set::GetDefaultConnect()
{
	return _T("DSN=\x5341\x4e00\x5468;DBQ=C:\\\x5b66\x751f\x7167\x7247\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ʮһ��ʵ���Set::GetDefaultSQL()
{
	return _T("[��Ϣ��]");
}

void C��ʮһ��ʵ���Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[����]"), column2);
	RFX_Text(pFX, _T("[ѧ��]"), column3);
	RFX_Text(pFX, _T("[�绰]"), column4);
	RFX_Text(pFX, _T("[��Ƭ·��]"), column5);


}
/////////////////////////////////////////////////////////////////////////////
// C��ʮһ��ʵ���Set ���

#ifdef _DEBUG
void C��ʮһ��ʵ���Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ʮһ��ʵ���Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

