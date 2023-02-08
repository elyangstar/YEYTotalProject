// CExcelAutomation.h: interface for the CExcelAutomation class.
//
//////////////////////////////////////////////////////////////////////
// ExcelAutomation 2005. 10. 4. ������
// Desc. �����͸� Excel ���Ϸ� ����
//
// ���� : 
// Excel Automation ���� ������Ʈ �ȿ� ����
// header ���Ͽ� #include ".\Excel Automation\ExcelAutomation.h"
// OLE �ʱ�ȭ : app->InitInstance->AfxOleInit();
// Excel ���� ���� : CreateExcel(CString ���ϸ�)
// Excel ���� ���� : OpenExcel(CString ���ϸ�)
// Excel ���� ���� : SaveExcel(CString ���ϸ�)
// Excel ���� �ݱ� : CloseExcel()
// �۾�ȭ�� ���� : ShowWorkSheet(BOOL 0 or FALSE(�����) �Ǵ� BOOL 1 or TRUE(����))
// ��Ʈ �̵� : SetSheet(short ��Ʈ��ȣ)
// �� ���� : SetValue(CString ���ۼ���ȣ, CString ����������ȣ, CString ��)
//           SetValue(CString ����ȣ, CString ��)
// �� �б� : GetValue(CString ���ۼ���ȣ, CString ����������ȣ)
// �� �б� : GetValue(CString ����ȣ)
// Ex)))
//	CExcelAutomation* pExcel;
//	pExcel = new CExcelAutomation;
//	pExcel->CreateExcel("");
//	pExcel->ShowWorkSheet(FALSE);
//	pExcel->SetSheet(1);
//	pExcel->SetValue("B1", "B1", "Data");
//	pExcel->SaveExcel("FileName");
//	pExcel->CloseExcel();
//	delete pExcel;
//	pExcel = NULL;


#include "excel.h"
#if !defined(AFX_CExcelAutomation_H__D3DB1116_A911_42E3_A44E_8B7A297189D3__INCLUDED_)
#define AFX_CExcelAutomation_H__D3DB1116_A911_42E3_A44E_8B7A297189D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define LINE_SOLID			1
#define LINE_DOT			2
#define LINE_THIN_DOT		3
#define LINE_DOT_SOLID		4
#define LINE_DOT_DOT_SOLID	5
#define LINE_BIG_DOT_SOLID	6
#define LINE_TWIN_SOLID		9

class AFX_EXT_CLASS CExcelAutomation  
{
public:
// Attributes
	_Application	m_app;
	_Workbook		m_book;
	_Worksheet		m_sheet;
	Range			m_range;
	Workbooks		m_books;
	Worksheets		m_sheets;
	Borders			m_borders;
	Border			m_border;
	Shapes			m_shapes;
	Shape			m_shape;
	Interior		m_interior;
	BOOL			m_bShow;

// Operations
	//khs-edit void to BOOL
	BOOL CreateExcel(									// ���� ���� ����
						CString ExcelName,				// ���� �̸�
						long SheetNum);					// ��Ʈ ��
	BOOL OpenExcel(										// ���� ���� ����
						CString ExcelName);				// ���� �̸�
	void SaveExcel(										// ���� ���� ����
						CString ExcelName);				// ���� �̸�
	void SetSheet(										// ��Ʈ ����
						short SheetNumber);				// ��Ʈ ��ȣ
	void SetValue(										// �� ����
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd,					// ����������ȣ
						LPCSTR CellValue);				// ��
	void SetValue(CString CellStart,										// �� ����
						//LPCSTR CellStart,				// ����ȣ
						LPCSTR CellValue);				// ��
	void SetName(										// ��Ʈ �̸� ����
						short SheetNumber,				// ��Ʈ ��ȣ
						LPCSTR SheetName);				// ��Ʈ �̸�
	CString GetValue(									// �� ��������
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd);				// ����������ȣ
	CString GetValue(									// �� ��������
						LPCSTR CellStart);				// ����ȣ
	void ShowWorkSheet(									// �۾����� ��Ʈ �����ֱ�
						BOOL show);						// True or Not
	void CloseExcel();									// ���� ���� �ݱ�
	void AutoFitColumn(									// Column ���߱�
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd);				// ����������ȣ
	void AutoFitRow(									// Raw ���߱�
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd);				// ����������ȣ
	void MergeCells(	CString CellStart,									// �� ����
						CString CellEnd);
					//	LPCSTR CellStart,				// ���ۼ���ȣ
					//	LPCSTR CellEnd);				// ����������ȣ
	void DrawTable(		CString CellStart,	
						CString CellEnd,						// ǥ �׸���
					//	LPCSTR CellStart,				// ���ۼ���ȣ	
					//	LPCSTR CellEnd,					// ����������ȣ
						short LineType);				// �� ���
	void SetPicture(									// �׸� �ֱ�
						LPCSTR FileName,				// ���ϸ�
						float x,						// x��ǥ
						float y,						// y��ǥ
						float width,					// ����
						float height,					// ����
						BOOL ErrMsg = TRUE);			// �����޼��� ó������
	void SetHeight(										// ���� ����
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd,					// ����������ȣ
						short height);					// ����
	void SetHeight(		CString CellStart,									// ���� ����
					//	LPCSTR CellStart,				// ����ȣ
						short height);					// ����
	void SetWidth(										// ���� ����
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd,					// ����������ȣ
						short width);					// ����
	void SetWidth(										// ���� ����
						LPCSTR CellStart,				// ����ȣ
						short width);					// ����
	void SetColor(	CString CellStart,
					CString CellEnd, // �� ����
					//	LPCSTR CellStart,				// ���ۼ���ȣ
					//	LPCSTR CellEnd,					// ����������ȣ
						COLORREF BgColor);				// ��
	void SetColor(										// �� ����
						LPCSTR CellStart,				// ����ȣ
						COLORREF BgColor);				// ��
	void SetFont(										// ��Ʈ ����
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd);				// ����������ȣ
	void SetAlignCenter(								// ��� ����
						LPCSTR CellStart,				// ���ۼ���ȣ
						LPCSTR CellEnd);				// ����������ȣ
	void SetAlignCenter(								// ��� ����
						LPCSTR CellStart);				// ����ȣ
	CExcelAutomation();
	virtual ~CExcelAutomation();

};

#endif // !defined(AFX_CExcelAutomation_H__D3DB1116_A911_42E3_A44E_8B7A297189D3__INCLUDED_)
