#ifndef __io__
#define __io__
#include <iostream>
using namespace std;
#endif // !__io__

#include <list>

class Component {
public:
	//Component();

	//Component(std::string n): name(n) {

	//}

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

	virtual std::string Operation() const = 0;

protected:

	Component* parent_;
	std::string name;
	unsigned long int size;
};

class File : public Component {
public:
	std::string Operation() const override {
		return "File";
	}
};

class Folder : public Component {
public:
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
		component->SetParent(this);
	}

	bool IsComposite() const override {
		return true;
	}

	std::string Operation() const override {
		std::string result;
		for (const Component* c : children_) {
			if (c == children_.back()) {
				result += c->Operation();
			}
			else {
				result += c->Operation() + "+";
			}
		}
		return "Folder(" + result + ")";
	}
protected:
	std::list<Component*> children_;
};
