#include <iostream>

//////////////////////////////////////////////////////////Tree Node Class//////////////////////////////////////////////////////////
template<typename X>
class Tree_node
{
	X *field = new X;
	size_t *count = new size_t;
	Tree_node<X> *left = nullptr, *right = nullptr;

public:
	Tree_node(X value);
	~Tree_node();

	X get_field();
	size_t get_count();

	void incr_count();

	void set_left(Tree_node *left_node);
	void set_right(Tree_node *right_node);

	Tree_node<X> *get_left();
	Tree_node<X> *get_right();
};


template<typename X>
Tree_node<X>::Tree_node(X value)
{
	//std::cout << "Constructor of node working!\n";
	*count += 1;
	*field = value;
};
template<typename X>
Tree_node<X>::~Tree_node()
{
	//std::cout << "Destructor of node is working!\n";
	delete left;
	delete right;
	delete field, count;
};


template<typename X>
X Tree_node<X>::get_field()
{ 
	return *field;
}
template<typename X>
size_t Tree_node<X>::get_count()
{
	return *count;
};


template<typename X>
void Tree_node<X>::incr_count()
{
	*count += 1;
	return;
};


template<typename X>
void Tree_node<X>::set_left(Tree_node<X> *left_node)
{
	left = left_node;
};
template<typename X>
void Tree_node<X>::set_right(Tree_node<X> *right_node)
{
	right = right_node;
};


template<typename X>
Tree_node<X> *Tree_node<X>::get_left()
{
	return left;
};
template<typename X>
Tree_node<X> *Tree_node<X>::get_right()
{
	return right;
};

//////////////////////////////////////////////////////////Tree Class//////////////////////////////////////////////////////////
template<typename X>
class Tree
{
	Tree_node<X> *root = nullptr;

public:
	Tree(X);
	~Tree();

	void add_node(X value, Tree_node<X> *node_ptr);
	void add_node(X value);

	Tree_node<X> *get_root();

	void treeprint_prefix(Tree_node<X> *node_ptr);
	void treeprint_prefix();
	void treeprint_infix(Tree_node<X> *node_ptr);
	void treeprint_infix();
	void treeprint_postfix(Tree_node<X> *node_ptr);
	void treeprint_postfix();
};

template<typename X>
Tree<X>::Tree(X value)
{
	//std::cout << "Constructor of tree is working!\n";
	Tree_node<X> *node = new Tree_node<X>(value);
	root = node;
};
template<typename X>
Tree<X>::~Tree()
{
	//std::cout << "Destructor of tree is working!\n";
	delete root;
};


template<typename X>
void Tree<X>::add_node(X value, Tree_node<X> *node_ptr)
{
	if (value == node_ptr->get_field())
	{
		node_ptr->incr_count();
		return;
	};

	if (value < node_ptr->get_field())
	{
		if (node_ptr->get_left()) add_node(value, node_ptr->get_left());
		else
		{
			Tree_node<X> *Node = new Tree_node<X>(value);
			node_ptr->set_left(Node);
			return;
		};
	};

	if (value > node_ptr->get_field())
	{
		if (node_ptr->get_right()) add_node(value, node_ptr->get_right());
		else
		{
			Tree_node<X> *Node = new Tree_node<X>(value);
			node_ptr->set_right(Node);
			return;
		};
	};
};
template<typename X>
void Tree<X>::add_node(X value)
{
	if (value == root->get_field())
	{
		root->incr_count();
		return;
	};
	if (value < root->get_field())
	{
		if (root->get_left()) add_node(value, root->get_left());
		else
		{
			Tree_node<X> *Node = new Tree_node<X>(value);
			root->set_left(Node);
			return;
		};
	};

	if (value > root->get_field())
	{
		if (root->get_right()) add_node(value, root->get_right());
		else
		{
			Tree_node<X> *Node = new Tree_node<X>(value);
			root->set_right(Node);
			return;
		};
	};

};


template<typename X>
Tree_node<X> *Tree<X>::get_root()
{
	return root;
};


template<typename X>
void Tree<X>::treeprint_prefix(Tree_node<X> *node_ptr)
{
	std::cout << node_ptr->get_field() << "\n";
	if(node_ptr->get_left()) treeprint_prefix(node_ptr->get_left());
	if(node_ptr->get_right()) treeprint_prefix(node_ptr->get_right());
	return;
};
template<typename X>
void Tree<X>::treeprint_prefix()
{
	std::cout << root->get_field() << "\n";
	if(root->get_left()) treeprint_prefix(root->get_left());
	if(root->get_right()) treeprint_prefix(root->get_right());
	return;
};


template<typename X>
void Tree<X>::treeprint_infix(Tree_node<X> *node_ptr)
{
	if (node_ptr->get_left()) treeprint_infix(node_ptr->get_left());
	std::cout << node_ptr->get_field() << "\n";
	if (node_ptr->get_right()) treeprint_infix(node_ptr->get_right());
	return;
};
template<typename X>
void Tree<X>::treeprint_infix()
{
	if (root->get_left()) treeprint_infix(root->get_left());
	std::cout << root->get_field() << "\n";
	if (root->get_right()) treeprint_infix(root->get_right());
	return;
};


template<typename X>
void Tree<X>::treeprint_postfix(Tree_node<X> *node_ptr)
{
	if (node_ptr->get_left()) treeprint_postfix(node_ptr->get_left());
	if (node_ptr->get_right()) treeprint_postfix(node_ptr->get_right());
	std::cout << node_ptr->get_field() << "\n";
	return;
}
template<typename X>
void Tree<X>::treeprint_postfix()
{
	if (root->get_left()) treeprint_postfix(root->get_left());
	if (root->get_right()) treeprint_postfix(root->get_right());
	std::cout << root->get_field() << "\n";
	return;
};

