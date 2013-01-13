#ifndef __MY_AVL_TREE__
	#define __MY_AVL_TREE__

	#include "my_node.hpp"
	template <typename T>
	class MyAVLTree {
		private:
			MyNode<T>* root_;
			void	delete_node(MyNode<T>*, MyNode<T>*, MyNode<T>*, bool = false);
			void	add_node(MyNode<T>*, MyNode<T>*);
			int		height_helper(MyNode<T>*);
			void	balance(MyNode<T>*);
			void	rr_rotation(MyNode<T>* grand_parent, MyNode<T>* parent, MyNode<T>* child);
			void	ll_rotation(MyNode<T>* grand_parent, MyNode<T>* parent, MyNode<T>* child);
			void	rl_rotation(MyNode<T>* grand_parent, MyNode<T>* parent, MyNode<T>* child);
			void	lr_rotation(MyNode<T>* grand_parent, MyNode<T>* parent, MyNode<T>* child);
			
		public:
			MyAVLTree();
			~MyAVLTree();
			void 	add(T, MyNode<T>* = NULL);
			void 	remove(T, MyNode<T>* = NULL, MyNode<T>* = NULL);
			void	preorder(MyNode<T>* = NULL);
			void 	inorder(MyNode<T>* = NULL);
			void 	postorder(MyNode<T>* = NULL);
			void 	clear(MyNode<T>*  = NULL);
			bool 	exists(T, MyNode<T>* = NULL);
			int  	height();
	};

	/////////////////////////////////
	template <typename T>
	MyAVLTree<T>::MyAVLTree() {
		root_ = NULL;
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	MyAVLTree<T>::~MyAVLTree() {
			clear();
	}
	/////////////////////////////////

	/////////////////////////////////
	using namespace std;
	#include <iostream>
	template <typename T>
	void MyAVLTree<T>::add(T elem, MyNode<T>* pos) {
		if(root_ == NULL)
			root_ = new MyNode<T>(elem, NULL, NULL);
		else {
			if(pos == NULL)
				pos = root_;

			//Left Branch
			if(elem <= pos->getData()) {
				//If left is null add
				if(pos->getLeft() == NULL) 
					pos->setLeft(new MyNode<T>(elem, NULL, NULL));
				//Keep Searching if not null
				else
					add(elem, pos->getLeft());
			}

			//Right Branch
			else {
				//If right is null add
				if(pos->getRight() == NULL) 
					pos->setRight(new MyNode<T>(elem, NULL, NULL));
				//Keep Searching if not null
				else
					add(elem, pos->getRight());	
			}
		}
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::add_node(MyNode<T>* parent, MyNode<T>* new_node) {
		if(parent && new_node) {
			//Left side
			if(new_node->getData() <= parent->getData()) {
				if(parent->getLeft())
					add_node(parent->getLeft(), new_node);
				else
					parent->setLeft(new_node);
			}
			//Right side
			else {
				if(parent->getRight())
					add_node(parent->getRight(), new_node);
				else
					parent->setRight(new_node);
			}
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	#include <iostream>
	using namespace std;
	template <typename T>
	void MyAVLTree<T>::delete_node(MyNode<T>* node, MyNode<T>* prev_node, MyNode<T>* new_val, bool move_node) {
		MyNode<T>* temp;
		if(node == root_)
			root_ = new_val;
		else {
			//Set left side of parent to new child
			if(prev_node->getLeft() && prev_node->getLeft()->getData() == node->getData()) 
				prev_node->setLeft(new_val);

			//Set right side of parent to new child
			else if(prev_node->getRight() && prev_node->getRight()->getData() == node->getData()) 
				prev_node->setRight(new_val);
		}
		if(move_node) {
			temp = new_val->getRight();
			new_val->setRight(node->getRight());
			add_node(new_val, temp);
		}
		delete node;
	}
	/////////////////////////////////

	
	/////////////////////////////////
	#include <iostream>
	using namespace std;
	template <typename T>
	void MyAVLTree<T>::remove(T elem, MyNode<T>* node, MyNode<T>* prev_node) {
		if(!node)
			node = root_;
		
		//Found matching node
		if(node->getData() == elem) {
			//Has left and right children
			if(node->getLeft() && node->getRight()) 
				delete_node(node, prev_node, node->getLeft(), true);
			//Has left child
			else if(node->getLeft() && !node->getRight()) 
				delete_node(node, prev_node, node->getLeft());
			//Has right child
			else if(node->getRight() && !node->getLeft()) 
				delete_node(node, prev_node, node->getRight());
			//Has no children
			else if(!node->getRight() && !node->getLeft()) {
				delete_node(node, prev_node, NULL);
			}
		}
		else {
			if(elem <= node->getData() && node->getLeft())
				remove(elem, node->getLeft(), node);
			if(elem > node->getData() && node->getRight())
				remove(elem, node->getRight(), node);
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	#include <iostream>
	template <typename T>
	void MyAVLTree<T>::preorder(MyNode<T>* node) {
		if(root_) {
			if(!node)
				node = root_;
			
			std::cout << node->getData() << " ";	
			
			if(node->getLeft())
				preorder(node->getLeft());
			
			if(node->getRight())
				preorder(node->getRight());
		}
	}
	/////////////////////////////////
	/////////////////////////////////
	#include <iostream>
	template <typename T>
	void MyAVLTree<T>::inorder(MyNode<T>* node) {
		if(root_) {
			if(!node)
				node = root_;
			
			if(node->getLeft())
				inorder(node->getLeft());
				
			std::cout << node->getData() << " ";	
			
			if(node->getRight())
				inorder(node->getRight());
		}
	}
	/////////////////////////////////

	/////////////////////////////////
	#include <iostream>
	template <typename T>
	void MyAVLTree<T>::postorder(MyNode<T>* node) {
		if(root_) {
			if(!node)
				node = root_;
			
			if(node->getLeft())
				postorder(node->getLeft());
			
			if(node->getRight())
				postorder(node->getRight());
			
			std::cout << node->getData() << " ";	
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::clear(MyNode<T>* node) {
		MyNode<T>* left;
		MyNode<T>* right;

		if(node == NULL)
			node = root_;

		if(node) {
			left = node->getLeft();
			right = node->getRight();
			if(left)
				clear(left);
			if(right)
				clear(right);
			if(node == root_)
				root_ = NULL;
			delete node;
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	bool MyAVLTree<T>::exists(T elem, MyNode<T>* node) {
		if(!node)
			node = root_;

		if(node) {
			MyNode<T>* left = node->getLeft();
			MyNode<T>* right = node->getRight();

			if(node->getData() == elem)
				return true;
			else {
				if((left && exists(elem, left)) || (right && exists(elem, right)))
					return true;
			}
		}
		return false;
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	int MyAVLTree<T>::height() {
		return height_helper(root_);
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	int MyAVLTree<T>::height_helper(MyNode<T>* node) {
		if(node == NULL)
			return 0;
		else {
			int left = height_helper(node->getLeft());
			int right = height_helper(node->getRight());

			if(left >= right)
				return left + 1;
			else
				return right + 1;
		}
	}
	/////////////////////////////////

#endif
