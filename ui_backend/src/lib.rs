#[no_mangle]
pub extern "C" fn mul(x: i32) -> i32 {
    x * 2
}

#[no_mangle]
pub extern "C" fn create_new_project() {
    println!("Creating new project");
}
