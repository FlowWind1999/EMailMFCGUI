
// MyMailDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MyMail.h"
#include "MyMailDlg.h"
#include "afxdialogex.h"
#include "Smtpmail.h"
#include "SMTPSET.h"
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//����STMP���ð����µĶԻ���
CString Buffer1;
CString Buffer2;

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

void   CMyMailDlg::SetControlInfo(WORD   CtrlId)
{
	m_control_info.Add(CtrlId);

}

CMyMailDlg::CMyMailDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MYMAIL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_old_cx = m_old_cy = 0;
}

void CMyMailDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyMailDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//����������MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CMyMailDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyMailDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyMailDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CMyMailDlg::OnEnChangeEdit1)
	ON_STN_CLICKED(IDC_ACCEPTADDR, &CMyMailDlg::OnStnClickedAcceptaddr)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// ��Ϣ�������
BOOL CMyMailDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
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
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	
	SetControlInfo(IDC_SET);//��ӿؼ�����
	SetControlInfo(IDC_NAME);
	SetControlInfo(IDC_EDIT1);
	SetControlInfo(IDC_PASSWORD);
	SetControlInfo(IDC_EDIT2);
	SetControlInfo(IDC_SENDADDR);
	SetControlInfo(IDC_EDIT3);
	SetControlInfo(IDC_ACCEPTADDR);
	SetControlInfo(IDC_EDIT4);
	SetControlInfo(IDC_SUBJECT);
	SetControlInfo(IDC_EDIT5);
	SetControlInfo(IDC_BUTTON1);
	SetControlInfo(IDC_BUTTON2);
	SetControlInfo(IDC_BUTTON3);
	SetControlInfo(IDC_CONTENT);
	SetControlInfo(IDC_EDIT6);
	SetControlInfo(IDC_STATIC0);
	//�Զ�����ʼ����
	GetDlgItem(IDC_EDIT1)->SetWindowText("m18810562015_1@163.com");
	GetDlgItem(IDC_EDIT2)->SetWindowText(""); /*fevdqvwyubcrbbbj*//*mrgpxkzgfzwdbfij*/
	GetDlgItem(IDC_EDIT3)->SetWindowText("m18810562015_1@163.com");
	GetDlgItem(IDC_EDIT4)->SetWindowText("m18810562015_1@163.com");
	GetDlgItem(IDC_EDIT5)->SetWindowText("����BUPT���ʺ�");
	GetDlgItem(IDC_EDIT6)->SetWindowText("��ã�");

	return TRUE;  
}

void CMyMailDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

//ʹ����֪
void CMyMailDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	char buffer[1023] = { 0 };
	ifstream  Guidance("ʹ����֪.txt");
	if (!Guidance.fail())
	{
		int i = 0;
		while (!Guidance.eof())
		{
			Guidance.get(buffer[i]);
			i++;
		}
		Guidance.close();
	}
	MessageBox(buffer, "ʹ��˵��", MB_OK);
}

//��ӱ���
void CMyMailDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); 
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CFile m_file("Background.jpg", CFile::modeRead);//��ȡͼƬ�ļ�
		DWORD m_filelen = m_file.GetLength();//��ȡ�ļ�����
		HGLOBAL m_hglobal = GlobalAlloc(GMEM_MOVEABLE, m_filelen);
        LPVOID pvdata = NULL;
		pvdata = GlobalLock(m_hglobal);
		m_file.Read(pvdata, m_filelen);
		IStream*  m_stream;
		GlobalUnlock(m_hglobal);
		CreateStreamOnHGlobal(m_hglobal, TRUE, &m_stream);
		OleLoadPicture(m_stream, m_filelen, TRUE, IID_IPicture, (LPVOID*)&m_picture);
		m_stream->Release();
		m_picture->get_Width(&m_width);
		m_picture->get_Height(&m_height);
		m_IsShow = TRUE;
		m_file.Close();

		if (m_IsShow == TRUE) {
			CRect rect;
			GetClientRect(rect);
			int nW, nH;
			nW = (int)(rect.Width());
			nH = (int)(rect.Height());
			m_picture->Render(dc, 0, 0, nW, nH, 0, m_height, m_width, -m_height, &rect);
		}
		CDialogEx::OnPaint();
	}
}

