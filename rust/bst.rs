use std::fmt::Display;

type Link<T> = Option<Box<TreeNode<T>>>;

struct TreeNode<T> {
    val: T,
    left: Link<T>,
    right: Link<T>,
}

impl<T> TreeNode<T> where T: Ord {
    fn new(val: T) -> Self {
        Self {val, left: None, right: None}
    }

    fn insert(&mut self, val: T) {
        if val < self.val {
            if let Some(ref mut left) = self.left {
                left.insert(val);
            } else {
                self.left = Some(Box::new(TreeNode::new(val)));
            }
        } else {
            if let Some(ref mut right) = self.right {
                right.insert(val);
            } else {
                self.right = Some(Box::new(TreeNode::new(val)));
            }
        }
    }
}

impl<T> TreeNode<T> where T: Display {
    fn print(&self) {
        if let Some(ref x) = self.left {
            x.print();
        }
        println!("{}", self.val);
        if let Some(ref x) = self.right {
            x.print();
        }
    }
}

fn main() {
    let mut n = TreeNode::new(5);
    n.insert(7);
    n.insert(2);
    n.insert(9);
    n.insert(0);
    n.insert(6);
    n.insert(200);
    n.insert(-20);
    n.print();
}
