#pragma once

#include "XmlAttribute.h"
#include "InstalledCheck.h"

class InstalledCheckRegistry : public InstalledCheck
{
public:
	// percorso del registry
	XmlAttribute path; 
	// nome del campo del registry
	XmlAttribute fieldname; 
	// valore del registry bisogna convertirlo in base al tipo
	XmlAttribute fieldvalue;
	// tipo del campo nel registry : REG_DWORD (long) o REG_SZ (string)
	XmlAttribute fieldtype; 
	// tipo di comparazione : match (verifica se le due stringhe sono uguali) version (che tratta le due stringhe come versioni e quindi se quella richiesta � minore bisogna installare altrimenti no)
	XmlAttribute comparison;
	XmlAttribute rootkey;
	//support for KEY_WOW64_32KEY and KEY_WOW64_64KEY
	XmlAttribute wowoption; 
public:
    InstalledCheckRegistry();
    void Load(TiXmlElement * node);
	bool IsInstalled() const;
};

typedef shared_any<InstalledCheckRegistry *, close_delete> InstalledCheckRegistryPtr;