HCURSOR CMyMailDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyMailDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

//�����ʼ�
void CMyMailDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    CString buffer;

	if (Buffer1.IsEmpty())
	{
		MessageBox("��������ַ����Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}

	if (Buffer2.IsEmpty())
	{
		MessageBox("�˿ڲ���Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}
	char* SmtpSrvName = Buffer1.GetBuffer(Buffer1.GetLength());
	char* Port = Buffer2.GetBuffer(Buffer2.GetLength());
	GetDlgItem(IDC_EDIT1)->GetWindowText(buffer);
	if (buffer.IsEmpty())
	{
		MessageBox("�û�������Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}
	char UserName[32];
	strcpy(UserName, buffer.GetBuffer(buffer.GetLength()));
	buffer.ReleaseBuffer();
	GetDlgItem(IDC_EDIT2)->GetWindowText(buffer);
	if (buffer.IsEmpty())
	{
		MessageBox("���벻��Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}
	char Password[16];
	strcpy(Password, buffer.GetBuffer(buffer.GetLength()));
	buffer.ReleaseBuffer();
	GetDlgItem(IDC_EDIT3)->GetWindowText(buffer);
	if (buffer.IsEmpty())
	{
		MessageBox("�����˵�ַ����Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}
	char From[32];
	strcpy(From, buffer.GetBuffer(buffer.GetLength()));
	buffer.ReleaseBuffer();
	GetDlgItem(IDC_EDIT4)->GetWindowText(buffer);
	if (buffer.IsEmpty())
	{
		MessageBox("�ռ��˵�ַ����Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}
	char To[32];
	strcpy(To, buffer.GetBuffer(buffer.GetLength()));
	buffer.ReleaseBuffer();
	GetDlgItem(IDC_EDIT5)->GetWindowText(buffer);
	if (buffer.IsEmpty())
	{
		MessageBox("���ⲻ��Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}
	char Subject[32];
	strcpy(Subject, buffer.GetBuffer(buffer.GetLength()));
	buffer.ReleaseBuffer();
	GetDlgItem(IDC_EDIT6)->GetWindowText(buffer);
	if (buffer.IsEmpty())
	{
		MessageBox("�ʼ����ݲ���Ϊ�գ�", "��ʾ", MB_OK);
		return;
	}
	char Msg[64];
	strcpy(Msg, buffer.GetBuffer(buffer.GetLength()));
	buffer.ReleaseBuffer();

	SmtpMail mymail(SmtpSrvName, Port, UserName, Password,
		From, To, Subject, Msg);

	if(NULL==mymail.SendMail())
		MessageBox("�ɹ�����!");

}

//smtp����
void CMyMailDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SMTPSET Dlg;
	Dlg.DoModal();
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
}

void CMyMailDlg::OnStnClickedAcceptaddr()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}

void CMyMailDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	if (cx == 0 || cy == 0)
	{
		cx = 800;
		cy = 600;
	}
	float   dx_percent = (m_old_cx == 0) ? 1 : (float)((float)cx / (float)m_old_cx);
	float   dy_percent = (m_old_cy == 0) ? 1 : (float)((float)cy / (float)m_old_cy);

	if (m_old_cx)
	{
		CRect   WndRect;
		CWnd   *pWnd;
		for (int i = 0; i < m_control_info.GetSize(); i++)
		{
			pWnd = GetDlgItem(m_control_info[i]);
			if (!pWnd)
			{
				TRACE("Control   ID   -  %d   NOT   FOUND!!\n ", m_control_info[i]);


				continue;
			}

			pWnd->GetWindowRect(&WndRect);
			ScreenToClient(&WndRect);

			WndRect.left = (int)(WndRect.left*dx_percent);
			WndRect.right = (int)(WndRect.right*   dx_percent);
			WndRect.bottom = (int)(WndRect.bottom*dy_percent);
			WndRect.top = (int)(WndRect.top*dy_percent);

			pWnd->MoveWindow(&WndRect);
		}

	}
	m_old_cx = cx;
	m_old_cy = cy;
}
