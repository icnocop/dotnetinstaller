#pragma once

#include "Component.h"
#include "ExecuteCallback.h"
#include "InstallSequence.h"

class Components : private std::vector<ComponentPtr>
{
private:
	std::map<std::wstring, ComponentPtr> components_map;
public:
	Components();
	Components(const Components& rhs);
	Components& operator=(const Components& rhs);
	// size of the components collection
	size_t size() const { return std::vector<ComponentPtr>::size(); }
	// add a component to the collection
	void add(const ComponentPtr& component);
	// returns whether the collection contains a component by this name
	bool contains(const std::wstring& description) const;
	// returns components that match current platform and processor architecture
	Components GetSupportedComponents(DVLib::LcidType lcidtype, InstallSequence sequence) const;
	// get a pointer reference for a component
	ComponentPtr GetComponentPtr(Component * pc) const;
	// reference
	const_reference operator[](size_type pos) const { return std::vector<ComponentPtr>::operator[](pos); }
	// synchronously execute components, returns true if all succeeded
	int Exec(IExecuteCallback * callback);
	virtual std::wstring GetString(int indent = 0) const;
	// return iterator for beginning of mutable sequence
	iterator begin() { return std::vector<ComponentPtr>::begin(); }
	// return iterator for beginning of nonmutable sequence
	const_iterator begin() const { return std::vector<ComponentPtr>::begin(); }
	// return iterator for end of mutable sequence
	iterator end() { return std::vector<ComponentPtr>::end(); }
	// return iterator for end of nonmutable sequence
	const_iterator end() const { return std::vector<ComponentPtr>::end(); }
};
