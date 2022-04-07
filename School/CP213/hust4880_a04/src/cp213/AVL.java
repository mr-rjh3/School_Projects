package cp213;

/**
 * Implements an AVL (Adelson-Velsky Landis) tree. Extends BST.
 *
 * @author your name here
 * @author David Brown
 * @version 2021-02-18
 * @param <T>
 */
public class AVL<T extends Comparable<T>> extends BST<T> {

    /**
     * Returns the balance value of node. If greater than 1, then left heavy, if
     * less than -1, then right heavy. If in the range -1 to 1 inclusive, the node
     * is balanced. Used to determine whether to rotate a node upon insertion.
     *
     * @param node The TreeNode to analyze for balance.
     * @return A balance number.
     */
    private int balance(final TreeNode<T> node) {
    	int balanced;
    	if(node != null) {
    		
	    	if(node.getLeft() == null && node.getRight() != null) {
				balanced = node.getRight().getHeight();
			}
			else if(node.getLeft() != null && node.getRight() == null){
				balanced = node.getLeft().getHeight();
			}
			else
				balanced = node.getLeft().getHeight() - node.getRight().getHeight();
    	}
    	else
    		balanced = 0;
    	return balanced;
    }

    /**
     * Performs a left rotation around node.
     *
     * @param node The subtree to rotate.
     * @return The new root of the subtree.
     */
    private TreeNode<T> rotateLeft(final TreeNode<T> node) {
    	
    	TreeNode<T> rotate = node.getRight();
    	TreeNode<T> temp_node = rotate.getLeft();
    	
    	rotate.setLeft(node);
    	node.setRight(temp_node);
    	
    	node.updateHeight();
    	rotate.updateHeight();
    	return rotate;

    }

    /**
     * Performs a right rotation around {@code node}.
     *
     * @param node The subtree to rotate.
     * @return The new root of the subtree.
     */
    private TreeNode<T> rotateRight(final TreeNode<T> node) {

    	TreeNode<T> rotate = node.getLeft();
    	TreeNode<T> temp_node = rotate.getRight();
    	
    	rotate.setRight(node);
    	node.setLeft(temp_node);
    	
    	node.updateHeight();
    	rotate.updateHeight();
    	return rotate;

    }

    /**
     * Auxiliary method for {@code insert}. Inserts data into this AVL.
     *
     * @param node the current node (TreeNode)
     * @param data Data to be inserted into the node
     * @return The inserted node.
     */
    @Override
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
		// Left Left Case
		if (this.balance(node) > 1) {
			if(node.getLeft() != null) {
				if(node.getValue().compareTo(node.getLeft().getValue()) > 0)
					this.rotateRight(node);
			}
		}
            
 
        // Right Right Case
        if (this.balance(node) < -1) {
        	if(node.getRight() != null) {
				if(node.getValue().compareTo(node.getRight().getValue()) < 0)
					this.rotateLeft(node);
			}
        }
 
        // Left Right Case
        if (this.balance(node) > 1) {
        	if(node.getRight() != null) {
				if(node.getValue().compareTo(node.getRight().getValue()) < 0) {
					node.setLeft(this.rotateLeft(node.getLeft()));
					this.rotateRight(node);
				}
			}
            
        }
 
        // Right Left Case
        if (this.balance(node) < -1) {
        	if(node.getRight() != null) {
				if(node.getValue().compareTo(node.getRight().getValue()) > 0) {
					node.setRight(this.rotateRight(node.getRight()));
		            this.rotateLeft(node);
				}
			}
            
        }
		
    	return insert;

    }

    /**
     * Auxiliary method for {@code valid}. Determines if a subtree based on node is
     * a valid subtree. An AVL must meet the BST validation conditions, and
     * additionally be balanced in all its subtrees - i.e. the difference in height
     * between any two children must be no greater than 1.
     *
     * @param node The root of the subtree to test for validity.
     * @return true if the subtree base on node is valid, false otherwise.
     */
    @Override
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
     * Determines whether two AVLs are identical.
     *
     * @param target The AVL to compare this AVL against.
     * @return true if this AVL and target contain nodes that match in position,
     *         value, count, and height, false otherwise.
     */
    public boolean equals(final AVL<T> target) {
	return super.equals(target);
    }

}