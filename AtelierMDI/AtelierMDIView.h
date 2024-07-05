
// AtelierMDIView.h : interface de la classe CAtelierMDIView
//

#pragma once


class CAtelierMDIView : public CScrollView
{
protected: // création à partir de la sérialisation uniquement
	CAtelierMDIView() noexcept;
	DECLARE_DYNCREATE(CAtelierMDIView)

// Attributs
public:
	CAtelierMDIDoc* GetDocument() const;

// Opérations
public:

// Substitutions
public:
	virtual void OnDraw(CDC* pDC);  // substitué pour dessiner cette vue
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // premier appel après la construction
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implémentation
public:
	virtual ~CAtelierMDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // version Debug dans AtelierMDIView.cpp
inline CAtelierMDIDoc* CAtelierMDIView::GetDocument() const
   { return reinterpret_cast<CAtelierMDIDoc*>(m_pDocument); }
#endif

