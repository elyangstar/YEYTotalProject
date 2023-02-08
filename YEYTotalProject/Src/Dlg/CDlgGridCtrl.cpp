// CDlgGridCtrl.cpp: 구현 파일
//

#include "../../pch.h"
#include "../../YEYTotalProject.h"
#include "CDlgGridCtrl.h"
#include "afxdialogex.h"

#define GRID_COL 4
// CDlgGridCtrl 대화 상자

IMPLEMENT_DYNAMIC(CDlgGridCtrl, CDialog)

CDlgGridCtrl::CDlgGridCtrl(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_GRIDCTRL, pParent)
{
	m_nGridCtrlRowCount = 0;
}

CDlgGridCtrl::~CDlgGridCtrl()
{
}

void CDlgGridCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GRIDCTRL, m_GridCtrl);
	DDX_Text(pDX, IDC_GRID_ROW_COUNT, m_nGridCtrlRowCount);
}

BOOL CDlgGridCtrl::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (m_nGridCtrlRowCount == 0)
		return FALSE;

	initGridCtrl();
	inputGridCtrl();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgGridCtrl::initGridCtrl()
{
	//m_GridCtrl.DeleteAllItems();
	m_GridCtrl.GetDefaultCell(FALSE, FALSE)->SetBackClr(RGB(242, 242, 242));
	m_GridCtrl.SetFixedBkColor(RGB(215, 228, 188));
	m_GridCtrl.SetFixedTextColor(RGB(0, 0, 0));
	m_GridCtrl.SetGridLineColor(RGB(80, 80, 80));
	m_GridCtrl.SetGridLines(GVL_BOTH);

	int nRow = m_nGridCtrlRowCount+1;				//3(DefectType, DefectSubType, DefectJudge) + SC_COUNT + 1
	int nCol = GRID_COL;

	m_GridCtrl.SetColumnCount(nCol);
	m_GridCtrl.SetRowCount(nRow);
	m_GridCtrl.SetFixedRowCount(1);
	//m_ctrlConditionGrid.SetFixedColumnCount(1);

	m_GridCtrl.ExpandColumnsToFit();


	CFont *pFont = m_GridCtrl.GetFont();
	if (!pFont)
		return;

	LOGFONT lf;
	pFont->GetLogFont(&lf);
	lf.lfItalic = 0;
	lf.lfHeight = 14;
	lf.lfWeight = FW_BOLD;
	strcpy_s(lf.lfFaceName, _T("Arial"));

	m_GridCtrl.GetDefaultCell(TRUE, FALSE)->SetFont(&lf);
	m_GridCtrl.GetDefaultCell(FALSE, TRUE)->SetFont(&lf);
	m_GridCtrl.GetDefaultCell(TRUE, TRUE)->SetFont(&lf);

	m_GridCtrl.SetEditable(TRUE);
	m_GridCtrl.EnableSelection(TRUE);


	{
		int itemcnt = 0;
		m_GridCtrl.SetItemText(0, itemcnt++, "No.");//"번호");
		m_GridCtrl.SetItemText(0, itemcnt++, "Type");//"조건");
		m_GridCtrl.SetItemText(0, itemcnt++, "Condition");//"판정 조건");
		m_GridCtrl.SetItemText(0, itemcnt++, "Judge Decision");//"최종판정");
	}

	GV_ITEM Item;
	Item.mask = GVIF_TEXT;

	for (int i = 1; i <= m_nGridCtrlRowCount; i++)
	{
		Item.row = i;
		m_GridCtrl.SetCellType(Item.row, 2, RUNTIME_CLASS(CGridCellCheck));
		m_GridCtrl.SetCellType(Item.row, 3, RUNTIME_CLASS(CGridCellCombo));
	}

	m_GridCtrl.Invalidate(FALSE);
}
void CDlgGridCtrl::inputGridCtrl()
{
	CString strValue = "";
	CStringArray GateDataOptions;
	GateDataOptions.Add(_T("1"));
	GateDataOptions.Add(_T("2"));
	GateDataOptions.Add(_T("3"));

	GV_ITEM Item;
	Item.mask = GVIF_TEXT;

	for (int i = 1; i <= m_nGridCtrlRowCount; i++)
	{
		int nCon = 0;
		Item.row = i ;

		Item.col = nCon++;
		strValue.Format("%d", i);
		Item.strText = strValue;
		m_GridCtrl.SetItem(&Item);

		Item.col = nCon++;
		strValue.Format("%d", nCon);
		Item.strText = strValue;
		m_GridCtrl.SetItem(&Item);

		CGridCellCheck *pCellCheck;
		Item.col = nCon++;
		Item.strText.Format("Use");
		m_GridCtrl.SetItem(&Item);
		pCellCheck = (CGridCellCheck*)m_GridCtrl.GetCell(Item.row, Item.col);
		//pCellCheck->SetCheck(TRUE);

		CGridCellCombo *pCell;
		pCell = (CGridCellCombo*)m_GridCtrl.GetCell(Item.row, Item.col);
		Item.col = nCon++;
		m_GridCtrl.SetItemText(Item.row, Item.col, _T("Num"));

		pCell = (CGridCellCombo*)m_GridCtrl.GetCell(Item.row, Item.col);
		pCell->SetOptions(GateDataOptions);
		pCell->SetStyle(CBS_DROPDOWNLIST);
	}
	m_GridCtrl.Invalidate(FALSE);
}

