#ifndef __io__
#define __io__
#include <iostream>
using namespace std;
#endif // !__io__

#include "Composite.cpp"

//Single simple component
void ClientCode1(Component *component) {
	std::cout << "RESULT:\n" << component->Operation();
}

//Composite component
void ClientCode2(Component *component1, Component *component2) {
	if (component1->IsComposite()) {
		component1->Add(component2);
	}
	std::cout << "RESULT:\n" << component1->Operation();
}


int main() {
	
	////Simple component
	//Component* simple = new File("FirstFile", 5);
	//std::cout << "Client: I've got a simple single component:" << std::endl;
	//ClientCode1(simple);
	//std::cout << std::endl << std::endl;

	////Composite component
	//Component *tree = new Folder("tree", 0);
	//Component *branch1 = new Folder("branch1", 0);

	//Component* leaf_1 = new File("file1", 10);
	//Component* leaf_2 = new File("file2", 20);
	//Component* leaf_3 = new File("file2", 30);

	//branch1->Add(leaf_1);
	//branch1->Add(leaf_2);

	//Component* branch2 = new Folder("branch2", 0);
	//branch2->Add(leaf_3);
	//tree->Add(branch1);
	//tree->Add(branch2);

	//std::cout << "Client: now I've got a simple composite component" << std::endl;
	//ClientCode1(tree);
	//std::cout << std::endl << std::endl;

	//std::cout << "Client: I don't need to check the components classes even when managing the tree:\n" << endl;
	//ClientCode2(tree, simple);
	//std::cout << std::endl;

	//delete simple;
	//delete tree;
	//delete branch1;
	//delete branch2;
	//delete leaf_1;
	//delete leaf_2;
	//delete leaf_3;

	Component *root = new Folder("root", 0);
	Component *folder1 = new Folder("folder1", 0);

	Component* leaf_1 = new File("file1", 10);
	Component* leaf_2 = new File("file2", 10);
	Component* leaf_3 = new File("file2", 10);

	folder1->Add(leaf_1);
	folder1->Add(leaf_2);
	folder1->Add(leaf_3);
	root->Add(folder1);

	Component* folder2 = new Folder("folder2", 0);

	Component* leaf_4 = new File("file4", 10);
	Component* leaf_5 = new File("file5", 10);
	Component* leaf_6 = new File("file6", 10);

	folder2->Add(leaf_4);
	folder2->Add(leaf_5);
	folder2->Add(leaf_6);
	root->Add(folder2);

	ClientCode1(root);
	std::cout << std::endl << std::endl;

}