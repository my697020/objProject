
// �ۺ�ʵ�������2��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ۺ�ʵ�������2��.h"
#include "�ۺ�ʵ�������2��Dlg.h"
#include "afxdialogex.h"

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


// C�ۺ�ʵ�������2��Dlg �Ի���



C�ۺ�ʵ�������2��Dlg::C�ۺ�ʵ�������2��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY2_DIALOG, pParent)
	, path(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ۺ�ʵ�������2��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(C�ۺ�ʵ�������2��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// C�ۺ�ʵ�������2��Dlg ��Ϣ�������

BOOL C�ۺ�ʵ�������2��Dlg::OnInitDialog()
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
	path =_T("C:\\�ۺ�ʵ��\\QQͼƬ20200415090030.jpg");
	

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ۺ�ʵ�������2��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�ۺ�ʵ�������2��Dlg::OnPaint()
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
	CImage im;
	im.Load(path);
	if (!im.IsNull())
	{
		int x, y, wh, hh;
		foo(im, x, y, wh, hh);
		CDC *pDC = GetDlgItem(IDC_STATIC1)->GetDC();
		pDC->SetStretchBltMode(HALFTONE);
		im.Draw(pDC->m_hDC, x, y, wh, hh);
	}
	else
	{
		MessageBox(_T("Load Error"));
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C�ۺ�ʵ�������2��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�ۺ�ʵ�������2��Dlg::foo(CImage& image, int& x, int& y, int& wh, int& hh)
{
	CRect rc;
	GetDlgItem(IDC_STATIC1)->GetClientRect(&rc);

	float img_rit = 1.0*image.GetWidth() / image.GetHeight();
	float clientrect_rit = 1.0*rc.Width() / rc.Height();
	if (clientrect_rit > img_rit)
	{
		hh = rc.Height();
		wh = hh*img_rit;
		x = (rc.Width() - wh) / 2;
		y = 0;

	}
	else
	{
		wh = rc.Width();
		hh = wh;
		x = 0;
		y = (rc.Height() - hh) / 2;


	}
	
}
