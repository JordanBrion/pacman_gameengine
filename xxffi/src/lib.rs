extern crate serde;
extern crate serde_json;

use serde::{Deserialize, Serialize};

#[no_mangle]
pub unsafe extern "C" fn hello_from_rust() {
    println!("Hello from Rust");
}

#[derive(Serialize, Deserialize, Debug)]
pub struct Point {
    x: i32,
    y: i32,
}

#[no_mangle]
pub unsafe extern "C" fn serialize_rust_struct() {
    let p1 = Point { x: 100, y: 200 };
    let serialized: std::string::String = serde_json::to_string(&p1).unwrap();
    println!("aaaaa {}", serialized);
    // let c_serialized = serialized.
    // serialized;
}

// #[cfg(test)]
// mod tests {
//     #[test]
//     fn it_works() {
//         assert_eq!(2 + 2, 4);
//     }
// }
