use std::cell::Cell;
use std::ops::Mul;
    
type real = f64;

#[derive(Debug, Copy, Clone)] // Copy trait has been implemented so that the the ownership can be transferred to another object
struct xy {
    x: real,
    y: real,
}
// addition trait to the vector 
type VecR = xy;

trait operation {
    fn VAdd(&mut self, a: xy) -> xy; 
    fn VSub(&mut self, a: xy) -> xy;
    fn VDot(&mut self, a: xy) -> f64;
    fn VSAdd(&mut self, a: xy, a3: xy) -> xy;
//    fn VTimes(&mut self, a3: i64) -> xy;
    fn VSet(&mut self, x1: real, x2: real);
    fn VSetAll(&mut self, v: real);
    // Checking periodic boundary conditions
//    fn VWrap(&mut self, t: i64);    
}

impl operation for xy {
    fn VAdd(&mut self, a: xy) -> xy {
        let mut b  = xy{x: 0.0, y: 0.0};        
        b.x = self.x + a.x;
        b.y = self.y + a.y;
        b
    }
    
    fn VSub(&mut self, a: xy) -> xy {
        let mut b  = xy{x: 0.0, y: 0.0};        
        b.x = self.x - a.x;
        b.y = self.y - a.y;
        b
    }
    
    fn VDot(&mut self, a: xy) -> f64 {
        let mut c : f64;        
        c = (self.x * a.x) + (self.y * a.y);
        c
    }   

    fn VSet(&mut self, x1: real, x2: real) {
        self.x = 0.0; // set x to zero 
        self.y = 0.0; // set y to zero
        self.x = x1;
        self.y = x2;
    }   

    fn VSetAll(&mut self, v: real) {
        self.VSet(v,v);
    }
    /*
 
   fn VTimes(&mut self, a3: i64) -> xy {
        let mut b  = xy{x: 0.0, y: 0.0};        
        b.x = self.x  * a3;
        b.y = self.y  * a3; 
        b
    }
     */
    
    fn VSAdd(&mut self, a: xy, a3: xy) -> xy {
        let mut b  = xy{x: 0.0, y: 0.0};        
        b.x = self.x + (a3.x * a.x);
        b.y = self.y + (a3.y * a.y);
        b
    }
}
// timestep algorithms

fn ComputeForces() {
    let dr : VecR;
    let (fcVal, rr, rrCut, rri, rri3) : (real, real, real, real, real);
    let (j1, j2, n) : (i64,i64,i64);
    // TODO - That needs to be fixed 
    let rrCut = rCut.sqrt(); // haven't defined rCut for some unknown reason 
    uSum = 0;

    for () {}// looping 
    
    
}

fn main () {


    
    let mut aa = xy {x : 2.1, y: 3.2};
    let mut bb = xy {x: 2.0, y: 3.0};

    let cc = aa.VAdd(bb); // testing VAdd
    let dd = aa.VSub(bb); // testing VSub
    let ee = aa.VDot(bb); // testing VDot
    //    let ff = aa.VSAdd(bb,3);
        
    println!("{} {}", cc.x, cc.y);
    println!("{} {}", dd.x, dd.y);
    println!("{}", ee);    
    aa.VSet(2.2,3.3);
    println!("{} {}", aa.x, aa.y);
    
    //    println!("{} {}", ff.x, ff.y);
   
}