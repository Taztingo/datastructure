#ifndef __MY_AVL_TREE__
	#define __MY_AVL_TREE__

	#include "my_node.hpp"
	template <typename T>
	class MyAVLTree {
		private:
			MyNode<T>* root_;

			void				delete_node(MyNode<T>*, MyNode<T>*, MyNode<T>*, bool = false);
			void				add_node(MyNode<T>*, MyNode<T>*);
			void				add_helper(T, MyNode<T>*);
			void				remove_helper(T, MyNode<T>*, MyNode<T>*);
			int					height_helper(MyNode<T>*);
			MyNode<T>*	get_parent(MyNode<T>*, MyNode<T>*);
			void				balance(MyNode<T>*);
			void				rotate_right(MyNode<T>*);
			void				rotate_left(MyNode<T>*);
			void				rr_rotation(MyNode<T>*);
			void				ll_rotation(MyNode<T>*);
			void				rl_rotation(MyNode<T>*);
			void				lr_rotation(MyNode<T>*);
			
		public:
			MyAVLTree();
			~MyAVLTree();
			void 	add(T);
			void 	remove(T);
			void	preorder(MyNode<T>* = NULL);
			void 	inorder(MyNode<T>* = NULL);
			void 	postorder(MyNode<T>* = NULL);
			void 	clear(MyNode<T>*  = NULL);
			bool 	exists(T, MyNode<T>* = NULL);
			int  	height();
	};

	/////////////////////////////////
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
	template<typename T>
	void MyAVLTree<T>::add_helper(T elem, MyNode<T>* pos) {

		if(root_ == NULL)
			root_ = new MyNode<T>(elem, NULL, NULL);
		else {

			//Left Branch
			if(elem <= pos->getData()) {
				//If left is null add
				if(pos->getLeft() == NULL) 
					pos->setLeft(new MyNode<T>(elem, NULL, NULL));
				//Keep Searching if not null
				else
					add_helper(elem, pos->getLeft());
			}

			//Right Branch
			else {
				//If right is null add
				if(pos->getRight() == NULL) 
					pos->setRight(new MyNode<T>(elem, NULL, NULL));
				//Keep Searching if not null
				else
					add_helper(elem, pos->getRight());	
			}
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template<typename T>
	void MyAVLTree<T>::remove_helper(T elem, MyNode<T>* node, MyNode<T>* prev_node) {
		if(!node)
			return;
		
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
			if(elem <= node->getData())
				remove_helper(elem, node->getLeft(), node);
			if(elem > node->getData())
				remove_helper(elem, node->getRight(), node);
		}
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
	
	/////////////////////////////////
	template <typename T>
	MyNode<T>* MyAVLTree<T>::get_parent(MyNode<T>* find_parent, MyNode<T>* node) {
		MyNode<T>* left;
		MyNode<T>* right;

		if(node == NULL)
			return NULL;

		if(node->getLeft() == find_parent || node->getRight() == find_parent)
			return node;

		left = get_parent(find_parent, node->getLeft());
		right = get_parent(find_parent, node->getRight());

		if(left)
			return left;
		else
			return right;
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::balance(MyNode<T>* node) {
		MyNode<T>* child;
		MyNode<T>* child_child;
		bool side;
		int tree_height;
		int left_height;
		int right_height;

		if(node) {
			left_height = height_helper(node->getLeft());
			right_height = height_helper(node->getRight());
			tree_height = left_height - right_height;

			if(tree_height == 2) {
				child = node->getLeft();
				side = false;
			}
			else if(tree_height == -2) {
				child = node->getRight();
				side = true;
			}
			else {
				balance(node->getLeft());
				balance(node->getRight());
				return;
			}
				
			if(child->getLeft()) {
				if(child->getLeft()->getLeft())
					ll_rotation(node);
				else
					lr_rotation(node);
			}
			else {
				if(child->getLeft()->getLeft())
					rl_rotation(node);
				else
					rr_rotation(node);
			}

		}
	}
	/////////////////////////////////


	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::rotate_right(MyNode<T>* node) {
		MyNode<T>* new_top;
		MyNode<T>* parent;
		
		new_top = node->getLeft();
		node->setLeft(new_top->getRight());
		new_top->setRight(node);

		//Fix parent of node being rotated only if node is not root
		if(root_ == node)
			root_ = new_top;
		else {
			parent = get_parent(node, root_);
			if(parent->getLeft() == node)
				parent->setLeft(new_top);
			else
				parent->setRight(new_top);
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::rotate_left(MyNode<T>* node) {
		MyNode<T>* new_top;
		MyNode<T>* parent;
		
		new_top = node->getRight();
		node->setRight(new_top->getLeft());
		new_top->setLeft(node);

		//Fix parent of node being rotated only if node is not root
		if(root_ == node)
			root_ = new_top;
		else {
			parent = get_parent(node, root_);
			if(parent->getLeft() == node)
				parent->setLeft(new_top);
			else
				parent->setRight(new_top);
		}
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::rr_rotation(MyNode<T>* node) {
		rotate_left(node);
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::ll_rotation(MyNode<T>* node) {
		rotate_right(node);	
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::rl_rotation(MyNode<T>* node) {
		rotate_right(node->getRight());
		rotate_left(node);
	}
	/////////////////////////////////
	
	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::lr_rotation(MyNode<T>* node) {
		rotate_left(node->getLeft());
		rotate_right(node);
	}
	/////////////////////////////////
	
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
	template <typename T>
	void MyAVLTree<T>::add(T elem) {
		add_helper(elem, root_);
		balance(root_);
	}
	/////////////////////////////////

	/////////////////////////////////
	template <typename T>
	void MyAVLTree<T>::remove(T elem) {
		remove_helper(elem, root_, NULL);
		balance(root_);
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
#endif
