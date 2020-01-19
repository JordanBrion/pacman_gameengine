#[no_mangle]
pub unsafe extern "C" fn request_create() {
    println!("Hello from Rust");
}

// #[cfg(test)]
// mod tests {
//     #[test]
//     fn it_works() {
//         assert_eq!(2 + 2, 4);
//     }
// }
