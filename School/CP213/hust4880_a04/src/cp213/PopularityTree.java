package cp213;

/**
 * Implements a Popularity Tree. Extends BST.
 *
 * @author your name here
 * @author David Brown
 * @version 2021-02-18
 */
public class PopularityTree<T extends Comparable<T>> extends BST<T> {

    /**
     * Auxiliary method for {@code valid}. May force node rotation if the retrieval
     * count of the located node value is incremented.
     *
     * @param node The node to examine for key.
     * @param key  The value to search for. Count is updated to count in matching
     *             node value if key is found.
     * @return the updated node.
     */
    private TreeNode<T> retrieveAux(TreeNode<T> node, final CountedData<T> key) {
    	TreeNode<T> data = null;
    	// Check if the key is less than or greater than the current root
		if(node.getValue().compareTo(key) > 0) {
			// if less than check if left child is null
			if(node.getLeft() != null) {
				if(node.getLeft().getValue().compareTo(key) == 0) {
					data = node.getLeft();
					data.getValue().incrementCount();
					if(data.getValue().getCount() > node.getValue().getCount())
						this.rotateRight(node);
				}
				else {
					// if left child is not null set node to it's right child
					data = retrieveAux(node.getLeft(), key);
				}
				this.comparisons++;
			}
		}
		// if greater than check if right child is null
		else if(node.getValue().compareTo(key) < 0) {
			if(node.getRight() != null) {
				if(node.getRight().getValue().compareTo(key) == 0) {
					data = node.getRight();
					data.getValue().incrementCount();
					if(data.getValue().getCount() > node.getValue().getCount())
						this.rotateLeft(node);
				}
				else {
					//if right child is not null set node to it's right child
					data = retrieveAux(node.getRight(), key);
				}
				this.comparisons++;
			}
		}

	
    	return data;
    	
    }

    /**
     * Performs a left rotation around node.
     *
     * @param parent The subtree to rotate.
     * @return The new root of the subtree.
     */
    private TreeNode<T> rotateLeft(final TreeNode<T> parent) {
    	TreeNode<T> rotate = parent.getRight();
    	TreeNode<T> temp_node = rotate.getLeft();
    	
    	rotate.setLeft(parent);
    	parent.setRight(temp_node);
    	
    	parent.updateHeight();
    	rotate.updateHeight();
    	return rotate;
    	
    }

    /**
     * Performs a right rotation around {@code node}.
     *
     * @param parent The subtree to rotate.
     * @return The new root of the subtree.
     */
    private TreeNode<T> rotateRight(final TreeNode<T> parent) {
    	TreeNode<T> rotate = parent.getLeft();
    	TreeNode<T> temp_node = rotate.getRight();
    	
    	rotate.setRight(parent);
    	parent.setLeft(temp_node);
    	
    	parent.updateHeight();
    	rotate.updateHeight();
    	return rotate;
    }

    /**
     * Replaces BST {@code insertAux} - does not increment count on repeated
     * insertion. Counts are incremented only on retrieve.
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
		
		node.updateHeight();
    	return insert;
    }

    /**
     * Auxiliary method for {@code valid}. Determines if a subtree based on node is
     * a valid subtree. An Popularity Tree must meet the BST validation conditions,
     * and additionally the counts of any node data must be greater than or equal to
     * the counts of its children.
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
     * Very similar to the BST retrieve, but increments the data count here instead
     * of in the insertion.
     *
     * @param key The key to search for.
     */
    @Override
    public CountedData<T> retrieve(CountedData<T> key) {
    	CountedData<T> data = null;
    	TreeNode<T> node = null;
		if(!this.isEmpty()) {
				node = this.retrieveAux(this.root, key);
				if(node != null) {
					data = node.getValue();
				}
		}
		return data;

    }

    /**
     * Determines whether two PopularityTrees are identical.
     *
     * @param target The PopularityTree to compare this PopularityTree against.
     * @return true if this PopularityTree and target contain nodes that match in
     *         position, value, count, and height, false otherwise.
     */
    public boolean equals(final PopularityTree<T> target) {
	return super.equals(target);
    }

}