package cp213;

import java.util.ArrayList;

/**
 * Implements a Binary Search Tree.
 *
 * @author your name here
 * @author David Brown
 * @version 2021-02-18
 */
public class BST<T extends Comparable<T>> {
    protected int comparisons = 0; // Count of comparisons performed by tree.

    // Attributes.
    protected TreeNode<T> root = null; // Root node of the tree.
    protected int size = 0; // Number of elements in the tree.

    /**
     * Auxiliary method for {@code equals}. Determines whether two subtrees are
     * identical in data and height.
     *
     * @param source Node of this BST.
     * @param target Node of that BST.
     * @return true if source and target are identical in data and height.
     */
    protected boolean equalsAux(final TreeNode<T> source, final TreeNode<T> target) {
    	boolean identical = true;
    	if(source != null && target != null && source.getValue().compareTo(target.getValue()) == 0 && source.getHeight() == target.getHeight()) {
    		if(source.getLeft() != null && target.getLeft() != null)
    			identical = equalsAux(source.getLeft(), target.getLeft());
    		if(source.getRight() != null && target.getRight() != null)
				identical = equalsAux(source.getRight(), target.getRight());
    	}
    	else 
    		identical = false;
    	
    	return identical;
    	

    }

    /**
     * Auxiliary method for {@code insert}. Inserts data into this BST.
     *
     * @param node the current node (TreeNode)
     * @param data data to be inserted into the node
     * @return the inserted node.
     */
    protected TreeNode<T> insertAux(TreeNode<T> node, final CountedData<T> data) {
    	TreeNode<T> insert = null;
    	// Check if the insert data is less than or greater than the current root
		if(node.getValue().compareTo(data) > 0) {
			// if less than check if left child is null
			if(node.getLeft() != null) {
				// if left child is not null call function again with left child as root
				insert = insertAux(node.getLeft(), data);
			}
			else {
				// otherwise make left child the new node
				insert = new TreeNode<T>(data);
				node.setLeft(insert);
			}
		}
		// if greater than check if right child is null
		else if(node.getValue().compareTo(data) < 0) {
			if(node.getRight() != null) {
				//if right child is not null call function again with right child as root
				insert = insertAux(node.getRight(), data);
			}
			else {
				// otherwise make right child the new node
				insert = new TreeNode<T>(data);
				node.setRight(insert);
			}
		}
		// If node is already in the BST increment it's data count
		else {
			node.getValue().incrementCount();
		}
		
		node.updateHeight();
    	return insert;
    }
    
    /**
     * Determines if this BST is a valid BST; i.e. a node's left child data is
     * smaller than its data, and its right child data is greater than its data, and
     * a node's height is equal to the maximum of the heights of its two children
     * (empty child nodes have a height of 0), plus 1.
     */

    /**
     * Auxiliary method for {@code valid}. Determines if a subtree based on node is
     * a valid subtree.
     *
     * @param node The root of the subtree to test for validity.
     * @return true if the subtree base on node is valid, false otherwise.
     */
    protected boolean isValidAux(final TreeNode<T> node) {
    	boolean valid = true;
    	if(node != null) {
    		if(node.getLeft() == null && node.getRight() != null) {
    			valid = node.getHeight() == node.getRight().getHeight();
    		}
    		else if(node.getLeft() != null && node.getRight() == null){
    			valid = node.getHeight() == node.getLeft().getHeight();
    		}
    		else
    			valid = node.getHeight() == node.getLeft().getHeight() + node.getRight().getHeight();
	    	
    		if(valid == true && node.getLeft() != null && node.getValue().compareTo(node.getLeft().getValue()) > 0) {
	    		valid = isValidAux(node.getLeft());
	    	}
	    	else if(node.getLeft() != null)
	    		valid = false;
	    	
	    	if(valid == true && node.getRight() != null && node.getValue().compareTo(node.getRight().getValue()) < 0) {
	    		valid = isValidAux(node.getRight());
	    	}
	    	else if(node.getRight() != null)
	    		valid = false;
    	}

    	return valid;
    	

    }

    /**
     * Returns the height of a given TreeNode.
     *
     * @param node The TreeNode to determine the height of.
     * @return The value of the height attribute of node, 0 if node is null.
     */
    protected int nodeHeight(final TreeNode<T> node) {
	int height = 0;

	if (node != null) {
	    height = node.getHeight();
	}
	return height;
    }

