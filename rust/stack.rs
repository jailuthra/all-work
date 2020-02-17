use std::fmt::Display;

struct Node<T> {
    val: T,
    next: Option<Box<Node<T>>>,
}

struct Stack<T> {
    head: Option<Box<Node<T>>>,
    length: i32,
}

impl<T: Display> Stack<T> {
    fn new() -> Self {
        Self {head: None, length: 0}
    }

    fn push(&mut self, val: T) {
        let n = Node {val, next: self.head.take()};
        self.head = Some(Box::new(n));
        self.length += 1;
    }

    fn print(&self) {
        let mut h = self.head.as_ref();
        for _ in 0..self.length {
            println!("{}", h.unwrap().val);
            h = h.unwrap().next.as_ref();
        }
    }
}

fn main() {
    let mut s: Stack<i32> = Stack::new();
    s.push(9);
    s.push(10);
    s.print()
}