void CDlgGridCtrl::SetGridNewRowCount()
{
	m_GridCtrl.SetRowCount(m_nGridCtrlRowCount+1);
	
	CString strValue = "";
	CStringArray GateDataOptions;
	GateDataOptions.Add(_T("2222"));
	GateDataOptions.Add(_T("3333"));
	GateDataOptions.Add(_T("4444"));

	GV_ITEM Item;
	Item.mask = GVIF_TEXT;

	for (int i = 1; i <= m_nGridCtrlRowCount; i++)
	{
		int nCon = 0;
		Item.row = i;

		Item.col = nCon++;
		strValue.Format("%d", i);
		Item.strText = strValue;
		m_GridCtrl.SetItem(&Item);

		Item.col = nCon++;
		strValue.Format("%d", i);
		Item.strText = strValue;
		m_GridCtrl.SetItem(&Item);

		CGridCellCheck *pCellCheck;
		Item.col = nCon++;
		Item.strText.Format("Use");
		m_GridCtrl.SetItem(&Item);
		pCellCheck = (CGridCellCheck*)m_GridCtrl.GetCell(Item.row, Item.col);
		//pCellCheck->SetCheck(TRUE);

		CGridCellCombo *pCell;
		pCell = (CGridCellCombo*)m_GridCtrl.GetCell(Item.row, Item.col);
		Item.col = nCon++;
		m_GridCtrl.SetItemText(Item.row, Item.col, _T("Num"));

		pCell = (CGridCellCombo*)m_GridCtrl.GetCell(Item.row, Item.col);
		pCell->SetOptions(GateDataOptions);
		pCell->SetStyle(CBS_DROPDOWNLIST);
	}
	m_GridCtrl.Invalidate(FALSE);
}

BEGIN_MESSAGE_MAP(CDlgGridCtrl, CDialog)
	ON_BN_CLICKED(IDC_BTN_SAVE_CSVFILE, &CDlgGridCtrl::OnBnClickedBtnSaveCsvfile)
	ON_BN_CLICKED(IDC_BTN_LOAD_CSVFILE, &CDlgGridCtrl::OnBnClickedBtnLoadCsvfile)
	ON_EN_CHANGE(IDC_GRID_ROW_COUNT, &CDlgGridCtrl::OnEnChangeGridRowCount)
	ON_BN_CLICKED(IDC_BTN_SAVE_HM, &CDlgGridCtrl::OnBnClickedBtnSaveHm)
	ON_BN_CLICKED(IDC_BTN_LOAD_HM, &CDlgGridCtrl::OnBnClickedBtnLoadHm)
	ON_BN_CLICKED(IDC_BTN_FIND_DATA, &CDlgGridCtrl::OnBnClickedBtnFindData)
END_MESSAGE_MAP()


void CDlgGridCtrl::OnEnChangeGridRowCount()
{
	m_nGridCtrlRowCount = GetDlgItemInt(IDC_GRID_ROW_COUNT);
	m_GridCtrl.DeleteAllItems();
	initGridCtrl();
	SetGridNewRowCount();
	FillGridData();
}



