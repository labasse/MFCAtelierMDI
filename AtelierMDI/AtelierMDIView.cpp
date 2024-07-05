
// AtelierMDIView.cpp : implémentation de la classe CAtelierMDIView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL, et permettent le partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "AtelierMDI.h"
#endif

#include "AtelierMDIDoc.h"
#include "AtelierMDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAtelierMDIView

IMPLEMENT_DYNCREATE(CAtelierMDIView, CScrollView)

BEGIN_MESSAGE_MAP(CAtelierMDIView, CScrollView)
	// Commandes d'impression standard
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CAtelierMDIView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// construction/destruction de CAtelierMDIView

CAtelierMDIView::CAtelierMDIView() noexcept
{
	// TODO: ajoutez ici du code de construction

}

CAtelierMDIView::~CAtelierMDIView()
{
}

BOOL CAtelierMDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: changez ici la classe ou les styles Window en modifiant
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// dessin de CAtelierMDIView

void CAtelierMDIView::OnDraw(CDC* /*pDC*/)
{
	CAtelierMDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ajoutez ici le code de dessin pour les données natives
}

void CAtelierMDIView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculez la taille totale de cette vue
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// impression de CAtelierMDIView


void CAtelierMDIView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CAtelierMDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// préparation par défaut
	return DoPreparePrinting(pInfo);
}

void CAtelierMDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez une initialisation supplémentaire avant l'impression
}

void CAtelierMDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ajoutez un nettoyage après l'impression
}

void CAtelierMDIView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CAtelierMDIView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// diagnostics de CAtelierMDIView

#ifdef _DEBUG
void CAtelierMDIView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CAtelierMDIView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CAtelierMDIDoc* CAtelierMDIView::GetDocument() const // la version non Debug est inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAtelierMDIDoc)));
	return (CAtelierMDIDoc*)m_pDocument;
}
#endif //_DEBUG


// gestionnaires de messages de CAtelierMDIView
