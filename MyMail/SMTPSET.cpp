// SMTPSET.cpp : ʵ���ļ�
// SMTPSET �Ի���

#include "stdafx.h"
#include "MyMail.h"
#include "SMTPSET.h"
#include "afxdialogex.h"
extern CString Buffer1;
extern CString Buffer2;

IMPLEMENT_DYNAMIC(SMTPSET, CDialogEx)

SMTPSET::SMTPSET(CWnd* pParent)
	: CDialogEx(IDD_SMTPSET, pParent)
{
}

BOOL SMTPSET::OnInitDialog()
{
	if (Buffer1.IsEmpty() && Buffer2.IsEmpty())
	{
		GetDlgItem(IDC_EDIT7)->SetWindowText("smtp.163.com");
		GetDlgItem(IDC_EDIT8)->SetWindowText("25");
	}
	else 
	{
		GetDlgItem(IDC_EDIT7)->SetWindowText(Buffer1);
		GetDlgItem(IDC_EDIT8)->SetWindowText(Buffer2);
	}
	return true;
}

SMTPSET::~SMTPSET()
{
}

void SMTPSET::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(SMTPSET, CDialogEx)
	ON_BN_CLICKED(ID_BTOK, &SMTPSET::OnBnClickedBtok)
	ON_BN_CLICKED(IDC_BTCLEAR, &SMTPSET::OnBnClickedBtclear)
END_MESSAGE_MAP()

//��Ϣ�������
void SMTPSET::OnBnClickedBtok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_EDIT7)->GetWindowText(Buffer1);
	GetDlgItem(IDC_EDIT8)->GetWindowText(Buffer2);
	if (Buffer1.IsEmpty())
		MessageBox("��������ַ����Ϊ�գ�", "��ʾ", MB_OK);
	if (Buffer2.IsEmpty())
		MessageBox("�˿ڲ���Ϊ�գ�", "��ʾ", MB_OK);
	if (!Buffer1.IsEmpty() && !Buffer2.IsEmpty())
	{
		OnCancel();
	}
}

void SMTPSET::OnBnClickedBtclear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	SetDlgItemText(IDC_EDIT7, "");
	SetDlgItemText(IDC_EDIT8, "");
}