//일반 File Open 을 통해서 CSV File 형식으로 저장 처리 하는것.******************************************Start
void CDlgGridCtrl::OnBnClickedBtnSaveCsvfile()
{
	CString strTestFilePath1 = "./TestFolder/GridDataPath.csv";
	int nCol = 0;
	CString strValue = "" , strValue2;

	SetDlgItemText(IDC_STATIC_GRIDDATA_PATH, "Grid Data Save Path : ./TestFolder/GridDataPath.csv");

	FILE *file = fopen(strTestFilePath1, "w");
	if (file)
	{	//TrimRight();오른쪽에 공백 , 개행 및 \n을 지운다
		for (int i = 1;  i <= m_nGridCtrlRowCount;  i++)
		{
			strValue2 = "";
			nCol = 0;
			strValue = m_GridCtrl.GetItemText(i, nCol);
			strValue2 += strValue.TrimRight()+ ",";

			nCol++;
			strValue = m_GridCtrl.GetItemText(i, nCol);
			strValue2 += strValue.TrimRight() + ",";
			
			nCol++;
			CGridCellCheck *pCellCheck;
			pCellCheck = (CGridCellCheck*)m_GridCtrl.GetCell(i, nCol);
			strValue.Format("%d", pCellCheck->GetCheck());
			strValue2 += strValue.TrimRight() + ",";

			nCol++;
			CGridCellCombo *pCell;
			pCell = (CGridCellCombo*)m_GridCtrl.GetCell(i, nCol);
			strValue = pCell->GetText();
			strValue2 += strValue.TrimRight();

			fprintf(file, "%s\n", strValue2);    //1. file format

		}
		fclose(file);
	}

}
//일반 File Open 을 통해서 CSV File 형식으로 저장 처리 하는것.******************************************End

//일반 File Open 을 통해서 CSV File 형식을 로드 처리 하는것.******************************************Start
void CDlgGridCtrl::OnBnClickedBtnLoadCsvfile()
{
	BOOL bCheckUse = FALSE;
	char buffer[2048] = {};
	CString strTestFilePath1 = "./TestFolder/GridDataPath.csv";
	CString strValue = "", strValue2 = "";
	int nCount = 0;

	FILE* pf = fopen(strTestFilePath1, "r");
	if (pf)
	{

		while (fgets(buffer, 2048, pf))
		{
			nCount++;
		}
		fclose(pf);
	}

	SetDlgItemInt(IDC_GRID_ROW_COUNT, nCount);
	m_GridCtrl.SetRowCount(nCount + 1);
	
	pf = fopen(strTestFilePath1, "r");
	if (pf)
	{
		nCount = 1;
		char buffer[2048] = {};
		while (fgets(buffer, 2048, pf))
		{
			{
				strValue = buffer;
				strValue = (LPSTR)buffer;
				AfxExtractSubString(strValue2, strValue, 0, ',');
				m_GridCtrl.SetItemText(nCount, 0, strValue2);

				AfxExtractSubString(strValue2, strValue, 1, ',');
				m_GridCtrl.SetItemText(nCount, 1, strValue2);

				CGridCellCheck *pCellCheck;
				pCellCheck = (CGridCellCheck*)m_GridCtrl.GetCell(nCount, 2);
				AfxExtractSubString(strValue2, strValue, 2, ',');
				pCellCheck->SetCheck(_ttoi(strValue2));

				CGridCellCombo *pCell;
				pCell = (CGridCellCombo*)m_GridCtrl.GetCell(nCount, 3);
				AfxExtractSubString(strValue2, strValue, 3, ',');
				pCell->SetText(strValue2);
			}
			nCount++;
		}
		
		fclose(pf);
	}
	else
		AfxMessageBox("Please click the Write Data Button");


}
//일반 File Open 을 통해서 CSV File 형식을 로드 처리 하는것.******************************************End

void CDlgGridCtrl::FillGridData()
{
	char buffer[2048] = {};
	CString strTestFilePath1 = "./TestFolder/GridDataPath.csv";
	CString strValue = "", strValue2 = "";
	FILE* pf = fopen(strTestFilePath1, "r");
	int nCount = 0;

	if (pf)
	{
		nCount = 1;
		char buffer[2048] = {};
		while (fgets(buffer, 2048, pf))
		{
			{
				strValue = buffer;
				strValue = (LPSTR)buffer;
				AfxExtractSubString(strValue2, strValue, 0, ',');
				m_GridCtrl.SetItemText(nCount, 0, strValue2);

				AfxExtractSubString(strValue2, strValue, 1, ',');
				m_GridCtrl.SetItemText(nCount, 1, strValue2);

				CGridCellCheck *pCellCheck;
				pCellCheck = (CGridCellCheck*)m_GridCtrl.GetCell(nCount, 2);
				AfxExtractSubString(strValue2, strValue, 2, ',');
				pCellCheck->SetCheck(_ttoi(strValue2));

				CGridCellCombo *pCell;
				pCell = (CGridCellCombo*)m_GridCtrl.GetCell(nCount, 3);
				AfxExtractSubString(strValue2, strValue, 3, ',');
				pCell->SetText(strValue2);
			}
			
			nCount++;

			if (nCount == m_nGridCtrlRowCount)
				break;
		}

		fclose(pf);
	}
	else
		AfxMessageBox("Please click the Write Data Button");
}
#include "MConfig.h"

