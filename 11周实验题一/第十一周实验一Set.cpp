
// ��ʮһ��ʵ��һSet.cpp : C��ʮһ��ʵ��һSet ���ʵ��
//

#include "stdafx.h"
#include "��ʮһ��ʵ��һ.h"
#include "��ʮһ��ʵ��һSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʮһ��ʵ��һSet ʵ��

// ���������� 2020��6��9��, 10:57

IMPLEMENT_DYNAMIC(C��ʮһ��ʵ��һSet, CRecordset)

C��ʮһ��ʵ��һSet::C��ʮһ��ʵ��һSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_1 = L"";
	m_2 = L"";
	m_3 = L"";
	m_4 = L"";
	m_5 = L"";
	m_nFields = 6;
	m_nDefaultType = snapshot;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C��ʮһ��ʵ��һSet::GetDefaultConnect()
{
	return _T("DSN=\x5341\x4e00\x5468;DBQ=C:\\\x5b66\x751f\x7167\x7247\\Database2.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C��ʮһ��ʵ��һSet::GetDefaultSQL()
{
	return _T("[��Ϣ��]");
}

void C��ʮһ��ʵ��һSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[�ֶ�1]"), m_1);
	RFX_Text(pFX, _T("[�ֶ�2]"), m_2);
	RFX_Text(pFX, _T("[�ֶ�3]"), m_3);
	RFX_Text(pFX, _T("[�ֶ�4]"), m_4);
	RFX_Text(pFX, _T("[�ֶ�5]"), m_5);

}
/////////////////////////////////////////////////////////////////////////////
// C��ʮһ��ʵ��һSet ���

#ifdef _DEBUG
void C��ʮһ��ʵ��һSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void C��ʮһ��ʵ��һSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

