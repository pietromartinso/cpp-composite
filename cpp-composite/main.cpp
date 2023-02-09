#ifndef __io__
#define __io__
#include <iostream>
using namespace std;
#endif // !__io__

#include "Composite.cpp"

//Single simple component
void ClientCode1(Component *component) {
	std::cout << "RESULT:" << component->Operation();
}

//Composite component
void ClientCode2(Component *component1, Component *component2) {
	if (component1->IsComposite()) {
		component1->Add(component2);
	}
	std::cout << "RESULT: " << component1->Operation();
}


int main() {
	
	//Simple component
	Component* simple = new File;
	std::cout << "Client: I've got a simple single component:" << std::endl;
	ClientCode1(simple);
	std::cout << std::endl << std::endl;

	//Composite component
	Component *tree = new Folder;
	Component *branch1 = new Folder;

	Component* leaf_1 = new File;
	Component* leaf_2 = new File;
	Component* leaf_3 = new File;

	branch1->Add(leaf_1);
	branch1->Add(leaf_2);

	Component* branch2 = new Folder;
	branch2->Add(leaf_3);
	tree->Add(branch1);
	tree->Add(branch2);

	std::cout << "Client: now I've got a simple composite component" << std::endl;
	ClientCode1(tree);
	std::cout << std::endl << std::endl;

	std::cout << "Client: I don't need to check the components classes even when managing the tree:" << endl;
	ClientCode2(tree, simple);
	std::cout << std::endl;

	delete simple;
	delete tree;
	delete branch1;
	delete branch2;
	delete leaf_1;
	delete leaf_2;
	delete leaf_3;

}