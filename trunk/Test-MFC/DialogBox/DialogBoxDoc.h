
// DialogBoxDoc.h : interface of the CDialogBoxDoc class
//


#pragma once


class CDialogBoxDoc : public CDocument
{
protected: // create from serialization only
	CDialogBoxDoc();
	DECLARE_DYNCREATE(CDialogBoxDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CDialogBoxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


