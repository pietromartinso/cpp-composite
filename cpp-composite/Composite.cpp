#ifndef __io__
#define __io__
#include <iostream>
using namespace std;
#endif // !__io__

#include <list>
#include <string>

class Component {
public:
	Component();

	Component(std::string n, unsigned long s): name_(n), size_(s) {

	}

	virtual ~Component() {}

	void SetParent(Component* parent) {
		this->parent_ = parent;
	}

	Component* GetParent() const {
		return this->parent_;
	}

	virtual void Add(Component* component) {};

	virtual void Remove(Component* component) {};

	virtual bool IsComposite() const {
		return false;
	}

	virtual std::string Operation(unsigned short i = 0) const = 0;

protected:

	Component* parent_;
	std::string name_;
	unsigned long size_;
};

class File : public Component {

public:
	File();

	File(std::string n, unsigned long s) : Component(n, s) {}

	std::string Operation(unsigned short i = 0) const override {
		std::string innerTabs = "";
		std::string tabs = "";
		int x;
		for (x = 0; x < i+1; x++) {
			tabs += "  ";
		}
		innerTabs = tabs + "  ";
		return "\n" + tabs + "File[" + to_string(x) + "]:\n" + innerTabs + "Name: " + this->name_ + "\n" + innerTabs + "Size: " + to_string(this->size_);
	}
};

class Folder : public Component {
public:

	Folder();

	Folder(std::string n, unsigned long s) : Component(n, s) {}
		
	void Add(Component* component) override {
		this->children_.push_back(component);
		component->SetParent(this);
	}

	void Remove(Component* component) override {
		// note that removing the pointer for the component from the list doesn't free the memory
		// here, probably, we need to call the children's "remove" recursivelly??
		// or.. ofcourse, client could delete them manually
		// or.. alternativelly, use smart pointers
		this->children_.remove(component);
		component->SetParent(nullptr);
	}

	bool IsComposite() const override {
		return true;
	}

	std::string Operation(unsigned short i = 0) const override {
		std::string result;
		std::string innerTabs = "";
		std::string tabs = "";
		int x;

		for (x = 0; x < i + 1; x++) {
			tabs += "  ";
		}
		innerTabs = tabs + "  ";
		i++;

		for (const Component* c : children_) {
			if (c == children_.back()) {
				result += c->Operation(i);
			}
			else {
				result += c->Operation(i) + "\n";
			}
		}

		return "\n" + tabs + "Folder["+ to_string(x) + "]:\n" + innerTabs + "Name: " + this->name_ + "\n" + innerTabs + "Size: " + to_string(this->size_) + "\n" + result + "\n";
	}
protected:
	std::list<Component*> children_;
};