void CDlgGridCtrl::OnBnClickedBtnSaveHm()
{
	CMConfig mConfig;
	CString strTestFilePath1 = "./TestFolder/GridConfigData.cfg";
	CString strValue = "";
	CString strData = "";
	SetDlgItemText(IDC_STATIC_GRIDDATA_PATH,"Path : ./TestFolder/GridConfigData.cfg" );
	strValue.Format("RowCount");
	mConfig.SetItemValue(strValue, m_nGridCtrlRowCount);

	for (int i = 1;i<=m_nGridCtrlRowCount;i++)
	{
		strValue.Format("Grid_%d_%d", i, 0);
		strData = m_GridCtrl.GetItemText(i, 0);
		mConfig.SetItemValue(strValue, strData.TrimRight());

		strValue.Format("Grid_%d_%d", i, 1);
		strData = m_GridCtrl.GetItemText(i, 1);
		mConfig.SetItemValue(strValue, strData.TrimRight());

		CGridCellCheck* pCellCheck;
		pCellCheck = (CGridCellCheck*)m_GridCtrl.GetCell(i, 2);
		strValue.Format("Grid_%d_%d", i, 2);
		strData.Format("%d", pCellCheck->GetCheck());
		mConfig.SetItemValue(strValue, strData.TrimRight());

		CGridCellCombo* pCellCombo;
		pCellCombo = (CGridCellCombo*)m_GridCtrl.GetCell(i, 3);
		strValue.Format("Grid_%d_%d", i, 3);
		strData.Format("%s", pCellCombo->GetText());
		mConfig.SetItemValue(strValue, strData.TrimRight());

	}

	mConfig.Write(strTestFilePath1);
	
}


void CDlgGridCtrl::OnBnClickedBtnLoadHm()
{
	CMConfig mConfig;
	CString strTestFilePath1 = "./TestFolder/GridConfigData.cfg";
	CString strValue = "";
	CString strData = "";
	BOOL bCheck = FALSE;

	mConfig.Read(strTestFilePath1);

	strValue.Format("RowCount");
	mConfig.GetItemValue(strValue, m_nGridCtrlRowCount);
	SetDlgItemInt(IDC_GRID_ROW_COUNT, m_nGridCtrlRowCount);
	if (m_nGridCtrlRowCount != 0)
	{
		initGridCtrl();
		inputGridCtrl();
	}
	for (int i = 1; i <= m_nGridCtrlRowCount; i++)
	{
		strValue.Format("Grid_%d_%d", i, 0);
		mConfig.GetItemValue(strValue, strData);
		m_GridCtrl.SetItemText(i, 0, strData);

		strValue.Format("Grid_%d_%d", i, 1);
		mConfig.GetItemValue(strValue, strData); 
		m_GridCtrl.SetItemText(i, 1, strData);

		CGridCellCheck* pCellCheck;
		pCellCheck = (CGridCellCheck*)m_GridCtrl.GetCell(i, 2);
		strValue.Format("Grid_%d_%d", i, 2);
		mConfig.GetItemValue(strValue, bCheck);
		if (bCheck == TRUE)
			pCellCheck->SetCheck(TRUE);
		else
			pCellCheck->SetCheck(FALSE);

		CGridCellCombo* pCellCombo;
		pCellCombo = (CGridCellCombo*)m_GridCtrl.GetCell(i, 3);
		strValue.Format("Grid_%d_%d", i, 3);
		mConfig.GetItemValue(strValue, strData);
		
		pCellCombo->SetText(strData);

	}

	mConfig.Write(strTestFilePath1);
}


void CDlgGridCtrl::OnBnClickedBtnFindData()
{
	CString strFindData = "";
	CString strData = "";
	GetDlgItemText(IDC_FIND_DATA, strFindData);
	CCellID cellID = m_GridCtrl.GetFocusCell();
	
	if (cellID.col == 0)
		cellID.col += 1;
	else if (cellID.col == 3)
	{
		cellID.row += 1;
		cellID.col = 0;
	}
	for (int i = cellID.row ;i<m_nGridCtrlRowCount;i++)
	{
		for (int j = cellID.col;j<4;j++)
		{
			strData = m_GridCtrl.GetItemText(i, j);

			if (strData == strFindData)
			{
				SCROLLINFO si;
				m_GridCtrl.GetScrollInfo(SB_VERT, &si);
				m_GridCtrl.EnsureVisible(i, 0);

				m_GridCtrl.SetFocusCell(i, j);
				m_GridCtrl.SetSelectedRange(i,j,i,j,TRUE);
				m_GridCtrl.RedrawWindow();
				m_GridCtrl.Refresh();
				break;
			}
		}
		if (strData == strFindData)
			break;

	}
}
