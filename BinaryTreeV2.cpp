using namespace std;
#include<iostream>
#include<climits>
#include <math.h>
#include<stack>
#include<cassert>
#include<vector>
#include<queue>
#include<deque>

class BinaryTree {
private:
	int data { };
	BinaryTree* left { };
	BinaryTree* right { };

public:

	BinaryTree(int data) :
			data(data) {
	}

	void add(vector<int> values, vector<char> direction) {
		assert(values.size() == direction.size());
		BinaryTree* current = this;
		// iterate on the path, create all necessary nodes
		for (int i = 0; i < (int) values.size(); ++i) {
			if (direction[i] == 'L') {
				if (!current->left)
					current->left = new BinaryTree(values[i]);
				else
					assert(current->left->data == values[i]);
				current = current->left;
			} else {
				if (!current->right)
					current->right = new BinaryTree(values[i]);
				else
					assert(current->right->data == values[i]);
				current = current->right;
			}
		}
	}
////////////////////////////

	void print_inorder() {
		if (left)
			left->print_inorder();
		cout << data << " ";
		if (right)
			right->print_inorder();
	}
	void print_preorder() {
		cout << data << " ";
		if (left)
			left->print_preorder();
		if (right)
			right->print_preorder();
	}

	void print_postorder() {
		if (left)
			left->print_postorder();
		if (right)
			right->print_postorder();
		cout << data << " ";
	}
////////////////////////////

int tree_max() {
		int res = data;
		if (left)
			res = max(res, left->tree_max());
		if (right)
			res = max(res, right->tree_max());
		return res;
	}
////////////////////////////	

	int tree_height() {
		int res = 0;
		if (left)
			res = 1 + left->tree_height();
		if (right)
			res = max(res, 1 + right->tree_height());
		return res;
}
////////////////////////////

	int total_nodes() {
		int res = 1;
		if (left)
			res += left->total_nodes();
		if (right)
			res += right->total_nodes();
		return res;
	}
////////////////////////////

	int leafs_count() {
		int res = !left && !right;
		if (left)
			res += left->leafs_count();
		if (right)
			res += right->leafs_count();
		return res;
	}
////////////////////////////

	bool is_exists(int value) {
		bool res = value == data;
		if (!res && left)
			res = left->is_exists(value);
		if (!res && right)
			res = right->is_exists(value);
		return res;
	}
////////////////////////////

	bool is_perfect(int h = -1) {	// default param.
		if (h == -1)	// first call
			h = tree_height();

		// All leaves must be on the same last level
		if (!left && !right)	//	1
			return (h == 0);	// but h isn't 0

		if (!left && right || left && !right)	// 2
			return false;	// one child!

		// perfect on level h is perfect on h-1 for children
		return left->is_perfect(h - 1) && right->is_perfect(h - 1);
	}
	

	bool is_perfect_fomula() {
		int h = tree_height();
		int n = total_nodes();
		return pow(2, h + 1) - 1 == n;
	}
////////////////////////////

void level_order_traversal() {	

	queue<BinaryTree*> nodes_queue;
	nodes_queue.push(this);

	while(!nodes_queue.empty()) {

			BinaryTree* temp = nodes_queue.front();
			nodes_queue.pop();
			cout << temp->data << " ";

			if(temp->left)
				nodes_queue.push(temp->left);
			if(temp->right)
				nodes_queue.push(temp->right);
	 	  	}
			cout << endl;
	}
///////////////////

void level_order_traversal_linebyline() {	

	queue<BinaryTree*> nodes_queue;
	nodes_queue.push(this);
	int level { };

	while(!nodes_queue.empty()) {
		int size = nodes_queue.size();	// current no. of nodes
		cout << "level " << level << ": ";

		while(size--){	// nodes of one level only

			BinaryTree* temp = nodes_queue.front();
			nodes_queue.pop();
			cout << temp->data << " ";

			if(temp->left)
				nodes_queue.push(temp->left);
			if(temp->right)
				nodes_queue.push(temp->right);

	 	  	}

		level++;	
		cout << endl;
	}
}
////////////////

void print_level(int cur_level) {

	if(!cur_level)
		cout << data << " " ;

	else {
	if(left)
		left->print_level(cur_level - 1);	

	if(right)
		right->print_level(cur_level - 1);
	}

}

void level_order_recursively() {
	int h = tree_height();

	for(int level = 0; level <= h; level++) // O(n^n)	- > O(n^2)
		print_level(level);	//	 0 		1 		2	   	3
}
/////////////////////

void level_order_spiral() {		// queue(normal forward)(FIFO)    stack (backward)(LIFO) -> deque

	deque<BinaryTree*> nodes_dequeue;	// front and back	push and pop
	nodes_dequeue.push_front(this);

    bool forward = true;	// L to R -- ODD - EVEN level

	while(!nodes_dequeue.empty()) {

		int size = nodes_dequeue.size();	

		while(size--){	

		BinaryTree* temp{ };


		if(forward) { 	
			temp = nodes_dequeue.front();
			nodes_dequeue.pop_front(); // forward

			if(temp->left)
				nodes_dequeue.push_back(temp->left);		// children	-> backward next
			if(temp->right)
				nodes_dequeue.push_back(temp->right);
		}

		else {							// backward		
			temp = nodes_dequeue.back();
			 nodes_dequeue.pop_back(); // backward

			if(temp->right)
				nodes_dequeue.push_front(temp->right);		// children -> forward next
			if(temp->left)
				nodes_dequeue.push_front(temp->left);
		}

		cout << temp->data << " "; // which you pop-ed

	}

	forward = !forward; // spiral 
}

}
///////////////////

