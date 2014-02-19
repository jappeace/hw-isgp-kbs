#pragma once
#include "resource1.h"

// AboutDialog dialog

class AboutDialog : public CDialogEx
{
	DECLARE_DYNAMIC(AboutDialog)

public:
	AboutDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~AboutDialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
