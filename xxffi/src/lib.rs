extern crate serde;
extern crate serde_json;

use serde::{Deserialize, Serialize};
use std::ffi::{CStr, CString};
use std::os::raw::c_char;

mod editor;
use editor::EditorLogic;

#[no_mangle]
pub unsafe extern "C" fn hello_from_rust() {
    println!("Hello from Rust");
}

#[repr(C)]
#[derive(Serialize, Deserialize, Debug)]
pub struct Point {
    x: i32,
    y: i32,
}

impl Point  {

    fn hello(&self) {
        println!("Hello from rust method!!!");
    }
}

#[no_mangle]
pub unsafe extern "C" fn my_point_print_hello(me: *const Point) {
    let me = &*me;
    me.hello();
}

#[no_mangle]
pub unsafe extern "C" fn serialize_rust_struct() -> *const c_char {
    let p1 = Point { x: 100, y: 200 };
    let serialized: std::string::String = serde_json::to_string(&p1).unwrap();
    let v_serialized = CString::new(serialized.into_bytes()).expect("CString::new failed");
    let c_serialized = v_serialized.as_c_str().as_ptr();
    std::mem::forget(v_serialized);
    c_serialized
}

#[no_mangle]
pub unsafe extern "C" fn get_rust_instance() -> Point {
    Point { x: 1000, y: 2000 }
}

#[no_mangle]
pub unsafe extern "C" fn init_editor_logic() -> EditorLogic {
    EditorLogic { a: 500, b: 600 }
}