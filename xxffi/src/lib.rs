extern crate ash;
extern crate serde;
extern crate serde_json;

use serde::{Deserialize, Serialize};
use std::ffi::{CStr, CString};
use std::os::raw::c_char;

use ash::version::EntryV1_0;
use ash::version::InstanceV1_0;
use ash::vk::Handle;

// mod editor;

pub struct VulkanContext {
    entry: ash::Entry,
    instance: ash::Instance,
}

#[no_mangle]
pub unsafe extern "C" fn create_vulkan_context() -> *mut VulkanContext {
    ;
    let entry = ash::Entry::new().expect("Cannot create entry");
    let instance = create_instance(&entry);
    let p_context = Box::new(VulkanContext {
        entry: entry,
        instance: instance,
    });
    Box::into_raw(p_context)
}

unsafe fn create_instance(entry: &ash::Entry) -> ash::Instance {
    let v_layers =
        vec![CString::new("VK_LAYER_KHRONOS_validation").expect("Cannot validation layer name")];
    let application_name = CString::new("003_swapchain").expect("Cannot create application name");
    let engine_name = CString::new("Not Unreal Engine 4").expect("Cannot create engine name");
    let application_info = ash::vk::ApplicationInfo {
        s_type: ash::vk::StructureType::APPLICATION_INFO,
        p_next: std::ptr::null(),
        p_application_name: application_name.as_ptr(),
        application_version: ash::vk_make_version!(1, 0, 0),
        p_engine_name: engine_name.as_ptr(),
        engine_version: ash::vk_make_version!(0, 0, 1),
        api_version: ash::vk_make_version!(1, 0, 0),
    };
    // TODO make extension names portable
    let v_extensions: Vec<&CStr> = vec![
        ash::extensions::khr::Surface::name(),
        ash::extensions::khr::XcbSurface::name(),
        ash::extensions::ext::DebugReport::name(),
    ];
    let v_extensions_c: Vec<*const u8> = v_extensions
        .iter()
        .map(|ss| ss.as_ptr() as *const u8)
        .collect();
    let instance_create_info = ash::vk::InstanceCreateInfo {
        s_type: ash::vk::StructureType::INSTANCE_CREATE_INFO,
        p_next: std::ptr::null(),
        flags: Default::default(),
        p_application_info: &application_info,
        enabled_layer_count: v_layers.len() as u32,
        pp_enabled_layer_names: v_layers.as_ptr() as *const *const i8,
        enabled_extension_count: v_extensions_c.len() as u32,
        pp_enabled_extension_names: v_extensions_c.as_ptr() as *const *const i8,
    };
    entry
        .create_instance(&instance_create_info, None)
        .expect("Cannot create instance")
}

#[no_mangle]
pub unsafe extern "C" fn get_vulkan_instance(p_context: *mut VulkanContext) -> u64 {
    println!("printer before get vk instance");
    let a = (*p_context).instance.handle().as_raw();
    println!("printer after get vk instance");
    a
}

// #[no_mangle]
// pub unsafe extern "C" fn import_vulkan_instance(p_context: *mut VulkanContext, instance_handle: u64) {
//     println!("vulkan instance is {}", instance_handle);
//     (*p_context).instance = ash::Instance { handle: ash::vk::Handle::from_raw(instance_handle), ..Default::default() };
// }

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

impl Point {
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