	bool is_complete() {	

	queue<BinaryTree*> nodes_queue;
	nodes_queue.push(this);


bool no_more_allowed = false; // 1st missing node means (LEFT before Right) NO more nodes should be there if yes complete if there is NOT complete
											// on CURRENT LEVEL

	while (!nodes_queue.empty())	// level by level
	{
			int sz = nodes_queue.size();

			while(sz--) {
				BinaryTree* temp = nodes_queue.front();
				nodes_queue.pop();

				if(temp->left) {
					if(no_more_allowed)
						return false;

					nodes_queue.push(temp->left); // next level --- children		
				}		
				else // NULL
				 no_more_allowed = true; // 1st missing node so no more allowed nodes should be there 

			  if(temp->right) {
					if(no_more_allowed)
						return false;

					nodes_queue.push(temp->right); // next level --- children		
				}		
				else // NULL
				 no_more_allowed = true; // 1st missing node so no more allowed nodes should be there 

			}
	}
	
return true;
}
//////////////////

	BinaryTree(deque<int>& preorder, deque<int>& inorder, int inorder_start = 0, int inorder_end = -1) {
		if(inorder_end == -1)
			inorder_end = (int)inorder.size() - 1;
	
	data = preorder[0];
	preorder.pop_front();

	for(int split = inorder_start; split <= inorder_end; ++split) {

		if(inorder[split] == data) {

				if(inorder_start < split) 
					left = new BinaryTree(preorder , inorder , inorder_start , split - 1);

				if(inorder_start > split) 
					right = new	BinaryTree(preorder , inorder , split + 1, inorder_end);

		break;

		}

	}

}
///////////////////////////////

// construct FULL/Stict BT from preorder	ONLY
//		0 or 2 
BinaryTree(queue<pair<int , bool>> &preorder_queue) {
	// value  Leaf or not
	pair<int , bool> current = preorder_queue.front();
	preorder_queue.pop();
	
data = current.first; // value

	if(current.second == false) { // internal node ... not leaf ... has 2 children
	// 0 or TWO !... L and R
		left = new BinaryTree(preorder_queue);
		right = new BinaryTree(preorder_queue);		// ABSTRACT RECURSION !
	}
	
}


};

//////////////////////////////// tests ///////////////////
 

void test1_numbers() {
	BinaryTree tree(1);
	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	tree.add( { 3, 6, 15 }, { 'R', 'R', 'L' });

	assert(tree.tree_max() == 15);
	assert(tree.tree_height() == 3);
	assert(tree.total_nodes() == 10);
	assert(tree.leafs_count() == 4);

	assert(tree.is_exists(1));
	assert(tree.is_exists(15));
	assert(tree.is_exists(4));
	assert(!tree.is_exists(61));
}
///////////// 
void test_completness() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });							//          1
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });					//			2		    	3

	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });	//					   4         5	      -      6

	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });//				    7     8   -     9	      10

	cout << tree.is_complete() << endl;	//  false
}

void test2_completness() {
	BinaryTree tree(1);

	tree.add( { 2, 7 } , { 'L', 'L' } );									//          1
	tree.add( { 3 } , { 'R'} );									//			2		    	3
															//	   	7 

	cout << tree.is_complete() << endl;	//  false
}

void test_level_order() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });							//       1
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });					//			2			3
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });	//					   4         5		      6
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });//					7	  8	     	9	  10

	tree.level_order_traversal();
}

void test_level_order_V2() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });							//       1
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });					//			2			3
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });	//					   4         5		      6
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });//					7	  8	     	9	  10

	tree.level_order_traversal_linebyline();
}

void test_level_order_recursively() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });							//       1
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });					//			2			3
	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });	//					   4         5		      6
	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });//					7	  8	     	9	  10

	tree.level_order_recursively();
}

void test_level_order_spiral() {
	BinaryTree tree(1);

	tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });							//          1
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });					//			2		    	3

	tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });	//					   4         5	      -      6

	tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });//				   7       8  -      9	      10

	tree.level_order_spiral();	// 1 3 2 4 5 6 10 9 8 7
}
///////////// 
void test_construct(deque<int> preo , deque<int> ino) {

	BinaryTree tree(preo , ino);

	cout << "Pre: " ;
	 tree.print_preorder();

	cout << "In: " ;
	 tree.print_inorder() ;
}



int main() {









//test1_numbers(); // Assertion failed: tree.tree_max() == ---, file -----.cpp, line --
//cout << " Gz ! \n";
/*
	test_level_order();
	test_level_order_V2();
	test_level_order_recursively(); 
	cout << endl;
	test_level_order_spiral();
*/

/*
	test_completness();
	
	test2_completness();
*/

/*
	deque<int> pre {7,5,3,6,2,1}; 

	deque<int> in  {3,5,7,2,6,1};

	test_construct(pre,in);

*/
	

    return 0;
}