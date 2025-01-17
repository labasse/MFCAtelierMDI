
// AtelierMDIDoc.h : interface de la classe CAtelierMDIDoc
//


#pragma once


class CAtelierMDIDoc : public CDocument
{
protected: // création à partir de la sérialisation uniquement
	CAtelierMDIDoc() noexcept;
	DECLARE_DYNCREATE(CAtelierMDIDoc)

// Attributs
private:
	CPoint m_pos;
public:
	const CPoint& GetPos() const { return m_pos; }
	void SetPos(CView *from, const POINT& pos) { 
		m_pos = pos; 
		SetModifiedFlag(TRUE);
		UpdateAllViews(from);
	}
	const CSize& GetTotalSize() const {
		return m_pos 
			+ GetRadius();
	}
	SIZE GetRadius() const
	{
		return { 100, 100 };
	}

// Opérations
public:

// Substitutions
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implémentation
public:
	virtual ~CAtelierMDIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Fonction d'assistance qui définit le contenu de recherche pour un gestionnaire de recherche
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
