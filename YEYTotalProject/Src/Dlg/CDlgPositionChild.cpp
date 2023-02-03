// CDlgPositionChild.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CDlgPositionChild.h"
#include "afxdialogex.h"


// CDlgPositionChild 대화 상자

IMPLEMENT_DYNAMIC(CDlgPositionChild, CDialog)

CDlgPositionChild::CDlgPositionChild(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_POSITION_CHILD, pParent)
{

}

CDlgPositionChild::~CDlgPositionChild()
{
}

void CDlgPositionChild::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPositionChild, CDialog)
END_MESSAGE_MAP()


// CDlgPositionChild 메시지 처리기
