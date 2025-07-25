﻿
// MFCNetClientDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCNetClient.h"
#include "MFCNetClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCNetClientDlg 대화 상자



CMFCNetClientDlg::CMFCNetClientDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCNETCLIENT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCNetClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCNetClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCNetClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCNetClientDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCNetClientDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCNetClientDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCNetClientDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCNetClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCNetClientDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCNetClientDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCNetClientDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCNetClientDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCNetClientDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCNetClientDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCNetClientDlg::OnBnClickedButton13)
END_MESSAGE_MAP()


// CMFCNetClientDlg 메시지 처리기

BOOL CMFCNetClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCNetClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCNetClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCNetClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCNetClientDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST, _T("이미지 파일|*.bmp;*.png;*.jpg;*.jpeg|모든 파일|*.*||"));
	if (dlg.DoModal() == IDOK)
	{
		CString path = dlg.GetPathName();
		CString cmd = _T("OPEN ") + path;

		// 서버로 명령 보내기
		AfxSocketInit();
		CSocket sock;
		sock.Create();
		if (sock.Connect(_T("127.0.0.1"), 9999))  
		{
			CStringA cmdA(cmd); 
			sock.Send(cmdA.GetBuffer(), cmdA.GetLength());

			sock.Close();
			AfxMessageBox(_T("이미지 열기 명령 전송 완료!"));
		}
		else
		{
			AfxMessageBox(_T("서버 연결 실패!"));
		}
	}
}

void CMFCNetClientDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("SAVEAS");

	// 서버로 명령 보내기
	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd); // ANSI 변환
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("다른 이름으로 저장 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}
void CMFCNetClientDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("FLIP_H");  // 좌우반전 명령

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd); // ANSI 변환
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("좌우반전 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}void CMFCNetClientDlg::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("FLIP_V");  // 좌우반전 명령

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd); // ANSI 변환
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("좌우반전 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}
void CMFCNetClientDlg::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("CHANNEL_R"); 

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd);
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("R채널 추출 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}
void CMFCNetClientDlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("CHANNEL_G");  

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd);
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("G채널 추출 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}

}
void CMFCNetClientDlg::OnBnClickedButton7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("CHANNEL_B"); 

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd);
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("B채널 추출 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}
void CMFCNetClientDlg::OnBnClickedButton8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("DRAW_LINE");

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd);
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("직선그리기 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}


void CMFCNetClientDlg::OnBnClickedButton9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("DRAW_RECT");

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd);
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("사각형그리기 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}

void CMFCNetClientDlg::OnBnClickedButton10()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("DRAW_ELLIPSE");

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd);
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("원그리기 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}

void CMFCNetClientDlg::OnBnClickedButton11()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString cmd = _T("SAVE");

	AfxSocketInit();
	CSocket sock;
	sock.Create();
	if (sock.Connect(_T("127.0.0.1"), 9999))
	{
		CStringA cmdA(cmd);
		sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
		sock.Close();
		AfxMessageBox(_T("저장 명령 전송 완료!"));
	}
	else
	{
		AfxMessageBox(_T("서버 연결 실패!"));
	}
}

void CMFCNetClientDlg::OnBnClickedButton12()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		COLORREF color = dlg.GetColor();
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		CString cmd;
		cmd.Format(_T("SET_FILLCOLOR %d %d %d"), r, g, b);

		// 2. 서버로 색상정보 전송 (아래는 이미 네트워크 통신 방식에 맞춤)
		AfxSocketInit();
		CSocket sock;
		sock.Create();
		if (sock.Connect(_T("127.0.0.1"), 9999))
		{
			CStringA cmdA(cmd);
			sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
			sock.Close();
			AfxMessageBox(_T("채우기 색상 명령 전송 완료!"));
		}
		else
			AfxMessageBox(_T("서버 연결 실패!"));
	}
}

void CMFCNetClientDlg::OnBnClickedButton13()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		COLORREF color = dlg.GetColor();
		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		CString cmd;
		cmd.Format(_T("SET_BORDERCOLOR %d %d %d"), r, g, b);

		// 소켓으로 명령 전송
		AfxSocketInit();
		CSocket sock;
		sock.Create();
		if (sock.Connect(_T("127.0.0.1"), 9999))
		{
			CStringA cmdA(cmd);
			sock.Send(cmdA.GetBuffer(), cmdA.GetLength());
			sock.Close();
			AfxMessageBox(_T("외곽선 색상 명령 전송 완료!"));
		}
		else
		{
			AfxMessageBox(_T("서버 연결 실패!"));
		}
	}
}
