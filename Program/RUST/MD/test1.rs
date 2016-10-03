struct MulOp<T1: HasValue + Copy, T2: HasValue + Copy> {
    lhs: T1,
    rhs: T2
}

struct Calculus<T: HasValue + Copy> {
    calc: T
}

impl<T: HasValue + Copy> HasValue for Calculus<T> {
    fn get_value(&self) -> int {
        self.calc.get_value()
    }
}

impl<T, O> Add<Calculus<O>, Calculus<AddOp<T, O>>> for Calculus<T>
    where T: HasValue + Copy, O: HasValue + Copy {
    fn add(&self, other : &Calculus<O>) -> Calculus<AddOp<T, O>> {
        Calculus { calc: AddOp { lhs: self.calc, rhs: other.calc } }
    }
}

impl<T, O> Mul<Calculus<O>, Calculus<MulOp<T, O>>> for Calculus<T>
    where T: HasValue + Copy, O: HasValue + Copy {
    fn mul(&self, other : &Calculus<O>) -> Calculus<MulOp<T, O>> {
        Calculus { calc: MulOp { lhs: self.calc, rhs: other.calc } }
    }
}

impl Val {
    fn new(n: int) -> Calculus<Val> {
        Calculus { calc: Val { value: n } }
    }
}

fn main() {
    let a = Val::new(1);
    let b = Val::new(2);
    let c = Val::new(3);

    let e = ((a + b) * c).get_value();

    print!("{}", e);
}
