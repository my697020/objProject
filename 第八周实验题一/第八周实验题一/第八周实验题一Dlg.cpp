
// �ڰ���ʵ����һDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ڰ���ʵ����һ.h"
#include "�ڰ���ʵ����һDlg.h"
#include "afxdialogex.h"
#include"Dialog1.h"
#include"Dialog2.h"
#include"Dialog3.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C�ڰ���ʵ����һDlg �Ի���



C�ڰ���ʵ����һDlg::C�ڰ���ʵ����һDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, one(0)
	, two(0)
	, result(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ڰ���ʵ����һDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, one);
	DDX_Text(pDX, IDC_EDIT3, two);
	DDX_Text(pDX, IDC_EDIT4, result);
}

BEGIN_MESSAGE_MAP(C�ڰ���ʵ����һDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &C�ڰ���ʵ����һDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &C�ڰ���ʵ����һDlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &C�ڰ���ʵ����һDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C�ڰ���ʵ����һDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C�ڰ���ʵ����һDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C�ڰ���ʵ����һDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &C�ڰ���ʵ����һDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &C�ڰ���ʵ����һDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// C�ڰ���ʵ����һDlg ��Ϣ�������

BOOL C�ڰ���ʵ����һDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ڰ���ʵ����һDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C�ڰ���ʵ����һDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ڰ���ʵ����һDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�ڰ���ʵ����һDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C�ڰ���ʵ����һDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void C�ڰ���ʵ����һDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	result = one + two;
	UpdateData(false);
}


void C�ڰ���ʵ����һDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	result = one-two;
	UpdateData(false);
}


void C�ڰ���ʵ����һDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	result = one*two;
	UpdateData(false);
}


void C�ڰ���ʵ����һDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if (two != 0) {

	result = one/two;
	UpdateData(false);
	}
	else
	{
		Dialog2 dlg1;
		dlg1.DoModal();
	}
}


void C�ڰ���ʵ����һDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if (one != 0) 
	{ result = 1 /one; UpdateData(false); }
	else
	{
		Dialog1 dlg;
		dlg.DoModal();

	}
}


void C�ڰ���ʵ����һDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(one>=0){
		result = sqrt(one);
		UpdateData(false);
	}
	else {
		Dialog3 dlg2;
		dlg2.DoModal();
	}
}