    /**
     * Determines if this BST contains key.
     *
     * @param key The key to search for.
     * @return true if this BST contains key, false otherwise.
     */
    public boolean contains(final CountedData<T> key) {
    	TreeNode<T> node = this.root;
    	boolean found = false;
    	// While loop till node is null
    	while(node != null && found == false) {
    		// check if node == key
    		if(node.getValue().compareTo(key) == 0) 
    			found = true;
    		// if less make node it's left child
    		else if(node.getValue().compareTo(key) > 0) 
    			node = node.getLeft();
        	// If greater make it it's right child
    		else 
    			node = node.getRight();
    	}
    	return found;
    }

    /**
     * Determines whether two BSTs are identical.
     *
     * @param target The BST to compare this BST against.
     * @return true if this BST and that BST contain nodes that match in position,
     *         value, count, and height, false otherwise.
     */
    public boolean equals(final BST<T> target) {
	boolean isEqual = false;

	if (this.size == target.size) {
	    isEqual = this.equalsAux(this.root, target.root);
	}
	return isEqual;
    }

    /**
     * Get number of comparisons executed by the {@code retrieve} method.
     *
     * @return comparisons
     */
    public int getComparisons() {
	return this.comparisons;
    }

    /**
     * Returns the height of the root node of this BST.
     *
     * @return height of root node, 0 if the root node is null.
     */
    public int getHeight() {
	int height = 0;

	if (this.root != null) {
	    height = this.root.getHeight();
	}
	return height;
    }

    /**
     * Returns the number of nodes in the BST.
     *
     * @return number of node in this BST.
     */
    public int getSize() {
	return this.size;
    }

    /**
     * Returns an array of copies of CountedData objects in a linked data
     * structure. The array contents are in data order from smallest to largest.
     *
     * Not thread safe as it assumes contents of data structure are not changed by
     * an external thread during the copy loop. If data elements are added or
     * removed by an external thread while the data is being copied to the array,
     * then the declared array size may no longer be valid.
     *
     * @return this tree data as an array of data.
     */
    public ArrayList<CountedData<T>> inOrder() {
	return this.root.inOrder();
    }

    /**
     * Inserts data into this BST.
     *
     * @param data Data to store.
     */
    public void insert(final CountedData<T> data) {
    	
    	// if empty insert into root
    	if(!this.isEmpty()) {
    		TreeNode<T> node = this.root;
    		this.insertAux(node, data);
    	}
    	else 
    		this.root = new TreeNode<T>(data);
    	this.size++;
    }

    /**
     * Determines if this BST is empty.
     *
     * @return true if this BST is empty, false otherwise.
     */
    public boolean isEmpty() {
	return this.root == null;
    }

    /**
     * Determines if this BST is a valid BST; i.e. a node's left child data is
     * smaller than its data, and its right child data is greater than its data, and
     * a node's height is equal to the maximum of the heights of its two children
     * (empty child nodes have a height of 0), plus 1.
     *
     * @return true if this BST is a valid BST, false otherwise.
     */
    public boolean isValid() {
	return this.isValidAux(this.root);
    }

    /**
     * Returns an array of copies of CountedData objects int a linked data
     * structure. The array contents are in level order starting from the root
     * (this) node. Helps determine the structure of the tree.
     *
     * Not thread safe as it assumes contents of data structure are not changed by
     * an external thread during the copy loop. If data elements are added or
     * removed by an external thread while the data is being copied to the array,
     * then the declared array size may no longer be valid.
     *
     * @return this tree data as an array of data.
     */
    public ArrayList<CountedData<T>> levelOrder() {
	return this.root.levelOrder();
    }

    /**
     * Resets the comparison count to 0.
     */
    public void resetComparisons() {
	this.comparisons = 0;
	return;
    }

    /**
     * Retrieves a copy of data matching key data (key should have data
     * count of 0). Returning a complete CountedData gives access to the
     * data and count.
     *
     * @param key The key to look for.
     * @return data The complete CountedData that matches key, null otherwise.
     */
    public CountedData<T> retrieve(final CountedData<T> key) {
    	CountedData<T> data = null;
    	TreeNode<T> node = this.root;
    	while(node != null && data == null) {
	    	// Check if the key is less than or greater than the current root
			if(node.getValue().compareTo(key) > 0) {
				// if less than check if left child is null
				if(node.getLeft() != null) {
					// if left child is not null set node to it's right child
					node = node.getLeft();
				}
			}
			// if greater than check if right child is null
			else if(node.getValue().compareTo(key) < 0) {
				if(node.getRight() != null) {
					//if right child is not null set node to it's right child
					node = node.getRight();
				}
			}
			// If node is already in the BST increment it's data count
			else {
				data = node.getValue();
			}
			this.comparisons++;
    	}
    	return data;

    }
}