
// �ۺ�ʵ����Set.cpp : C�ۺ�ʵ����Set ���ʵ��
//

#include "stdafx.h"
#include "�ۺ�ʵ����.h"
#include "�ۺ�ʵ����Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ۺ�ʵ����Set ʵ��

// ���������� 2020��7��8��, 19:19

IMPLEMENT_DYNAMIC(C�ۺ�ʵ����Set, CRecordset)

C�ۺ�ʵ����Set::C�ۺ�ʵ����Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = L"";
	m_nFields = 6;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString C�ۺ�ʵ����Set::GetDefaultConnect()
{
	return _T("DSN=\x7efc\x5408\x5b9e\x9a8c\x56db;DBQ=C:\\Users\\16932\\Documents\\Database1.mdb;DefaultDir=C:\\Users\\16932\\Documents;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString C�ۺ�ʵ����Set::GetDefaultSQL()
{
	return _T("[ѧ����Ϣ��]");
}

void C�ۺ�ʵ����Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[����]"), column1);
	RFX_Text(pFX, _T("[ѧ��]"), column2);
	RFX_Text(pFX, _T("[����]"), column3);
	RFX_Text(pFX, _T("[�ֻ�����]"), column4);
	RFX_Text(pFX, _T("[��Ƭ��ַ]"), column5);

}
/////////////////////////////////////////////////////////////////////////////
// C�ۺ�ʵ����Set ���

#ifdef _DEBUG
void C�ۺ�ʵ����Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C�ۺ�ʵ����Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

