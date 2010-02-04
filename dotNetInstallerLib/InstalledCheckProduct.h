#pragma once

#include "InstalledCheck.h"
#include "XmlAttribute.h"

class InstalledCheckProduct : public InstalledCheck
{
public:
	// UpgradeCode or ProductCode
	XmlAttribute id_type;
	// product/upgrade code
	XmlAttribute id;
	// product property to check
	XmlAttribute propertyname;
	// one of version, match, etc.
	std::wstring comparison;
	// property value to match
	XmlAttribute propertyvalue;
public:
    InstalledCheckProduct();
    void Load(TiXmlElement * node);
	virtual bool IsInstalled() const;
};

typedef shared_any<InstalledCheckProduct *, close_delete> InstalledCheckProductPtr;

