extern crate rusty_machine as rm;
extern crate rusty_machine;
extern crate rand;

//impl<T: Copy + One + Zero + Add<T, Output = T>> Add<Matrix<T>> for Matrix<T> {
//    type Output = Matrix<T>;    
//    fn add(self, f: Matrix<T>) -> Matrix<T> { ... }
//}

fn determineDim() {
let NDIM: i32 = 2;
}

fn regions() {
let (region, vSum) : (VecR, VecR);
}

type real = f64;
struct xy {
    x: real,
    y: real,
}
// addition trait to the vector 
impl xy {
    fn Vadd(&self, a: xy) -> xy {
        let b : xy;        
        b.x = self.x + a.x;
        b.y = self.y + a.y;
        b
    }
    
    fn Vsub(&self, a: xy) -> xy {
        b.x = self.x - a.x;
        b.y = self.y - a.y;
        b
    }
    
    fn VDot(&self, a: xy) {
        (self.x * b.x) + (self.y * b.y); 
    }

    fn VSAdd(&self, a: xy, b: xy, c: xy) {
        
    }
}

fn InitCoords () {
    let (c, gap) : (VecR, VecR);
    let (n, nx, ny) : (i64, i64, i64);

}

type VecR = xy;

struct Mol {
    r: VecR,
    rv: VecR,
    ra: VecR,
}

type newMol = Mol;
fn ComputeForces() {
    let dr = VecR {x: 0.0, y: 0.0};
    let (j1, j2, n) : (i32,i32,i32);

    // I shall uncomment these as soon as the variables inside this function are properly established. 
    
//    rrCut = rCut.powf(2.0); // raise power of rCut to 2.0
//    for n in (0..nMol) {
 //       mol[n].ra.x = 0.0; // allocate all the x coordinates as 0 
  //      mol[n].ra.y = 0.0; // allocate all the y coordinates as 0 
  //  }
    
}

fn main () {

}
